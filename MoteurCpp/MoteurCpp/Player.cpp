#include "Player.h"
#include "AsciiComponent.h"
#include "GameManager.h"

Player::Player(char c, glm::vec2 pos) : AsciiObject(c, pos)
{}

void Player::update(char a)
{
	AsciiComponent* comp = ((AsciiComponent*)components[0]);

	switch (a)
	{
	case 'z':
		comp->pos.y++;
		break;
	case 's':
		comp->pos.y--;
		break;
	}

	GameManager* manager = GameManager::getInstance();

	manager->setScreenValue(comp->pos, comp->c);
}