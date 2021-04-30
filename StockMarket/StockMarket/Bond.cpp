#include "Asset.h"
#include "Bond.h"
#include <iostream>
#include <string>

Bond::Bond(){}

Bond::Bond(std::string n, double p, int t, double y): Asset(n, p, "Bond"){
	originalTerm = t * 365;
	term = t * 365;
	daysTillPayout = 365;
	yield = y;
}

//Manages the payments and terms of bonds
double Bond::movePrice(int days) {

	double payment = 0;
	daysTillPayout -= days;
	term -= days;
	
	while (daysTillPayout < 0) {
		if (daysTillPayout <= 0) {
			daysTillPayout += 365;
			payment += yield * getPrice() * getQuantity();
		}
	}
	
	
	if (term <= 0) {
		std::cout << "test ";
		payment += getPrice() * getQuantity();
		setQuantity(0);
		term = originalTerm;
	}
	
	return payment;
}

//Prints info that is apart of bond class
void Bond::printInfo(){
	std::cout << "\tYield: ";
	printf("%.3f", yield);

	std::cout << std::endl << "\tTerm remaining: " << term/365 << std::endl << std::endl;
}


