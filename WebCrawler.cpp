#include "WebCrawler.h"

using namespace System;
using namespace System::Windows::Forms;

void main()
{
	Application::EnableVisualStyles();
	Application::SetCompatibleTextRenderingDefault(false);
	PROJECT_DS::WebCrawler form;
	Application::Run(% form);
}
