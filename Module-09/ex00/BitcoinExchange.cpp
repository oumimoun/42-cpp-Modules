#include "BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange(void) {}

BitcoinExchange::BitcoinExchange(BitcoinExchange const &other)
{
    *this = other;
}

BitcoinExchange::~BitcoinExchange(void) {}

BitcoinExchange &BitcoinExchange::operator=(BitcoinExchange const &other)
{
    if (this != &other)
    {
        database = other.database;
    }
    return (*this);
}

bool isLeapYear(int year)
{
    // A year is a leap year if it is divisible by 4 but not by 100,
    // unless it is also divisible by 400.
    return (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0);
}

bool isValidDateOfTheYear(int year, int month, int day)
{
    if (year < 2009)
        return false;

    if (month < 1 || month > 12)
        return false;

    if (day < 1)
        return false;

    int daysInMonth[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

    if (month == 2 && isLeapYear(year))
    {
        daysInMonth[1] = 29;
    }

    if (day > daysInMonth[month - 1])
        return false;

    return true;
}

bool BitcoinExchange::isValidDate(const std::string &date)
{
    if (date.empty())
        return false;
    if (date.size() != 10 || date[4] != '-' || date[7] != '-')
        return false;
    int year, month, day;
    char dash1, dash2;
    std::istringstream ss(date);
    if (!(ss >> year >> dash1 >> month >> dash2 >> day) || dash1 != '-' || dash2 != '-')
        return false;
    return (isValidDateOfTheYear(year, month, day));
}

bool BitcoinExchange::isValidValue(const std::string &value, double &num)
{
    if (value.empty())
        return false;
    char *end;
    num = std::strtod(value.c_str(), &end);
    if (*end != '\0')
        return false;
    return (num >= 0 && num <= 1000);
}

std::string trim(const std::string &value)
{
    size_t start = 0;
    while (start < value.size() && isspace(value[start]))
        start++;

    if (start == value.size())
        return "";

    size_t end = value.size() - 1;
    while (end > start && isspace(value[end]))
        end--;

    return value.substr(start, end - start + 1);
}

void BitcoinExchange::loadDatabase(const std::string &filename)
{
    std::ifstream file(filename.c_str());
    std::string line, date, price;

    if (!file)
    {
        std::cerr << "Error: could not open file." << std::endl;
        exit(1);
    }
    std::getline(file, line);
    while (std::getline(file, line))
    {
        std::istringstream ss(line);
        if (std::getline(ss, date, ',') && std::getline(ss, price))
        {
            double value;
            if (isValidDate(date) && isValidValue(price, value))
            {
                database[date] = value;
            }
        }
    }
}

bool validDouble(const std::string &input)
{
    if (input.empty())
        return false;

    bool hasDecimal = false;

    if (!isdigit(input[0]) && input[0] != '+' && input[0] != '-')
        return false;

    for (size_t i = 1; i < input.size(); i++)
    {
        if (isdigit(input[i]))
            continue;

        if (input[i] == '.')
        {
            if (hasDecimal || i == 0 || i == input.size() - 1)
                return false;
            hasDecimal = true;
        }
        else
        {
            return false;
        }
    }

    return true;
}

bool checkBadInput(std::string &input)
{
    if (input.size() < 11)
        return true;

    if (!isdigit(input[0]) || !isdigit(input[1]) || !isdigit(input[2]) || !isdigit(input[3]) || input[4] != '-' ||
        !isdigit(input[5]) || !isdigit(input[6]) || input[7] != '-' ||
        !isdigit(input[8]) || !isdigit(input[9]))
    {
        return true;
    }

    if (input.substr(10, 3) != " | ")
    {
        return true;
    }

    std::string numberPart = input.substr(13);

    if (!validDouble(numberPart))
        return true;

    return false;
}

void BitcoinExchange::processInput(const std::string &filename)
{
    std::ifstream file(filename.c_str());
    std::string line, date, value;
    if (!file)
    {
        std::cerr << "Error: could not open file." << std::endl;
        exit(1);
    }
    std::getline(file, line);
    if (line != "date | value")
        std::cerr << "Error: bad input => " << line << std::endl;
    while (std::getline(file, line))
    {
        if (line.empty())
            continue;
        if (checkBadInput(line))
        {
            std::cerr << "Error: bad input => " << line << std::endl;
            continue;
        }
        std::istringstream ss(line);
        if (!(std::getline(ss, date, '|') && std::getline(ss, value)))
        {
            std::cerr << "Error: bad input => " << line << std::endl;
            continue;
        }
        date = trim(date);
        value = trim(value);
        double num;
        if (!isValidDate(date))
        {
            std::cerr << "Error: bad input => " << line << std::endl;
            continue;
        }
        if (!isValidValue(value, num))
        {
            std::cerr << (num < 0 ? "Error: not a positive number." : "Error: too large a number.") << std::endl;
            continue;
        }
        std::map<std::string, double>::const_iterator it = database.lower_bound(date);
        if (it == database.end() || it->first != date)
        {
            if (it == database.begin())
            {
                std::cerr << "Error: no previous data available for " << date << std::endl;
                continue;
            }
            --it;
        }
        std::cout << date << " => " << num << " = " << num * it->second << std::endl;
    }
}
