Python Primitives API
=====================

This section documents the generated Python primitives.



.. py:function:: safety_stop()

   Primitive for safety_stop

   **Returns:** ``str`` — the encoded trame.


.. py:function:: handshake_ilo()

   Primitive for handshake_ilo

   **Returns:** ``str`` — the encoded trame.


.. py:function:: get_robot_version()

   Primitive for get_robot_version

   **Returns:** ``str`` — the encoded trame.


.. py:function:: start_firmware_upload(size: int)

   Primitive for start_firmware_upload

   **Returns:** ``str`` — the encoded trame.


.. py:function:: start_trame_s(trame_s_params: str)

   Primitive for start_trame_s

   **Returns:** ``str`` — the encoded trame.


.. py:function:: stop_tasks()

   Primitive for stop_tasks

   **Returns:** ``str`` — the encoded trame.


.. py:function:: get_color_rgb_center()

   Primitive for get_color_rgb_center

   **Returns:** ``str`` — the encoded trame.


.. py:function:: get_color_rgb_left()

   Primitive for get_color_rgb_left

   **Returns:** ``str`` — the encoded trame.


.. py:function:: get_color_rgb_right()

   Primitive for get_color_rgb_right

   **Returns:** ``str`` — the encoded trame.


.. py:function:: get_color_clear()

   Primitive for get_color_clear

   **Returns:** ``str`` — the encoded trame.


.. py:function:: get_line()

   Primitive for get_line

   **Returns:** ``str`` — the encoded trame.


.. py:function:: set_line_threshold_value(threshold: int)

   Primitive for set_line_threshold_value

   **Returns:** ``str`` — the encoded trame.


.. py:function:: get_line_threshold_value()

   Primitive for get_line_threshold_value

   **Returns:** ``str`` — the encoded trame.


.. py:function:: get_accessory_status()

   Primitive for get_accessory_status

   **Returns:** ``str`` — the encoded trame.


.. py:function:: get_sensor_distance()

   Primitive for get_sensor_distance

   **Returns:** ``str`` — the encoded trame.


.. py:function:: get_distance_front()

   Primitive for get_distance_front

   **Returns:** ``str`` — the encoded trame.


.. py:function:: get_distance_right()

   Primitive for get_distance_right

   **Returns:** ``str`` — the encoded trame.


.. py:function:: get_distance_back()

   Primitive for get_distance_back

   **Returns:** ``str`` — the encoded trame.


.. py:function:: get_distance_left()

   Primitive for get_distance_left

   **Returns:** ``str`` — the encoded trame.


.. py:function:: get_imu_info()

   Primitive for get_imu_info

   **Returns:** ``str`` — the encoded trame.


.. py:function:: reset_angle()

   Primitive for reset_angle

   **Returns:** ``str`` — the encoded trame.


.. py:function:: get_raw_imu()

   Primitive for get_raw_imu

   **Returns:** ``str`` — the encoded trame.


.. py:function:: get_battery_info()

   Primitive for get_battery_info

   **Returns:** ``str`` — the encoded trame.


.. py:function:: get_led_color()

   Primitive for get_led_color

   **Returns:** ``str`` — the encoded trame.


.. py:function:: set_led_color(red: int, green: int, blue: int)

   Primitive for set_led_color

   **Returns:** ``str`` — the encoded trame.


.. py:function:: set_led_shape(shape: str)

   Primitive for set_led_shape

   **Returns:** ``str`` — the encoded trame.


.. py:function:: set_led_mode(mode: str, nb_loop: int)

   Primitive for set_led_mode

   **Returns:** ``str`` — the encoded trame.


.. py:function:: set_led_captor(brightness: int)

   Primitive for set_led_captor

   **Returns:** ``str`` — the encoded trame.


.. py:function:: set_led_single(type: str, id: int, red: int, green: int, blue: int)

   Primitive for set_led_single

   **Returns:** ``str`` — the encoded trame.


.. py:function:: display_word(word: str, delay: int, nb_loops: int)

   Primitive for display_word

   **Returns:** ``str`` — the encoded trame.


.. py:function:: display_word_slide()

   Primitive for display_word_slide

   **Returns:** ``str`` — the encoded trame.


.. py:function:: set_animation_flag_false()

   Primitive for set_animation_flag_false

   **Returns:** ``str`` — the encoded trame.


.. py:function:: run_command_motor(params: str)

   Primitive for run_command_motor

   **Returns:** ``str`` — the encoded trame.


.. py:function:: ping_motor(ping_status_0: int, ping_status_1: int)

   Primitive for ping_motor

   **Returns:** ``str`` — the encoded trame.


.. py:function:: drive_single_motor_speed(motor_index: int, acc: int, speed: int)

   Primitive for drive_single_motor_speed

   **Returns:** ``str`` — the encoded trame.


.. py:function:: get_single_motor_speed(motor_index: int)

   Primitive for get_single_motor_speed

   **Returns:** ``str`` — the encoded trame.


