# OpenRW SCM 脚本 Opcode 实现状态

本文档由 `GTA3ModuleImpl.inl` 的 Doxygen `@brief` 与 `RW_UNIMPLEMENTED_OPCODE` 标记自动梳理 + 人工审校生成,反映 OpenRW 对 GTA III SCM 脚本虚拟机的实现进度。


**总览**:opcode 904 个 | 已实现 519 (57%) | 未实现 385 (43%) | 条件opcode(bool 返回) 248


> 说明:`0x8000` 高位是"取反条件"标志(VM 层处理),注册表 key 始终是低 15 位。条件opcode 返回 bool,非条件返回 void。


## 一、全局统计
### 按 ID 段实现率

| ID 段 | 范围 | 已实现 | 未实现 | 实现率 |
|---|---|---|---|---|
| 0x00xx | 0x0000-0x00ff | 196 | 26 | 88% |
| 0x01xx | 0x0100-0x01ff | 138 | 58 | 70% |
| 0x02xx | 0x0200-0x02ff | 76 | 91 | 46% |
| 0x03xx | 0x0300-0x03ff | 76 | 155 | 33% |
| 0x04xx | 0x0400-0x04ff | 33 | 55 | 38% |

### 按功能域分布

| 功能域 | 已实现 | 未实现 | 实现率 |
|---|---|---|---|
| 流程控制与线程 | 37 | 7 | 84% |
| 系统与平台 | 4 | 6 | 40% |
| 任务与脚本事件 | 24 | 51 | 32% |
| 物件操作与碰撞 | 88 | 33 | 72% |
| 变量与数学运算 | 174 | 31 | 84% |
| 摄像机 | 11 | 14 | 44% |
| 过场动画 | 7 | 3 | 70% |
| 角色与AI行为 | 83 | 104 | 44% |
| 车辆 | 26 | 53 | 33% |
| 拾取物与武器 | 4 | 1 | 80% |
| 文本与UI | 15 | 41 | 26% |
| 环境天气时间 | 5 | 3 | 62% |
| 区域与车库 | 10 | 3 | 76% |
| 地图标记 Blip | 5 | 0 | 100% |
| 音频 | 4 | 3 | 57% |
| 特效(粒子/爆炸/火焰) | 3 | 10 | 23% |
| 输入控制 | 1 | 2 | 33% |
| 统计与存档 | 12 | 9 | 57% |
| 其他(未归类) | 6 | 11 | 35% |

## 二、各功能域明细


### 流程控制与线程  (实现 37 / 未实现 7)

**已实现**

| Opcode | Brief | 条件 |
|---|---|---|
| 0x0001 | wait %1d% ms |  |
| 0x0002 | goto %1p% |  |
| 0x004c | goto_if_true %1p% |  |
| 0x004d | goto_if_false %1p% |  |
| 0x004e | end_thread |  |
| 0x004f | create_thread %1p% |  |
| 0x0050 | gosub %1p% |  |
| 0x0051 | return |  |
| 0x00c5 | return_true | ✓ |
| 0x00c6 | return_false | ✓ |
| 0x00d6 | if %1d% |  |
| 0x00d7 | create_thread_without_extra_params %1p% |  |
| 0x00d8 | mission_has_finished |  |
| 0x0180 | declare_mission_flag %1d% |  |
| 0x0181 | declare_mission_flag_for_contact %1d% as %2d% |  |
| 0x01c5 | remove_actor_from_mission_cleanup_list %1d% |  |
| 0x01c6 | remove_car_from_mission_cleanup_list %1d% |  |
| 0x01c7 | remove_object_from_mission_cleanup_list %1d% |  |
| 0x0255 | set_critical_mission_restart_at %1d% %2d% %3d% angle %4d% |  |
| 0x02a1 | skippable_wait |  |
| 0x02cd | call %1p% %2p% |  |
| 0x030c | set_mission_points += %1d% |  |
| 0x030d | set_total_mission_points_to %1d% |  |
| 0x030e | save_jump_distance %1d% |  |
| 0x030f | save_jump_height %1d% |  |
| 0x0310 | save_jump_flips %1d% |  |
| 0x0311 | save_jump_rotation %1d% |  |
| 0x0312 | save_jump_type %1d% |  |
| 0x0313 | increment_unique_jumps_found |  |
| 0x0314 | set_total_unique_jumps_to %1d% |  |
| 0x0317 | increment_mission_attempts |  |
| 0x0318 | set_latest_mission_passed %1g% |  |
| 0x0394 | play_mission_passed_music %1d% |  |
| 0x03a4 | name_thread %1s% |  |
| 0x0407 | time_taken_defuse_mission = %1d% |  |
| 0x0417 | start_mission %1d% |  |
| 0x042c | set_total_missions_to %1d% |  |

**未实现**

| Opcode | Brief | 条件 |
|---|---|---|
| 0x00a7 | car_goto_coordinates %1d% coords %2d% %3d% %4d% |  |
| 0x00af | set_car_mission %1d% to %2d% |  |
| 0x02eb | restore_camera_jumpcut |  |
| 0x0372 | set_actor %1d% anim %2d% wait_state_time %3d% ms |  |
| 0x03c3 | set_timer_with_text_to %1d% type %2h% text %3g% |  |
| 0x040d | clear_mission_audio |  |
| 0x0459 | end_threads_named %1s% |  |


### 系统与平台  (实现 4 / 未实现 6)

**已实现**

| Opcode | Brief | 条件 |
|---|---|---|
| 0x00c3 | debug_on |  |
| 0x00c4 | debug_off |  |
| 0x0112 | has_deatharrest_been_executed | ✓ |
| 0x043d | set_intro_is_playing %1d% |  |

**未实现**

| Opcode | Brief | 条件 |
|---|---|---|
| 0x0351 | gore_enabled | ✓ |
| 0x03af | set_streaming %1b:enabled/disabled% |  |
| 0x03e3 | set_sprites_draw_before_fade %1h% |  |
| 0x040b | is_french_game | ✓ |
| 0x040c | is_german_game | ✓ |
| 0x0424 | metric | ✓ |


### 任务与脚本事件  (实现 24 / 未实现 51)

**已实现**

| Opcode | Brief | 条件 |
|---|---|---|
| 0x0169 | set_fade_color %1d% %2d% %3d% |  |
| 0x016a | fade %2b% for %1d% ms |  |
| 0x016b | fading | ✓ |
| 0x016e | override_next_restart at %1d% %2d% %3d% heading %4d% |  |
| 0x01f0 | set_max_wanted_level_to %1d% |  |
| 0x01f6 | cancel_override_restart |  |
| 0x024a | %3d% = create_payphone_at %1d% %2d% |  |
| 0x024c | text_payphone %1d% %2g% |  |
| 0x024e | disable_payphone %1d% |  |
| 0x02ec | put_hidden_package_at %1d% %2d% %3d% |  |
| 0x02ed | set_total_hidden_packages_to %1d% |  |
| 0x034a | portland_complete |  |
| 0x034b | staunton_complete |  |
| 0x034c | shoreside_complete |  |
| 0x0354 | set_up_chase_scene %1d% |  |
| 0x0355 | clean_up_chase_scene |  |
| 0x035b | %4d% = create_drop_off_package %1d% %2d% %3d% |  |
| 0x03c2 | payphone %1d% answered | ✓ |
| 0x0405 | enable_payphone %1d% |  |
| 0x0408 | set_total_rampages_to %1d% |  |
| 0x0413 | enable %1d% get_out_of_jail_free %2d% |  |
| 0x041f | override_hospital %1d% |  |
| 0x043c | set_game_sounds_fade %1d% |  |
| 0x0447 | is_player_lifting_a_payphone %1d% | ✓ |

**未实现**

| Opcode | Brief | 条件 |
|---|---|---|
| 0x0149 | car %1d% crushed_by_car_crusher | ✓ |
| 0x0178 | player %1d% picked_up_object %2d% | ✓ |
| 0x0179 | actor %1d% picked_up_object %2d% | ✓ |
| 0x01ee | activate_crane %1d% %2d% %3d% %4d% %5d% %6d% %7d% %8d% %9d% %10d% |  |
| 0x01ef | deactivate_crane %1d% %2d% |  |
| 0x01f9 | init_rampage %1g% weapon %2d% time %3d% %4d% targets %5o% %6o% %7o% %8o% flag %9d% |  |
| 0x01fa | %1d% = rampage_status |  |
| 0x021d | set_free_bomb_shop_to %1btrue/false% |  |
| 0x024b | text_payphone_repeatedly %1d% %2g% |  |
| 0x024d | payphone_text_been_displayed %1d% | ✓ |
| 0x0297 | clear_rampage_kills |  |
| 0x0298 | %2d% = rampage_kills %1o% |  |
| 0x02fb | create_crusher_crane %1d% %2d% %3d% %4d% %5d% %6d% %7d% %8d% %9d% %10d% |  |
| 0x0335 | set_free_paynspray_to %1b:true/false% |  |
| 0x033a | create_incoming_cessna |  |
| 0x033b | incoming_cessna_landed | ✓ |
| 0x033c | incoming_cessna_destroyed | ✓ |
| 0x034f | destroy_actor_with_fade %1d% |  |
| 0x0358 | start_drug_drop_off |  |
| 0x0359 | drop_off_cessna_shot_down | ✓ |
| 0x035a | find_drop_off_plane_coords %1d% %2d% %3d% |  |
| 0x0367 | init_headshot_rampage %1g% weapon %2d% time %3d% %4d% targets %5o% %6o% %7o% %8o% flag %9d% |  |
| 0x0368 | create_ev_crane %1d% %2d% %3d% %4d% %5d% %6d% %7d% %8d% %9d% %10d% |  |
| 0x0378 | text_payphone_1string_repeatedly %1d% %2g% %3g% |  |
| 0x0379 | text_payphone_1string %1d% %2g% %3g% |  |
| 0x037a | text_payphone_2strings_repeatedly %1d% %2g% %3g% %4g% |  |
| 0x037b | text_payphone_2strings %1d% %2g% %3g% %4g% |  |
| 0x037c | text_payphone_3strings_repeatedly %1d% %2g% %3g% %4g% %5g% |  |
| 0x037d | text_payphone_3strings %1d% %2g% %3g% %4g% %5g% |  |
| 0x0386 | text_payphone_4strings_repeatedly %1d% %2g% %3g% %4g% %5g% %6g% |  |
| 0x0387 | text_payphone_4strings %1d% %2g% %3g% %4g% %5g% %6g% |  |
| 0x0388 | text_payphone_5strings_repeatedly %1d% %2g% %3g% %4g% %5g% %6g% %7g% |  |
| 0x0389 | text_payphone_5strings %1d% %2g% %3g% %4g% %5g% %6g% %7g% |  |
| 0x03a0 | car %3d% picked_up_by_crane %1d% %2d% | ✓ |
| 0x03aa | play_suspect_last_seen_at %1d% %2d% %3d% |  |
| 0x03ac | clear_route %1d% |  |
| 0x03b2 | start_catalina_flyby |  |
| 0x03b3 | catalina_take_off |  |
| 0x03b4 | remove_catalina_heli |  |
| 0x03b5 | catalina_shot_down | ✓ |
| 0x03b9 | create_catalinas_chopper %1d% |  |
| 0x03be | catalina_heli_drop_explosives_on_player |  |
| 0x03c7 | set_sensitivity_to_crime_to %1d% |  |
| 0x03e0 | set_text_draw_before_fade %1h% |  |
| 0x03ec | ev_crane_collected_all_cars | ✓ |
| 0x040e | %1b:set/clear% FadeInAfterNextArrest |  |
| 0x040f | %1b:set/clear% FadeInAfterNextDeath |  |
| 0x0434 | show_credits |  |
| 0x0435 | end_credits |  |
| 0x0436 | reached_end_of_credits | ✓ |
| 0x044c | change_to_island %1d% |  |


