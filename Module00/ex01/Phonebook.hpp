#ifndef PHONEBOOK_HPP
#define PHONEBOOK_HPP

#include <cctype>	// std::isalpha / std::isdigit
#include <string>	// std::string
#include <iostream> //std::cin, std::cout, std::endl, std::cerr
#include <iomanip>	//std::setw
#include "Contact.hpp"

class PhoneBook
{
private:
	Contact contacts[8];
	int currentIndex;
	int contactCount;

public:
	PhoneBook();
	void addContact();
	void searchContact() const;
	void displayContact(int index) const;

	std::string cropString(const std::string &str, size_t width) const;

	bool isAlpha(const std::string &str) const;
	bool isValidPhoneNumber(const std::string &phoneNumber) const;
};

#endif
