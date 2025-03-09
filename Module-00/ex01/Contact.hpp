#ifndef CONTACT_HPP
# define CONTACT_HPP

# include <iomanip>
# include <iostream>

class Contact
{
  public:
	Contact(void);
	~Contact(void);
	void setIndex(int index);
	int getIndex(void) const;
	std::string getFirstName(void) const;
	std::string getLastName(void) const;
	std::string getNickname(void) const;
	std::string getPhoneNumber(void) const;
	std::string getDarkestSecret(void) const;
	std::string truncateField(const std::string &field) const;

	void setContact(const std::string &first, const std::string &last, 
    	const std::string &nick, const std::string &phone, const std::string &secret);

	void displaySummary(int index) const;
	void displayDetails(void) const;

  private:
	std::string _firstName;
	std::string _lastName;
	std::string _nickname;
	std::string _phoneNumber;
	std::string _darkestSecret;
	int _index;
};

#endif