### 物件操作与碰撞  (实现 88 / 未实现 33)

**已实现**

| Opcode | Brief | 条件 |
|---|---|---|
| 0x0056 | is_player_in_area_2d %1d% coords %2d% %3d% to %4d% %5d% sphere %6b% | ✓ |
| 0x0057 | is_player_in_area_3d %1d% coords %2d% %3d% %4d% to %5d% %6d% %7d% sphere %8b% | ✓ |
| 0x00a3 | is_char_in_area_2d %1d% from %2d% %3d% to %4d% %5d% sphere %6d% | ✓ |
| 0x00a4 | is_char_in_area_3d %1d% from %2d% %3d% %4d% to %5d% %6d% %7d% sphere %8d% | ✓ |
| 0x00b0 | is_car_in_area_2d %1d% from %2d% %3d% to %4d% %5d% sphere %6d% | ✓ |
| 0x00b1 | is_car_in_area_3d %1d% from %2d% %3d% %4d% to %5d% %6d% %7d% sphere %8d% | ✓ |
| 0x00e3 | player %1d% %6bin-sphere/%near_point %2d% %3d% radius %4d% %5d% | ✓ |
| 0x00e4 | player %1d% %6b:in-sphere/%near_point_on_foot %2d% %3d% radius %4d% %5d% | ✓ |
| 0x00e5 | player %1d% %6bin-sphere/%near_point_in_car %2d% %3d% radius %4d% %5d% | ✓ |
| 0x00e6 | player %1d% stopped %6bin-sphere/%near_point %2d% %3d% radius %4d% %5d% | ✓ |
| 0x00e7 | player %1d% stopped %6b:in-sphere/%near_point_on_foot %2d% %3d% radius %4d% %5d% | ✓ |
| 0x00e8 | player %1d% stopped %6b:in-sphere/%near_point_in_car %2d% %3d% radius %4d% %5d% | ✓ |
| 0x00e9 | player %1d% %5b:in-sphere/%near_actor %2d% radius %3d% %4d% | ✓ |
| 0x00ea | player %1d% %5b:in-sphere/%near_actor_on_foot %2d% radius %3d% %4d% | ✓ |
| 0x00eb | player %1d% %5b:in-sphere/%near_actor_in_car %2d% radius %3d% %4d% | ✓ |
| 0x00ec | actor %1d% %6bin-sphere/%near_point %2d% %3d% radius %4d% %5d% | ✓ |
| 0x00ed | actor %1d% %6bin-sphere/%near_point_on_foot %2d% %3d% radius %4d% %5d% | ✓ |
| 0x00ee | actor %1d% %6bin-sphere/%near_point_in_car %2d% %3d% radius %4d% %5d% | ✓ |
| 0x00ef | actor %1d% sphere %6bin-sphere/%near_point %2d% %3d% radius %4d% %5d% | ✓ |
| 0x00f0 | actor %1d% stopped %6bin-sphere/%near_point_on_foot %2d% %3d% radius %4d% %5d% | ✓ |
| 0x00f1 | actor %1d% stopped %6bin-sphere/%near_point_in_car %2d% %3d% radius %4d% %5d% | ✓ |
| 0x00f2 | locate_char_any_means_char_2d %1d% char %2d% radius %3d% %4d% sphere %5h% | ✓ |
| 0x00f3 | actor %1d% near_actor_on_foot %2d% radius %3d% %4d% sphere %5h% | ✓ |
| 0x00f5 | player %1d% %8b:in-sphere/%near_point %2d% %3d% %4d% radius %5d% %6d% %7d% | ✓ |
| 0x00f6 | player %1d% %8b:in-sphere/%near_point_on_foot %2d% %3d% %4d% radius %5d% %6d% %7d% | ✓ |
| 0x00f7 | player %1d% sphere %8b% near_point_in_car %2d% %3d% %4d% radius %5d% %6d% %7d% | ✓ |
| 0x00f8 | player %1d% stopped %8b:in-sphere/%near_point %2d% %3d% %4d% radius %5d% %6d% %7d% | ✓ |
| 0x00f9 | player %1d% stopped %8b:in-sphere/%near_point_on_foot %2d% %3d% %4d% radius %5d% %6d% %7d% | ✓ |
| 0x00fa | player %1d% stopped %8b:in-sphere/%near_point_in_car %2d% %3d% %4d% radius %5d% %6d% %7d% | ✓ |
| 0x00fb | player %1d% %6b:in-sphere/%near_actor %2d% radius %3d% %4d% %5d% | ✓ |
| 0x00fc | player %1d% %6b:in-sphere/%near_actor %2d% on_foot radius %3d% %4d% %5d% | ✓ |
| 0x00fd | player %1d% %6b:in-sphere/%near_actor %2d% in_car radius %3d% %4d% %5d% | ✓ |
| 0x00fe | actor %1d% %8bin-sphere/%near_point %2d% %3d% %4d% radius %5d% %6d% %7d% | ✓ |
| 0x00ff | actor %1d% %8bin-sphere/%near_point_on_foot %2d% %3d% %4d% radius %5d% %6d% %7d% | ✓ |
| 0x0100 | actor %1d% near_point_in_car %2d% %3d% %4d% radius %5d% %6d% %7d% sphere %8h% | ✓ |
| 0x0101 | actor %1d% stopped_near_point %2d% %3d% %4d% radius %5d% %6d% %7d% sphere %8h% | ✓ |
| 0x0102 | actor %1d% stopped_near_point_on_foot %2d% %3d% %4d% radius %5d% %6d% %7d% sphere %8h% | ✓ |
| 0x0103 | actor %1d% stopped_near_point_in_car %2d% %3d% %4d% radius %5d% %6d% %7d% sphere %8d% | ✓ |
| 0x0104 | actor %1d% near_actor %2d% radius %3d% %4d% %5d% sphere %6h% | ✓ |
| 0x0105 | actor %1d% near_actor_on_foot %2d% radius %3d% %4d% %5d% sphere %6h% | ✓ |
| 0x0107 | %5d% = create_object %1o% at %2d% %3d% %4d% |  |
| 0x0108 | destroy_object %1d% |  |
| 0x0163 | %4d% = create_marker_above_object %1d% color %2d% visibility %3d% |  |
| 0x0176 | %2d% = object %1d% z_angle |  |
| 0x0177 | set_object %1d% z_angle_to %2d% |  |
| 0x0188 | %2d% = create_marker_above_object %1d% |  |
| 0x0197 | player %1d% %6b:in-sphere/%in_rectangle_on_foot %2d% %3d% %4d% %5d% | ✓ |
| 0x0198 | player %1d% %6b:in-sphere/%in_rectangle_in_car %2d% %3d% %4d% %5d% | ✓ |
| 0x0199 | player %1d% %6b:in-sphere/%in_rectangle %2d% %3d% %4d% %5d% | ✓ |
| 0x019a | player %1d% stopped %6b:in-sphere/%in_rectangle_on_foot %2d% %3d% %4d% %5d% | ✓ |
| 0x019b | player %1d% stopped %6b:in-sphere/%in_rectangle_in_car %2d% %3d% %4d% %5d% | ✓ |
| 0x019c | player %1d% %8b:in-sphere/%in_cube_on_foot %2d% %3d% %4d% %5d% %6d% %7d% | ✓ |
| 0x019d | player %1d% %8b:in-sphere/%in_cube_in_car %2d% %3d% %4d% %5d% %6d% %7d% | ✓ |
| 0x019e | player %1d% stopped %8b:in-sphere/%in_cube %2d% %3d% %4d% %5d% %6d% %7d% | ✓ |
| 0x019f | player %1d% stopped %8b:in-sphere/%in_cube_on_foot %2d% %3d% %4d% %5d% %6d% %7d% | ✓ |
| 0x01a0 | player %1d% stopped %8b:in-sphere/%in_cube_in_car %2d% %3d% %4d% %5d% %6d% %7d% | ✓ |
| 0x01a1 | actor %1d% %6b:in-sphere/%in_rectangle_on_foot %2d% %3d% %4d% %5d% | ✓ |
| 0x01a2 | actor %1d% %6b:in-sphere/%in_rectangle_in_car %2d% %3d% %4d% %5d% | ✓ |
| 0x01a3 | actor %1d% stopped %6bin-sphere/%in_rectangle %2d% %3d% %4d% %5d% | ✓ |
| 0x01a4 | actor %1d% stopped %6bin-sphere/%in_rectangle_on_foot %2d% %3d% %4d% %5d% | ✓ |
| 0x01a5 | actor %1d% stopped %6b:in-sphere/%in_rectangle_in_car %2d% %3d% %4d% %5d% | ✓ |
| 0x01a6 | actor %1d% %8b:in-sphere/%in_cube_on_foot %2d% %3d% %4d% %5d% %6d% %7d% | ✓ |
| 0x01a7 | actor %1d% %8b:in-sphere/%in_cube_in_car %2d% %3d% %4d% %5d% %6d% %7d% | ✓ |
| 0x01a8 | actor %1d% stopped %8bin-sphere/%in_cube %2d% %3d% %4d% %5d% %6d% %7d% | ✓ |
| 0x01a9 | actor %1d% stopped %8b:in-sphere/%in_cube_on_foot %2d% %3d% %4d% %5d% %6d% %7d% | ✓ |
| 0x01aa | actor %1d% stopped %8b:in-sphere/%in_cube_in_car %2d% %3d% %4d% %5d% %6d% %7d% | ✓ |
| 0x01ab | car %1d% stopped %6b:in-sphere/%in_rectangle %2d% %3d% %4d% %5d% | ✓ |
| 0x01ac | car %1d% stopped %8b:in-sphere/%in_cube %2d% %3d% %4d% %5d% %6d% %7d% | ✓ |
| 0x01ad | car %1d% sphere %6b% near_point %2d% %3d% radius %4d% %5d% | ✓ |
| 0x01ae | car %1d% stopped %6b:in-sphere/%near_point %2d% %3d% %4d% %5d% | ✓ |
| 0x01af | car %1d% %8bin-sphere/%near_point %2d% %3d% %4d% radius %5d% %6d% %7d% | ✓ |
| 0x01b0 | car %1d% stopped %8b:in-sphere/%near_point %2d% %3d% %4d% radius %5d% %6d% %7d% | ✓ |
| 0x01bb | store_object %1d% position_to %2d% %3d% %4d% |  |
| 0x01bc | set_object_coordinates %1d% at %2d% %3d% %4d% |  |
| 0x01c4 | remove_references_to_object %1d% |  |
| 0x01e0 | clear_leader %1d% |  |
| 0x01e7 | switch_roads_on %1d% %2d% %3d% to %4d% %5d% %6d% |  |
| 0x01e8 | switch_roads_off %1d% %2d% %3d% to %4d% %5d% %6d% |  |
| 0x0202 | actor %1d% near_car %2d% radius %3d% %4d% sphere %5d% | ✓ |
| 0x029b | %5d% = create_object %1o% at %2d% %3d% %4d% |  |
| 0x02a7 | %5d% = create_icon_marker_and_sphere %4d% at %1d% %2d% %3d% |  |
| 0x02ce | get_ground_z_for_3d_coord %1d% %2d% %3d% store_to %4d% |  |
| 0x02e5 | %2d% = create_cutscene_object %1o% |  |
| 0x02f3 | load_object %1o% %2f% |  |
| 0x0339 | objects_in_cube %1d% %2d% %3d% to %4d% %5d% %6d% flags %7d% %8d% %9d% %10d% %11d% | ✓ |
| 0x034d | rotate_object %1d% from_angle %2d% to %3d% collision_check %4d% | ✓ |
| 0x0363 | toggle_model_render_at %1d% %2d% %3d% radius %4d% object %5o% %6d% |  |
| 0x0392 | object %1d% toggle_in_moving_list %2d% |  |

