#include "LTE_WindowClass.h"

WcheckBox::WcheckBox()
{
	m_Texture = new sf::Texture();

	m_Sprite = new sf::Sprite();

	m_Text = new sf::Text();

	m_Font = new sf::Font();
}

WcheckBox::~WcheckBox()
{
	delete m_Texture;
	delete m_Sprite;
	delete m_Text;
	delete m_Font;
}

void WcheckBox::Start(sf::Vector2f position, sf::String string)
{
	m_Texture->loadFromFile("res/checkBox.png", sf::IntRect(0, 0, 32, 32));

	m_Sprite->setTexture(*m_Texture);
	m_Sprite->setTextureRect(sf::IntRect(0, 0, 32, 32));
	m_Sprite->setPosition(position);
	m_Sprite->setScale(0.55f, 0.55f);

	m_Text->setString(string);
	m_Font->loadFromFile("res/ARIAL.TTF");
	m_Text->setFont(*m_Font);
	m_Text->setPosition(position.x + 25.0f, position.y);
	m_Text->setFillColor(sf::Color::White);
	m_Text->setCharacterSize(15U);
}

void WcheckBox::Event(sf::Event* event, sf::RenderWindow* window)
{
	if (m_Sprite->getGlobalBounds().contains(sf::Vector2f(sf::Mouse::getPosition(*window).x, sf::Mouse::getPosition(*window).y)))
	{
		if (event->type == sf::Event::MouseButtonPressed && event->mouseButton.button == sf::Mouse::Left)
		{
			if (m_Value)
			{
				m_Sprite->setTextureRect(sf::IntRect(0, 0, 32, 32));

				m_Value = false;
			}
			else
			{
				m_Sprite->setTextureRect(sf::IntRect(32, 32, 32, 32));

				m_Value = true;
			}
		}
	}
}

void WcheckBox::Draw(sf::RenderWindow* window)
{
	window->draw(*m_Sprite);
	window->draw(*m_Text);
}
