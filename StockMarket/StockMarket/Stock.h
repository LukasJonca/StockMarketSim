#pragma once
#include "Asset.h"
#include "IAsset.h"
#include <string>

class Stock : public Asset {
private:
	std::string symbol;
	int top, bottom;
	

public:
	Stock();
	Stock(std::string n, std::string s, double p, int t, int b);
	std::string getSymbol();
	double movePrice(int days);

};