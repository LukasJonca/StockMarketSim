#include "IAsset.h"
#include "Asset.h"
#include <iostream>
#include <string>
#include "Account.h"

Asset::Asset() {}

Asset::Asset(std::string n, double p)
{
	name = n;
	price = p;
	quantity = 0;
}

void Asset::setPrice(double p) {
	price = p;
}
void Asset::setName(std::string n) {
	name = n;
}
double Asset::getPrice() {
	return price;
}
std::string Asset::getName() {
	return name;
}

int Asset::getQuantity()
{
	return quantity;
}

void Asset::buy(int n)
{
	quantity += n;	
}

void Asset::sell(int n)
{
	quantity -= n;
}
