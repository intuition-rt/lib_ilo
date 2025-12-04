// Auto-generated primitives for ilo communication
// This file is generated. Do not edit manually.

#include <string>
#include <sstream>


/**
 * Primitive for safety_stop
 */
inline std::string safety_stop() {
    std::ostringstream oss;
        oss << "";
    return oss.str();
}

/**
 * Primitive for handshake_ilo
 */
inline std::string handshake_ilo() {
    std::ostringstream oss;
        oss << "ilo";
    return oss.str();
}

/**
 * Primitive for get_robot_version
 */
inline std::string get_robot_version() {
    std::ostringstream oss;
        oss << "500y";
    return oss.str();
}

/**
 * Primitive for start_firmware_upload
 */
inline std::string start_firmware_upload(int size) {
    std::ostringstream oss;
        oss << "500x";
        oss << size;
        oss << "";
    return oss.str();
}

/**
 * Primitive for start_trame_s
 */
inline std::string start_trame_s(std::string trame_s_params) {
    std::ostringstream oss;
        oss << "0";
        oss << trame_s_params;
        oss << "";
    return oss.str();
}

/**
 * Primitive for stop_tasks
 */
inline std::string stop_tasks() {
    std::ostringstream oss;
        oss << "00";
    return oss.str();
}

/**
 * Primitive for get_color_rgb_center
 */
inline std::string get_color_rgb_center() {
    std::ostringstream oss;
        oss << "10c";
    return oss.str();
}

/**
 * Primitive for get_color_rgb_left
 */
inline std::string get_color_rgb_left() {
    std::ostringstream oss;
        oss << "10l";
    return oss.str();
}

/**
 * Primitive for get_color_rgb_right
 */
inline std::string get_color_rgb_right() {
    std::ostringstream oss;
        oss << "10d";
    return oss.str();
}

/**
 * Primitive for get_color_clear
 */
inline std::string get_color_clear() {
    std::ostringstream oss;
        oss << "11";
    return oss.str();
}

/**
 * Primitive for get_line
 */
inline std::string get_line() {
    std::ostringstream oss;
        oss << "12";
    return oss.str();
}

/**
 * Primitive for set_line_threshold_value
 */
inline std::string set_line_threshold_value(int threshold) {
    std::ostringstream oss;
        oss << "13t";
        oss << threshold;
        oss << "";
    return oss.str();
}

/**
 * Primitive for get_line_threshold_value
 */
inline std::string get_line_threshold_value() {
    std::ostringstream oss;
        oss << "14";
    return oss.str();
}

/**
 * Primitive for get_accessory_status
 */
inline std::string get_accessory_status() {
    std::ostringstream oss;
        oss << "15";
    return oss.str();
}

/**
 * Primitive for get_sensor_distance
 */
inline std::string get_sensor_distance() {
    std::ostringstream oss;
        oss << "20";
    return oss.str();
}

/**
 * Primitive for get_distance_front
 */
inline std::string get_distance_front() {
    std::ostringstream oss;
        oss << "21";
    return oss.str();
}

/**
 * Primitive for get_distance_right
 */
inline std::string get_distance_right() {
    std::ostringstream oss;
        oss << "22";
    return oss.str();
}

/**
 * Primitive for get_distance_back
 */
inline std::string get_distance_back() {
    std::ostringstream oss;
        oss << "23";
    return oss.str();
}

/**
 * Primitive for get_distance_left
 */
inline std::string get_distance_left() {
    std::ostringstream oss;
        oss << "24";
    return oss.str();
}

/**
 * Primitive for get_imu_info
 */
inline std::string get_imu_info() {
    std::ostringstream oss;
        oss << "30";
    return oss.str();
}

/**
 * Primitive for reset_angle
 */
inline std::string reset_angle() {
    std::ostringstream oss;
        oss << "31";
    return oss.str();
}

/**
 * Primitive for get_raw_imu
 */
