#include "Menu.h"
using namespace std;

Menu::Menu(){
	m = 0;
}

void Menu::printMenu()
{
	
	cout << "Funds: " << "$" << user.getBal() << endl;
	cout << "Portfolio: " << "$" << user.getVal() << endl;
	cout << "1. Buy/Sell\n" << "3. Positions\n" << "4. Progress time\n"
		<< "5. log out\n";
}

void Menu::optionsMenu()
{
	printMenu();

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
			printMenu();
			break;
		case 2:
			break;
		case 3:
			user.print();
			printMenu();
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
