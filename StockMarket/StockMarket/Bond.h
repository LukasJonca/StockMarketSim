#pragma once
#include "Asset.h"
#include "IAsset.h"
#include <string>

class Bond : public Asset {
private:
	int originalTerm, term, daysTillPayout;
	double yield;

public:

	Bond(std::string n, double p, int term, int yield);
	double movePrice(int days);
	
};