#include "Phonebook.hpp"
#include <iostream> // std::cin, std::cout, std::endl, std::cerr
#include <string>	// std::string
#include <iomanip>	// std::setw

using std::cin;
using std::cout;
using std::endl;
using std::right;
using std::setw;
using std::string;

int main()
{
	PhoneBook phoneBook;
	string command;

	while (true)
	{
		cout << "📘 PhoneBook 📕\n"
			 << endl;
		cout << "Enter command (ADD, SEARCH, EXIT): ";

		if (!getline(cin, command))
		{
			if (cin.eof())
			{
				// The user entered EOF (for example, Ctrl+D)
				cout << "\n\033[0;34m👋 See You Later! 👋\033[0m" << endl;
				break;
			}
			else
			{
				// An input error occurred
				cin.clear(); // Reset the stream state
				cout << "Input error. Please try again." << endl;
				continue;
			}
		}

		if (command == "ADD")
		{
			phoneBook.addContact();
		}
		else if (command == "SEARCH")
		{
			phoneBook.searchContact();
		}
		else if (command == "EXIT")
		{
			cout << "\033[0;34m👋 See You Later! 👋\033[0m" << endl;
			break;
		}
		else
		{
			cout << "Invalid command." << endl;
		}
	}
	return 0;
}
