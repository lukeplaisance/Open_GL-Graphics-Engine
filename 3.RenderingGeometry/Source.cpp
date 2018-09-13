
#include "RenderingGeometryApp.h"


int main()
{
	unsigned int num;

	Application *app = new RenderingGeometryApp();
	app->run("draw a plane", 800, 600, false);
}
