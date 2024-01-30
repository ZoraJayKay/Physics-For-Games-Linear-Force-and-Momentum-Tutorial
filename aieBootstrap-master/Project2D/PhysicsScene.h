#pragma once

#include <glm/vec2.hpp>	// obviously glm
#include <vector>	// standard vector
#include "PhysicsObject.h"
#include "Sphere.h"

class PhysicsScene {
	//class PhysicsObject;	// Forward declaration of the PhysicsObject class rather than #including it (disabled because I needed to use class members)

public:
	// Constructor
	PhysicsScene();

	// Destructor
	~PhysicsScene();

	void addActor(PhysicsObject* actor);
	void removeActor(PhysicsObject* actor);
	// Update the physical simulation, updating the actor's position according to its internal stat, including collision detection and response.

	void update(float dt);
	// Draw to the screen once per frame. Because we are batching draw calls, we want to add each gizmo to the remnder using an add function call during the update loop, then when drawing, the renderer can draw all objects at once.

	void draw();

	void setGravity(const glm::vec2 gravity);
	glm::vec2 getGravity() const;

	void setTimeStep(const float timeStep);
	float getTimeStep() const;

protected:
	glm::vec2 m_gravity;
	float m_timeStep;

	// Collection of PhysicsObject pointers, our 'actors' (all the physical objects in the scene)
	std::vector<PhysicsObject*> m_actors;

	static bool sphere2Sphere(PhysicsObject* obj1, PhysicsObject* obj2);
};