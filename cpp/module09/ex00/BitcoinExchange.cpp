#include"BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange()
{

}

BitcoinExchange::BitcoinExchange(const BitcoinExchange &copy)
{
    this->data = copy.data;
}

BitcoinExchange::~BitcoinExchange()
{

}

BitcoinExchange &BitcoinExchange::operator=(const BitcoinExchange &copy)
{
    if(this == &copy)
        return (*this);
    this->data = copy.data;
    return (*this);
}

int BitcoinExchange::date_into_int(std::string str_date)
{
    int year = std::atoi(str_date.substr(0, str_date.find_first_of('-')).c_str());
    int month = std::atoi(str_date.substr(str_date.find_first_of('-') + 1, str_date.find_last_of('-')).c_str());
    int day = std::atoi(str_date.substr(str_date.find_last_of('-') + 1).c_str());

    if((year < 2009 || month < 1 || month > 12 || day < 1 || day > 31)
    || ((month == 4 || month == 6 || month == 9 || month == 11) && day > 30)
    || (month == 2 && day > 28 && year % 4 != 0)
    || (month == 2 && day > 29 && year % 4 == 0))
        return 0;
    
    return year * 10000 + month * 100 + day;
}

void BitcoinExchange::parse_line_csv(std::string line)
{
    if(line.size() == 0)
        return ;
    std::string str_date = line.substr(0, line.find(','));
    std::string str_price = line.substr(line.find(',') + 1);

    int date = date_into_int(str_date);
    float price = std::strtof(str_price.c_str(), NULL);

    if(date == 0 || price < 0 || price > TOO_LARGE_A_NUMBER)
        throw BitcoinExchange::invalid_data_file_exception();

    this->data[date] = price;
}

void BitcoinExchange::load_data(std::string filename)
{
    std::ifstream datafile(filename.c_str());
    if(!datafile.is_open())
    {
        std::cout << "Error: could not open file" << std::endl;
        return ;
    }

    std::string line;
    std::getline(datafile, line);
    while(std::getline(datafile, line))
        parse_line_csv(line);
}

float BitcoinExchange::get_price(int date)
{
    std::map<int, float>::iterator it = this->data.upper_bound(date);
    
    if(it == this->data.begin())
        throw BitcoinExchange::bad_input_exception();
    else
        return (--it)->second;
}

void BitcoinExchange::parse_line_input(int& date, double& amount, std::string line)
{
    std::string str_date = line.substr(0, line.find('|'));
    std::string str_amount = line.substr(line.find('|') + 1);

    if(str_date.size() == 0 || str_amount.size() == 0)
        throw BitcoinExchange::bad_input_exception();

    date = date_into_int(str_date);
    amount = std::atof(str_amount.c_str());

    if(date == 0)
        throw BitcoinExchange::bad_input_exception();
    else if(amount <= 0)
        throw BitcoinExchange::not_a_positive_number_exception();
    else if(amount > TOO_LARGE_A_NUMBER)
        throw BitcoinExchange::too_large_a_number_exception();
}

void BitcoinExchange::process_line(std::string line)
{
    int date;
    double amount;
    double price;
    
    parse_line_input(date, amount, line);
    price = get_price(date);
    std::cout << date << " => " << amount << " = " << price * amount << std::endl;
}

const char* BitcoinExchange::bad_input_exception::what() const throw()
{
	return ("Error: bad input => ");
}

const char* BitcoinExchange::not_a_positive_number_exception::what() const throw()
{
	return ("Error: not a positive number");
}

const char* BitcoinExchange::too_large_a_number_exception::what() const throw()
{
	return ("Error: too large a number");
}

const char* BitcoinExchange::invalid_data_file_exception::what() const throw()
{
	return ("Error: invalid data file");
}