**未实现**

| Opcode | Brief | 条件 |
|---|---|---|
| 0x01d8 | actor %1d% destroy_object %2d% |  |
| 0x023a | has_player_collided_with_object %1d% %2d% |  |
| 0x023b | has_actor_collided_with_object %1d% %2d% |  |
| 0x0240 | flash_object %1d% %2d% |  |
| 0x02ad | player %1d% in_area %2d% %3d% %4d% %5d% radius %6d% sphere %7h% | ✓ |
| 0x02ae | player %1d% in_area_on_foot %2d% %3d% %4d% %5d% radius %6d% sphere %7h% | ✓ |
| 0x02af | player %1d% in_area_in_car %2d% %3d% %4d% %5d% radius %6d% sphere %7h% | ✓ |
| 0x02b0 | player %1d% stopped_in_area %2d% %3d% %4d% %5d% radius %6d% sphere %7h% | ✓ |
| 0x02b1 | player %1d% stopped_in_area_on_foot %2d% %3d% %4d% %5d% radius %6d% sphere %7h% | ✓ |
| 0x02b2 | player %1d% stopped_in_area_in_car %2d% %3d% %4d% %5d% radius %6d% sphere %7h% | ✓ |
| 0x02b3 | player %1d% in_cube %2d% %3d% %4d% %5d% %6d% %7d% radius %8d% sphere %9h% | ✓ |
| 0x02b4 | player %1d% in_cube_on_foot %2d% %3d% %4d% %5d% %6d% %7d% radius %8d% sphere %9h% | ✓ |
| 0x02b5 | player %1d% in_cube_in_car %2d% %3d% %4d% %5d% %6d% %7d% radius %8d% sphere %9h% | ✓ |
| 0x02b6 | player %1d% stopped_in_cube %2d% %3d% %4d% %5d% %6d% %7d% radius %8d% sphere %9h% | ✓ |
| 0x02b7 | player %1d% stopped_in_cube_on_foot %2d% %3d% %4d% %5d% %6d% %7d% radius %8d% sphere %9h% | ✓ |
| 0x02b8 | player %1d% stopped_in_cube_in_car %2d% %3d% %4d% %5d% %6d% %7d% radius %8d% sphere %9h% | ✓ |
| 0x02c7 | scatter_platinum %5d% at %1d% %2d% %3d% %4d% |  |
| 0x02ee | is_projectile_in_cube %1d% %2d% %3d% to %4d% %5d% %6d% | ✓ |
| 0x02ef | destroy_projectiles_in_cube %1d% %2d% %3d% to %4d% %5d% %6d% |  |
| 0x02f1 | drop_nautical_mine_at %1d% %2d% %3d% |  |
| 0x034e | move_object %1d% to %2d% %3d% %4d% speed %5d% %6d% %7d% collision_check %8d% | ✓ |
| 0x035c | place_object %1d% relative_to_car %2d% offset %3d% %4d% %5d% |  |
| 0x035d | make_object %1d% targetable |  |
| 0x0381 | throw_object %1d% distance %2d% %3d% %4d% |  |
| 0x0382 | set_object %1d% collision_detection %2d% |  |
| 0x038c | object %1d% scatter %2d% %3d% %4d% |  |
| 0x03ae | remove_objects_from_cube %1d% %2d% %3d% to %4d% %5d% %6d% |  |
| 0x03bc | %5d% = create_sphere_at %1d% %2d% %3d% radius %4d% |  |
| 0x03bd | destroy_sphere %1d% |  |
| 0x03ca | object %1d% exists | ✓ |
| 0x0418 | set_object %1d% draw_last %2h% |  |
| 0x0453 | object %1d% set_rotation %2d% %3d% %4d% |  |
| 0x0458 | is_player_targeting_object %1d% %1d% | ✓ |


### 变量与数学运算  (实现 174 / 未实现 31)

**已实现**

