#include <Python.h>
#include <structmember.h>

#include <fcntl.h>
#include <stdbool.h>
#include <stddef.h>
#include <stdio.h>
#include <sys/stat.h>

#include "core/trame.h"

static
PyObject *py__get_name(PyObject *self, PyObject *args)
{
    char *p = build_simple_trame("get_hostname");

    if (!PyArg_ParseTuple(args, ""))
        return NULL;

    printf("%s\n", p);
    return PyUnicode_FromString(p);
}

static
PyMethodDef ILO_BINDING_METHODS[] = {
    {"get_name", py__get_name, METH_VARARGS, "."},
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
