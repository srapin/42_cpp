#include "BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange()
{
}

BitcoinExchange::BitcoinExchange(const BitcoinExchange &other)
{
	(void)other;
	throw InvalidUsage();
}

BitcoinExchange &BitcoinExchange::operator=(const BitcoinExchange &other)
{
	(void)other;
	throw InvalidUsage();
	return (*this);
}

void BitcoinExchange::printErr(std::string line)
{
	std::cerr << "Error: ";
	if (_e == neg)
		std::cerr << "not a positive number.";
	else if (_e == tobig)
		std::cerr << "too large a number.";
	else
		std::cerr << "bad input =>" << line;
	std::cerr << std::endl;
}

BitcoinExchange::~BitcoinExchange()
{
}

void BitcoinExchange::output()
{
	std::string line;
	std::getline(_inputFile, line);
	if (line != "date | value")
		throw InvalidInputFile();
	for (; std::getline(_inputFile, line);)
		treatLine(line);
}

float BitcoinExchange::getNumber(std::string nb_str)
{
	float	nb;

	if (nb_str.empty())
		throw lineError();
	if (nb_str.find_first_not_of("0123456789.-") != std::string::npos)
		throw lineError();
	nb = atof(nb_str.c_str());
	if (nb < 0)
	{
		_e = neg;
		throw lineError();
	}
	if (atol(nb_str.c_str()) > 1000)
	{
		_e = tobig;
		throw lineError();
	}
	return (nb);
}



void BitcoinExchange::treatLine(std::string line)
{
	int		sep;
	float	nb;
	Date	d;

	sep = line.find("|");
	_e = none;
	try
	{
		nb = getNumber(line.substr(sep + 2));
		d = Date(line.substr(0, sep - 1));
	}
	catch (const std::exception &e)
	{
		return (printErr(line));
	}
	std::map<Date, float>::iterator it = _db.begin();
	while (it != _db.end() && (*it).first < d)
	{
		it++;
	}
	if (!((*it).first == d))
		*it--;
	std::cout << d << " => " << nb << " = "
				<< nb * (*it).second << std::endl;
}

void BitcoinExchange::checkOpen(std::string file, std::ifstream *stream,
		std::string toCehck)
{
	if (file.size() <= 5 || file.substr(file.size() - 4) != toCehck)
		throw InvalidInputFile();
	stream->open(file.c_str());
	if (!stream->is_open())
		throw InvalidInputFile();
}

void BitcoinExchange::setDb()
{
	Date	d;

	std::ifstream dbStream;
	try
	{
		checkOpen(std::string(DB_FILENAME), &dbStream, std::string(".csv"));
	}
	catch (const InvalidInputFile &e)
	{
		throw InvalidDb();
	}
	std::string line;
	std::getline(dbStream, line);
	while (std::getline(dbStream, line))
	{
		d = Date(line.substr(0, line.find(",")));
		std::pair<Date, float> p = std::pair<Date, float>(d, 
			atof(line.substr(line.find(",") + 1).c_str()));
		_db.insert(p);
	}
}

BitcoinExchange::BitcoinExchange(std::string input_file)
{
	try
	{
		setDb();
		checkOpen(input_file, &_inputFile, std::string(".txt"));
	}
	catch (const std::exception &e)
	{
		std::cerr << e.what() << '\n';
		std::cerr << "Exiting program" << std::endl;
		exit(1);
	}
	output();
}

const char *BitcoinExchange::InvalidInputFile::what() const throw()
{
	return ("Bad input file.");
}

const char *BitcoinExchange::InvalidDb::what() const throw()
{
	return ("Failed to create database.");
}

const char * BitcoinExchange::lineError::what() const throw()
{
	return "Error";
}

const char *BitcoinExchange::InvalidUsage::what() const throw()
{
	return "Classe BitcoinExchange is not supposed to be copied";
}