| Opcode | Brief | 条件 |
|---|---|---|
| 0x0004 | %1d% = %2d% |  |
| 0x0005 | %1d% = %2d% |  |
| 0x0006 | %1d% = %2d% |  |
| 0x0007 | %1d% = %2d% |  |
| 0x0008 | %1d% += %2d% |  |
| 0x0009 | %1d% += %2d% |  |
| 0x000a | %1d% += %2h% |  |
| 0x000b | %1d% += %2d% |  |
| 0x000c | %1d% -= %2d% |  |
| 0x000d | %1d% -= %2d% |  |
| 0x000e | %1d% -= %2h% |  |
| 0x000f | %1d% -= %2d% |  |
| 0x0010 | %1d% *= %2d% |  |
| 0x0011 | %1d% *= %2d% |  |
| 0x0012 | %1d% *= %2d% |  |
| 0x0013 | %1d% *= %2d% |  |
| 0x0014 | %1d% /= %2d% |  |
| 0x0015 | %1d% /= %2d% |  |
| 0x0016 | %1d% /= %2d% |  |
| 0x0017 | %1d% /= %2d% |  |
| 0x0018 | %1d% > %2d% | ✓ |
| 0x0019 | %1d% > %2d% | ✓ |
| 0x001a | %1d% > %2d% | ✓ |
| 0x001b | %1d% > %2d% | ✓ |
| 0x001c | %1d% > %2d% | ✓ |
| 0x001d | %1d% > %2d% | ✓ |
| 0x001e | %1d% > %2d% | ✓ |
| 0x001f | %1d% > %2d% | ✓ |
| 0x0020 | %1d% > %2d% | ✓ |
| 0x0021 | %1d% > %2d% | ✓ |
| 0x0022 | %1d% > %2d% | ✓ |
| 0x0023 | %1d% > %2d% | ✓ |
| 0x0024 | %1d% > %2d% | ✓ |
| 0x0025 | %1d% > %2d% | ✓ |
| 0x0026 | %1d% > %2d% | ✓ |
| 0x0027 | %1d% > %2d% | ✓ |
| 0x0028 | %1d% >= %2d% | ✓ |
| 0x0029 | %1d% >= %2d% | ✓ |
| 0x002a | %1d% >= %2d% | ✓ |
| 0x002b | %1d% >= %2d% | ✓ |
| 0x002c | %1d% >= %2d% | ✓ |
| 0x002d | %1d% >= %2d% | ✓ |
| 0x002e | %1d% >= %2d% | ✓ |
| 0x002f | %1d% >= %2d% | ✓ |
| 0x0030 | %1d% >= %2d% | ✓ |
| 0x0031 | %1d% >= %2d% | ✓ |
| 0x0032 | %1d% >= %2d% | ✓ |
| 0x0033 | %1d% >= %2d% | ✓ |
| 0x0034 | %1d% >= %2d% | ✓ |
| 0x0035 | %1d% >= %2d% | ✓ |
| 0x0036 | %1d% >= %2d% | ✓ |
| 0x0037 | %1d% >= %2d% | ✓ |
| 0x0038 | %1d% == %2d% | ✓ |
| 0x0039 | %1d% == %2d% | ✓ |
| 0x003a | %1d% == %2d% | ✓ |
| 0x003b | %1d% == %2d% | ✓ |
| 0x003c | %1d% == %2d% | ✓ |
| 0x0042 | %1d% == %2d% | ✓ |
| 0x0043 | %1d% == %2d% | ✓ |
| 0x0044 | %1d% == %2d% | ✓ |
| 0x0045 | %1d% == %2d% | ✓ |
| 0x0046 | %1d% == %2d% | ✓ |
| 0x0053 | %5d% = create_player %1o% at %2d% %3d% %4d% |  |
| 0x0058 | %1d% += %2d% |  |
| 0x0059 | %1d% += %2d% |  |
| 0x005a | %1d% += %2d% |  |
| 0x005b | %1d% += %2d% |  |
| 0x005c | %1d% += %2d% |  |
| 0x005d | %1d% += %2d% |  |
| 0x005e | %1d% += %2d% |  |
| 0x005f | %1d% += %2d% |  |
| 0x0060 | %1d% -= %2d% |  |
| 0x0061 | %1d% -= %2d% |  |
| 0x0062 | %1d% -= %2d% |  |
| 0x0063 | %1d% -= %2d% |  |
| 0x0064 | %1d% -= %2d% |  |
| 0x0065 | %1d% -= %2d% |  |
| 0x0066 | %1d% -= %2d% |  |
| 0x0067 | %1d% -= %2d% |  |
| 0x0068 | %1d% *= %2d% |  |
| 0x0069 | %1d% *= %2d% |  |
| 0x006a | %1d% *= %2d% |  |
| 0x006b | %1d% *= %2d% |  |
| 0x006c | %1d% *= %2d% |  |
| 0x006d | %1d% *= %2d% |  |
| 0x006e | %1d% *= %2d% |  |
| 0x006f | %1d% *= %2d% |  |
| 0x0070 | %1d% /= %2d% |  |
| 0x0071 | %1d% /= %2d% |  |
| 0x0072 | %1d% /= %2d% |  |
| 0x0073 | %1d% /= %2d% |  |
| 0x0074 | %1d% /= %2d% |  |
| 0x0075 | %1d% /= %2d% |  |
| 0x0076 | %1d% /= %2d% |  |
| 0x0077 | %1d% /= %2d% |  |
| 0x0084 | %1d% = %2d% |  |
| 0x0085 | %1d% = %2d% |  |
| 0x0086 | %1d% = %2d% |  |
| 0x0087 | %1d% = %2d% |  |
| 0x0088 | %1d% = %2d% |  |
| 0x0089 | %1d% = %2d% |  |
| 0x008a | %1d% = %2d% |  |
| 0x008b | %1d% = %2d% |  |
| 0x008c | %1d% = float_to_integer %2d% |  |
| 0x008d | %1d% = integer_to_float %2d% |  |
| 0x008e | %1d% = float_to_integer %2d% |  |
| 0x008f | %1d% = integer_to_float %2d% |  |
| 0x0090 | %1d% = float_to_int %2d% |  |
| 0x0091 | %1d% = int_to_float %2d% |  |
| 0x0092 | %1d% = float_to_int %2d% |  |
| 0x0093 | %1d% = int_to_float %2d% |  |
| 0x0098 | generate_random_float %1d% |  |
| 0x0099 | generate_random_int %1d% |  |
| 0x009a | %6d% = create_char %1d% model %2o% at %3d% %4d% %5d% |  |
| 0x00a5 | %5d% = create_car %1o% at %2d% %3d% %4d% |  |
| 0x00c1 | %3d% = get_minutes_until_time_of_day %1d% %2d% |  |
| 0x00d9 | %2d% = store_car_char_is_in %1d% |  |
| 0x00da | %2d% = store_car_player_is_in %1d% |  |
| 0x0109 | player %1d% money += %2d% |  |
| 0x010a | player %1d% money > %2d% | ✓ |
| 0x010b | %2d% = player %1d% money |  |
| 0x0137 | car %1d% id == %2o% | ✓ |
| 0x014b | %13d% = init_car_generator %5o% %6d% %7d% force_spawn %8d% alarm %9d% door_lock %10d% min_delay %11d% max_delay %12d% at %1d% %2d% %3d% angle %4d% |  |
| 0x014e | start_timer_at %1d% |  |
| 0x014f | stop_timer %1d% |  |
| 0x015d | set_time_scale %1d% |  |
| 0x0161 | %4d% = create_marker_above_car %1d% color %2d% visibility %3d% |  |
| 0x0162 | %4d% = create_marker_above_actor %1d% color %2d% visibility %3d% |  |
| 0x0167 | %6d% = create_marker_at %1d% %2d% %3d% color %4d% visibility %5d% |  |
| 0x0170 | %2d% = player %1d% z_angle |  |
| 0x0172 | %2d% = actor %1d% z_angle |  |
| 0x0174 | %2d% = car %1d% z_angle |  |
| 0x0182 | contact %1d% base_brief = %2d% |  |
| 0x0183 | player %1d% health > %2h% | ✓ |
| 0x0184 | actor %1d% health >= %2d% | ✓ |
| 0x0185 | car %1d% health >= %2d% | ✓ |
| 0x0186 | %2d% = create_marker_above_car %1d% |  |
| 0x0187 | %2d% = create_marker_above_actor %1d% |  |
| 0x0189 | %4d% = unknown_create_checkpoint_at %1d% %2d% %3d% |  |
| 0x018a | %4d% = create_checkpoint_at %1d% %2d% %3d% |  |
| 0x018d | %5d% = create_sound %4d% at %1d% %2d% %3d% |  |
| 0x01bd | %1d% = current_time_in_ms |  |
| 0x01c8 | %5d% = create_actor %2d% model %3o% in_car %1d% passenger_seat %4d% |  |
| 0x01e9 | %2d% = car %1d% num_passengers |  |
| 0x01ea | %2d% = car %1d% max_passengers |  |
| 0x01f5 | %2d% = create_emulated_actor_from_player %1d% |  |
| 0x01fb | %2d% = square_root %1d% |  |
| 0x0208 | %3d% = random_float %1d% %2d% |  |
| 0x0209 | %3d% = random_int_in_ranges %1d% %2d% |  |
| 0x0213 | %6d% = create_pickup %1o% type %2d% at %3d% %4d% %5d% |  |
| 0x0219 | %8h% = create_garage %7h% from %1d% %2d% %3d% to %4d% %5d% %6d% |  |
| 0x0225 | %2d% = player %1d% health |  |
| 0x0226 | %2d% = actor %1d% health |  |
| 0x0227 | %2d% = car %1d% health |  |
| 0x0293 | %1d% = get_controller_mode |  |
| 0x02a8 | %5d% = create_marker %4d% at %1d% %2d% %3d% |  |
| 0x02c5 | %1d% = donkey_mags_picked_up |  |
| 0x02d7 | player %1d% currentweapon == %2c% | ✓ |
| 0x02d8 | actor %1d% current_weapon == %2c% | ✓ |
| 0x02d9 | donkey_mags_picked_up = none |  |
| 0x02e1 | %5d% = create_cash_pickup %4d% at %1d% %2d% %3d% |  |
| 0x02e3 | %2d% = car %1d% speed |  |
| 0x02e8 | %1d% = cutscenetime |  |
| 0x02f6 | %2d% = sine %1d% |  |
| 0x02f7 | %2d% = cosine %1d% |  |
| 0x032b | %7d% = create_weapon_pickup %1o% type %2d% ammo %3d% at %4d% %5d% %6d% |  |
| 0x0376 | %4d% = create_random_actor %1d% %2d% %3d% |  |
| 0x0396 | pause_timer %1d% |  |
| 0x03c1 | %2d% = player %1d% car_no_save |  |
| 0x03c6 | current_island == %1d% | ✓ |
| 0x03dc | %2d% = create_marker_above_pickup %1d% |  |
| 0x03e1 | %1d% = packages_found |  |
| 0x0425 | %2d% = meters_to_feet %1d% |  |
| 0x042d | %2d% = round(meters_to_feet(%1d%)) |  |

**未实现**

