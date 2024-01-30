#include "Sphere.h"
#include "Gizmos.h"

// Construct a sphere and its rigidbody (and use its inherited rigidbody constructor with some fixed variables such as type and orientation).
Sphere::Sphere(	glm::vec2 position,	glm::vec2 velocity,	float mass,	float radius, glm::vec4 colour) : RigidBody(SPHERE, position, velocity, 0, mass) {
	m_radius = radius;
	m_colour = colour;
};

Sphere::Sphere() {};
Sphere::~Sphere() {};

float Sphere::GetRadius() { return m_radius; };
glm::vec4 Sphere::GetColour() { return m_colour; };

void Sphere::draw() {
	aie::Gizmos::add2DCircle(m_position, m_radius, 20, m_colour);
};