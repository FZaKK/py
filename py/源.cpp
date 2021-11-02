#include<iostream>
#include <Python.h>

using namespace std;

int main()
{
	//***python调用***//
	//初始化python模块
	Py_Initialize();
	// 检查初始化是否成功  
	if (!Py_IsInitialized())
	{
		cout << "初始化失败" << endl;
		Py_Finalize();
	}

	PyObject* pModule;
	PyObject* pFunc = NULL;
	PyObject* pArg = NULL;
	PyRun_SimpleString("import sys");
	PyRun_SimpleString("sys.path.append('./')");//设置python模块，搜寻位置，文件放在.cpp文件一起


	pModule = PyImport_ImportModule("demo_test");//Python文件名     
	if (!pModule) {
		cout << "py文件导入失败" << endl;
		Py_Finalize();
	}
	else {
		pFunc = PyObject_GetAttrString(pModule, "run");//Python文件中的函数名  
		if (!pFunc) {
			cout << "函数导入失败" << endl;
			Py_Finalize();
		}

		PyObject* pyParams = Py_BuildValue("(s)", "helllo world!");//c++类型转python类型

		char* result1;
		pArg = PyObject_Call(pFunc, pyParams,NULL);//调用函数
		PyArg_Parse(pArg, "s", &result1);//python类型转c++类型
		cout << result1 << endl;


		system("pause");
	}
}