| Opcode | Brief | 条件 |
|---|---|---|
| 0x0078 | %1d% += frame_delta_time * %2d% |  |
| 0x0079 | %1d% += frame_delta_time * %2d% |  |
| 0x007a | %1d% += frame_delta_time * %2d% |  |
| 0x007b | %1d% += frame_delta_time * %2d% |  |
| 0x007c | %1d% += frame_delta_time * %2d% |  |
| 0x007d | %1d% += frame_delta_time * %2d% |  |
| 0x007e | %1d% -= frame_delta_time * %2d% |  |
| 0x007f | %1d% -= frame_delta_time * %2d% |  |
| 0x0080 | %1d% -= frame_delta_time * %2d% |  |
| 0x0081 | %1d% -= frame_delta_time * %2d% |  |
| 0x0082 | %1d% -= frame_delta_time * %2d% |  |
| 0x0083 | %1d% -= frame_delta_time * %2d% |  |
| 0x00a8 | car_wander_randomly %1d% |  |
| 0x00e2 | %3d% = get_pad_state %1d% button %2d% |  |
| 0x010f | player %1d% wanted_level > %2d% | ✓ |
| 0x0129 | %4d% = create_actor %2d% %3o% in_car %1d% driverseat |  |
| 0x01c0 | %2d% = player %1d% wanted_level |  |
| 0x0228 | car %1d% bomb_status == %2d% | ✓ |
| 0x02c8 | %1d% = platinum_pieces_in_car |  |
| 0x02cf | %4d% = create_fire_at %1d% %2d% %3d% |  |
| 0x02dd | get_random_actor %2d% in_zone %1s% |  |
| 0x02f2 | actor %1d% model == %2h% | ✓ |
| 0x0327 | %6d% = get_random_car_of_type %5d% in_area %1d% %2d% to %3d% %4d% |  |
| 0x0349 | text_draw_style = %1d% |  |
| 0x0397 | car %1d% siren = %2b:on/off% |  |
| 0x03c0 | %2d% = actor %1d% car |  |
| 0x03c5 | create_random_car_for_carpark %1d% %2d% %3d% %4d% |  |
| 0x03cc | car %1d% add_to_stuck_car_check %2d% = %3d% |  |
| 0x03df | all_random_peds %1o% |  |
| 0x0432 | %3d% = get_passenger_in_car %1d% seat %2h% |  |
| 0x0441 | %2d% = car %1d% model |  |


### 摄像机  (实现 11 / 未实现 14)

**已实现**

| Opcode | Brief | 条件 |
|---|---|---|
| 0x0157 | camera_on_player %1d% mode %2d% switchstyle %3d% |  |
| 0x0158 | camera_on_vehicle %1d% mode %2d% switchstyle %3d% |  |
| 0x0159 | camera_on_ped %1d% mode %2d% switchstyle %3d% |  |
| 0x015a | restore_camera |  |
| 0x015f | set_camera_position %1d% %2d% %3d% rotation %4d% %5d% %6d% |  |
| 0x0160 | point_camera %1d% %2d% %3d% switchstyle %4d% |  |
| 0x01be | set_actor %1d% to_look_at_spot %2d% %3d% %4d% |  |
| 0x020e | actor %1d% look_at_actor %2d% |  |
| 0x020f | actor %1d% look_at_player %2d% |  |
| 0x0210 | player %1d% look_at_actor %2d% |  |
| 0x041d | set_camera_near_clip %1d% |  |

**未实现**

| Opcode | Brief | 条件 |
|---|---|---|
| 0x0003 | shake_cam %1d% |  |
| 0x0136 | shake_cam_with_point %1d% xyz %2% %3% %4% |  |
| 0x022c | set_actor %1d% to_look_at_actor %2d% |  |
| 0x022d | set_actor %1d% to_look_at_player %2d% |  |
| 0x022e | set_player %1d% to_look_at_actor %2d% |  |
| 0x032a | set_behind_camera_mode_to %1h% |  |
| 0x0373 | set_camera_directly_behind_player |  |
| 0x0374 | set_motion_blur %1d% |  |
| 0x03c8 | set_camera_directly_before_player |  |
| 0x03da | set_garage %1d% camera_follows_player |  |
| 0x03ea | generate_cars_around_camera %1d% |  |
| 0x0452 | enable_player_control_camera |  |
| 0x0454 | store_debug_camera_position_to %1d% %2d% %3d% |  |
| 0x0463 | get_debug_camera_point_at %1d% %2d% %3d% |  |


### 过场动画  (实现 7 / 未实现 3)

**已实现**

| Opcode | Brief | 条件 |
|---|---|---|
| 0x0244 | set_cutscene_pos %1d% %2d% %3d% |  |
| 0x02e4 | load_cutscene_data %1s% |  |
| 0x02e6 | set_cutscene_anim %1d% %2s% |  |
| 0x02e7 | start_cutscene |  |
| 0x02e9 | cutscene_reached_end | ✓ |
| 0x02ea | end_cutscene |  |
| 0x02f4 | create_cutscene_actor %3d% from_head %2o% and_body %1d% |  |

**未实现**

| Opcode | Brief | 条件 |
|---|---|---|
| 0x03b7 | process_cut_scene_only %1b:false/true% |  |
| 0x043f | play_cutscene_music |  |
| 0x0440 | stop_cutscene_music |  |


### 角色与AI行为  (实现 83 / 未实现 104)

**已实现**

| Opcode | Brief | 条件 |
|---|---|---|
| 0x0054 | get_player_coordinates %1d% store_to %2d% %3d% %4d% |  |
| 0x0055 | set_player_coordinates %1d% to %2d% %3d% %4d% |  |
| 0x009b | delete_char %1d% |  |
| 0x00a0 | get_char_coordinates %1d% store_to %2d% %3d% %4d% |  |
| 0x00a1 | set_char_coordinates %1d% to %2d% %3d% %4d% |  |
| 0x00a2 | is_char_still_alive %1d% | ✓ |
| 0x00db | is_char_in_car %1d% car %2d% | ✓ |
| 0x00dc | is_player_in_car %1d% car %2d% | ✓ |
| 0x00dd | is_char_in_model %1d% model %2o% | ✓ |
| 0x00de | is_player_in_model %1d% model %2t% | ✓ |
| 0x00df | is_char_in_any_car %1d% | ✓ |
| 0x00e0 | is_player_in_any_car %1d% | ✓ |
| 0x00f4 | actor %1d% near_actor_in_car %2d% radius %3d% %4d% %5h% | ✓ |
| 0x0106 | actor %1d% near_actor_in_car %2d% radius %3d% %4d% %5d% %6h% | ✓ |
| 0x0111 | set_wasted_busted_check_to %1benabled/disabled% |  |
| 0x0113 | add_ammo_to_player %1d% weapon %2h% to %3d% |  |
| 0x0117 | player %1d% wasted | ✓ |
| 0x0118 | actor %1d% dead | ✓ |
| 0x0121 | player %1d% in_zone %2z% | ✓ |
| 0x0126 | actor %1d% walking | ✓ |
| 0x012a | put_player %1d% at %2d% %3d% %4d% and_remove_from_car |  |
| 0x0154 | actor %1d% in_zone %2z% | ✓ |
| 0x016c | restart_if_wasted at %1d% %2d% %3d% heading %4d% |  |
| 0x016d | restart_if_busted at %1d% %2d% %3d% heading %4d% |  |
| 0x0171 | set_player %1d% z_angle_to %2d% |  |
| 0x0173 | set_actor %1d% z_angle_to %2d% |  |
| 0x017a | set_player %1d% weapon %2d% ammo_to %3d% |  |
| 0x01b1 | give_player %1d% weapon %2c% ammo %3d% |  |
| 0x01b2 | give_actor %1d% weapon %2c% ammo %3d% |  |
| 0x01b4 | set_player %1d% controllable %2btrue/false% |  |
| 0x01b8 | set_player %1d% armed_weapon_to %2c% |  |
| 0x01b9 | set_actor %1d% armed_weapon_to %2c% |  |
| 0x01c1 | car %1d% stopped | ✓ |
| 0x01c2 | remove_references_to_actor %1d% |  |
| 0x01d3 | actor %1d% leave_car %2d% |  |
| 0x01d4 | actor %1d% go_to_car %2d% and_enter_it_as_a_passenger |  |
| 0x01d5 | actor %1d% go_to_and_drive_car %2d% |  |
| 0x01df | tie_actor %1d% to_player %2d% |  |
| 0x01f4 | car %1d% flipped | ✓ |
| 0x01fc | player %1d% near_car %2d% radius %3d% %4d% unknown %5d% | ✓ |
| 0x01fd | player %1d% near_car_on_foot %2d% radius %3d% %4d% unknown %5d% | ✓ |
| 0x01fe | player %1d% near_car_in_car %2d% radius %3d% %4d% unknown %5d% | ✓ |
| 0x0203 | actor %1d% near_car_on_foot %2d% radius %3d% %4d% unknown %5d% | ✓ |
| 0x0204 | actor %1d% near_car_in_car %2d% radius %3d% %4d% unknown %5d% | ✓ |
| 0x0211 | actor %1d% walk_to %2d% %3d% |  |
| 0x0222 | set_player %1d% health_to %2d% |  |
| 0x0223 | set_actor %1d% health_to %2d% |  |
| 0x0224 | set_car %1d% health_to %2d% |  |
| 0x022a | switch_ped_roads_on %1d% %2d% %3d% to %4d% %5d% %6d% |  |
| 0x022b | switch_ped_roads_off %1d% %2d% %3d% to %4d% %5d% %6d% |  |
| 0x0239 | actor %1d% run_to %2d% %3d% |  |
| 0x023c | load_special_actor %2d% as %1d% |  |
| 0x023d | special_actor %1d% loaded | ✓ |
| 0x0256 | is_player %1d% defined | ✓ |
| 0x029f | player %1d% stopped | ✓ |
| 0x02a0 | actor %1d% stopped | ✓ |
| 0x02c0 | set %4d% %5d% %6d% to_ped_path_coords_closest_to %1d% %2d% %3d% |  |
| 0x02de | player %1d% driving_taxi_vehicle | ✓ |
| 0x02f5 | set_head_anim %1d% %2s% |  |
| 0x0319 | set_actor %1d% running %2b:true/false% |  |
| 0x0320 | actor %1d% in_range_of_player %2d% | ✓ |
| 0x0321 | kill_actor %1d% |  |
| 0x0322 | kill_player %1d% |  |
| 0x0324 | set_zone_pedgroup_info %1z% %2b:day/night% %3u% |  |
| 0x0336 | set_player %1d% visible %2d% |  |
| 0x0337 | set_actor %1d% visible %2h% |  |
| 0x0352 | set_actor %1d% skin_to %2s% |  |
| 0x035e | set_player %1d% armour_to %2d% |  |
| 0x035f | set_actor %1d% armour_to %2d% |  |
| 0x0362 | remove_actor %1d% from_car_and_place_at %2d% %3d% %4d% |  |
| 0x0369 | put_player %1d% in_car %2d% |  |
| 0x036a | put_actor %1d% in_car %2d% |  |
| 0x03b8 | clear_weapons_from_player %1d% |  |
| 0x03ef | player %1d% make_safe |  |
| 0x0402 | increment_criminals_stopped |  |
| 0x0414 | toggle_player %1d% free_treatment_once %2d% |  |
| 0x0419 | get_ammo_of_player %1d% weapon %2c% store_to %3d% |  |
| 0x0442 | player %1d% in_car %2d% | ✓ |
| 0x0443 | player %1d% in_a_car | ✓ |
| 0x0448 | actor %1d% in_car %2d% | ✓ |
| 0x0449 | actor %1d% in_a_car | ✓ |
| 0x044a | player %1d% on_foot | ✓ |
| 0x044b | is_char_on_foot %1d% | ✓ |

