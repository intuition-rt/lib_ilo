#include <stdbool.h>
#include <stdio.h>
#include <string.h>

#include "trame.h"

const trame TRAMES[] = {
  { "safety_stop", "" },

  // general
  { "handshake_ilo", "ilo" },
  { "get_robot_version", "500y" },
  { "start_firmware_upload", "500x[i:size]" },
  { "start_trame_s", "0[s:trame_s_params]" },
  { "stop_tasks", "00" },

  // sensors
  { "get_color_rgb_center", "10c" },
  { "get_color_rgb_left", "10l" },
  { "get_color_rgb_right", "10d" },
  { "get_color_clear", "11" },
  { "get_line", "12" },
  { "set_line_threshold_value", "13t[i:threshold]" },
  { "get_line_threshold_value", "14" },
  { "get_accessory_status", "15" }, // deprecated?
  { "get_sensor_distance", "20" },
  { "get_distance_front", "21" },
  { "get_distance_right", "22" },
  { "get_distance_back", "23" },
  { "get_distance_left", "24" },
  { "get_imu_info", "30" },
  { "reset_angle", "31" },
  { "get_raw_imu", "32" },
  { "get_battery_info", "40" },

  // LEDs
  { "get_led_color", "50" },
  { "set_led_color", "51r[i:red]g[i:green]b[i:blue]" },
  { "set_led_shape", "52v[s:shape]" },
  { "set_led_mode", "53[s:mode]/[i:nb_loop]" },
  { "set_led_captor", "54l[i:brightness]" },
  { "set_led_single", "55t[s:type]d[i:id]r[i:red]g[i:green]b[i:blue]" },
  { "display_word", "56w[s:word]d[i:delay]/[i:nb_loops]" },
  { "display_word_slide", "57" },
  { "get_product_id", "150" },
  { "set_animation_flag_false", "58" },

  // motors
  { "run_command_motor", "a[s:params]" },
  { "ping_motor", "60i[i:ping_status_0]s[i:ping_status_1]" },
  { "drive_single_motor_speed", "610i[i:motor_index]a[i:acc]v[i:speed]" },
  { "get_single_motor_speed", "611i[i:motor_index]" },
  { "drive_single_motor_angle", "620i[i:motor_index]a[i:acc]v[i:vel]p[i:position]" },
  { "get_single_motor_angle", "621i[:motor_index]" },
  { "get_single_motor_temp", "63i[i:motor_index]" },
  { "get_single_motor_volt", "64i[i:motor_index]" },
  { "get_single_motor_load", "65i[i:motor_index]" },
  { "get_single_motor_current", "66i[i:motor_index]" },
  { "get_single_motor_move", "67i[i:motor_index]" },
  { "set_motors_ilo_acc", "680a[i:acc]" },
  { "get_motors_ilo_acc", "681" },
  { "set_tempo_pos", "690t[i:tempo_pos]" },
  { "get_tempo_pos", "691" },
  { "set_pid", "70p[i:Kp]i[i:Ki]d[i:Kd]" },
  { "get_pid", "71" },

  // others
  { "check_auto_mode", "80[i:current_auto_mode]"},

  // WiFi/ble/com
  { "set_wifi_credentials", "90[s:ssid]{|||}[s:password]" },
  { "get_wifi_credentials", "92" },
  { "get_hostname", "93" },
  { "get_hostname_legacy", "930" },
  { "set_name", "94n[s:name]" },
  { "set_server_status", "95s[i:status]" },
  { "get_server_status", "96" },

  // accessory
  { "get_accessory_data", "100" },
  { "get_accessory_info", "101" },
  { "very_very_usefull", "102" },

  // others
  { "set_debug_state", "103s[i:state]" },
  { "start_diag", "110" },
  { "get_manufacturing_date", "120" },
  { "set_manufacturing_date", "121s[s:date]" },
  { "get_first_use_date", "130" },
  { "set_first_use_date", "131s[s:date]" },
  { "get_product_version", "140" },
  { "set_product_version", "141s[s:version]" },
  { "get_product_id", "150" },
  { "set_product_id", "151s[s:product_id]" },
  { "get_review_date", "160" },
  { "set_review_date", "161s[s:date]" },
  { "set_auto_setup", "170a[i:auto_setup]" },
};

const size_t TRAME_COUNT = countof(TRAMES);

char *exposed_build_trame(char const *name, uint nb_params, trame_param *params)
{
    static char buffer[512] = { 0 };
    const trame *builder = NULL;

    char const *argname;
    char argtype;

    char *p = buffer + 1;
    char arg_cmp_buff[128];
    uint c = 0;

    memset(buffer, '\0', sizeof buffer);
    buffer[0] = TRAME_CHAR_START;

    for (unsigned int i = 0; i < countof(TRAMES); i++) {
        if (!strcmp(name, TRAMES[i].name)) {
            builder = TRAMES + i;
            goto found;
        }
    }
    return NULL;
found:
    for (char const *fmt = builder->format; *fmt != '\0';) {
        if (*fmt != TRAME_BUILDER_CHAR_PARAM_START) {
            *p++ = *fmt++;
            continue;
        }

        argtype = *++fmt;
        if (argtype == '\0' || *++fmt != TRAME_BUILDER_CHAR_PARAM_SEP)
            /* something is off */
            continue;

        argname = ++fmt;
        for (c = 0; *fmt++ != TRAME_BUILDER_CHAR_PARAM_END; c++);

        memcpy(arg_cmp_buff, argname, c);
        arg_cmp_buff[c] = '\0';

        for (unsigned int j = 0; j < nb_params; j++) {
            if (!strcmp(arg_cmp_buff, params[j].name)) {
                memcpy(p, params[j].value, strlen(params[j].value));
                p += strlen(params[j].value);
            }
        }
    }

    *p++ = TRAME_CHAR_END;
    return buffer;
}
