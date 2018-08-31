#include "IntroductionApp.h"
#include "Transform.h"
#include <glm/glm.hpp>
#include <Gizmos.h>
#include <glfw3.h>

//finish header file
//make main work that abides to the header file

IntroductionApp::IntroductionApp()
{
}

IntroductionApp::~IntroductionApp()
{
}


void IntroductionApp::startup()
{
	Gizmos::create();
	model = glm::mat4(1);
	m_Camera->setLookAt(glm::vec3(10, 10, 10), glm::vec3(0), glm::vec3(0, 1, 0));
	m_Camera->setProjectionMatrix(m_Camera->getProjection(), glm::pi<float>()*0.25f, 16 / 9.0f, 0.1f, 1000.0f);
	m_Camera->setSpeed(0.1f);
}

void IntroductionApp::shutdown()
{
	Gizmos::destroy();
}

void IntroductionApp::draw()
{
	Gizmos::clear();	
	Gizmos::addSphere(glm::vec3(0, 0, 0), 5, 15, 10, glm::vec4(1, 0, 0, 1), &model);
	for (int i = 0; i < 21; ++i) {
		Gizmos::addLine(glm::vec3(-10 + i, 0, 10),
			glm::vec3(-10 + i, 0, -10),
			i == 10 ? glm::vec4(1, 1, 1, 1) : glm::vec4(0, 0, 0, 1));
		Gizmos::addLine(glm::vec3(10, 0, -10 + i),
			glm::vec3(-10, 0, -10 + i),
			i == 10 ? glm::vec4(1, 1, 1, 1) : glm::vec4(0, 0, 0, 1));
	}
	Gizmos::draw(m_Camera->getProjection() * m_Camera->getView() * m_Camera->getWorldTransform());

}

void IntroductionApp::update(float dt)
{
	Transform trans = Transform();
	trans.setWorld(model);
	trans.translate(glm::vec3(10, 0, 10));
	//trans.rotate(dt , glm::vec3(0,1,0));
	model = trans.World;
}