inline std::string get_raw_imu() {
    std::ostringstream oss;
        oss << "32";
    return oss.str();
}

/**
 * Primitive for get_battery_info
 */
inline std::string get_battery_info() {
    std::ostringstream oss;
        oss << "40";
    return oss.str();
}

/**
 * Primitive for get_led_color
 */
inline std::string get_led_color() {
    std::ostringstream oss;
        oss << "50";
    return oss.str();
}

/**
 * Primitive for set_led_color_circle
 */
inline std::string set_led_color_circle(std::string r, std::string g, std::string b) {
    std::ostringstream oss;
        oss << "511r";
        oss << r;
        oss << "g";
        oss << g;
        oss << "b";
        oss << b;
        oss << "";
    return oss.str();
}

/**
 * Primitive for set_led_color_circle_2
 */
inline std::string set_led_color_circle_2(std::string r, std::string g, std::string b) {
    std::ostringstream oss;
        oss << "512r";
        oss << r;
        oss << "g";
        oss << g;
        oss << "b";
        oss << b;
        oss << "";
    return oss.str();
}

/**
 * Primitive for set_led_shape
 */
inline std::string set_led_shape(std::string shape) {
    std::ostringstream oss;
        oss << "52v";
        oss << shape;
        oss << "";
    return oss.str();
}

/**
 * Primitive for set_led_mode
 */
inline std::string set_led_mode(std::string mode, int nb_loop) {
    std::ostringstream oss;
        oss << "53";
        oss << mode;
        oss << "/";
        oss << nb_loop;
        oss << "";
    return oss.str();
}

/**
 * Primitive for set_led_captor
 */
inline std::string set_led_captor(int brightness) {
    std::ostringstream oss;
        oss << "54l";
        oss << brightness;
        oss << "";
    return oss.str();
}

/**
 * Primitive for set_led_single
 */
inline std::string set_led_single(std::string type, int id, int red, int green, int blue) {
    std::ostringstream oss;
        oss << "55t";
        oss << type;
        oss << "d";
        oss << id;
        oss << "r";
        oss << red;
        oss << "g";
        oss << green;
        oss << "b";
        oss << blue;
        oss << "";
    return oss.str();
}

/**
 * Primitive for display_word
 */
inline std::string display_word(std::string word, int delay, int nb_loops) {
    std::ostringstream oss;
        oss << "56w";
        oss << word;
        oss << "d";
        oss << delay;
        oss << "/";
        oss << nb_loops;
        oss << "";
    return oss.str();
}

/**
 * Primitive for display_word_slide
 */
inline std::string display_word_slide() {
    std::ostringstream oss;
        oss << "57";
    return oss.str();
}

/**
 * Primitive for set_animation_flag_false
 */
inline std::string set_animation_flag_false() {
    std::ostringstream oss;
        oss << "58";
    return oss.str();
}

/**
 * Primitive for run_command_motor
 */
inline std::string run_command_motor(std::string params) {
    std::ostringstream oss;
        oss << "a";
        oss << params;
        oss << "";
    return oss.str();
}

/**
 * Primitive for ping_motor
 */
inline std::string ping_motor(int ping_status_0, int ping_status_1) {
    std::ostringstream oss;
        oss << "60i";
        oss << ping_status_0;
        oss << "s";
        oss << ping_status_1;
        oss << "";
    return oss.str();
}

/**
 * Primitive for drive_single_motor_speed
 */
inline std::string drive_single_motor_speed(int motor_index, int acc, int speed) {
    std::ostringstream oss;
        oss << "610i";
        oss << motor_index;
        oss << "a";
        oss << acc;
        oss << "v";
        oss << speed;
        oss << "";
    return oss.str();
}

/**
 * Primitive for get_single_motor_speed
 */
inline std::string get_single_motor_speed(int motor_index) {
    std::ostringstream oss;
        oss << "611i";
        oss << motor_index;
        oss << "";
    return oss.str();
}

