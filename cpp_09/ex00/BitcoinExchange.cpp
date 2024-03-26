#include "BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange(/* args */)
{
}

BitcoinExchange::BitcoinExchange(const BitcoinExchange &other)
{
	(void)other;
}

BitcoinExchange &BitcoinExchange::operator=(const BitcoinExchange &other)
{
	(void)other;
	return (*this);
}

BitcoinExchange::~BitcoinExchange()
{
}

void BitcoinExchange::checkOpen(std::string file, std::ifstream *stream, std::string toCehck)
{
	if (file.size() <= 5 || file.substr(file.size() - 4) != toCehck)
		throw InvalidFile();
	stream->open(file.c_str());
	if (!stream->is_open())
		throw InvalidFile();
}

void BitcoinExchange::setDb()
{
	std::ifstream dbStream;
	checkOpen(std::string(DB_FILENAME), &dbStream, std::string(".csv"));
	std::string line;
	std::getline(dbStream, line);
	Date d;
	while (std::getline(dbStream, line))
	{
		d = Date(line.substr(0, line.find(",")));
		std::pair<Date, float> p = std::pair<Date, float>(d,
					atof(line.substr(line.find(",")).c_str()));
		_db.insert(p);
	}
}

BitcoinExchange::BitcoinExchange(std::string input_file)
{
	try
	{
		setDb();
	}
	catch(const std::exception& e)
	{
		std::cerr << "Failed to create database.\n Exiting program" << std::endl;
		std::cerr << e.what() << '\n';
		exit(1);
	}
	try
	{
		checkOpen(input_file, &_inputFile, std::string(".txt"));
	}
	catch(const std::exception& e)
	{
		std::cerr << "Failed to open input file.\n Exiting program" << std::endl;
		std::cerr << e.what() << '\n';
		exit(1);
	}
	for (auto line : _db)
		std::cout << line.first._input << std::endl;

	// for( std::string line; std::getline( input, line ); )
	// {
	// 	...for each line in input...
	// }
}


