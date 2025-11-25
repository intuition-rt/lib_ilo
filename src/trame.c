#include <stdbool.h>
#include <string.h>

#include "trame.h"

const trame TRAMES[] = {
  { "safety_stop", "" },

  { "run_command_motor", "a[params]" },

  // general
  { "handshake_ilo", "ilo" },
  { "get_robot_version", "500y" },
  { "start_firmware_upload", "500x[size]" },
  { "start_trame_s", "0[trame_s_params]" },
  { "stop_tasks", "00" },

  // sensors
  { "get_color_rgb_center", "10c" },
  { "get_color_rgb_left", "10l" },
  { "get_color_rgb_right", "10d" },
  { "get_color_clear", "11" },
  { "get_line", "12" },
  { "set_line_threshold_value", "13t[threshold]" },
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
  { "set_led_color", "51r[red]g[green]b[blue]" },
  { "set_led_shape", "52v[shape]" },
  { "set_led_mode", "53[mode]/[nb_loop]" },
  { "set_led_captor", "54l[brightness]" },
  { "set_led_single", "55t[type]d[id]r[red]g[green]b[blue]" },
  { "display_word", "56w[word]d[delay]/[nb_loops]" },
  { "display_word_slide", "57" },
  { "get_product_id", "150" },
  { "set_animation_flag_false", "58" },

  // motors
  { "ping_motor", "60i[ping_status_0]s[ping_status_1]" },
  { "drive_single_motor_speed", "610i[motor_index]a[acc]v[speed]" },
  { "get_single_motor_speed", "611i[motor_index]" },
  { "drive_single_motor_angle", "620i[motor_index]a[acc]v[vel]p[position]" },
  { "get_single_motor_angle", "621i[motor_index]" },
  { "get_single_motor_temp", "63i[motor_index]" },
  { "get_single_motor_volt", "64i[motor_index]" },
  { "get_single_motor_load", "65i[motor_index]" },
  { "get_single_motor_current", "66i[motor_index]" },
  { "get_single_motor_move", "67i[motor_index]" },
  { "set_motors_ilo_acc", "680a[acc]" },
  { "get_motors_ilo_acc", "681" },
  { "set_tempo_pos", "690t[tempo_pos]" },
  { "get_tempo_pos", "691" },
  { "set_pid", "70p[Kp]i[Ki]d[Kd]" },
  { "get_pid", "71" },

  // others
  { "check_auto_mode", "80[current_auto_mode]"},

  // WiFi/ble/com
  { "set_wifi_credentials", "90[ssid]{|||}[password]" },
  { "get_wifi_credentials", "92" },
  { "get_hostname", "93" },
  { "get_hostname_legacy", "930" },
  { "set_name", "94n[name]" },
  { "set_server_status", "95s[status]" },
  { "get_server_status", "96" },

  // accessory
  { "get_accessory_data", "100" },
  { "get_accessory_info", "101" },
  { "very_very_usefull", "102" },

  // others
  { "set_debug_state", "103s[state]" },
  { "start_diag", "110" },
  { "get_manufacturing_date", "120" },
  { "set_manufacturing_date", "121s[date]" },
  { "get_first_use_date", "130" },
  { "set_first_use_date", "131s[date]" },
  { "get_product_version", "140" },
  { "set_product_version", "141s[version]" },
  { "get_product_id", "150" },
  { "set_product_id", "151s[product_id]" },
  { "get_review_date", "160" },
  { "set_review_date", "161s[date]" },
  { "set_auto_setup", "170a[auto_setup]" },
};

char *exposed_build_trame(char const *name, uint nb_params, trame_param *params)
{
    static char buffer[512] = { 0 };
    const trame *builder = NULL;
    char const *argname;
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
