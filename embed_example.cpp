#include <Python.h>
#include <complex.hpp>
#include <iostream>

typedef struct {
  PyObject_HEAD
  void *ptr; // This is the pointer to the actual C++ instance
  void *ty;  // swig_type_info originally, but shouldn't matter
  int own;
  PyObject *next;
} SwigPyObject;

int main(int argc, char *argv[]) {
  Py_SetProgramName((wchar_t *)argv[0]); /* optional but recommended */
  Py_Initialize();
  PyRun_SimpleString("from time import time,ctime\n"
                     "print('Today is',ctime(time()))\n");

  auto x = PyRun_SimpleString("import "
                              "sys\nsys.path.append('/home/andy/repos/"
                              "swigexperiment')\nimport test2\n");
  PyRun_SimpleString("print(sys.path)");

  PyObject *myModuleString = PyUnicode_DecodeFSDefault("test2");
  std::cout << "Bing " << myModuleString << std::endl;
  PyObject *myModule = PyImport_Import(myModuleString);
  std::cout << "Bam " << myModule << std::endl;

  PyObject *myFunction = PyObject_GetAttrString(myModule, (char *)"ret");
  PyObject *myFunction2 =
      PyObject_GetAttrString(myModule, (char *)"get_complex");
  PyObject *myFunction3 = PyObject_GetAttrString(myModule, (char *)"get_addr");

  std::cout << "Boom " << myFunction2 << std::endl;

  PyObject *myResult = PyObject_CallObject(myFunction, nullptr);
  PyObject *myResult2 = PyObject_CallObject(myFunction2, nullptr);
  PyObject *myResult3 = PyObject_CallObject(myFunction3, nullptr);

  std::cout << "result is " << myResult << std::endl;
  std::cout << "result2 is " << myResult2 << std::endl;
  std::cout << "result3 is " << myResult3 << std::endl;

  PyRun_SimpleString("print('id=%s' % id(test2.x2))");

  double result = PyFloat_AsDouble(myResult);

  std::cout << "Double is " << result << std::endl;
  auto addr = PyLong_AsLong(myResult3);

  auto complex = reinterpret_cast<Complex *>(addr);
  std::cout << "Addr is " << addr << std::endl;

  auto sw = reinterpret_cast<SwigPyObject *>(addr);
  auto complex2 = reinterpret_cast<Complex*>(sw->ptr);

  std::cout << "ptris" << sw->ptr << std::endl;
  std::cout << "Addr is " << addr << std::endl;

  complex->x = 10;
  complex->y = 20;

  std::cout << "x=" << complex->getX() << " y=" << complex->getY() << std::endl;
  std::cout << "c=" << complex->toString() << std::endl;

  std::cout << "x2=" << complex2->getX() << " y2=" << complex2->getY() << std::endl;
  std::cout << "c2=" << complex2->toString() << std::endl;
  
  PyRun_SimpleString("test2.do_print()\n");

  Py_Finalize();
  return 0;
}
