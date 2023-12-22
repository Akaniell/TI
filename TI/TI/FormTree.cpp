#include "FormTree.h"
#include "Tree.h"

using namespace System;
using namespace System::Windows::Forms;


[STAThreadAttribute]
void TreeMain() {
	Application::SetCompatibleTextRenderingDefault(false);
	Application::EnableVisualStyles();
	TI::FormTree frm;
	Application::Run(% frm);
}