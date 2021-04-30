#include "Asset.h"
#include "Stock.h"
#include <iostream>
#include <string>

	
Stock::Stock(){}

Stock::Stock(std::string n, std::string s, double p, int t, int b, double d): Asset(n, p, "Stock") {
	symbol = s;
	top = t;
	bottom = b;
	dividend = d;
	daysUntilDividend = 365;
}

//Generates price changes in stock and also pays out divends
double Stock::movePrice(int days) {
	double move;
	double payment = 0;
	for (int i = 0; i < days; i++) {
		move = rand() % (top - bottom + 1) + bottom;
		move = move / 365;
			
		setPrice(getPrice() * (1 + move / 100));
	}

	daysUntilDividend -= days;

	while (daysUntilDividend <= 0) {
			daysUntilDividend += 365;
			payment += dividend * getPrice() * getQuantity();
	}

	return payment;
}

//Prints info that is apart of stock class
void Stock::printInfo(){
	std::cout << "\tDividend: ";
	printf("%.3f", dividend);
	std::cout << std::endl << std::endl;
}

//Return unique symbol
std::string Stock::getSymbol(){
	return symbol;
}


