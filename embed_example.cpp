#include <Python.h>
#include <iostream>

int
main(int argc, char *argv[])
{
    Py_SetProgramName( (wchar_t*)argv[0]);  /* optional but recommended */
  Py_Initialize();
  PyRun_SimpleString("from time import time,ctime\n"
                     "print('Today is',ctime(time()))\n");
  
  auto x = PyRun_SimpleString("import sys\nsys.path.append('/home/andy/repos/swigexperiment')\n");
  PyRun_SimpleString("print(sys.path)");

  PyObject* myModuleString = PyUnicode_DecodeFSDefault("test2");
  std::cout << "Bing " << myModuleString << std::endl;
  PyObject* myModule = PyImport_Import(myModuleString);
  std::cout << "Bam " << myModule  << std::endl;

  PyObject* myFunction = PyObject_GetAttrString(myModule,(char*)"ret");
  std::cout << "Boom" << std::endl;
  
  PyObject* myResult = PyObject_CallObject(myFunction, nullptr);

  std::cout << "result is " << myResult << std::endl;
  
  double result = PyFloat_AsDouble(myResult);
  
  std::cout << "Double is " << result << std::endl;
  
  Py_Finalize();
  return 0;
}
