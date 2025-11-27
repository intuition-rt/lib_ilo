#include <Python.h>
#include <structmember.h>

#include <fcntl.h>
#include <stdbool.h>
#include <stddef.h>
#include <sys/stat.h>

#include "core/trame.h"

static
PyObject *py_get_trames(PyObject *self, PyObject *args)
{
    PyObject *tuple;
    PyObject *list = PyList_New(0);
    if (!list) return NULL;

    (void)self, (void)args;

    for (int i = 0; i < TRAME_COUNT; i++) {
        PyObject *d = Py_BuildValue(
            "(s,s)",
            TRAMES[i].name,
            TRAMES[i].format
        );

        if (d == NULL) {
            Py_DECREF(list);
            return NULL;
        }
        PyList_Append(list, d);
        Py_DECREF(d);
    }

    tuple = PyList_AsTuple(list);
    Py_DECREF(list);
    return tuple;
}

static
PyObject *py_build_trame(PyObject *self, PyObject *args)
{
    trame_param t_params[8];

    PyObject *param_tuple;
    char const *trame_name;

    (void)self;
    if (!PyArg_ParseTuple(args, "sO!", &trame_name, &PyTuple_Type, &param_tuple))
        return NULL;

    Py_ssize_t n = PyTuple_Size(param_tuple);

    if (n >= (int)countof(t_params)) {
        PyErr_SetString(PyExc_ValueError, "too many parameters");
        return NULL;
    }

    char *result = NULL;

    for (Py_ssize_t i = 0; i < n; i++) {
        PyObject *item = PyTuple_GetItem(param_tuple, i);
        if (!PyTuple_Check(item) || PyTuple_Size(item) != 2) {
            PyErr_Format(PyExc_TypeError,
                         "param %zd must be a tuple of (str, str)", i);
            return NULL;
        }

        PyObject *py_name = PyTuple_GetItem(item, 0);
        PyObject *py_value = PyTuple_GetItem(item, 1);

        if (!PyUnicode_Check(py_name) || !PyUnicode_Check(py_value)) {
            PyErr_Format(PyExc_TypeError,
                         "param %zd elements must be str", i);
            return NULL;
        }

        t_params[i].name = PyUnicode_AsUTF8(py_name);
        t_params[i].value = PyUnicode_AsUTF8(py_value);

        if (t_params[i].name == NULL || t_params[i].value == NULL)
            return NULL;
    }

    result = exposed_build_trame(trame_name, n, t_params);
    if (!result) {
        PyErr_Format(PyExc_RuntimeError, "build_trame failed for %s", trame_name);
        return NULL;
    }

    return PyUnicode_FromString(result);
}

static
PyMethodDef ILO_BINDING_METHODS[] = {
    { "get_trames", py_get_trames, METH_VARARGS, NULL },
    { "build_trame", py_build_trame, METH_VARARGS, NULL },
    { NULL, NULL, 0, NULL }
};

static
struct PyModuleDef MODULE = {
    PyModuleDef_HEAD_INIT,
    .m_name = "ilo_binding_ext",
    .m_doc = NULL,
    .m_size = -1,
    .m_methods = ILO_BINDING_METHODS
};

// NOLINTNEXTLINE(readability-identifier-naming): mendatory func name
PyMODINIT_FUNC PyInit_ilo_binding_ext(void)
{
    PyObject *mod = PyModule_Create(&MODULE);

    return mod;
}
