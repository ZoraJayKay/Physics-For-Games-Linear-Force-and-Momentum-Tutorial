#pragma once
#include "PhysicsObject.h"

// Derived class from PhysicsObject.
class RigidBody : public PhysicsObject
{
public:
	RigidBody(
		ShapeType shapeID,
		glm::vec2 position,
		glm::vec2 velocity,
		float orientation,
		float mass);

	RigidBody();
	~RigidBody();

	// Inherited overrides.
	virtual void fixedUpdate(glm::vec2 gravity, float timeStep);

	// RigidBody methods.
	void applyForce(glm::vec2 force);
	void applyForceToActor(RigidBody* actor2, glm::vec2 force);

	glm::vec2 getPosition();
	float getOrientation();
	glm::vec2 getVelocity();
	float getMass();

protected:
	glm::vec2 m_position;
	glm::vec2 m_velocity;
	float m_mass;
	float m_orientation;
};

