#pragma once
#include <iostream>
#include <map>
#include <string>
#include "Position.h"

class Account {

private:
	double balance;
	std::map <std::string, Position> portfolio;
public:
	Account();
	double getBal();
	//void addPosition();
	//void remPosition();

};
