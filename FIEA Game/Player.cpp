#include "Player.h"

Player::Player()
{
}


Player::~Player()
{
}

void Player::set_name(std::string _name){
	name = _name;
}
std::string Player::get_name(){
	return name;
}