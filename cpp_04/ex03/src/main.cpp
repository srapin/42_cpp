/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srapin <srapin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/02 18:46:41 by srapin            #+#    #+#             */
/*   Updated: 2024/02/06 23:43:03 by srapin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/IMateriaSource.hpp"
#include "../inc/ICharacter.hpp"
#include "../inc/Character.hpp"

#include "../inc/AMateria.hpp"
#include "../inc/Ice.hpp"
#include "../inc/Cure.hpp"
#include "../inc/ICharacter.hpp"
#include "../inc/Character.hpp"
#include "../inc/MateriaSource.hpp"

void personalTests()
{

	std::cout << "-----INIT MATERIA SOURCE-----" << std::endl;
	AMateria *truc;
	
	IMateriaSource *src = new MateriaSource();
	
	truc = new Ice();
	src->learnMateria(truc);
	truc = new Cure();
	src->learnMateria(truc);
	std::cout << "-----CREATE + EQUIP MATERIA-----" << std::endl;
	Character* me = new Character("me");
	AMateria* tmp;
	AMateria *toDiscard;
	toDiscard = src->createMateria("ice");
	me->equip(toDiscard);
	tmp = src->createMateria("cure");
	me->equip(tmp);
	
	std::cout << "-----ALREADY EQUIPED MATERIA-----" << std::endl;
	me->equip(tmp); //check no leaks
	
	ICharacter* bob = new Character("bob");
	
	std::cout << "-----MATERIA USE-----" << std::endl;
	me->use(0, *bob);
	me->use(1, *bob);
	me->use(2, *bob); //should do nothing
	
	std::cout << "-----MATERIASOURCE UNKNOWN TYPE-----" << std::endl;
	tmp = src->createMateria("bazinga"); //should do nothing
	
	std::cout << "-----FULL CHARA INVENTORY-----" << std::endl;
	
	tmp = src->createMateria("ice");
	me->equip(tmp);
	tmp = src->createMateria("cure");
	me->equip(tmp);
	tmp = src->createMateria("ice");
	me->equip(tmp); //should do nothing
	delete tmp;
	tmp = src->createMateria("cure"); //should do nothing
	delete tmp;
	me->equip(tmp);
	
	std::cout << "-----FULL MATERIA SOURCE WITH IDENTICAL TYPES-----" << std::endl;
	truc = new Ice();
	src->learnMateria(truc);
	truc = new Ice();
	src->learnMateria(truc);
	truc = new Ice();
	src->learnMateria(truc);
	delete truc;
	
	std::cout << "-----UNEQUIP MATERIA-----" << std::endl;
	tmp = src->createMateria("Ice");
	bob->equip(tmp);
	bob->use(0, *me);
	bob->unequip(0);
	
	std::cout << "-----UNEQUIP EMPTY IDX-----" << std::endl;
	bob->unequip(0); //should do nothing
	
	std::cout << "-----DELETION *BOOM NO LEAKS*-----" << std::endl;
	delete toDiscard;
	delete bob;
	delete me;
	delete src;
}

void subectTest()
{
	IMateriaSource* src = new MateriaSource();
	src->learnMateria(new Ice());
	src->learnMateria(new Cure());
	ICharacter* me = new Character("me");
	AMateria* tmp;
	tmp = src->createMateria("ice");
	me->equip(tmp);
	tmp = src->createMateria("cure");
	me->equip(tmp);
	ICharacter* bob = new Character("bob");
	me->use(0, *bob);
	me->use(1, *bob);
	delete bob;
	delete me;
	delete src;
}

int main(void) {

	subectTest();
	personalTests();
	
	return 0;
}
