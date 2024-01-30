#include "RigidBody.h"

// Custom constructor.
RigidBody::RigidBody(ShapeType shapeID,	glm::vec2 position,	glm::vec2 velocity,	float orientation, float mass) : PhysicsObject(shapeID) {	
	m_position = position;
	m_velocity = velocity;
	m_mass = mass;
	m_orientation = orientation;
};

// Default destructor.
RigidBody::~RigidBody() {};
RigidBody::RigidBody() {};

// Inherited overrides.
// Apply any forces to the actor before calculating the final position.
void RigidBody::fixedUpdate(glm::vec2 gravity, float timeStep) {
	// WHETHER GRAVITY IS APPLIED BEFORE OR AFTER UPDATING POSITION NTRODUCES A SYSTEMATIC ERROR.
	// Add the updated vector to the actor's position to get the new position of the actor.
	m_position += m_velocity * timeStep;
	
	// Apply gravity as a force by multiplying the object's mass first so that it acts as pure acceleration.
	glm::vec2 temp = gravity * m_mass * timeStep;
	this->applyForce(temp);	
};


// Apply Newton's Second Law: Modify the velocity of the object according to the object's mass and how much force has been applied.
void RigidBody::applyForce(glm::vec2 force) {
	// Calculate acceleration (a = f/m) and add it to the actor's velocity, effectively increasing the actor's momentum.
	m_velocity += (force / m_mass);
};

// Apply Newton's Third Law: Push another actor.
void RigidBody::applyForceToActor(RigidBody* actor2, glm::vec2 force) {
	// 1: Apply the input force to the input actor.
	actor2->applyForce(force);

	// 2: Apply the opposite force to the current actor.
	this->applyForce(-force);
};


glm::vec2 RigidBody::getPosition() { return m_position; };
float RigidBody::getOrientation() { return m_orientation; };
glm::vec2 RigidBody::getVelocity() { return m_velocity; };
float RigidBody::getMass() { return m_mass; };