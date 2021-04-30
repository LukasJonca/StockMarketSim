#pragma once
#include "Asset.h"
#include "IAsset.h"
#include <string>

class Bond : public Asset {
private:
	int originalTerm, term, daysTillPayout;
	double yield;
	//double payment;

public:
	Bond();
	Bond(std::string n, double p, int term, double yield);
	double movePrice(int days);
	
};