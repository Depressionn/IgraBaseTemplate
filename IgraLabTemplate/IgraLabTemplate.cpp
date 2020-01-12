// IgraLabTemplate.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
#include "pch.h"
void ResizeGLScene(GLsizei width, GLsizei height) {
	if (height == 0)
		height = 1;

	//reset viewport
	glViewport(0, 0, width, height);

	//use projection matrix
	glMatrixMode(GL_PROJECTION);

	//reset matrix
	glLoadIdentity();

	//calculate aspect ratio
	gluPerspective(45.0f, (GLfloat)width / (GLfloat)height, 0.1f, 100.0f);
}

void Render() {
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glClearColor(1, 1, 1, 1);

	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	gluLookAt(
		5, 5, 5,
		0, 0, 0,
		0, 1, 0
	);

#pragma region Axis
	glBegin(GL_LINES);
	{
		//x
		glColor3f(1, 0, 0);
		glVertex3f(0, 0, 0);
		glVertex3f(100, 0, 0);
		//y
		glColor3f(0, 1, 0);
		glVertex3f(0, 0, 0);
		glVertex3f(0, 100, 0);
		//z
		glColor3f(0, 0, 1);
		glVertex3f(0, 0, 0);
		glVertex3f(0, 0, 100);
	}
	glEnd();
#pragma endregion
}

int main(){
	//settings
	sf::ContextSettings contextSettings;
	contextSettings.majorVersion = 1;
	contextSettings.minorVersion = 0;
	contextSettings.depthBits = 24;
	contextSettings.stencilBits = 8;

	sf::RenderWindow window(sf::VideoMode(W_WIDTH, W_HEIGHT), "Window", sf::Style::Default, contextSettings);
#pragma region InitOpenGl
	glClearDepth(1.0f);
	glEnable(GL_DEPTH_TEST);
	glDepthFunc(GL_LEQUAL);
	glHint(GL_PERSPECTIVE_CORRECTION_HINT, GL_NICEST);
	//glEnable(GL_CULL_FACE);

	//lighting
	glShadeModel(GL_SMOOTH);
	GLfloat LightAmbient[] = { 0.5f, 0.5f, 0.5f, 1 };
	GLfloat LightDiffuse[] = { 0.5f, 0.5f, 0.5f, 1 };
	GLfloat LightSpecular[] = { 0.5f, 0.5f, 0.5f, 1 };
	GLfloat LightPosition[] = { 10, 10, 10, 0 };
	glLightfv(GL_LIGHT0, GL_AMBIENT, LightAmbient);
	glLightfv(GL_LIGHT0, GL_DIFFUSE, LightDiffuse);
	glLightfv(GL_LIGHT0, GL_SPECULAR, LightSpecular);
	glLightfv(GL_LIGHT0, GL_POSITION, LightPosition);
	glEnable(GL_LIGHT0);
	ResizeGLScene(W_WIDTH, W_HEIGHT);
#pragma endregion
	Time::Start();

	bool isRunning = true;
	while (isRunning) {
		//update time
		Time::UpdateDeltaTime();
		sf::Event event;
		while (window.pollEvent(event)) {
			switch (event.type) {
			case sf::Event::Closed:
			{
				isRunning = false;
			}
			break;
			case sf::Event::Resized:
			{
				ResizeGLScene(event.size.width, event.size.height);
			}
			break;
			case sf::Event::KeyPressed:
			{

			}
			break;
			default:
				break;
			}
		}
		Render();
		window.display();
	}

	glDisable(GL_DEPTH_TEST);

	return 0;
}