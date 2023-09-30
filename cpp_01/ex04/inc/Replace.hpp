/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Replace.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srapin <srapin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/30 23:37:40 by srapin            #+#    #+#             */
/*   Updated: 2023/10/01 00:07:14 by srapin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef REPLACE_HPP
#define REPLACE_HPP

#include <iostream>
#include <fstream>
#include <stdlib.h>

class Replace
{
	private:
		std::ifstream	_infile;
		std::ofstream	_outfile;
        std::string     _to_find;
        std::string     _replace_with;
        void            open_files(std::string filename);
        void            fillOutfile();
	public:
		Replace(std::string file_name, std::string to_find, std::string replace_with);
		~Replace(void);
};

#endif