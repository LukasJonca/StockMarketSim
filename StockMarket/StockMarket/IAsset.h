#pragma once

class IAsset {	
private:
	double price;
public:
	virtual ~IAsset();
	virtual void movePrice();
	virtual double getPrice();
};
