#include "GUIApplication.h"
int main()
{
	Application* app = new GUIApplication();
	app->run("gui app", 800, 600, false);
}