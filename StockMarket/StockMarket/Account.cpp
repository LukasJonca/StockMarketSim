#include <iostream>
#include "Account.h"
#include "Bond.h"
#include "Stock.h"
#include "Asset.h"
//using namespace std;

Account::Account(){
	balance = 10000;

	portfolio.push_back(Stock("Food Corp", "FOO", 20, 55, -50));
	portfolio.push_back(Stock("Tech Inc", "TCH", 100, 320, -300));
	portfolio.push_back(Stock("Real Property Group", "RPG", 4, 110, -100));
	portfolio.push_back(Bond("Gov AAA", 500, 5, 0.03));
	portfolio.push_back(Bond("Bank A+", 1000, 10, 0.05));
}

double Account::getBal() {
	return balance;
}

double Account::getVal()
{
	double value = 0;
	for (auto i : portfolio) {
		value += i.getPrice() * i.getQuantity();
	}
	return value;
}

void Account::chgBal(double change)
{
	balance += change;
}

void Account::order(int n, int i, Account &a)
{
	if (n > 0) {
		if (n*portfolio[i - 1].getPrice() <= a.getBal()) {
			a.chgBal(-n * portfolio[i - 1].getPrice());
			portfolio[i - 1].buy(n);

			std::cout << "Sucessful order : " << n << " units bought" << std::endl;
		}
		else {
			std::cout << "Insufficient balance" << std::endl;
		}
	}
	if (n < 0) {
		std::cout << portfolio[i - 1].getQuantity() << std::endl;
		if ((portfolio[i - 1].getQuantity()) <= n) {
			std::cout << portfolio[i - 1].getQuantity() << std::endl;
			a.chgBal(-n * portfolio[i - 1].getPrice());
			portfolio[i - 1].sell(-n);

			std::cout << "Sucessful order : " << -n << " units sold" << std::endl;
		}
		else {
			std::cout << "Insufficient units" << std::endl;
		}
	}
}

void Account::print()
{
	for (int i = 0; i < portfolio.size(); i++) {
		std::cout << i+1 << ". " << portfolio[i].getName() << std::endl
		<< "\tPrice: $" << portfolio[i].getPrice() << std::endl << "\tOwned: " << portfolio[i].getQuantity() <<
		std::endl << std::endl;
	}

}

int Account::NAssets()
{
	return portfolio.size();
}



