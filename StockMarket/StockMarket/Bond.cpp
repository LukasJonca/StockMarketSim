#include "IAsset.h"
#include "Bond.h"
#include <string>

Bond::Bond(std::string n, double p, int t, int y): Asset(n, p)
{
	
	originalTerm = t * 365;
	term = t * 365;
	daysTillPayout = 365;
	yield = y;
}

double Bond::movePrice(int days) {
	double payment = 0;
	daysTillPayout -= days;
	term -= days;

	if (daysTillPayout <= 0) {
		daysTillPayout += 365;
		payment += yield * getPrice();
	}

	if (daysTillPayout < 365 && daysTillPayout > 0) {
		setPrice(getPrice() * (1 + (yield / daysTillPayout)));
	}
	
	if (term <= 0) {
		payment += getPrice() * getQuantity();
		sell(getQuantity());
		term = originalTerm;
	}

	return payment;
}