**未实现**

| Opcode | Brief | 条件 |
|---|---|---|
| 0x009c | char_wander_dir %1d% to %2d% |  |
| 0x009d | char_wander_range |  |
| 0x009e | char_follow_path %1d% path %2d% %3d% %4d% |  |
| 0x009f | char_set_idle %1d% |  |
| 0x00a9 | car_set_idle %1d% |  |
| 0x010c | change_player_into_rc_buggy %1d% at %2d% %3d% %4d% %5d% |  |
| 0x010d | set_player %1d% wanted_level_to %2d% |  |
| 0x010e | set_player %1d% minimum_wanted_level_to %2d% |  |
| 0x0110 | clear_player %1d% wanted_level |  |

| 0x0114 | set_actor %1d% car_weapon %2h% ammo_to %3d% |  |
| 0x011a | set_actor %1d% search_threat %2i% |  |
| 0x011c | actor %1d% clear_objective |  |
| 0x0122 | player %1d% pressing_horn | ✓ |
| 0x0123 | actor %1d% spotted_player %2d% | ✓ |
| 0x0130 | player %1d% busted | ✓ |
| 0x014d | text_pager %1g% time_per_char %2d% ms unknown_flags %3d% %4d% |  |
| 0x0156 | set_zone_ped_density %1z% %2b:day/night% %3d% |  |
| 0x017b | set_actor %1d% weapon %2d% ammo_to %3d% |  |
| 0x018f | car %1d% flipped_for_2_seconds | ✓ |
| 0x0190 | add_car %1d% to_flipped_check |  |
| 0x0191 | remove_car %1d% from_flipped_check |  |
| 0x0192 | set_actor %1d% objective_to_stand_still |  |
| 0x0193 | set_actor %1d% objective_to_act_like_ped |  |
| 0x0194 | set_actor %1d% objective_to_guard_point %2d% %3d% %4d% |  |
| 0x0195 | set_actor %1d% objective3 %2d% %3d% %4d% %5d% |  |
| 0x0196 | actor %1d% objective5 |  |
| 0x01c9 | actor %1d% kill_actor %2d% |  |
| 0x01ca | actor %1d% kill_player %2d% |  |
| 0x01cb | actor %1d% kill_actor %2d% |  |
| 0x01cc | actor %1d% kill_player %2d% |  |
| 0x01ce | actor %1d% avoid_player %2d% |  |
| 0x01cf | actor %1d% avoid_char %2d% |  |
| 0x01d0 | actor %1d% avoid_player %2d% |  |
| 0x01d1 | actor %1d% follow_actor %2d% |  |
| 0x01d2 | actor %1d% follow_player %2d% |  |
| 0x01d9 | actor %1d% destroy_car %2d% |  |
| 0x01de | tie_actor %1d% to_actor %2d% |  |
| 0x01e1 | set_actor %1d% follow_route %2d% behaviour %3d% |  |
| 0x01ed | clear_actor %1d% threat_search |  |
| 0x01f7 | set_player %1d% ignored_by_cops_state_to %2b:true/false% |  |
| 0x01ff | player %1d% near_car %2d% radius %3d% %4d% %5d% unknown %6h% | ✓ |
| 0x0200 | player %1d% near_car_on_foot %2d% radius %3d% %4d% %5d% unknown %6h% | ✓ |
| 0x0201 | player %1d% near_car_in_car %2d% radius %3d% %4d% %5d% unknown %6h% | ✓ |
| 0x0205 | actor %1d% near_car %2d% radius %3d% %4d% %5d% unknown %6h% | ✓ |
| 0x0206 | actor %1d% near_car_on_foot %2d% radius %3d% %4d% %5d% unknown %6h% | ✓ |
| 0x0207 | actor %1d% near_car_in_car %2d% radius %3d% %4d% %5d% unknown %6h% | ✓ |
| 0x0221 | set_player %1d% apply_brakes_to_car %2d% |  |
| 0x022f | set_actor %1d% stop_looking |  |
| 0x0230 | set_player %1d% stop_looking |  |
| 0x0241 | player %1d% in_remote_mode | ✓ |
| 0x0243 | set_actor %1d% ped_stats_to %2d% |  |
| 0x0245 | set_actor %1d% walk_style_to %2d% |  |
| 0x0291 | set_actor %1d% attack_when_provoked %2d% |  |
| 0x0296 | unload_special_actor %1d% |  |
| 0x02a9 | set_char_only_damaged_by_player %1d% to %2d% |  |
| 0x02aa | set_car %1d% immune_to_nonplayer %2d% |  |
| 0x02ab | set_actor %1d% immunities BP %2d% FP %3d% EP %4d% CP %5d% MP %6d% |  |
| 0x02bc | set_cop_behaviour %1b:kill/arrest% |  |
| 0x02cb | is_actor_on_screen %1d% | ✓ |
| 0x02d5 | player %1d% firing_weapons_in_rectangle %2d% %3d% %4d% %5d% %6d% | ✓ |
| 0x02df | player %1d% agressive |  |
| 0x02e0 | actor %1d% firing_weapon | ✓ |
| 0x02e2 | set_actor %1d% weapon_accuracy_to %2d% |  |
| 0x031d | actor %1d% hit_by_weapon %2d% | ✓ |
| 0x031f | unknown_actor %1d% unknown_actor %2d% | ✓ |

| 0x0326 | set_actor_on_fire %1d% fire store_to %2d% |  |
| 0x0330 | set_player %1d% infinite_run_to %2b:true/false% |  |
| 0x0331 | set_player %1d% fast_reload %2h% |  |
| 0x0332 | set_actor %1d% bleeding_to %2b:true/false% |  |
| 0x0342 | set_text_draw_centered %1d% |  |
| 0x0344 | set_text_draw_linewidth %1d% for_centered_text |  |
| 0x0350 | set_actor %1d% maintain_position_when_attacked %2d% |  |
| 0x0353 | refresh_actor %1d% |  |
| 0x0365 | set_actor %1d% objective_hail_taxi |  |
| 0x0377 | set_actor %1d% steal_any_car |  |
| 0x037f | give_player_detonator |  |
| 0x0383 | player %1d% car_horn_activated | ✓ |
| 0x0398 | remove_forbidden_for_peds_angled_cube %1d% %2d% %3d% to %4d% %5d% %6d% angle %7d% |  |
| 0x0399 | create_forbidden_for_peds_angled_cube %1d% %2d% %3d% to %4d% %5d% %6d% angle %7d% |  |
| 0x039e | set_char_cant_be_dragged_out %1d% to %2d% |  |
| 0x03a3 | is_char_male %1d% | ✓ |
| 0x03bf | set_player %1d% ignored_by_everyone_to %2b:true/false% |  |
| 0x03de | set_ped_density_multiplier %1d% |  |
| 0x03ee | player %1d% controllable | ✓ |
| 0x03f1 | pedtype %1e% add_threat %2e% |  |
| 0x03f2 | pedgroup %1e% remove_threat %2e% |  |
| 0x03f8 | get_body_cast_health %1d% |  |
| 0x03f9 | make_actors %1d% %2d% converse_in %3d% ms |  |
| 0x03fc | set_actor %1d% stays_on_current_island %2d% |  |
| 0x0411 | set_actor %1d% use_pednode_seek %2d:true/false% |  |

| 0x041a | get_ammo_of_actor %1d% weapon %2c% store_to %3d% |  |
| 0x041c | make_actor %1d% say %2d% |  |
| 0x0427 | create_save_peds_between_levels_cube %1d% %2d% %3d% to %4d% %5d% %6d% |  |
| 0x0428 | set_car %1d% avoid_level_transitions %2d% |  |
| 0x042a | ped_threat_exists %1u% %2u% | ✓ |
| 0x042b | clear_peds_from_cube %1d% %2d% %3d% %4d% %5d% %6d% |  |
| 0x0433 | set_actor %1d% criminal_flag %2h% |  |
| 0x0438 | set_actor %1d% ignore_level_transitions %2d% |  |
| 0x043a | start_boat_foam_animation |  |
| 0x043b | update_boat %1d% foam_animation |  |
| 0x0446 | set_actor %1d% dismemberment_possible %2d% |  |
| 0x0450 | car %1d% warp_to_player |  |
| 0x0456 | is_player_targeting_any_char %1d% | ✓ |
| 0x0457 | is_player_targeting_char %1d% %2d% | ✓ |


### 车辆  (实现 26 / 未实现 53)

**已实现**

