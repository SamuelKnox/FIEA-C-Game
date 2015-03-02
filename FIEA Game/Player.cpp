#include "Player.h"

Player::Player()
{
}


Player::~Player()
{
}

void Player::SetName(std::string name){
	name_ = name;
}
std::string Player::GetName(){
	return name_;
}