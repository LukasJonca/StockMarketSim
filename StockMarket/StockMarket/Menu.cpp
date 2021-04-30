#include "Menu.h"
using namespace std;

Menu::Menu(){
	m = 0;
}

void Menu::printMenu()
{
	
	cout << "Funds: " << "$" << user.getBal() << endl;
	cout << "Portfolio: " << "$" << user.getVal() << endl;
	cout << "1. Buy/Sell\n" << "2. Positions\n" << "3. Progress time\n"
		<< "4. log out\n";
}

void Menu::optionsMenu()
{
	printMenu();

	while (m != 4) {
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
			printMenu();
			break;
		case 2:
			user.print();
			printMenu();
			break;
		case 3:
			cout << "How many days would you like to pass?";
			cin >> amount;
			user.time(amount);
			printMenu();
			break;
		case 4:
			exit(0);
			break;
		default:
			cout << "Invalid option" << endl;
		}
	}
}
