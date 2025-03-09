#ifndef BITCOINEXCHANGE_HPP
# define BITCOINEXCHANGE_HPP

#include <iostream>
#include <fstream>
#include <sstream>
#include <map>
#include <limits>
#include <cstdlib>

class BitcoinExchange
{
private:
	std::map<std::string, double> database;
public :
	BitcoinExchange(void);
	BitcoinExchange(BitcoinExchange const &other);
	~BitcoinExchange(void);
	BitcoinExchange &operator = (BitcoinExchange const &other);
	bool isValidDate(const std::string &date);
	bool isValidValue(const std::string &value, double &num);
	void loadDatabase(const std::string &filename);
	void processInput(const std::string &filename);

};

#endif