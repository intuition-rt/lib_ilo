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
    return simple_trame_getter("safety_stop", args);
}

static
PyObject *py__handshake_ilo(PyObject *self, PyObject *args)
{
    return simple_trame_getter("handshake_ilo", args);
}

static
PyObject *py__get_name(PyObject *self, PyObject *args)
{
    return simple_trame_getter("get_hostname", args);
}

static
PyObject *py__get_robot_version(PyObject *self, PyObject *args)
{
    return simple_trame_getter("get_robot_version", args);
}

static
PyObject *py__start_firmware_upload(PyObject *self, PyObject *args)
{
    char *p;
    int size;

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

    if (!PyArg_ParseTuple(args, "s", &trame_s_param))
        return NULL;
    p = build_trame("start_trame_s", trame_s_param);
    return PyUnicode_FromString(p);
}

static
PyObject *py__stop_tasks(PyObject *self, PyObject *args)
{
    return simple_trame_getter("stop_tasks", args);
}

static
PyMethodDef ILO_BINDING_METHODS[] = {
    { "get_name", py__get_name, METH_VARARGS, NULL },
    { "safety_stop", py__safety_stop, METH_VARARGS, NULL },
    { "handshake_ilo", py__handshake_ilo, METH_VARARGS, NULL },
    { "start_firmware_upload", py__start_firmware_upload, METH_VARARGS, NULL },
    { "start_trame_s", py__start_trame_s, METH_VARARGS, NULL },
    { "stop_tasks", py__stop_tasks, METH_VARARGS, NULL },

    { "get_robot_version", py__get_robot_version, METH_VARARGS, NULL },
    {NULL, NULL, 0, NULL}
};

static
struct PyModuleDef MODULE = {
    PyModuleDef_HEAD_INIT,
    "ilo_binding",
    NULL,
    -1,
    ILO_BINDING_METHODS
};

PyMODINIT_FUNC PyInit_ilo_binding(void)
{
    PyObject *mod = PyModule_Create(&MODULE);

    return mod;
}