/**
 * Primitive for drive_single_motor_angle
 */
inline std::string drive_single_motor_angle(int motor_index, int acc, int vel, int position) {
    std::ostringstream oss;
        oss << "620i";
        oss << motor_index;
        oss << "a";
        oss << acc;
        oss << "v";
        oss << vel;
        oss << "p";
        oss << position;
        oss << "";
    return oss.str();
}

/**
 * Primitive for get_single_motor_angle
 */
inline std::string get_single_motor_angle(int motor_index) {
    std::ostringstream oss;
        oss << "621i";
        oss << motor_index;
        oss << "";
    return oss.str();
}

/**
 * Primitive for get_single_motor_temp
 */
inline std::string get_single_motor_temp(int motor_index) {
    std::ostringstream oss;
        oss << "63i";
        oss << motor_index;
        oss << "";
    return oss.str();
}

/**
 * Primitive for get_single_motor_volt
 */
inline std::string get_single_motor_volt(int motor_index) {
    std::ostringstream oss;
        oss << "64i";
        oss << motor_index;
        oss << "";
    return oss.str();
}

/**
 * Primitive for get_single_motor_load
 */
inline std::string get_single_motor_load(int motor_index) {
    std::ostringstream oss;
        oss << "65i";
        oss << motor_index;
        oss << "";
    return oss.str();
}

/**
 * Primitive for get_single_motor_current
 */
inline std::string get_single_motor_current(int motor_index) {
    std::ostringstream oss;
        oss << "66i";
        oss << motor_index;
        oss << "";
    return oss.str();
}

/**
 * Primitive for get_single_motor_move
 */
inline std::string get_single_motor_move(int motor_index) {
    std::ostringstream oss;
        oss << "67i";
        oss << motor_index;
        oss << "";
    return oss.str();
}

/**
 * Primitive for set_motors_ilo_acc
 */
inline std::string set_motors_ilo_acc(int acc) {
    std::ostringstream oss;
        oss << "680a";
        oss << acc;
        oss << "";
    return oss.str();
}

/**
 * Primitive for get_motors_ilo_acc
 */
inline std::string get_motors_ilo_acc() {
    std::ostringstream oss;
        oss << "681";
    return oss.str();
}

/**
 * Primitive for set_tempo_pos
 */
inline std::string set_tempo_pos(int tempo_pos) {
    std::ostringstream oss;
        oss << "690t";
        oss << tempo_pos;
        oss << "";
    return oss.str();
}

/**
 * Primitive for get_tempo_pos
 */
inline std::string get_tempo_pos() {
    std::ostringstream oss;
        oss << "691";
    return oss.str();
}

/**
 * Primitive for set_pid
 */
inline std::string set_pid(int Kp, int Ki, int Kd) {
    std::ostringstream oss;
        oss << "70p";
        oss << Kp;
        oss << "i";
        oss << Ki;
        oss << "d";
        oss << Kd;
        oss << "";
    return oss.str();
}

/**
 * Primitive for get_pid
 */
inline std::string get_pid() {
    std::ostringstream oss;
        oss << "71";
    return oss.str();
}

/**
 * Primitive for check_auto_mode
 */
inline std::string check_auto_mode(int current_auto_mode) {
    std::ostringstream oss;
        oss << "80";
        oss << current_auto_mode;
        oss << "";
    return oss.str();
}

/**
 * Primitive for set_wifi_credentials
 */
inline std::string set_wifi_credentials(std::string ssid, std::string password) {
    std::ostringstream oss;
        oss << "90";
        oss << ssid;
        oss << "{|||}";
        oss << password;
        oss << "";
    return oss.str();
}

/**
 * Primitive for get_wifi_credentials
 */
inline std::string get_wifi_credentials() {
    std::ostringstream oss;
        oss << "92";
    return oss.str();
}

