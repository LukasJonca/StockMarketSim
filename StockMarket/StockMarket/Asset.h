#pragma once
#include "IAsset.h"
#include <string>
class Asset : IAsset{
private:
	double price;
	int quantity;
	std::string name, type;
	
public:
	Asset();
	~Asset();
	Asset(std::string name, double p, std::string t);

	void setPrice(double p) override;
	void setName(std::string n) override;
	double getPrice() override;
	std::string getName() override;
	int getQuantity() override;
	void setQuantity(int n) override;
	void operator+(int n) override;
	void operator-(int n) override;
	std::string getType() override;

	virtual std::string getSymbol() { return NULL; }
	virtual double movePrice(int days) = 0;
	virtual void printInfo() = 0;
};
