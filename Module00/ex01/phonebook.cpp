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

// Constructor
PhoneBook::PhoneBook() : currentIndex(0), contactCount(0) {}

bool PhoneBook::isAlpha(const string &str) const
{
	for (char c : str)
	{
		if (!std::isalpha(static_cast<unsigned char>(c)))
			return false;
	}
	return true;
}

bool PhoneBook::isValidPhoneNumber(const string &phoneNumber) const
{
	for (char c : phoneNumber)
	{
		if (!std::isdigit(static_cast<unsigned char>(c)))
			return false;
	}
	return true;
}

void PhoneBook::addContact()
{
	Contact newContact; // Local variable
	string input;		// User input

	// First Name
	while (true)
	{
		cout << "Enter first name: ";
		getline(cin, input);
		if (input.empty() || !isAlpha(input))
			cout << "Invalid first name. Please use only alphabetic characters." << endl;
		else
		{
			newContact.setFirstName(input);
			break; // Exit the loop upon valid input
		}
	}

	// Last Name
	while (true)
	{
		cout << "Enter last name: ";
		getline(cin, input);
		if (input.empty() || !isAlpha(input))
			cout << "Invalid last name. Please use only alphabetic characters." << endl;
		else
		{
			newContact.setLastName(input);
			break;
		}
	}

	// Nickname
	while (true)
	{
		cout << "Enter nickname: ";
		getline(cin, input);
		if (input.empty() || !isAlpha(input))
			cout << "Invalid nickname. Please use only alphabetic characters." << endl;
		else
		{
			newContact.setNickName(input);
			break;
		}
	}

	// Phone Number
	while (true)
	{
		cout << "Enter phone number: ";
		getline(cin, input);
		if (input.empty() || !isValidPhoneNumber(input))
			cout << "Invalid phone number. Please enter only digits." << endl;
		else
		{
			newContact.setPhoneNumber(input);
			break;
		}
	}

	// Darkest Secret
	cout << "Enter darkest secret: ";
	getline(cin, input);
	if (input.empty())
		newContact.setDarkestSecret("No Secrets");
	else
		newContact.setDarkestSecret(input);

	contacts[currentIndex] = newContact;
	currentIndex = (currentIndex + 1) % 8;
	if (contactCount < 8)
		contactCount++;

	cout << "\033[0;32mContact Added Successfully!\033[0m\n";
}

void PhoneBook::searchContact() const
{
	if (contactCount == 0) // Use contactCount for checking
	{
		cout << "\033[1;31mPhoneBook is empty. Please add a contact before searching.\033[0m\n"
			 << endl;
		return; // Exit the function
	}
	else
	{
		// Display table headers
		cout << setw(10) << right << "Index" << '|'
			 << setw(10) << right << "First Name" << '|'
			 << setw(10) << right << "Last Name" << '|'
			 << setw(10) << right << "Nickname" << '|' << endl;

		// Display list of contacts
		for (int i = 0; i < contactCount; i++)
		{
			cout << setw(10) << right << i << '|'
				 << setw(10) << right << cropString(contacts[i].getFirstName(), 10) << '|'
				 << setw(10) << right << cropString(contacts[i].getLastName(), 10) << '|'
				 << setw(10) << right << cropString(contacts[i].getNickName(), 10) << '|' << endl;
		}

		// Prompt user for index
		int index;
		cout << "Enter index of contact to display: ";
		cin >> index;
		cin.ignore(); // Ignore the newline character

		// Validate index
		if (index < 0 || index >= contactCount)
			cout << "Invalid index." << endl;
		else
			// Display information of the selected contact
			displayContact(index);
	}
}

// Function to crop strings and replace the last character with a dot if the string is longer than the specified width
std::string PhoneBook::cropString(const std::string &str, size_t width) const
{
	if (str.length() > width)
		return str.substr(0, width - 1) + '.'; // Extract substring starting at position 0 with length width - 1 characters
	else
		return str;
}

void PhoneBook::displayContact(int index) const
{
	cout << "First Name: " << contacts[index].getFirstName() << endl;
	cout << "Last Name: " << contacts[index].getLastName() << endl;
	cout << "Nickname: " << contacts[index].getNickName() << endl;
	cout << "Phone Number: " << contacts[index].getPhoneNumber() << endl;
	cout << "Darkest Secret: " << contacts[index].getDarkestSecret() << endl;
}
