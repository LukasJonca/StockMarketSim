#pragma once

#include <string>
class IAsset {

public:
	
	
	virtual ~IAsset() {};
	//virtual void movePrice(int days) = 0;
	virtual void setPrice(double p) = 0;
	virtual void setName(std::string n) = 0;
	virtual double getPrice() = 0;
	virtual std::string getName() = 0;
	virtual int getQuantity() = 0;
	virtual void setQuantity(int n) = 0;
	virtual void operator+(int n) = 0;
	virtual void operator-(int n) = 0;
	virtual std::string getType() = 0;

};
