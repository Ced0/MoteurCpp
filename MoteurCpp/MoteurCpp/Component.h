#pragma once
#include <string>

class Component
{
private:
	static unsigned int index;
	unsigned int id;
	unsigned int goId;

public:
	Component();

	Component(unsigned int index);

	~Component() {};

	const unsigned int getId();

	const unsigned int getgoId();

	void setgoId(unsigned int id);

	bool operator== (const Component& other) const;
	
};

