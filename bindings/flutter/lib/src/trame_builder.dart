// Auto-generated primitives for ilo communication
// This file is generated. Do not edit manually.

class TrameBuilder {

  /// Primitive for safety_stop
  static String safety_stop() {
    StringBuffer buffer = StringBuffer();
    buffer.write("");
    return buffer.toString();
  }
  /// Primitive for handshake_ilo
  static String handshake_ilo() {
    StringBuffer buffer = StringBuffer();
    buffer.write("ilo");
    return buffer.toString();
  }
  /// Primitive for get_robot_version
  static String get_robot_version() {
    StringBuffer buffer = StringBuffer();
    buffer.write("500y");
    return buffer.toString();
  }
  /// Primitive for start_firmware_upload
  static String start_firmware_upload(int size) {
    StringBuffer buffer = StringBuffer();
    buffer.write("500x");
    buffer.write(size);
    buffer.write("");
    return buffer.toString();
  }
  /// Primitive for start_trame_s
  static String start_trame_s(String trame_s_params) {
    StringBuffer buffer = StringBuffer();
    buffer.write("0");
    buffer.write(trame_s_params);
    buffer.write("");
    return buffer.toString();
  }
  /// Primitive for stop_tasks
  static String stop_tasks() {
    StringBuffer buffer = StringBuffer();
    buffer.write("00");
    return buffer.toString();
  }
  /// Primitive for get_color_rgb_center
  static String get_color_rgb_center() {
    StringBuffer buffer = StringBuffer();
    buffer.write("10c");
    return buffer.toString();
  }
  /// Primitive for get_color_rgb_left
  static String get_color_rgb_left() {
    StringBuffer buffer = StringBuffer();
    buffer.write("10l");
    return buffer.toString();
  }
  /// Primitive for get_color_rgb_right
  static String get_color_rgb_right() {
    StringBuffer buffer = StringBuffer();
    buffer.write("10d");
    return buffer.toString();
  }
  /// Primitive for get_color_clear
  static String get_color_clear() {
    StringBuffer buffer = StringBuffer();
    buffer.write("11");
    return buffer.toString();
  }
  /// Primitive for get_line
  static String get_line() {
    StringBuffer buffer = StringBuffer();
    buffer.write("12");
    return buffer.toString();
  }
  /// Primitive for set_line_threshold_value
  static String set_line_threshold_value(int threshold) {
    StringBuffer buffer = StringBuffer();
    buffer.write("13t");
    buffer.write(threshold);
    buffer.write("");
    return buffer.toString();
  }
  /// Primitive for get_line_threshold_value
  static String get_line_threshold_value() {
    StringBuffer buffer = StringBuffer();
    buffer.write("14");
    return buffer.toString();
  }
  /// Primitive for get_accessory_status
  static String get_accessory_status() {
    StringBuffer buffer = StringBuffer();
    buffer.write("15");
    return buffer.toString();
  }
  /// Primitive for get_sensor_distance
  static String get_sensor_distance() {
    StringBuffer buffer = StringBuffer();
    buffer.write("20");
    return buffer.toString();
  }
  /// Primitive for get_distance_front
  static String get_distance_front() {
    StringBuffer buffer = StringBuffer();
    buffer.write("21");
    return buffer.toString();
  }
  /// Primitive for get_distance_right
  static String get_distance_right() {
    StringBuffer buffer = StringBuffer();
    buffer.write("22");
    return buffer.toString();
  }
  /// Primitive for get_distance_back
  static String get_distance_back() {
    StringBuffer buffer = StringBuffer();
    buffer.write("23");
    return buffer.toString();
  }
  /// Primitive for get_distance_left
  static String get_distance_left() {
    StringBuffer buffer = StringBuffer();
    buffer.write("24");
    return buffer.toString();
  }
  /// Primitive for get_imu_info
  static String get_imu_info() {
    StringBuffer buffer = StringBuffer();
    buffer.write("30");
    return buffer.toString();
  }
  /// Primitive for reset_angle
  static String reset_angle() {
    StringBuffer buffer = StringBuffer();
    buffer.write("31");
    return buffer.toString();
  }
  /// Primitive for get_raw_imu
  static String get_raw_imu() {
    StringBuffer buffer = StringBuffer();
    buffer.write("32");
    return buffer.toString();
  }
  /// Primitive for get_battery_info
  static String get_battery_info() {
    StringBuffer buffer = StringBuffer();
    buffer.write("40");
    return buffer.toString();
  }
  /// Primitive for get_led_color
  static String get_led_color() {
    StringBuffer buffer = StringBuffer();
    buffer.write("50");
    return buffer.toString();
  }
  /// Primitive for set_led_color_circle
  static String set_led_color_circle(String r, String g, String b) {
    StringBuffer buffer = StringBuffer();
    buffer.write("511r");
    buffer.write(r);
    buffer.write("g");
    buffer.write(g);
    buffer.write("b");
    buffer.write(b);
    buffer.write("");
    return buffer.toString();
  }
  /// Primitive for set_led_color_circle_2
  static String set_led_color_circle_2(String r, String g, String b) {
    StringBuffer buffer = StringBuffer();
    buffer.write("512r");
    buffer.write(r);
    buffer.write("g");
    buffer.write(g);
    buffer.write("b");
    buffer.write(b);
    buffer.write("");
    return buffer.toString();
  }
  /// Primitive for set_led_shape
  static String set_led_shape(String shape) {
    StringBuffer buffer = StringBuffer();
    buffer.write("52v");
    buffer.write(shape);
    buffer.write("");
    return buffer.toString();
  }
  /// Primitive for set_led_mode
  static String set_led_mode(String mode, int nb_loop) {
    StringBuffer buffer = StringBuffer();
    buffer.write("53");
    buffer.write(mode);
    buffer.write("/");
    buffer.write(nb_loop);
    buffer.write("");
    return buffer.toString();
  }
  /// Primitive for set_led_captor
  static String set_led_captor(int brightness) {
    StringBuffer buffer = StringBuffer();
    buffer.write("54l");
    buffer.write(brightness);
    buffer.write("");
    return buffer.toString();
  }
  /// Primitive for set_led_single
  static String set_led_single(String type, int id, int red, int green, int blue) {
    StringBuffer buffer = StringBuffer();
    buffer.write("55t");
    buffer.write(type);
    buffer.write("d");
    buffer.write(id);
    buffer.write("r");
    buffer.write(red);
    buffer.write("g");
    buffer.write(green);
    buffer.write("b");
    buffer.write(blue);
    buffer.write("");
    return buffer.toString();
  }
  /// Primitive for display_word
  static String display_word(String word, int delay, int nb_loops) {
    StringBuffer buffer = StringBuffer();
    buffer.write("56w");
    buffer.write(word);
    buffer.write("d");
    buffer.write(delay);
    buffer.write("/");
    buffer.write(nb_loops);
    buffer.write("");
    return buffer.toString();
  }
  /// Primitive for display_word_slide
  static String display_word_slide() {
    StringBuffer buffer = StringBuffer();
    buffer.write("57");
    return buffer.toString();
  }
  /// Primitive for set_animation_flag_false
  static String set_animation_flag_false() {
    StringBuffer buffer = StringBuffer();
    buffer.write("58");
    return buffer.toString();
  }
  /// Primitive for run_command_motor
  static String run_command_motor(String params) {
    StringBuffer buffer = StringBuffer();
    buffer.write("a");
    buffer.write(params);
    buffer.write("");
    return buffer.toString();
  }
  /// Primitive for ping_motor
  static String ping_motor(int ping_status_0, int ping_status_1) {
    StringBuffer buffer = StringBuffer();
    buffer.write("60i");
    buffer.write(ping_status_0);
    buffer.write("s");
    buffer.write(ping_status_1);
    buffer.write("");
    return buffer.toString();
  }
  /// Primitive for drive_single_motor_speed
  static String drive_single_motor_speed(int motor_index, int acc, int speed) {
    StringBuffer buffer = StringBuffer();
    buffer.write("610i");
    buffer.write(motor_index);
    buffer.write("a");
    buffer.write(acc);
    buffer.write("v");
    buffer.write(speed);
    buffer.write("");
    return buffer.toString();
  }
  /// Primitive for get_single_motor_speed
  static String get_single_motor_speed(int motor_index) {
    StringBuffer buffer = StringBuffer();
    buffer.write("611i");
    buffer.write(motor_index);
    buffer.write("");
    return buffer.toString();
  }
  /// Primitive for drive_single_motor_angle
  static String drive_single_motor_angle(int motor_index, int acc, int vel, int position) {
    StringBuffer buffer = StringBuffer();
    buffer.write("620i");
    buffer.write(motor_index);
    buffer.write("a");
    buffer.write(acc);
    buffer.write("v");
    buffer.write(vel);
    buffer.write("p");
    buffer.write(position);
    buffer.write("");
    return buffer.toString();
  }
  /// Primitive for get_single_motor_angle
  static String get_single_motor_angle(int motor_index) {
    StringBuffer buffer = StringBuffer();
    buffer.write("621i");
    buffer.write(motor_index);
    buffer.write("");
    return buffer.toString();
  }
  /// Primitive for get_single_motor_temp
  static String get_single_motor_temp(int motor_index) {
    StringBuffer buffer = StringBuffer();
    buffer.write("63i");
    buffer.write(motor_index);
    buffer.write("");
    return buffer.toString();
  }
  /// Primitive for get_single_motor_volt
  static String get_single_motor_volt(int motor_index) {
    StringBuffer buffer = StringBuffer();
    buffer.write("64i");
    buffer.write(motor_index);
    buffer.write("");
    return buffer.toString();
  }
  /// Primitive for get_single_motor_load
  static String get_single_motor_load(int motor_index) {
    StringBuffer buffer = StringBuffer();
    buffer.write("65i");
    buffer.write(motor_index);
    buffer.write("");
    return buffer.toString();
  }
  /// Primitive for get_single_motor_current
  static String get_single_motor_current(int motor_index) {
    StringBuffer buffer = StringBuffer();
    buffer.write("66i");
    buffer.write(motor_index);
    buffer.write("");
    return buffer.toString();
  }
  /// Primitive for get_single_motor_move
  static String get_single_motor_move(int motor_index) {
    StringBuffer buffer = StringBuffer();
    buffer.write("67i");
    buffer.write(motor_index);
    buffer.write("");
    return buffer.toString();
  }
  /// Primitive for set_motors_ilo_acc
  static String set_motors_ilo_acc(int acc) {
    StringBuffer buffer = StringBuffer();
    buffer.write("680a");
    buffer.write(acc);
    buffer.write("");
    return buffer.toString();
  }
  /// Primitive for get_motors_ilo_acc
  static String get_motors_ilo_acc() {
    StringBuffer buffer = StringBuffer();
    buffer.write("681");
    return buffer.toString();
  }
  /// Primitive for set_tempo_pos
  static String set_tempo_pos(int tempo_pos) {
    StringBuffer buffer = StringBuffer();
    buffer.write("690t");
    buffer.write(tempo_pos);
    buffer.write("");
    return buffer.toString();
  }
  /// Primitive for get_tempo_pos
  static String get_tempo_pos() {
    StringBuffer buffer = StringBuffer();
    buffer.write("691");
    return buffer.toString();
  }
  /// Primitive for set_pid
  static String set_pid(int Kp, int Ki, int Kd) {
    StringBuffer buffer = StringBuffer();
    buffer.write("70p");
    buffer.write(Kp);
    buffer.write("i");
    buffer.write(Ki);
    buffer.write("d");
    buffer.write(Kd);
    buffer.write("");
    return buffer.toString();
  }
  /// Primitive for get_pid
  static String get_pid() {
    StringBuffer buffer = StringBuffer();
    buffer.write("71");
    return buffer.toString();
  }
  /// Primitive for check_auto_mode
  static String check_auto_mode(int current_auto_mode) {
    StringBuffer buffer = StringBuffer();
    buffer.write("80");
    buffer.write(current_auto_mode);
    buffer.write("");
    return buffer.toString();
  }
  /// Primitive for set_wifi_credentials
  static String set_wifi_credentials(String ssid, String password) {
    StringBuffer buffer = StringBuffer();
    buffer.write("90");
    buffer.write(ssid);
    buffer.write("{|||}");
    buffer.write(password);
    buffer.write("");
    return buffer.toString();
  }
  /// Primitive for get_wifi_credentials
  static String get_wifi_credentials() {
    StringBuffer buffer = StringBuffer();
    buffer.write("92");
    return buffer.toString();
  }
  /// Primitive for get_hostname
  static String get_hostname() {
    StringBuffer buffer = StringBuffer();
    buffer.write("93");
    return buffer.toString();
  }
  /// Primitive for get_hostname_legacy
  static String get_hostname_legacy() {
    StringBuffer buffer = StringBuffer();
    buffer.write("930");
    return buffer.toString();
  }
  /// Primitive for set_name
  static String set_name(String name) {
    StringBuffer buffer = StringBuffer();
    buffer.write("94n");
    buffer.write(name);
    buffer.write("");
    return buffer.toString();
  }
  /// Primitive for set_server_status
  static String set_server_status(int status) {
    StringBuffer buffer = StringBuffer();
    buffer.write("95s");
    buffer.write(status);
    buffer.write("");
    return buffer.toString();
  }
  /// Primitive for get_server_status
  static String get_server_status() {
    StringBuffer buffer = StringBuffer();
    buffer.write("96");
    return buffer.toString();
  }
  /// Primitive for get_accessory_data
  static String get_accessory_data() {
    StringBuffer buffer = StringBuffer();
    buffer.write("100");
    return buffer.toString();
  }
  /// Primitive for get_accessory_info
  static String get_accessory_info() {
    StringBuffer buffer = StringBuffer();
    buffer.write("101");
    return buffer.toString();
  }
  /// Primitive for very_very_usefull
  static String very_very_usefull() {
    StringBuffer buffer = StringBuffer();
    buffer.write("102");
    return buffer.toString();
  }
  /// Primitive for set_debug_state
  static String set_debug_state(int state) {
    StringBuffer buffer = StringBuffer();
    buffer.write("103s");
    buffer.write(state);
    buffer.write("");
    return buffer.toString();
  }
  /// Primitive for start_diag
  static String start_diag() {
    StringBuffer buffer = StringBuffer();
    buffer.write("110");
    return buffer.toString();
  }
  /// Primitive for get_manufacturing_date
  static String get_manufacturing_date() {
    StringBuffer buffer = StringBuffer();
    buffer.write("120");
    return buffer.toString();
  }
  /// Primitive for set_manufacturing_date
  static String set_manufacturing_date(String date) {
    StringBuffer buffer = StringBuffer();
    buffer.write("121s");
    buffer.write(date);
    buffer.write("");
    return buffer.toString();
  }
  /// Primitive for get_first_use_date
  static String get_first_use_date() {
    StringBuffer buffer = StringBuffer();
    buffer.write("130");
    return buffer.toString();
  }
  /// Primitive for set_first_use_date
  static String set_first_use_date(String date) {
    StringBuffer buffer = StringBuffer();
    buffer.write("131s");
    buffer.write(date);
    buffer.write("");
    return buffer.toString();
  }
  /// Primitive for get_product_version
  static String get_product_version() {
    StringBuffer buffer = StringBuffer();
    buffer.write("140");
    return buffer.toString();
  }
  /// Primitive for set_product_version
  static String set_product_version(String version) {
    StringBuffer buffer = StringBuffer();
    buffer.write("141s");
    buffer.write(version);
    buffer.write("");
    return buffer.toString();
  }
  /// Primitive for get_product_id
  static String get_product_id() {
    StringBuffer buffer = StringBuffer();
    buffer.write("150");
    return buffer.toString();
  }
  /// Primitive for set_product_id
  static String set_product_id(String product_id) {
    StringBuffer buffer = StringBuffer();
    buffer.write("151s");
    buffer.write(product_id);
    buffer.write("");
    return buffer.toString();
  }
  /// Primitive for get_review_date
  static String get_review_date() {
    StringBuffer buffer = StringBuffer();
    buffer.write("160");
    return buffer.toString();
  }
  /// Primitive for set_review_date
  static String set_review_date(String date) {
    StringBuffer buffer = StringBuffer();
    buffer.write("161s");
    buffer.write(date);
    buffer.write("");
    return buffer.toString();
  }
  /// Primitive for set_auto_setup
  static String set_auto_setup(int auto_setup) {
    StringBuffer buffer = StringBuffer();
    buffer.write("170a");
    buffer.write(auto_setup);
    buffer.write("");
    return buffer.toString();
  }
}