#pragma once

#include <string>

class Player
{
public:
	std::string GetName() const;
	void SetName(std::string name);
private:
	std::string name_;
};

