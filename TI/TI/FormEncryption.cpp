#include "FormEncryption.h"

using namespace System;
using namespace System::Windows::Forms;


[STAThreadAttribute]
void EncryptionMain() {
	Application::SetCompatibleTextRenderingDefault(false);
	Application::EnableVisualStyles();
	TI::FormEncryption frm;
	Application::Run(% frm);
}