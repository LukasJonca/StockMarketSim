#include "Asset.h"
#include "IAsset.h"
#include "Bond.h"
#include <iostream>
#include <string>

Bond::Bond(){
}

Bond::Bond(std::string n, double p, int t, double y): Asset(n, p, "Bond")
{
	
	originalTerm = t * 365;
	term = t * 365;
	daysTillPayout = 365;
	yield = y;
	//payment = 0;
}

double Bond::movePrice(int days) {

	double payment = 0;
	daysTillPayout -= days;
	term -= days;
	
	while (daysTillPayout < 0) {
		if (daysTillPayout <= 0) {
			daysTillPayout += 365;
			payment += yield * getPrice() * getQuantity();
			//printf("%.2f", yield);
		}

		if (daysTillPayout < 365 && daysTillPayout > 0) {
			//setPrice(getPrice() * (1 + (yield / daysTillPayout)));
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