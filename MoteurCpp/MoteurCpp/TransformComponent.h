#pragma once
#include "Component.h"
#include <glm.hpp>

class TransformComponent : public Component
{
private :
	glm::vec2 position;
	float rotation;
	glm::vec2 scale;

public : 
	TransformComponent(int goId);

	TransformComponent(float positionX, float positionY, float rotation, float scaleX, float scaleY, int goId);
	
	~TransformComponent() {};

	const float getPositionX();

	const float getPositionY();

	const glm::vec2 getPosition();

	const float getRotation();

	const float getScaleX();

	const float getScaleY();

	const glm::vec2 getScale();

	void setPositionX(float x);

	void setPositionY(float y);

	void setPosition(float x, float y);

	void setRotation(float r);

	void setScaleX(float x);

	void setScaleY(float y);

	void setScale(float x, float y);
};

