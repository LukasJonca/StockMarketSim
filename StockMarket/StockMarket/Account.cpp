#include <iostream>
#include "Account.h"
#include "Bond.h"
#include "Stock.h"
#include "Asset.h"
//using namespace std;

Account::Account() {
	balance = 10000;
	food = Stock("Food Corp", "FOO", 20, 55, -50);
	tech = Stock("Tech Inc", "TCH", 100, 320, -300);
	real = Stock("Real Property Group", "RPG", 4, 110, -100);

	gove = Bond("Gov AAA", 500, 5, 0.03);
	bank = Bond("Bank A+", 1000, 10, 0.05);
	mort = Bond("Bank BB", 1000, 10, 0.06);
	
	portfolio.push_back(&food);
	portfolio.push_back(&tech);
	portfolio.push_back(&real);
	portfolio.push_back(&gove);
	portfolio.push_back(&bank);
	portfolio.push_back(&mort);
}

double Account::getBal() {
	return balance;
}

double Account::getVal()
{
	double value = 0;
	for (int i = 0; i < portfolio.size(); i++) {
		value += portfolio[i]->getPrice() * portfolio[i]->getQuantity();
	}
	return value;
}
//
void Account::chgBal(double change)
{
	balance += change;
}

void Account::order(int n, int i, Account &a)
{
	if (n > 0) {
		if (n*portfolio[i - 1]->getPrice() <= a.getBal()) {
			a.chgBal(-n * portfolio[i - 1]->getPrice());
			(*portfolio[i - 1]) + n;

			std::cout << "Sucessful order : " << n << " units bought" << std::endl;
		}
		else {
			std::cout << "Insufficient balance" << std::endl;
		}
	}
	if (n < 0) {
		std::cout << portfolio[i - 1]->getQuantity() << std::endl;
		if ((portfolio[i - 1]->getQuantity()) <= n) {
			std::cout << portfolio[i - 1]->getQuantity() << std::endl;
			a.chgBal(-n * portfolio[i - 1]->getPrice());
			(*portfolio[i - 1])-(-n);

			std::cout << "Sucessful order : " << -n << " units sold" << std::endl;
		}
		else {
			std::cout << "Insufficient units" << std::endl;
		}
	}
}

void Account::print()
{
	//Stock temp;
	for (int i = 0; i < portfolio.size(); i++) {
		std::cout << i + 1 << ". " << portfolio[i]->getName();
		/*if (portfolio[i] = "Stock") {

			std::cout << "(" << portfolio[i]->getPrice() << ")";
		}*/
		std::cout << std::endl << "\tPrice: $";
		printf("%.2f", portfolio[i]->getPrice());
		std::cout << std::endl << "\tOwned: "
		<< portfolio[i]->getQuantity() << std::endl << std::endl;

		
	}
}

int Account::NAssets(){
	return portfolio.size();
}

void Account::time(int n)
{
	for (int i = 0; i < portfolio.size(); i++) {
		std::string temp = "Stock";
		/*if (portfolio[i] == temp) {*/
			balance += portfolio[i]->movePrice(n);
		//}
		
		
	}
}





