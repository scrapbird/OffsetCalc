#include "OffsetCalc.h"

using namespace System;
using namespace System::Windows::Forms;


[STAThread]
void Main(array<String^>^ args)
{
	Application::EnableVisualStyles();
	Application::SetCompatibleTextRenderingDefault(false);

	OffsetCalc::OffsetCalc form;
	Application::Run(%form);
}
