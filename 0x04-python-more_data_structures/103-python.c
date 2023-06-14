#include <stdio.h>
#include <Python.h>

/**
 * print_python_bytes - Prints bytes information
 *
 * @p: Python Object
 * Return: no return
 */
void print_python_bytes(PyObject *p)
{
  PyBytesObject *bytes = (PyBytesObject *)p;
  Py_ssize_t size, i, limit;

  printf("[.] bytes object info\n");

  if (!PyBytes_Check(p))
    {
      printf("  [ERROR] Invalid Bytes Object\n");
      return;
    }

  size = PyBytes_Size(p);
  char *string = PyBytes_AsString(p);

  printf("  size: %ld\n", size);
  printf("  trying string: %s\n", string);

  if (size >= 10)
    limit = 10;
  else
    limit = size + 1;

  printf("  first %ld bytes:", limit);

  for (i = 0; i < limit; i++)
    {
      printf(" %02x", string[i]);
    }

  printf("\n");
}

/**
 * print_python_list - Prints list information
 *
 * @p: Python Object
 * Return: no return
 */
void print_python_list(PyObject *p)
{
  Py_ssize_t size, i;
  PyListObject *list;

  size = PyList_Size(p);
  list = (PyListObject *)p;

  printf("[*] Python list info\n");
  printf("[*] Size of the Python List = %ld\n", size);
  printf("[*] Allocated = %ld\n", list->allocated);

  for (i = 0; i < size; i++)
    {
      PyObject *obj = list->ob_item[i];
      const char *typeName = obj->ob_type->tp_name;
      printf("Element %ld: %s\n", i, typeName);

      if (PyBytes_Check(obj))
	{
	  print_python_bytes(obj);
	}
    }
}
