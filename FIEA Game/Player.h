#pragma once

#include <string>

class Player
{
private:
	std::string name;
public:
	Player();
	~Player();
	void set_name(std::string);
	std::string get_name();
};

