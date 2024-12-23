//
// Created by jason.lu on 2024/12/23.
//
#include "types.hpp"
#include "debug.hpp"

#define RW_COMP_ONE(name, id) #name,
const char *RW_COMPONENT_NAMES[] = {
#include "components_list.inl"
};
#undef RW_COMP_ONE

const char *RW_State_currently_in = RW_COMPONENT_NAMES[RW_COMPONENT::RWC_ENGINE_COMMON];
static RW_TRACE_KIND Current_Cmd_Opt = TRACE_ERROR;
static RW_TRACE_KIND Trace_opts[RW_COMPONENT_MAX];

void RW_Assertion_Failure_Print ( const char *fmt, ... )
{
    va_list vp;

    char msg[512];
    INT32 pos;

    /* Prepare header line: */
    va_start ( vp, fmt );
    pos = sprintf ( &msg[0], "### Assertion Failure in Phase %s: \n", RW_State_currently_in);
    pos += vsprintf ( &msg[pos], fmt, vp );
    sprintf ( &msg[pos], "\n" );
    va_end ( vp );
    fprintf(stderr, "%s\n", msg);
    exit(EXIT_ASSERTION);
}

void RW_Failure_print ( const char *fmt, ... )
{
    va_list vp;

    char msg[512];
    INT32 pos;

    /* Prepare header line: */
    va_start ( vp, fmt );
    pos = sprintf ( &msg[0], "Compilation failure in phase %s: \n", RW_State_currently_in);
    pos += vsprintf ( &msg[pos], fmt, vp );
    sprintf ( &msg[pos], "\n" );
    va_end ( vp );
    fprintf(stderr, "%s\n", msg);
    exit(EXIT_COMP_ERR);
}

/***
 *  Quit the processing with trace
 **/
void RW_Quit_with_tracing(const char * file, UINT32 line) {
    // In case we don't want to expose the source code,
    // we could remove it compile-time by specify OCC_NO_TRACE_LINENO
    // we could remove it run-time by specify TRACE_OPT_NOLINENO
#ifndef OCC_NO_TRACE_LINENO
    if (Current_Cmd_Opt != RW_TRACE_KIND::TRACE_OPT_NOLINENO) {
        fprintf(stderr, "### In file %s:%d\n", file, line);
    }
#endif
    fprintf(stderr, "%s", "occ: fatal error: ");
}

/**
 * Get tracing level for specific component, this should not be exposed elsewhere than this file.
 * @param whole
 */
static RW_TRACE_KIND Get_tracing_level(RW_COMPONENT whole) {
    INT32 outcome = static_cast<INT32>(whole);
    RW_ASSERT_THAT(outcome < RW_COMPONENT_MAX, ("Failed to process component id = %.8x, to trace ", whole));
    RW_ASSERT_THAT(outcome >= 0, ("Failed to process component id = %.8x, to trace ", whole));
    return Trace_opts[outcome];
}

void RW_init_trace_opts() {
    Current_Cmd_Opt = (RW_TRACE_KIND) ((int) TRACE_DEBUG | (int) TRACE_ERROR);
    for (UINT32 i = 0; i < RW_COMPONENT_MAX; i++) {
        Trace_opts[i] = Current_Cmd_Opt;
    }
}

void RW_init_trace_opts(RW_TRACE_KIND tp) {
    for (UINT32 i = 0; i < RW_COMPONENT_MAX; i++) {
        Trace_opts[i] = tp;
    }
}


/**
 *  The tracing option function used to determine whether to enable tracing for this kind of trace
 **/
BOOL Tracing(RW_COMPONENT tl, RW_TRACE_KIND tk) {
    // Make sure I have a table to set each component's log level here.
    RW_TRACE_KIND lvl = Get_tracing_level(tl);
    return !!(lvl & tk);
}

/**
 * Set up tracing option given command line argument
 * @param opts can be either default / verbose or a specific trace level.
 */
void Set_tracing_option(RW_TRACE_KIND mopts) {
    RW_TRACE_KIND res_opts = mopts;
    if (mopts == TRACE_OPT_DEFAULT || mopts == TRACE_OPT_NOLINENO) {
        res_opts = TRACE_ERROR;
    } else if (mopts == TRACE_OPT_VERBOSE) {
        res_opts = static_cast<RW_TRACE_KIND>(0x7fffffff);
    }
    Current_Cmd_Opt = res_opts;
    UINT32 max = RW_COMPONENT_MAX;
    for (UINT32 i = 0; i < max; i++) {
        Trace_opts[i] = res_opts;
    }
}

void Set_mod_tracing_option(RW_COMPONENT comp, RW_TRACE_KIND desired) {
    RW_TRACE_KIND res_opts = desired;
    if (desired == TRACE_OPT_DEFAULT || desired == TRACE_OPT_NOLINENO) {
        res_opts = TRACE_ERROR;
    } else if (desired == TRACE_OPT_VERBOSE) {
        res_opts = static_cast<RW_TRACE_KIND>(0x7fffffff);
    }
    UINT32 max = RW_COMPONENT_MAX;
    RW_ASSERT_THAT(comp <= max,
                   ("Component index out of bound when seeting up trace opt: %d", comp));
    Trace_opts[comp] = res_opts;
}