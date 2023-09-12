#include"BitcoinExchange.hpp"

int main(int argc, char** argv)
{
    if(argc != 2)
    {
        std::cout << "Error: invalid number of arguments" << std::endl;
        return 1;
    }

    BitcoinExchange btc;
    std::string data_filename = "data.csv";
    try
    {
        btc.load_data(data_filename);
    }
    catch(const BitcoinExchange::invalid_data_file_exception& e)
    {
        std::cerr << e.what() << std::endl;
        return 1;
    }

    std::ifstream input_file(argv[1]);
    std::string line;

    std::getline(input_file, line);
    while(std::getline(input_file, line))
    {
        try
        {
            btc.process_line(line);
        }
        catch(const BitcoinExchange::not_a_positive_number_exception& e)
        {
            std::cerr << e.what() << std::endl;
        }
        catch(const BitcoinExchange::too_large_a_number_exception& e)
        {
            std::cerr << e.what() << std::endl;
        }
        catch(const BitcoinExchange::bad_input_exception& e)
        {
            std::cerr << e.what() << line << std::endl;
        }
    }

    return 0;
}