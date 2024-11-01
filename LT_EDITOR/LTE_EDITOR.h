#pragma once
#include <SFML/Graphics.hpp>
#include "LTE_WindowClass.h"

class LTE_Editor
{
	sf::RenderWindow* m_Window;

	sf::Event* m_Event;


	sf::Image* m_Logo;

	sf::RectangleShape* m_Sbackground = nullptr;

	sf::RectangleShape* m_EgridX = nullptr;
	sf::RectangleShape* m_EgridY = nullptr;

	WcheckBox* m_CBgrid = nullptr;

public:

	LTE_Editor() = default;

	LTE_Editor(sf::RenderWindow* window, sf::Event* event);

	~LTE_Editor();


	bool ifStart = false;


	void Start();

	void Update();

	void Events();

	void Draw();
};