.. py:function:: drive_single_motor_angle(motor_index: int, acc: int, vel: int, position: int)

   Primitive for drive_single_motor_angle

   **Returns:** ``str`` — the encoded trame.


.. py:function:: get_single_motor_angle(motor_index: int)

   Primitive for get_single_motor_angle

   **Returns:** ``str`` — the encoded trame.


.. py:function:: get_single_motor_temp(motor_index: int)

   Primitive for get_single_motor_temp

   **Returns:** ``str`` — the encoded trame.


.. py:function:: get_single_motor_volt(motor_index: int)

   Primitive for get_single_motor_volt

   **Returns:** ``str`` — the encoded trame.


.. py:function:: get_single_motor_load(motor_index: int)

   Primitive for get_single_motor_load

   **Returns:** ``str`` — the encoded trame.


.. py:function:: get_single_motor_current(motor_index: int)

   Primitive for get_single_motor_current

   **Returns:** ``str`` — the encoded trame.


.. py:function:: get_single_motor_move(motor_index: int)

   Primitive for get_single_motor_move

   **Returns:** ``str`` — the encoded trame.


.. py:function:: set_motors_ilo_acc(acc: int)

   Primitive for set_motors_ilo_acc

   **Returns:** ``str`` — the encoded trame.


.. py:function:: get_motors_ilo_acc()

   Primitive for get_motors_ilo_acc

   **Returns:** ``str`` — the encoded trame.


.. py:function:: set_tempo_pos(tempo_pos: int)

   Primitive for set_tempo_pos

   **Returns:** ``str`` — the encoded trame.


.. py:function:: get_tempo_pos()

   Primitive for get_tempo_pos

   **Returns:** ``str`` — the encoded trame.


.. py:function:: set_pid(Kp: int, Ki: int, Kd: int)

   Primitive for set_pid

   **Returns:** ``str`` — the encoded trame.


.. py:function:: get_pid()

   Primitive for get_pid

   **Returns:** ``str`` — the encoded trame.


.. py:function:: check_auto_mode(current_auto_mode: int)

   Primitive for check_auto_mode

   **Returns:** ``str`` — the encoded trame.


.. py:function:: set_wifi_credentials(ssid: str, password: str)

   Primitive for set_wifi_credentials

   **Returns:** ``str`` — the encoded trame.


.. py:function:: get_wifi_credentials()

   Primitive for get_wifi_credentials

   **Returns:** ``str`` — the encoded trame.


.. py:function:: get_hostname()

   Primitive for get_hostname

   **Returns:** ``str`` — the encoded trame.


.. py:function:: get_hostname_legacy()

   Primitive for get_hostname_legacy

   **Returns:** ``str`` — the encoded trame.


.. py:function:: set_name(name: str)

   Primitive for set_name

   **Returns:** ``str`` — the encoded trame.


.. py:function:: set_server_status(status: int)

   Primitive for set_server_status

   **Returns:** ``str`` — the encoded trame.


.. py:function:: get_server_status()

   Primitive for get_server_status

   **Returns:** ``str`` — the encoded trame.


.. py:function:: get_accessory_data()

   Primitive for get_accessory_data

   **Returns:** ``str`` — the encoded trame.


.. py:function:: get_accessory_info()

   Primitive for get_accessory_info

   **Returns:** ``str`` — the encoded trame.


.. py:function:: very_very_usefull()

   Primitive for very_very_usefull

   **Returns:** ``str`` — the encoded trame.


.. py:function:: set_debug_state(state: int)

   Primitive for set_debug_state

   **Returns:** ``str`` — the encoded trame.


.. py:function:: start_diag()

   Primitive for start_diag

   **Returns:** ``str`` — the encoded trame.


.. py:function:: get_manufacturing_date()

   Primitive for get_manufacturing_date

   **Returns:** ``str`` — the encoded trame.


.. py:function:: set_manufacturing_date(date: str)

   Primitive for set_manufacturing_date

   **Returns:** ``str`` — the encoded trame.


.. py:function:: get_first_use_date()

   Primitive for get_first_use_date

   **Returns:** ``str`` — the encoded trame.


.. py:function:: set_first_use_date(date: str)

   Primitive for set_first_use_date

   **Returns:** ``str`` — the encoded trame.


.. py:function:: get_product_version()

   Primitive for get_product_version

   **Returns:** ``str`` — the encoded trame.


.. py:function:: set_product_version(version: str)

   Primitive for set_product_version

   **Returns:** ``str`` — the encoded trame.


.. py:function:: get_product_id()

   Primitive for get_product_id

   **Returns:** ``str`` — the encoded trame.


.. py:function:: set_product_id(product_id: str)

   Primitive for set_product_id

   **Returns:** ``str`` — the encoded trame.


.. py:function:: get_review_date()

   Primitive for get_review_date

   **Returns:** ``str`` — the encoded trame.


.. py:function:: set_review_date(date: str)

   Primitive for set_review_date

   **Returns:** ``str`` — the encoded trame.


.. py:function:: set_auto_setup(auto_setup: int)

   Primitive for set_auto_setup

   **Returns:** ``str`` — the encoded trame.

