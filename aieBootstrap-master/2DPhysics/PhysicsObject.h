#pragma once
#include <glm/vec2.hpp>

class PhysicsObject
{
protected:
	PhysicsObject() {};

public:
	// pure virtual - must be implemented in deriving class.
	virtual void fixedUpdate(glm::vec2 gravity, float timeStep) = 0;
	// pure virtual - must be implemented in deriving class.
	virtual void draw() = 0;
	// Can be overriden but not mandatory.
	virtual void resetPosition() {};
};