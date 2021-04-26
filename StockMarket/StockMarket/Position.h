#pragma once
#include "IAsset.h"
class Position {
private:
	IAsset asset;
	int quantity;
public:
	Position();
	Position(IAsset a, int q);
	double getVal();
};