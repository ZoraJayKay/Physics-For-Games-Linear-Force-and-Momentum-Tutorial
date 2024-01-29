#include "PhysicsScene.h"

// Constructor
PhysicsScene::PhysicsScene() {
	// Initialise the timestep to 0.01.
	setTimeStep(0.01f);

	// Initialise gravity to (0,0) {0 on x, 0 on y}.
	setGravity({ 0,0 });
};

// Destructor
PhysicsScene::~PhysicsScene() {};

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
	}
};

// Draw each actor in the vector of actors.
void PhysicsScene::draw() {
	for (auto pActor : m_actors) {
		pActor->draw();
	}
};

void PhysicsScene::setGravity(const glm::vec2 gravity) { m_gravity = gravity; };
glm::vec2 PhysicsScene::getGravity() const { return m_gravity; };

void PhysicsScene::setTimeStep(const float timeStep) { m_timeStep = timeStep; };
float PhysicsScene::getTimeStep() const { return m_timeStep; };