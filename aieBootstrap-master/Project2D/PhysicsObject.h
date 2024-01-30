#pragma once
#include <glm/vec2.hpp>

// Collision detection categorisation labels.
enum ShapeType {
	PLANE,
	SPHERE,
	BOX
};

// This is the base class for both derived dynamic rigibody physics objects and static plane objects.
// A single base class permits the use of a single polymorphic list when updating and adding gizmos to the scene. This permits the neatest form of collision detection routines.
class PhysicsObject
{

protected:
	// Constructor including assignment of collision detection classification.
	PhysicsObject(ShapeType a_shapeID) : m_shapeID(a_shapeID) {};
	PhysicsObject() {};

public:
	// pure virtual - must be implemented in deriving class.
	virtual void fixedUpdate(glm::vec2 gravity, float timeStep) = 0;
	// pure virtual - must be implemented in deriving class.
	virtual void draw() = 0;
	// Can be overriden but not mandatory.
	virtual void resetPosition() {};

	ShapeType m_shapeID;
};