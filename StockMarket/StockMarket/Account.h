#pragma once
#include <iostream>
#include <vector>
#include <string>
#include "Stock.h"
#include "Asset.h"

class Account {

private:
	double balance;
	std::vector <Asset> portfolio;

public:
	Account();
	double getBal();
	double getVal();
	void chgBal(double change);
	void order(int n, int i, Account &a);
	void print();
	int NAssets();

};
