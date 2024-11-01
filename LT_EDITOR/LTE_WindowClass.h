#pragma once
#include <SFML/Graphics.hpp>

class WcheckBox
{
	sf::Texture* m_Texture = nullptr;

	sf::Sprite* m_Sprite = nullptr;

	sf::Text* m_Text = nullptr;

	sf::Font* m_Font = nullptr;

public:

	bool m_Value = false;

	WcheckBox();

	~WcheckBox();

	void Start(sf::Vector2f position, sf::String string);

	void Event(sf::Event* event, sf::RenderWindow* window);

	void Draw(sf::RenderWindow* window);
};