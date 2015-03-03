#include "Player.h"

void Player::SetName(std::string name){
	name_ = name;
}
std::string Player::GetName() const{
	return name_;
}