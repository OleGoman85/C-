#ifndef CONTACT_HPP
#define CONTACT_HPP

#include <iostream>
#include <string>

class Contact
{
private:
	std::string firstName;
	std::string lastName;
	std::string nickName;
	std::string phoneNumber;
	std::string darkestSecret;

public:
	// Setters
	void setFirstName(const std::string &input);
	void setLastName(const std::string &input);
	void setNickName(const std::string &input);
	void setPhoneNumber(const std::string &input);
	void setDarkestSecret(const std::string &input);

	// Getters
	std::string getFirstName() const;
	std::string getLastName() const;
	std::string getNickName() const;
	std::string getPhoneNumber() const;
	std::string getDarkestSecret() const;
};

#endif
