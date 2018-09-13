#include "Transform.h"
int main()
{
	Transform* t = new Transform();
	t->Rotate(90, glm::vec3(1, 0, 0));
}