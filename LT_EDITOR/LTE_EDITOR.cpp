#include "LTE_EDITOR.h"

LTE_Editor::LTE_Editor(sf::RenderWindow* window, sf::Event* event)
{
	m_Window = window;

	m_Event = event;


	m_Logo = new sf::Image();

	m_Logo->loadFromFile("res/LTE_Logo.png");

	window->setIcon(64U, 64U, m_Logo->getPixelsPtr());

	m_Sbackground = new sf::RectangleShape();

	m_EgridX = new sf::RectangleShape();
	m_EgridY = new sf::RectangleShape();

	m_CBgrid = new WcheckBox();
}

LTE_Editor::~LTE_Editor()
{
	delete m_Logo;
	delete m_Sbackground;
}

void LTE_Editor::Start()
{
	m_Sbackground->setSize(sf::Vector2f(200.0f, m_Window->getSize().y));
	m_Sbackground->setPosition(m_Window->getSize().x - 200.0f, 0.0f);
	m_Sbackground->setFillColor(sf::Color(28U, 27U, 34U));

	m_EgridX->setSize(sf::Vector2f(1.0f, m_Window->getSize().y));
	m_EgridX->setPosition((m_Window->getSize().x / 2.0f) - 100.0f, 0.0f);
	m_EgridX->setFillColor(sf::Color::Black);

	m_EgridY->setSize(sf::Vector2f(m_Window->getSize().x - 200.0f, 1.0f));
	m_EgridY->setPosition(0.0f, m_Window->getSize().y / 2.0f);
	m_EgridY->setFillColor(sf::Color::Black);

	
	m_CBgrid->Start(sf::Vector2f(m_Window->getSize().x - 190.0f, 10.0f), "not Grid");
}

void LTE_Editor::Update()
{

}

void LTE_Editor::Events()
{
	m_CBgrid->Event(m_Event, m_Window);
}

void LTE_Editor::Draw()
{
	m_Window->draw(*m_Sbackground);

	if (!m_CBgrid->m_Value)
	{
		m_Window->draw(*m_EgridX);
		m_Window->draw(*m_EgridY);
	}

	m_CBgrid->Draw(m_Window);
}
