#pragma once
#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/Window/Event.hpp>
#include <SFML/Graphics/Sprite.hpp>

class LTE_Editor
{
	sf::RenderWindow* m_Window;

	sf::Event* m_Event;




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