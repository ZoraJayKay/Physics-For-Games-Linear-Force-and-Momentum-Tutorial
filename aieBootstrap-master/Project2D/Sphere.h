#pragma once
#include "RigidBody.h"
#include "glm/vec4.hpp"

class Sphere : public RigidBody
{	
protected:
	// Additional rigidbody variables for spheres.
	float m_radius;
	glm::vec4 m_colour;

public:
	// Constructor to initialise sphere.
	Sphere(
		glm::vec2 position, 
		glm::vec2 velocity, 
		float mass, 
		float radius, 
		glm::vec4 colour);

	// Default constructor.
	Sphere();
	~Sphere();

	// Additional rigidbody variables for spheres.
	float GetRadius();
	glm::vec4 GetColour();

	// Overriden PhysicsObject member variables.
	// Draw functions are unique per class because their draw requirements differ, unlike their physics.
	virtual void draw();
};