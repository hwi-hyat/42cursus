#ifndef BITCOINEXCHANGE_HPP
# define BITCOINEXCHANGE_HPP

#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>
#include <map>

#define TOO_LARGE_A_NUMBER 2147483647

class BitcoinExchange
{
    private:
        std::map<int, float> data;

        int date_into_int(std::string str_date);
        void parse_line_csv(std::string line);
        void parse_line_input(int& date, double& amount, std::string line);

    public:
        BitcoinExchange();
        BitcoinExchange(const BitcoinExchange &copy);
        ~BitcoinExchange();
        BitcoinExchange &operator=(const BitcoinExchange &copy);

        void load_data(std::string filename);
        float get_price(int date);
        void process_line(std::string line);

        class bad_input_exception : public std::exception
        {
            public:
                const char* what() const throw();
        };

        class not_a_positive_number_exception : public std::exception
        {
            public:
                const char* what() const throw();
        };

        class too_large_a_number_exception : public std::exception
        {
            public:
                const char* what() const throw();
        };

        class invalid_data_file_exception : public std::exception
        {
            public:
                const char* what() const throw();
        };
};




#endif
