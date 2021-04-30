#pragma once
#include "IAsset.h"
#include <string>
class Asset {
private:
	double price;
	int quantity;
	std::string name, type;
	
public:
	Asset();
	Asset(std::string name, double p, std::string t);
	void setPrice(double p);
	void setName(std::string n);
	double getPrice();
	std::string getName();
	int getQuantity();
	void setQuantity(int n);
	void operator+(int n);
	void operator-(int n);
	//bool operator = (std::string a);
	virtual double movePrice(int days) { return 0; }
};
