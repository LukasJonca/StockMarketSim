#pragma once
//#include "Account.h"
#include <string>
class Asset {
private:
	double price;
	int quantity;
	std::string name;
public:
	Asset();
	Asset(std::string name, double p);
	void setPrice(double p);
	void setName(std::string n);
	double getPrice();
	std::string getName();
	int getQuantity();
	void buy(int n);
	void sell(int n);
};
