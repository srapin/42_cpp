/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srapin <srapin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/02 18:46:41 by srapin            #+#    #+#             */
/*   Updated: 2023/10/03 23:21:11 by srapin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/IMateriaSource.hpp"
#include "../inc/ICharacter.hpp"
#include "../inc/Character.hpp"

#include "../inc/AMateria.hpp"
#include "../inc/IceMateria.hpp"
#include "../inc/CureMateria.hpp"
#include "../inc/ICharacter.hpp"
#include "../inc/Character.hpp"
#include "../inc/MateriaSource.hpp"

int main(void) {

	std::cout << "-----INIT MATERIA SOURCE-----" << std::endl;
	AMateria *truc;
	
	IMateriaSource *src = new MateriaSource();
	
	truc = new IceMateria();
	src->learnMateria(truc);
	delete truc;
	truc = new CureMateria();
	src->learnMateria(truc);
	delete truc;
	
	std::cout << std::endl;
	std::cout << "-----CREATE + EQUIP MATERIA-----" << std::endl;
	Character* me = new Character("me");
	
	std::cout << std::endl;
	AMateria* tmp;
	AMateria *toDiscard;

	toDiscard = src->createMateria("ice");
	me->equip(toDiscard);
	tmp = src->createMateria("cure");
	me->equip(tmp);

	std::cout << std::endl;
	std::cout << "-----ALREADY EQUIPED MATERIA-----" << std::endl;
	me->equip(tmp);
	
	std::cout << std::endl;


	std::cout << std::endl;
	ICharacter* bob = new Character("bob");

	std::cout << std::endl;
	std::cout << "-----MATERIA USE-----" << std::endl;
	me->use(0, *bob);
	me->use(1, *bob);

	std::cout << std::endl;
	std::cout << "-----MATERIASOURCE UNKNOWN TYPE-----" << std::endl;
	tmp = src->createMateria("bazinga");

	std::cout << std::endl;
	std::cout << "-----FULL CHARA INVENTORY-----" << std::endl;

	tmp = src->createMateria("ice");
	me->equip(tmp);
	std::cout << std::endl;
	tmp = src->createMateria("cure");
	me->equip(tmp);
	std::cout << std::endl;
	tmp = src->createMateria("ice");
	me->equip(tmp);
	delete tmp;
	std::cout << std::endl;
	tmp = src->createMateria("cure");
	delete tmp;
	me->equip(tmp);
	std::cout << std::endl;

	std::cout << std::endl;
	std::cout << "-----FULL MATERIA SOURCE WITH IDENTICAL TYPES-----" << std::endl;
	truc = new IceMateria();
	src->learnMateria(truc);
	delete truc;
	std::cout << std::endl;
	truc = new IceMateria();
	src->learnMateria(truc);
	delete truc;
	std::cout << std::endl;
	truc = new IceMateria();
	src->learnMateria(truc);
	delete truc;
	
	std::cout << std::endl;
	std::cout << "-----UNEQUIP MATERIA-----" << std::endl;
	tmp = src->createMateria("IceMateria");
	bob->equip(tmp);
	bob->use(0, *me);
	bob->unequip(0);

	std::cout << std::endl;
	std::cout << "-----UNEQUIP EMPTY IDX-----" << std::endl;
	bob->unequip(0);

	std::cout << std::endl;
	std::cout << "-----MATERIA TRANSFER BETWEEN CHARACTERS-----" << std::endl;


	me->unequip(0);
	me->equip(tmp);
	std::cout << "-----NOTE THE INCREASED XP UPON USE-----" << std::endl;
	me->use(0, *bob);

	std::cout << std::endl;
	std::cout << "-----DELETION *BOOM NO LEAKS*-----" << std::endl;

	std::cout << std::endl;
	delete toDiscard;
	std::cout << std::endl;
	delete bob;
	std::cout << std::endl;
	delete me;
	std::cout << std::endl;
	delete src;
	
	return 0;
}
