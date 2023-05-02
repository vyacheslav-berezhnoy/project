#include "MyForm.h"
using namespace System;
using namespace System::Windows::Forms;
[STAThreadAttribute]

void main(array<String^>^ args)
{
	Application::SetCompatibleTextRenderingDefault(false);
	Application::EnableVisualStyles();
	//WinformCDemo is your project name
	GUI1::MyForm frm;
	Application::Run(% frm);

}

