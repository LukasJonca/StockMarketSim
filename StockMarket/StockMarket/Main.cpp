#include <iostream>
#include "Account.h"
using namespace std;

void printMenu(Account A) {
	cout << "Funds: " << "$" <<A.getBal() << endl;
	cout << "Portfolio: " << "$" << endl;
	cout << "1. Buy\n" << "2. Sell\n"
	<< "3. Positions\n" <<"4. Progress time\n"<< "5. log out\n";
}

int main()
{
	int m = 0;
	Account user;
	printMenu(user);

	while (m != 4) {
		cin >> m;

		switch (m) {
			case 1:
				break;
			case 2:
				break;
			case 3:
				break;
			case 4:
				break;
			case 5:
				exit(0);
				break;
			default:
				cout << "Invalid option" << endl;
		}
	}
	

}
