#include <Python.h>
#include <structmember.h>

#include <fcntl.h>
#include <stdbool.h>
#include <stddef.h>
#include <sys/stat.h>

#include "core/trame.h"

static
PyObject *simple_trame_getter(char const *tr_name, PyObject *args)
{
    char *p;

    /* ensure no argument where provided, because it wouldn't be correct? */
    if (!PyArg_ParseTuple(args, ""))
        return NULL;
    p = build_simple_trame(tr_name);
    return PyUnicode_FromString(p);
}

static
PyObject *py__safety_stop(PyObject *self, PyObject *args)
{
    (void)self;
    return simple_trame_getter("safety_stop", args);
}

static
PyObject *py__handshake_ilo(PyObject *self, PyObject *args)
{
    (void)self;
    return simple_trame_getter("handshake_ilo", args);
}

static
PyObject *py__get_name(PyObject *self, PyObject *args)
{
    (void)self;
    return simple_trame_getter("get_hostname", args);
}

static
PyObject *py__get_robot_version(PyObject *self, PyObject *args)
{
    (void)self;
    return simple_trame_getter("get_robot_version", args);
}

static
PyObject *py__start_firmware_upload(PyObject *self, PyObject *args)
{
    char *p;
    int size;

    (void)self;
    if (!PyArg_ParseTuple(args, "i", &size))
        return NULL;
    p = build_trame("start_firmware_upload", size);
    return PyUnicode_FromString(p);
}

static
PyObject *py__start_trame_s(PyObject *self, PyObject *args)
{
    char *p;
    char *trame_s_param;

    (void)self;
    if (!PyArg_ParseTuple(args, "s", &trame_s_param))
        return NULL;
    p = build_trame("start_trame_s", trame_s_param);
    return PyUnicode_FromString(p);
}

static
PyObject *py__stop_tasks(PyObject *self, PyObject *args)
{
    (void)self;
    return simple_trame_getter("stop_tasks", args);
}

static
PyObject *py__get_color_rgb_center(PyObject *self, PyObject *args)
{
    (void)self;
    return simple_trame_getter("get_color_rgb_center", args);
}

static
PyObject *py__get_color_rgb_left(PyObject *self, PyObject *args)
{
    (void)self;
    return simple_trame_getter("get_color_rgb_left", args);
}

static
PyObject *py__get_color_rgb_right(PyObject *self, PyObject *args)
{
    (void)self;
    return simple_trame_getter("get_color_rgb_right", args);
}

static
PyObject *py__get_color_clear(PyObject *self, PyObject *args)
{
    (void)self;
    return simple_trame_getter("get_color_clear", args);
}

static
PyObject *py__get_line(PyObject *self, PyObject *args)
{
    (void)self;
    return simple_trame_getter("get_line", args);
}

static
PyObject *py__set_line_threshold_value(PyObject *self, PyObject *args)
{
    int threshold;
    char *p;

    (void)self;
    if (!PyArg_ParseTuple(args, "i", &threshold))
        return NULL;

    p = build_trame("set_line_threshold_value", threshold);
    return PyUnicode_FromString(p);
}

static
PyObject *py__get_line_threshold_value(PyObject *self, PyObject *args)
{
    (void)self;
    return simple_trame_getter("get_line_threshold_value", args);
}

static
PyObject *py__get_accessory_status(PyObject *self, PyObject *args)
{
    (void)self;
    return simple_trame_getter("get_accessory_status", args);
}

static
PyObject *py__get_sensor_distance(PyObject *self, PyObject *args)
{
    (void)self;
    return simple_trame_getter("get_sensor_distance", args);
}

static
PyObject *py__get_distance_front(PyObject *self, PyObject *args)
{
    (void)self;
    return simple_trame_getter("get_distance_front", args);
}

static
PyObject *py__get_distance_right(PyObject *self, PyObject *args)
{
    (void)self;
    return simple_trame_getter("get_distance_right", args);
}

static
PyObject *py__get_distance_back(PyObject *self, PyObject *args)
{
    (void)self;
    return simple_trame_getter("get_distance_back", args);
}

static
PyObject *py__get_distance_left(PyObject *self, PyObject *args)
{
    (void)self;
    return simple_trame_getter("get_distance_left", args);
}

static
PyObject *py__get_imu_info(PyObject *self, PyObject *args)
{
    (void)self;
    return simple_trame_getter("get_imu_info", args);
}

static
PyObject *py__reset_angle(PyObject *self, PyObject *args)
{
    (void)self;
    return simple_trame_getter("reset_angle", args);
}

static
PyObject *py__get_raw_imu(PyObject *self, PyObject *args)
{
    (void)self;
    return simple_trame_getter("get_raw_imu", args);
}

static
PyObject *py__get_battery_info(PyObject *self, PyObject *args)
{
    (void)self;
    return simple_trame_getter("get_battery_info", args);
}

static
PyMethodDef ILO_BINDING_METHODS[] = {
    { "safety_stop", py__safety_stop, METH_VARARGS, NULL },

    { "handshake_ilo", py__handshake_ilo, METH_VARARGS, NULL },
    { "get_robot_version", py__get_robot_version, METH_VARARGS, NULL },
    { "start_firmware_upload", py__start_firmware_upload, METH_VARARGS, NULL },
    { "start_trame_s", py__start_trame_s, METH_VARARGS, NULL },
    { "stop_tasks", py__stop_tasks, METH_VARARGS, NULL },

    { "get_color_rgb_center", py__get_color_rgb_center, METH_VARARGS, NULL },
    { "get_color_rgb_left", py__get_color_rgb_left, METH_VARARGS, NULL },
    { "get_color_rgb_right", py__get_color_rgb_right, METH_VARARGS, NULL },
    { "get_color_clear", py__get_color_clear, METH_VARARGS, NULL },

    { "get_line", py__get_line, METH_VARARGS, NULL },
    { "set_line_threshold_value", py__set_line_threshold_value, METH_VARARGS, NULL },
    { "get_line_threshold_value", py__get_line_threshold_value, METH_VARARGS, NULL },
    { "get_accessory_status", py__get_accessory_status, METH_VARARGS, NULL },

    { "get_sensor_distance", py__get_sensor_distance, METH_VARARGS, NULL },
    { "get_distance_front", py__get_distance_front, METH_VARARGS, NULL },
    { "get_distance_right", py__get_distance_right, METH_VARARGS, NULL },
    { "get_distance_back", py__get_distance_back, METH_VARARGS, NULL },
    { "get_distance_left", py__get_distance_left, METH_VARARGS, NULL },

    { "get_imu_info", py__get_imu_info, METH_VARARGS, NULL },
    { "reset_angle", py__reset_angle, METH_VARARGS, NULL },
    { "get_raw_imu", py__get_raw_imu, METH_VARARGS, NULL },

    { "get_battery_info", py__get_battery_info, METH_VARARGS, NULL },


    { "get_name", py__get_name, METH_VARARGS, NULL },
    {NULL, NULL, 0, NULL}
};

static
struct PyModuleDef MODULE = {
    PyModuleDef_HEAD_INIT,
    .m_name = "ilo_binding",
    .m_doc = NULL,
    .m_size = -1,
    .m_methods = ILO_BINDING_METHODS
};

// NOLINTNEXTLINE(readability-identifier-naming): mendatory func name
PyMODINIT_FUNC PyInit_ilo_binding(void)
{
    PyObject *mod = PyModule_Create(&MODULE);

    return mod;
}
