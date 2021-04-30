#include <iostream>
#include <vector>
#include <string>
#include"IAsset.h"
#include "Account.h"
#include "Asset.h"
#include "Stock.h"
#include "Bond.h"

using namespace std;

void printMMenu(Account a) {
	cout << "Funds: " << "$" << a.getBal() << endl;
	cout << "Portfolio: " << "$" << a.getVal() << endl;
	cout << "1. Buy/Sell\n" << "3. Positions\n" <<"4. Progress time\n"
	<< "5. log out\n";
}
//void printPorfolio(vector <Position> portfolio) {
//	for (auto i : portfolio) {
//		//cout << i.name << endl;
//	}
//}
int main()
{
	int amount, option, m = 0;

	Account user;

	//user.order(1, 1, user);
	//user.order(3, 4, user);
	
	printMMenu(user);

	while (m != 5) {
		cin >> m;

		switch (m) {
			case 1:
				user.print();
				cout << "What would you like to buy?" << endl;
				cin >> option;
				if (option <= user.NAssets() && option >= 1) {
					cout << "How many would you like to buy (+int = buy, -int = sell)?" << endl;
					cin >> amount;

					user.order(amount, option, user);
				}
				else {
					cout << "Invalid option" << endl;
				}
				printMMenu(user);
				break;
			case 2:
				break;
			case 3:
				user.print();
				printMMenu(user);
				break;
			case 4:
				cout << "How many days would you like to pass?";
				cin >> amount;
				user.time(amount);
				break;
			case 5:
				exit(0);
				break;
			default:
				cout << "Invalid option" << endl;
		}
	}
	

}
