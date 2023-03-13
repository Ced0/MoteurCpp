#pragma once
#include <string>

class Component
{
public:
	virtual ~Component();

	inline std::string getType() { return type; };

protected:
	std::string type = "none";
};

