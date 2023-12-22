#include "MyForm.h"
#include "FormGraph.h"
#include "FormEncryption.h"
#include "FormTree.h"


using namespace System;
using namespace System::Windows::Forms;
[STAThreadAttribute]

int main() {
	Application::SetCompatibleTextRenderingDefault(false);
	Application::EnableVisualStyles();
	TI::MyForm frm;
	Application::Run(% frm);
	return 0;
}