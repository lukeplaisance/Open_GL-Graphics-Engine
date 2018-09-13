#pragma once

#include "Application.h"

class GUIApplication : public Application
{
	// Inherited via Application
	virtual void startup() override;
	virtual void shutdown() override;
	virtual void update(float dt) override;
	virtual void draw() override;
};
