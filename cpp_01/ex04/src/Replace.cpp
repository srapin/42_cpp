/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Replace.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srapin <srapin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/30 23:39:04 by srapin            #+#    #+#             */
/*   Updated: 2023/10/01 00:13:00 by srapin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/Replace.hpp"

void            Replace::open_files(std::string filename)
{
	_infile.open(filename.c_str());
	if (!(_infile.is_open()))
	{
		std::cout << "error : can't opening " << filename << std::endl;
		exit(1);
	}
	_outfile.open((filename + ".replace").c_str());
	if (!(_outfile.is_open()))
	{
        _infile.close();
		std::cout << "error : can't opening " << filename << ".replace" << std::endl;
		exit(1);
	}
}

void            Replace::fillOutfile()
{
    std::string line;
    size_t index;
    while (std::getline(_infile, line))
    {
        index = line.find(_to_find);
        while (_to_find != "" && index != std::string::npos)
        {
            
            line.erase(index, _to_find.length());
			line.insert(index, _replace_with);
            index = line.find(_to_find);
        }
        _outfile << line << std::endl;
    }
}

Replace::Replace(std::string file_name, std::string to_find, std::string replace_with)
{
    open_files(file_name);
    _to_find =to_find;
    _replace_with = replace_with;
    fillOutfile();
}

Replace::~Replace(void)
{
    _infile.close();
    _outfile.close();
}