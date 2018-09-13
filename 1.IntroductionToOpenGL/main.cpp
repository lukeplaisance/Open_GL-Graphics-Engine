#include "IntroductionApp.h"

//we need a base class to inherit from
//this baseclass will provide all the functionality we need to make seperate instances of our programs
//we will have a 1.IntroToOpenGL program
//-each program will have a class associated with it that will be used to draw
//we will have a 2.CamerasAndProjection program

int main()
{
	auto * app = new IntroductionApp();
	app->run("Intro to OpenGL", 800, 600, false);
}