| Opcode | Brief | 条件 |
|---|---|---|
| 0x00a6 | delete_car %1d% |  |
| 0x00aa | get_car_coordinates %1d% store_to %2d% %3d% %4d% |  |
| 0x00ab | set_car_coordinates %1d% to %2d% %3d% %4d% |  |
| 0x00ac | is_car_still_alive %1d% | ✓ |
| 0x0119 | car %1d% wrecked | ✓ |
| 0x014c | set_parked_car_generator %1d% cars_to_generate_to %2d% |  |
| 0x0152 | set_zone_car_info %1s% %2bday/night% %3h% %4h% %5h% %6h% %7h% %8h% %9h% %10h% %11h% %12h% %13h% %14h% %15h% %16h% %17h% |  |
| 0x0175 | set_car %1d% z_angle_to %2d% |  |
| 0x01c3 | remove_references_to_car %1d% |  |
| 0x020b | explode_car %1d% |  |
| 0x020d | car %1d% is_upright | ✓ |
| 0x021b | set_garage %1d% to_accept_car %2d% |  |
| 0x021c | car_inside_garage %1d% | ✓ |
| 0x0229 | set_car %1d% color_to %2d% %3d% |  |
| 0x029c | is_boat %1d% | ✓ |
| 0x02bf | car %1d% sunk | ✓ |
| 0x02c1 | set %4d% %5d% %6d% to_car_path_coords_closest_to %1d% %2d% %3d% |  |
| 0x0315 | increment_taxi_dropoffs |  |
| 0x0316 | save_taxi_earnings_from %1d% |  |
| 0x039f | turn_car %1d% to_face %2d% %3d% |  |
| 0x03b1 | garage %1d% door_closed | ✓ |
| 0x03bb | set_garage %1d% door_type_to_swing_open |  |
| 0x03d4 | garage %1d% contains_neededcar %2d% | ✓ |
| 0x040a | remove_car_from_chase %1d% |  |
| 0x0422 | garage_contain_car %1d% %2d% | ✓ |
| 0x0431 | car %1d% passenger_seat_free %2d% | ✓ |

**未实现**

| Opcode | Brief | 条件 |
|---|---|---|
| 0x00ad | set_car_cruise_speed %1d% to %2d% |  |
| 0x00ae | set_car_driving_style %1d% to %2d% |  |
| 0x0135 | set_car %1d% door_lock %2d% |  |
| 0x015e | car %1d% wheels_on_ground | ✓ |
| 0x01eb | set_car_density_to %1d% |  |
| 0x01ec | make_car %1d% very_heavy %2h% |  |
| 0x01f3 | car %1d% airborne | ✓ |
| 0x020a | set_car %1d% door_status_to %2d% |  |

| 0x0216 | set_car %1d% taxi_available_light_to %2b:on/off% |  |
| 0x0220 | car %d has_car_bomb | ✓ |
| 0x0231 | script_heli %1bon/off% |  |
| 0x0236 | set_gang %1d% car_to %2o% |  |
| 0x0242 | set_car %1d% bomb_status_to %2d% |  |
| 0x0294 | set_car %1d% resprayable_to %2benabled/disabled% |  |
| 0x02ac | set_car %1d% immunities %2d% %3d% %4d% %5d% %6d% |  |
| 0x02c2 | car %1d% drive_to_point %2d% %3d% %4d% |  |
| 0x02c9 | remove_platinum_from_car |  |
| 0x02ca | is_car_on_screen %1d% | ✓ |
| 0x02d3 | boat %1d% drive_to %2d% %3d% %4d% |  |
| 0x02d4 | boat_stop %1d% |  |
| 0x02db | set_boat %1d% speed_to %2d% |  |
| 0x02f8 | get_car %1d% Z_angle_sine_to %2d% |  |
| 0x02f9 | get_car %1d% Z_angle_cosine_to %2d% |  |
| 0x031e | vehicle %1d% hit_by_weapon %2h% | ✓ |
| 0x0323 | enable_boat %1d% anchor %2d% |  |
| 0x0325 | set_car_on_fire %1d% store_to %2d% |  |
| 0x032c | car %1d% ram %2d% |  |
| 0x032d | car %1d% block %2d% |  |
| 0x038a | car_in_cube %1d% %2d% %3d% to %4d% %5d% %6d% | ✓ |
| 0x039a | remove_forbidden_for_cars_angled_cube %1d% %2d% %3d% to %4d% %5d% %6d% angle %7d% |  |
| 0x039b | create_forbidden_for_cars_angled_cube %1d% %2d% %3d% to %4d% %5d% %6d% angle %7d% |  |
| 0x039c | set_car %1d% watertight %2h% |  |
| 0x03a2 | set_car_status %1d% to %2h% |  |
| 0x03a6 | get_drug_plane_coords %1d% %2d% %3d% |  |
| 0x03ab | set_car %1d% strong %2d% |  |
| 0x03b0 | garage %1d% door_open | ✓ |
| 0x03ba | clear_cars_from_cube %1d% %2d% %3d% to %4d% %5d% %6d% |  |
| 0x03c9 | car %1d% damaged | ✓ |
| 0x03cd | car %1d% remove_from_stuck_car_check |  |
| 0x03ce | car %1d% stuck | ✓ |
| 0x03d3 | get_closest_car_node_at %1d% %2d% %3d% store_to %4d% %5d% %6d% heading %7d% |  |
| 0x03ed | set_car %1d% not_damaged_when_upside_down %2h% |  |
| 0x03f3 | get_car %1d% color %2d% %3d% |  |
| 0x03f4 | set_all_cars_can_be_damaged %1b:true/false% |  |
| 0x03f5 | set_car %1d% can_be_damaged %1b:true/false% |  |
| 0x03fb | set_car %1d% stays_on_current_island %2d% |  |
| 0x0409 | blow_up_rc_buggy |  |
| 0x0423 | car %1d% improve_handling %2d% |  |
| 0x0426 | create_save_cars_between_levels_cube %1d% %2d% %3d% to %4d% %5d% %6d% |  |
| 0x0445 | are_any_car_cheats_activated | ✓ |
| 0x044e | car %1d% level %2b:set_from_position/clear% |  |
| 0x044f | make_craigs_car_a_bit_stronger %1d% %2d% |  |
| 0x0477 | set_car_temp_action %1d% to %2h% time %3d% |  |


### 拾取物与武器  (实现 4 / 未实现 1)

**已实现**

| Opcode | Brief | 条件 |
|---|---|---|
| 0x0214 | pickup %1d% picked_up | ✓ |
| 0x0215 | destroy_pickup %1d% |  |
| 0x02c6 | remove_pickup_items_from_ground |  |
| 0x03dd | pickup %1d% show_on_radar %2d% %3d% |  |

**未实现**

| Opcode | Brief | 条件 |
|---|---|---|
| 0x0237 | set_gang %1d% primary_weapon_to %2c% secondary_weapon_to %3c% |  |


### 文本与UI  (实现 15 / 未实现 41)

**已实现**

| Opcode | Brief | 条件 |
|---|---|---|
| 0x00ba | print_big %1g% duration %2d% ms style %3d% |  |
| 0x00bb | print %1g% duration %2d% ms flag %3d% |  |
| 0x00bc | print_now %1g% duration %2d% ms flag %3d% |  |
| 0x00bd | print_soon %1g% duration %2d% ms flag %3d% |  |
| 0x00be | clear_prints |  |
| 0x01e3 | text_1number_styled %1g% number %2d% duration %3d% ms style %4d% |  |
| 0x02a3 | toggle_widescreen %1bon/off% |  |
| 0x033e | text_draw %1d% %2d% %3g% |  |
| 0x0340 | set_text_draw_color %1d% %2d% %3d% %4d% |  |
| 0x0346 | set_text_draw_background_color %1d% %2d% %3d% %4d% |  |
| 0x036d | text_2numbers_styled %1g% numbers %2d% %3d% duration %4d% ms style %5d% |  |
| 0x03d5 | remove_text %1g% |  |
| 0x03e5 | text_box %1g% |  |
| 0x03e6 | remove_text_box |  |
| 0x03e7 | flash_hud %1d% |  |

**未实现**

