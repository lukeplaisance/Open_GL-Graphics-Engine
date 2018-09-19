#include "GUIApplication.h"
#include <iostream>
int main()
{
	
	Application* app = new GUIApplication();
	app->run("gui app", 1080, 720, false);
}