#include <iostream>
#include "Account.h"
//using namespace std;

Account::Account(){
	balance = 10000;
}

double Account::getBal() {
	return balance;
}