| Opcode | Brief | 条件 |
|---|---|---|
| 0x0151 | remove_status_text %1d% |  |
| 0x01e4 | text_1number_lowpriority %1g% number %2d% duration %3d% ms flag %4d% |  |
| 0x01e5 | text_1number_highpriority %1g% number %2d% duration %3d% ms flag %4d% |  |
| 0x0217 | text_big_styled %1g% duration %2d% ms style %3d% |  |
| 0x0218 | text_big_1number_styled %1g% number %2d% duration %3d% ms style %4d% |  |
| 0x02fc | text_2numbers %1g% numbers %2d% %3d% duration %4d% ms flag %5d% |  |
| 0x02fd | text_2numbers_lowpriority %1g% numbers %2d% %3d% duration %4d% ms flag %5d% |  |
| 0x02fe | text_2numbers_highpriority %1g% numbers %2d% %3d% duration %4d% ms flag %5d% |  |
| 0x02ff | text_3numbers %1g% numbers %2d% %3d% %4d% duration %5d% ms flag %6h% |  |
| 0x0300 | text_3numbers_highpriority %1g% numbers %2d% %3d% %4d% duration %5d% ms flag %6h% |  |
| 0x0301 | text_3numbers_lowpriority %1g% numbers %2d% %3d% %4d% duration %5d% ms flag %6h% |  |
| 0x0302 | text_4numbers %1g% numbers %2d% %3d% %4d% %5d% duration %6d% ms flag %7d% |  |
| 0x0303 | text_4numbers_highpriority %1g% numbers %2d% %3d% %4d% %5d% duration %6d% ms flag %7d% |  |
| 0x0304 | text_4numbers_lowpriority %1g% numbers %2d% %3d% %4d% %5d% duration %6d% ms flag %7d% |  |
| 0x0305 | text_5numbers %1g% numbers %2d% %3d% %4d% %5d% %6d% duration %7d% ms flag %8d% |  |
| 0x0306 | text_5numbers_highpriority %1g% numbers %2d% %3d% %4d% %5d% %6d% duration %7d% ms flag %8d% |  |
| 0x0307 | text_5numbers_lowpriority %1g% numbers %2d% %3d% %4d% %5d% %6d% duration %7d% ms flag %8d% |  |
| 0x0308 | text_6numbers %1g% numbers %2d% %3d% %4d% %5d% %6d% %7d% duration %8d% ms flag %9d% |  |
| 0x0309 | text_6numbers_highpriority %1g% numbers %2d% %3d% %4d% %5d% %6d% %7d% duration %8d% ms flag %9d% |  |
| 0x030a | text_6numbers_lowpriority %1g% numbers %2d% %3d% %4d% %5d% %6d% %7d% duration %8d% ms flag %9d% |  |
| 0x033f | set_text_draw_letter_width_height %1d% %2d% |  |
| 0x0341 | set_text_draw_align_justify %1d% |  |
| 0x0343 | set_text_linewidth %1d% |  |
| 0x0345 | enable_text_draw_background %1d% |  |
| 0x0348 | enable_text_draw_proportional %1d% |  |
| 0x036e | text_3numbers_styled %1g% numbers %2d% %3d% %4d% duration %5d% ms style %6d% |  |
| 0x036f | text_4numbers_styled %1g% numbers %2d% %3d% %4d% %5d% duration %6d% ms flag %7d% |  |
| 0x0370 | text_5numbers_styled %1g% numbers %2d% %3d% %4d% %5d% %6d% duration %7d% ms flag %8d% |  |
| 0x0371 | text_6numbers_styled %1g% numbers %2d% %3d% %4d% %5d% %6d% %7d% duration %8d% ms flag %9d% |  |
| 0x0375 | text_1string %1g% %2g% duration %3d% ms flag %4d% |  |
| 0x0384 | text_1string %1g% string %2g% duration %3d% ms flag %4d% |  |
| 0x0385 | text_1string_lowpriority %1g% string %2g% duration %3d% ms flag %4d% |  |
| 0x038d | draw_texture %1h% position %2d% %3d% size %4d% %5d% RGBA %6d% %7d% %8d% %9d% |  |
| 0x038f | load_texture %2h% as %1d% |  |
| 0x0391 | release_textures |  |
| 0x03c4 | set_status_text_to %1d% %2b:bar/number% %3g% |  |
| 0x03d6 | remove_styled_text %1g% |  |
| 0x03e4 | set_text_draw_align_right %1h% |  |
| 0x03eb | clear_small_messages_only |  |
| 0x03f0 | enable_text_draw %1d% |  |
| 0x045b | text_draw_2numbers %3g% numbers %4d% %5d% at %1d% %2d% |  |


### 环境天气时间  (实现 5 / 未实现 3)

**已实现**

| Opcode | Brief | 条件 |
|---|---|---|
| 0x00bf | get_time_of_day %1d% %2d% |  |
| 0x00c0 | set_current_time %1d% %2d% |  |
| 0x01b5 | force_weather %1d% |  |
| 0x01b6 | set_weather %1d% |  |
| 0x01b7 | release_weather |  |

**未实现**

| Opcode | Brief | 条件 |
|---|---|---|
| 0x0253 | save_current_time |  |
| 0x0254 | restore_time_of_day |  |
| 0x0421 | force_rain %1d% |  |


### 区域与车库  (实现 10 / 未实现 3)

**已实现**

| Opcode | Brief | 条件 |
|---|---|---|
| 0x015c | set_zone_gang_info %1s% %2bday/night% %3h% %4h% %5h% %6h% %7h% %8h% %9h% %10h% %11h% |  |
| 0x0299 | activate_garage %1d% |  |
| 0x02b9 | deactivate_garage %1d% |  |
| 0x02fa | garage %1d% change_to_type %2d% |  |
| 0x0329 | garage %1d% respray_done | ✓ |
| 0x0360 | open_garage %1d% |  |
| 0x0361 | close_garage %1d% |  |
| 0x0395 | clear_area %5d% at %1d% %2d% range %3d% %4d% |  |
| 0x03a5 | set_garage %1d% type_to %2d% %3d% |  |
| 0x03d7 | set_wav_location %1d% %2d% %3d% |  |

**未实现**

| Opcode | Brief | 条件 |
|---|---|---|
| 0x00c2 | is_point_on_screen %1d% %2d% %3d% %4d% | ✓ |
| 0x0357 | explosion_type %1d% in_zone %2z% |  |
| 0x037e | is_sniper_bullet_in_area %1d% %2d% %3d% to %4d% %5d% %6d% | ✓ |


### 地图标记 Blip  (实现 5 / 未实现 0)

**已实现**

| Opcode | Brief | 条件 |
|---|---|---|
| 0x0164 | disable_marker %1d% |  |
| 0x0165 | set_marker %1d% color_to %2d% |  |
| 0x0166 | set_marker %1d% brightness_to %2d% |  |
| 0x0168 | show_on_radar %1d% %2d% |  |
| 0x018b | show_on_radar %1d% %2d% |  |


### 音频  (实现 4 / 未实现 3)

**已实现**

| Opcode | Brief | 条件 |
|---|---|---|
| 0x018c | play_sound %4d% at %1d% %2d% %3d% |  |
| 0x018e | stop_sound %1d% |  |
| 0x03d1 | play_wav |  |
| 0x03d2 | wav_ended | ✓ |

**未实现**

| Opcode | Brief | 条件 |
|---|---|---|
| 0x041e | set_radio_station %1d% %2d% |  |
| 0x0444 | create_fire_audio %1d% %2d% |  |
| 0x0451 | load_end_of_game_audio |  |


### 特效(粒子/爆炸/火焰)  (实现 3 / 未实现 10)

**已实现**

| Opcode | Brief | 条件 |
|---|---|---|
| 0x020c | create_explosion %4d% at %1d% %2d% %3d% |  |
| 0x0404 | increment_fires_extinguished |  |
| 0x0406 | save_dodo_flight_time %1d% |  |

**未实现**

| Opcode | Brief | 条件 |
|---|---|---|
| 0x016f | create_particle %1a% %5d% %6d% %7d% %8d% %9d% %10d% at %2d% %3d% %4d% |  |

| 0x0250 | create_light_at %1d% %2d% %3d% RGB_values %4d% %5d% %6d% |  |
| 0x02a2 | create_particle %1a% %5d% at %2d% %3d% %4d% |  |
| 0x02d0 | fire %1d% extinguished | ✓ |
| 0x02d1 | remove_fire %1d% |  |
| 0x031a | remove_all_fires |  |
| 0x0356 | explosion_type %1d% in_cube %2d% %3d% %4d% to %5d% %6d% %7d% | ✓ |
| 0x039d | scatter_particles type %1a% %8d% %9d% %10d% %11d% %12d% from %2d% %3d% %4d% to %5d% %6d% %7d% |  |
| 0x03ad | set_rubbish %1b:visible/invisible% |  |
| 0x0437 | scatter_particle %1a% %8d% at %2d% %3d% %4d% to %5d% %6d% %7d% |  |


### 输入控制  (实现 1 / 未实现 2)

**已实现**

| Opcode | Brief | 条件 |
|---|---|---|
| 0x02c3 | create_donkey_mags %1d% |  |

**未实现**

| Opcode | Brief | 条件 |
|---|---|---|
| 0x00e1 | is_button_pressed %1d% button %2d% | ✓ |
| 0x0494 | get_joystick %1h% direction_offset_to %2d% %3d% %4d% %5d% |  |


### 统计与存档  (实现 12 / 未实现 9)

**已实现**

| Opcode | Brief | 条件 |
|---|---|---|
| 0x03cf | load_wav %1s% |  |
| 0x03d0 | wav_loaded | ✓ |
| 0x03e2 | save_turismo_time %1d% |  |
| 0x03fd | save_offroad_time %1d% |  |
| 0x03fe | save_offroadII_time %1d% |  |
| 0x03ff | save_offroadIII_time %1d% |  |
| 0x0400 | save_mayhem_time %1d% |  |
| 0x0401 | increment_people_saved_in_ambulance |  |
| 0x0403 | save_highest_ambulance_level %1d% |  |
| 0x0420 | override_police_station %1d% |  |
| 0x042f | save_record %1d% %2d% |  |
| 0x044d | load_splash %1x% |  |

**未实现**

| Opcode | Brief | 条件 |
|---|---|---|
| 0x0235 | set_gang %1h% models_to %2o% %3o% |  |
| 0x038b | load_all_models_now |  |
| 0x0390 | load_txd_dictionary %1h% |  |
| 0x03cb | load_scene %1d% %2d% %3d% |  |
| 0x03d8 | show_save_screen |  |
| 0x03d9 | save_done | ✓ |
| 0x03f7 | load_island_data %1d% |  |
| 0x0410 | override_gang_model %1d% %2d% |  |
| 0x042e | register_lowest_int_stat %1h% to %2d% |  |


### 其他(未归类)  (实现 6 / 未实现 11)

**已实现**

| Opcode | Brief | 条件 |
|---|---|---|
| 0x0000 | NOP |  |
| 0x0094 | abs_var_int %1d% |  |
| 0x0095 | abs_lvar_int %1d% |  |
| 0x0096 | abs_var_float %1d% |  |
| 0x0097 | abs_lvar_float %1d% |  |
| 0x03b6 | replace_model_at %1d% %2d% %3d% radius %4d% from %5o% to %6o% |  |

**未实现**

| Opcode | Brief | 条件 |
|---|---|---|
| 0x01e2 | add_route_point %1d% at %2d% %3d% %4d% |  |
| 0x0247 | request_model %1o% |  |
| 0x0248 | model %1o% available | ✓ |
| 0x0249 | release_model %1o% |  |
| 0x024f | create_corona %4d% %5d% %6d% with_color %7d% %8d% %9d% at_point %1d% %2d% %3d% |  |
| 0x02cc | is_object_on_screen %1d% | ✓ |
| 0x0366 | had_object_been_damaged %1d% | ✓ |
| 0x03a1 | unknown_clear_point %1d% %2d% %3d% radius %4d% |  |
| 0x0412 | opcode 0412 |  |
| 0x0415 | opcode 0415 |  |
| 0x0455 | opcode 0455 |  |