/**
 * Primitive for get_hostname
 */
inline std::string get_hostname() {
    std::ostringstream oss;
        oss << "93";
    return oss.str();
}

/**
 * Primitive for get_hostname_legacy
 */
inline std::string get_hostname_legacy() {
    std::ostringstream oss;
        oss << "930";
    return oss.str();
}

/**
 * Primitive for set_name
 */
inline std::string set_name(std::string name) {
    std::ostringstream oss;
        oss << "94n";
        oss << name;
        oss << "";
    return oss.str();
}

/**
 * Primitive for set_server_status
 */
inline std::string set_server_status(int status) {
    std::ostringstream oss;
        oss << "95s";
        oss << status;
        oss << "";
    return oss.str();
}

/**
 * Primitive for get_server_status
 */
inline std::string get_server_status() {
    std::ostringstream oss;
        oss << "96";
    return oss.str();
}

/**
 * Primitive for get_accessory_data
 */
inline std::string get_accessory_data() {
    std::ostringstream oss;
        oss << "100";
    return oss.str();
}

/**
 * Primitive for get_accessory_info
 */
inline std::string get_accessory_info() {
    std::ostringstream oss;
        oss << "101";
    return oss.str();
}

/**
 * Primitive for very_very_usefull
 */
inline std::string very_very_usefull() {
    std::ostringstream oss;
        oss << "102";
    return oss.str();
}

/**
 * Primitive for set_debug_state
 */
inline std::string set_debug_state(int state) {
    std::ostringstream oss;
        oss << "103s";
        oss << state;
        oss << "";
    return oss.str();
}

/**
 * Primitive for start_diag
 */
inline std::string start_diag() {
    std::ostringstream oss;
        oss << "110";
    return oss.str();
}

/**
 * Primitive for get_manufacturing_date
 */
inline std::string get_manufacturing_date() {
    std::ostringstream oss;
        oss << "120";
    return oss.str();
}

/**
 * Primitive for set_manufacturing_date
 */
inline std::string set_manufacturing_date(std::string date) {
    std::ostringstream oss;
        oss << "121s";
        oss << date;
        oss << "";
    return oss.str();
}

/**
 * Primitive for get_first_use_date
 */
inline std::string get_first_use_date() {
    std::ostringstream oss;
        oss << "130";
    return oss.str();
}

/**
 * Primitive for set_first_use_date
 */
inline std::string set_first_use_date(std::string date) {
    std::ostringstream oss;
        oss << "131s";
        oss << date;
        oss << "";
    return oss.str();
}

/**
 * Primitive for get_product_version
 */
inline std::string get_product_version() {
    std::ostringstream oss;
        oss << "140";
    return oss.str();
}

/**
 * Primitive for set_product_version
 */
inline std::string set_product_version(std::string version) {
    std::ostringstream oss;
        oss << "141s";
        oss << version;
        oss << "";
    return oss.str();
}

/**
 * Primitive for get_product_id
 */
inline std::string get_product_id() {
    std::ostringstream oss;
        oss << "150";
    return oss.str();
}

/**
 * Primitive for set_product_id
 */
inline std::string set_product_id(std::string product_id) {
    std::ostringstream oss;
        oss << "151s";
        oss << product_id;
        oss << "";
    return oss.str();
}

/**
 * Primitive for get_review_date
 */
inline std::string get_review_date() {
    std::ostringstream oss;
        oss << "160";
    return oss.str();
}

/**
 * Primitive for set_review_date
 */
inline std::string set_review_date(std::string date) {
    std::ostringstream oss;
        oss << "161s";
        oss << date;
        oss << "";
    return oss.str();
}

/**
 * Primitive for set_auto_setup
 */
inline std::string set_auto_setup(int auto_setup) {
    std::ostringstream oss;
        oss << "170a";
        oss << auto_setup;
        oss << "";
    return oss.str();
}

