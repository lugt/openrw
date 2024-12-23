#ifndef _LIBRW_DEBUG_HPP_
#define _LIBRW_DEBUG_HPP_

#ifdef RW_DEBUG
#include <cstdlib>
#include <functional>

extern std::function<void()> _rw_abort_cb[2];
#define SET_RW_ABORT_CB(cb0, cb1) do { _rw_abort_cb[0] = cb0; _rw_abort_cb[1] = cb1;} while (0)

#define RW_ABORT() do { if(_rw_abort_cb[0]) _rw_abort_cb[0](); ::abort(); } while (0)
#define RW_ASSERT(cond) do { if (!(cond)) RW_ABORT();} while (0)

#if defined(RW_WINDOWS)
void WinBreak();
#define RW_BREAKPOINT() WinBreak()
#else
#include <csignal>
#define RW_BREAKPOINT() do { if(_rw_abort_cb[0]) _rw_abort_cb[0](); ::raise(SIGTRAP); if(_rw_abort_cb[1]) _rw_abort_cb[1](); } while (0)
#endif

#define RW_FAILED_NO_ACTION         0
#define RW_FAILED_ABORT_OPTION      1
#define RW_FAILED_BREAKPOINT_OPTION 2

#if RW_FAILED_CHECK_ACTION == RW_FAILED_NO_ACTION
#define _RW_FAILED_CHECK_ACTION()
#elif RW_FAILED_CHECK_ACTION == RW_FAILED_ABORT_OPTION
#define _RW_FAILED_CHECK_ACTION() RW_ABORT()
#elif RW_FAILED_CHECK_ACTION == RW_FAILED_BREAKPOINT_OPTION
#define _RW_FAILED_CHECK_ACTION() RW_BREAKPOINT()
#endif

#else
#define SET_RW_ABORT_CB(cb0, cb1)
#define RW_ABORT()
#define RW_ASSERT(cond)
#define RW_BREAKPOINT()
#define _RW_FAILED_CHECK_ACTION()
#endif

#if defined(RW_DEBUG) && defined(RW_VERBOSE_DEBUG_MESSAGES)
#include <iostream>
#define RW_MESSAGE(msg) \
    std::cout << __FILE__ << ":" << __LINE__ << ": " << msg << '\n'
#define RW_ERROR(msg) \
    std::cerr << __FILE__ << ":" << __LINE__ << ": " << msg << '\n'
#else
#define Release_Mode 1
#define RW_MESSAGE(msg)
#define RW_ERROR(msg)
#endif

#if RW_DEBUG
#define RW_CHECK(cond, msg) \
    do { if (!(cond)) { RW_ERROR(msg); _RW_FAILED_CHECK_ACTION();}} while (0)
#else
#define RW_CHECK(cond, msg)
#endif

#define RW_UNUSED(var) (void)var

#define RW_UNIMPLEMENTED(msg) RW_MESSAGE("Unimplemented: " << msg)

#define RW_assert_dev(Condition, Params) \
(Condition ? (void) 1 \
:(RW_Quit_with_tracing ( __FILE__, __LINE__ ),	\
RW_Assertion_Failure_Print Params) );

/* Only in non-release mode */
#ifndef Release_Mode
# define RW_ASSERT_THAT RW_assert_dev
# define Assert_Ret(cond, msg, ...) RW_ASSERT_THAT(cond, msg)
#else
# define RW_ASSERT_THAT(a, b) ((void) 1)
# define Assert_Ret (cond, msg, ...)    \
  if(!(cond)) {                         \
    return __VA_ARGS__;                 \
  }
#endif

// Host definitions
typedef int INT;
typedef bool BOOL;
typedef short SHORT;
typedef char INT8;
typedef short INT16;
typedef unsigned char BYTE;
typedef int INT32;
typedef long long INT64;
typedef unsigned int UINT;
typedef unsigned char UINT8;
typedef unsigned short UINT16;
typedef unsigned int UINT32;
typedef unsigned long long UINT64;

#define TFile stderr
#define RW_TFile stderr
#define Is_Trace(cond, printval) { if ((cond)) { fprintf printval; fflush(stderr); } }
#define RW_TRACE(cond, printval) { if ((cond)) { fprintf printval; fflush(stderr); } }
#define RWT Tracing

extern void RW_Quit_with_tracing(const char *, unsigned int); // Quiting
extern void RW_Assertion_Failure_Print ( const char *fmt, ... ); // Printf-like function
extern const char * RW_State_currently_in; // Compilation Phase currently in
extern void RW_Failure_print ( const char *fmt, ... ); // Compilation Failure message printing

typedef enum {
    EXIT_NORMAL = 0,
    EXIT_UNKNOWN = 1,
    EXIT_ASSERTION = 2,
    EXIT_OPTION_ERR = 3,
    EXIT_COMP_ERR = 4,
} EXIT_CODES;

#define RW_COMP_ONE(name, id)   name = id,
enum RW_COMPONENT {
#include "components_list.inl"
};
#undef RW_COMP_ONE

extern const char *RW_COMPONENT_NAMES[];

enum RW_TRACE_KIND {
    TRACE_DEBUG       = 0x1,
    TRACE_DATA        = 0x2,
    TRACE_INFO        = 0x4,
    TRACE_PERFORMANCE = 0x8,
    TRACE_INVOCATION  = 0x10,
    TRACE_OPTIONS     = 0x20,
    TRACE_EMIT_CORE   = 0x40,
    TRACE_EMIT_BASIC  = 0x80,
    TRACE_WARN        = 0x100,
    TRACE_ERROR       = 0x200,
    TRACE_FATAL       = 0x400,
    TRACE_OPT_DEFAULT = 0x800,
    TRACE_OPT_VERBOSE = 0x1000,
    TRACE_OPT_NOLINENO= 0x2000,
    TRACE_CUSTOM1     = 0x4000,
    TRACE_CUSTOM2     = 0x8000,
};

// Tracing option
extern bool Tracing(RW_COMPONENT tl, RW_TRACE_KIND tk);
extern void RW_init_trace_opts(RW_TRACE_KIND opts);
extern void RW_set_mod_tracing_option(RW_COMPONENT comp, RW_TRACE_KIND desired);
extern void RW_init_trace_opts();

#endif
