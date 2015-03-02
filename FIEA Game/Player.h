#pragma once

#include <string>

class Player
{
private:
	std::string name_;
public:
	Player();
	~Player();
	std::string GetName();
	void SetName(std::string);
};

