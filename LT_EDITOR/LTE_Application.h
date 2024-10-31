#pragma once
#include "LTE_EDITOR.h"

class LTE_Application
{
	sf::RenderWindow* m_Window = nullptr;

	sf::Event* m_Event = nullptr;


	LTE_Editor* m_Editor = nullptr;


	void Awake();

	void Update();

	void Destroy();

public:

	void Start();
};