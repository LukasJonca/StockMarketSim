#pragma once
#include "Asset.h"
#include "IAsset.h"
#include <string>

class Stock : public Asset {
private:
	std::string symbol;
	int top, bottom;

public:

	Stock(std::string n, std::string s, double p, int t, int b);
	
	void movePrice(int days);

};