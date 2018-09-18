#include "GUIApplication.h"
#include <iostream>
int main()
{
	Shader *shader = new Shader();
	shader->load("VERTEX.txt");

	Application* app = new GUIApplication();
	app->run("gui app", 1080, 720, false);
}