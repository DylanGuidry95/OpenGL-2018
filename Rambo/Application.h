#pragma once
//IntroApp : Application{
//coid startup() (printf("welcome to jurassic park");)
//}
struct GLFWwindow;

class Application
{
	Application();
	virtual ~Application();
	void run(const char * title, unsigned int width, unsigned int height, bool fullscreen);
	void clearScreen();
protected:
	virtual void startup() = 0;
	virtual void shutdown() = 0;
	virtual void update(float dt) = 0;
	virtual void draw() = 0;
	GLFWwindow* m_window;
	bool m_gameOver;
	float m_clearColor[4];
	float m_runningTime;
};