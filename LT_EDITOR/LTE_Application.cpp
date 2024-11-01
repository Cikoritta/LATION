#include "LTE_Application.h"
#include "EazyConfig.h"

const sf::Uint16 CREATE_WIDTH = stoi(Config::Read(L"lteConfig.ini", L"CREATE_WIDTH"));
const sf::Uint16 CREATE_HEIGHT = stoi(Config::Read(L"lteConfig.ini", L"CREATE_HEIGHT"));

const bool VSYNC = stoi(Config::Read(L"lteConfig.ini", L"VSYNC"));

const sf::Uint16 FRAME_RATE = stoi(Config::Read(L"lteConfig.ini", L"FRAME_RATE"));

void LTE_Application::Awake()
{
	m_Window = new sf::RenderWindow(sf::VideoMode(CREATE_WIDTH, CREATE_HEIGHT), "Lation Editor");

	m_Window->setVerticalSyncEnabled(VSYNC);

	m_Window->setFramerateLimit(FRAME_RATE);


	m_Event = new sf::Event();

	m_Editor = new LTE_Editor(m_Window, m_Event);
}

void LTE_Application::Update()
{
	while (m_Window->isOpen())
	{
		if (!m_Editor->ifStart)
		{
			m_Editor->Start();

			m_Editor->ifStart = true;
		}

		m_Editor->Update();

		m_Window->clear(sf::Color::White);

		m_Editor->Draw();

		m_Window->display();

		while (m_Window->pollEvent(*m_Event))
		{
			if (m_Event->type == m_Event->Closed)
			{
				m_Window->close();
			}

			if (m_Event->type == m_Event->Resized)
			{
				m_Window->setView(sf::View(sf::FloatRect(0.0f, 0.0f, m_Event->size.width, m_Event->size.height)));

				m_Editor->ifStart = false;
			}

			m_Editor->Events();
		}
	}
}

void LTE_Application::Destroy()
{
	delete m_Window;
	delete m_Event;
	delete m_Editor;
}

void LTE_Application::Start()
{
	Awake();

	Update();

	Destroy();
}
