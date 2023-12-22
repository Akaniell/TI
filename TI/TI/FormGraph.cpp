#include "FormGraph.h"

const int MAX = 100;

using namespace System;
using namespace System::Windows::Forms;


[STAThreadAttribute]
void GraphMain() {
	Application::SetCompatibleTextRenderingDefault(false);
	Application::EnableVisualStyles();
	TI::FormGraph frm;
	Application::Run(% frm);
}