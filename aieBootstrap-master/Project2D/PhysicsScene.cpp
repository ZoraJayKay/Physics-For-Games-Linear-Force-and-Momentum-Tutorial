#include "PhysicsScene.h"
#include "glm/geometric.hpp"

// Constructor
PhysicsScene::PhysicsScene() {
	// Initialise the timestep to 0.01.
	setTimeStep(0.01f);

	// Initialise gravity to (0,0) {0 on x, 0 on y}.
	setGravity({ 0,0 });
};

// Destructor
PhysicsScene::~PhysicsScene() {
	for (auto pActor : m_actors) {
		delete pActor;
		pActor = nullptr;
	}
};

void PhysicsScene::addActor(PhysicsObject* actor) {
	m_actors.push_back(actor);
};

// Iterate through all of the actors in the vector and if this one is found, remove it and then stop the function.
void PhysicsScene::removeActor(PhysicsObject* actor) {
	int temp = 0;

	for (PhysicsObject* _actor : m_actors) {
		if (_actor == actor) {
			m_actors.erase(m_actors.begin(), m_actors.begin() + temp);
			return;
		}

		else {
			temp++;
		}
	}
};

// Update the position of each actor in the vector of actors.
void PhysicsScene::update(float dt) {
	// Update physics at a fixed time step by...
	// Establishing desired rendering frequency.
	static float accumulatedTime = 0.0f;
	// Update the render timer.
	accumulatedTime += dt;

	// When the render timer exceeds the render frequency, update the calculations of each actor and then reset the render timer
	while (accumulatedTime >= m_timeStep) {
		for (auto pActor : m_actors) {
			pActor->fixedUpdate(m_gravity, m_timeStep);
		}

		accumulatedTime -= m_timeStep;

		// ******** COLLISION DETECTION ******** 
		// Check for collisions (AIE: "Ideally you would want some kind of scene management in place")
		int actorCount = m_actors.size();

		// Check for collisions between this object and all other except for itself
		for (int outer = 0; outer < actorCount - 1; outer++) {
			// Only assess each pair of objects once (add +1 to outer).
			for (int inner = outer + 1; inner < actorCount; inner++) {
				PhysicsObject* object1 = m_actors[outer];
				PhysicsObject* object2 = m_actors[inner];

				// Assume that both objets are spheres until other shapes are implemented
				sphere2Sphere(object1, object2);
			}
		}

		// ******** COLLISION DETECTION ******** 
	}
};

// Draw each actor in the vector of actors.
void PhysicsScene::draw() {
	for (auto pActor : m_actors) {
		pActor->draw();
	}
};

bool PhysicsScene::sphere2Sphere(PhysicsObject* obj1, PhysicsObject* obj2) {
	// Try to cast objects to spheres
	Sphere* sphere1 = dynamic_cast<Sphere*>(obj1);
	Sphere* sphere2 = dynamic_cast<Sphere*>(obj2);

	// If that's successful, test for collision
	if (sphere1 != nullptr && sphere2 != nullptr) {
		// If the distance between the centre of the spheres is <= the sum of their radii then the spheres have collided.
		if (glm::distance(sphere2->getPosition(), sphere1->getPosition()) <= (sphere2->GetRadius() + sphere1->GetRadius())){
			// If the spheres touch, set their velocities to zero (by applying a force equal to negative velocity)
			sphere1->applyForceToActor(sphere2, -sphere2->getVelocity());
		};
	}

	return false;
};

void PhysicsScene::setGravity(const glm::vec2 gravity) { m_gravity = gravity; };
glm::vec2 PhysicsScene::getGravity() const { return m_gravity; };
void PhysicsScene::setTimeStep(const float timeStep) { m_timeStep = timeStep; };
float PhysicsScene::getTimeStep() const { return m_timeStep; };