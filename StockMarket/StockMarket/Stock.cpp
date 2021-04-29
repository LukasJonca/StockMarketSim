#include "Asset.h"
#include "Stock.h"
#include <iostream>
#include <string>

	

	void Stock::movePrice(int days) {
		double move;
		for (int i = 0; i < days; i++) {
			move = rand() % (top - bottom + 1) + bottom;
			move = move / 253;
			printf("%.2f", move);
			std::cout << ", ";
			setPrice(getPrice() * (1 + move / 100));
		}
	}
	

	Stock::Stock(std::string n, std::string s, double p, int t, int b): Asset(n, p) {
		symbol = s;
		top = t;
		bottom = b;
	}


