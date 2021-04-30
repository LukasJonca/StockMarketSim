#pragma once
#include <iostream>
#include <vector>
#include <string>
#include "Asset.h"
#include "Stock.h"
#include "Bond.h"
#include "Account.h"


class Menu {
private:
	int amount, option, m = 0;
	Account user;
public:
	Menu();
	void printMenu();
	void optionsMenu();
};