#pragma once
#include <iostream>
#include <vector>
#include <string>
#include "Stock.h"
#include "Bond.h"
#include "Asset.h"

class Account {

private:
	double balance;
	std::vector <Asset*> portfolio;
	Stock food, tech, real;
	Bond gove, bank, mort;


public:
	Account();
	double getBal();
	double getVal();
	void chgBal(double change);
	void order(int n, int i, Account &a);
	void print();
	int NAssets();
	void time(int n);
};
