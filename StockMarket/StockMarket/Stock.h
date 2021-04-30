#pragma once
#include "Asset.h"
#include <string>

class Stock : public Asset {
private:
	std::string symbol;
	int top, bottom, daysUntilDividend;
	double dividend;
	

public:
	Stock();
	Stock(std::string n, std::string s, double p, int t, int b, double d);
	std::string getSymbol();

	double movePrice(int days) override;
	void printInfo() override;

};