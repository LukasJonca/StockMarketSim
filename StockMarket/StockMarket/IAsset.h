#pragma once
#include <string>
class IAsset {

public:
	
	
	virtual ~IAsset();
	//virtual void movePrice(int days) = 0;
	virtual void setPrice(double p) = 0;
	virtual void setName(std::string n) = 0;
	virtual double getPrice() = 0;
	virtual std::string getName() = 0;
	virtual int getQuantity() = 0;
	virtual void buy(int n) = 0;
	virtual void sell(int n) = 0;

};
