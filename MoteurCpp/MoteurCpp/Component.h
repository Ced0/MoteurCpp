#pragma once
#include <string>

class Component
{
	unsigned int id;

public:

	int getId();

	bool operator== (const Component& other) const;
	
};

