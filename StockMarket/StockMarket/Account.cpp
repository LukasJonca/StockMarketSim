#include <iostream>
#include "Account.h"
#include "Bond.h"
#include "Stock.h"
#include "Asset.h"

Account::Account() {
	balance = 10000;
	food = Stock("Food Corp", "FOO", 20, 55, -50, 0.01);
	tech = Stock("Tech Inc", "TCH", 100, 315, -310, 0.00);
	real = Stock("Real Property Group", "RPG", 4, 107, -100, 0.03);

	gove = Bond("Gov AAA Bond", 500, 5, 0.03);
	bank = Bond("Bank A+ Bond", 1000, 10, 0.05);
	mort = Bond("Mortgage BB+ Bond", 1000, 10, 0.06);
	
	portfolio.push_back(&food);
	portfolio.push_back(&tech);
	portfolio.push_back(&real);
	portfolio.push_back(&gove);
	portfolio.push_back(&bank);
	portfolio.push_back(&mort);
}

Account::~Account(){
	//Clears Asset vector
	portfolio.clear();
}

double Account::getBal() {
	return balance;
}

//calculates the total value of the accounts portfolio
double Account::getVal()
{
	double value = 0;
	for (int i = 0; i < portfolio.size(); i++) {
		value += portfolio[i]->getPrice() * portfolio[i]->getQuantity();
	}
	return value;
}

void Account::chgBal(double change)
{
	balance += change;
}


//Fufills user buy and sell orders 
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

//Prints the users current portfolio
void Account::print(){
	for (int i = 0; i < portfolio.size(); i++) {

		std::cout << i + 1 << ". " << portfolio[i]->getName();
		
		if ((portfolio[i]->getType()).compare("Stock") == 0) {
			std::cout << " (" << portfolio[i]->getSymbol() << ")";
		}

		std::cout << std::endl << "\tPrice: $";
		printf("%.2f", portfolio[i]->getPrice());
		std::cout << std::endl << "\tOwned: " << 
		portfolio[i]->getQuantity() << std::endl;

		portfolio[i]->printInfo();
	}
}

//returns the number of unique assets in the portfolio
int Account::NAssets(){
	return portfolio.size();
}

//Progresses time for portfolio
void Account::time(int n)
{
	for (int i = 0; i < portfolio.size(); i++) {
		balance += portfolio[i]->movePrice(n);
		if ((portfolio[i]->getPrice())<=0.01) {
			std::cout << portfolio[i]->getName() << " has been bankrupted!";
			portfolio.erase(portfolio.begin() + i);
		}
	}
}





