#include<iostream>
#include <Python.h>

using namespace std;

int main()
{
	//***python����***//
	//��ʼ��pythonģ��
	Py_Initialize();
	// ����ʼ���Ƿ�ɹ�  
	if (!Py_IsInitialized())
	{
		cout << "��ʼ��ʧ��" << endl;
		Py_Finalize();
	}

	PyObject* pModule;
	PyObject* pFunc = NULL;
	PyObject* pArg = NULL;
	PyRun_SimpleString("import sys");
	PyRun_SimpleString("sys.path.append('./')");//����pythonģ�飬��Ѱλ�ã��ļ�����.cpp�ļ�һ��


	pModule = PyImport_ImportModule("demo_test");//Python�ļ���     
	if (!pModule) {
		cout << "py�ļ�����ʧ��" << endl;
		Py_Finalize();
	}
	else {
		pFunc = PyObject_GetAttrString(pModule, "run");//Python�ļ��еĺ�����  
		if (!pFunc) {
			cout << "��������ʧ��" << endl;
			Py_Finalize();
		}

		PyObject* pyParams = Py_BuildValue("(s)", "helllo world!");//c++����תpython����

		char* result1;
		pArg = PyObject_Call(pFunc, pyParams,NULL);//���ú���
		PyArg_Parse(pArg, "s", &result1);//python����תc++����
		cout << result1 << endl;


		system("pause");
	}
}