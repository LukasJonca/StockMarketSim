#include "IAsset.h"
#include "Asset.h"
#include <iostream>
#include <string>
#include "Account.h"

Asset::Asset() {}

Asset::Asset(std::string n, double p, std::string t)
{
	name = n;
	price = p;
	quantity = 0;
	type = t;
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

int Asset::getQuantity(){
	return quantity;
}

void Asset::setQuantity(int n) {
	quantity = n;
}

void Asset::operator+(int n){
	quantity += n;
	std::cout << quantity;
}

void Asset::operator-(int n){
	quantity -= n;
}

//void Asset::movePrice(int days)
//{
//}

//bool Asset::operator=(std::string a)
//{
//	if (type.compare(a)) {
//		return true;
//	}
//	return false;
//}
