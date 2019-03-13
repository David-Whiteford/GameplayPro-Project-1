#ifndef GAME_H
#define GAME_H

#include <string>
#include <sstream>

//#define TINYC2_IMPL
#include <tinyc2.h>

#include <iostream>
#include <GL/glew.h>
#include <GL/wglew.h>


#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>

#include <SFML/Graphics.hpp>
#include <SFML/OpenGL.hpp>

#include <Debug.h>

#define STB_IMAGE_IMPLEMENTATION
#include <stb_image.h>

#include <GameObject.h>

using namespace std;
using namespace sf;
using namespace glm;

class Game
{
public:
	Game();
	Game(sf::ContextSettings settings);
	~Game();
	void run();
	
private:
	GameObject* game_object[50];
	GameObject* playerObject;
	GameObject* obstacleObject[3];
	RenderWindow window;
	sf::Texture texture;
	sf::RectangleShape playerRect;
	sf::RectangleShape obstacleRect;

	c2AABB aabb_ground;
	c2AABB aabb_player;
	int result{ 0 };

	Clock clock;
	Time time;
	bool animate = false;
	vec3 animation = vec3(0.0f);
	float rotation = 0.0f;
	float xPos{ 0.0f };
	float yPos{ 0.0f };
	bool isRunning = false;
	int m_timer{ 0 };
	void initialize();
	void update();
	void render();
	void unload();
	void setUpcontent();
	enum AiMove
	{
		MoveUp,
		MoveDown
	}
	m_blockMove;
	enum MoveStates
	{
		Jumping,
		Falling,
		Stationary

	}
	m_moveState;


};

#endif  // ! GAME_H