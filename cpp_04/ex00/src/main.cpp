/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srapin <srapin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/01 23:36:01 by srapin            #+#    #+#             */
/*   Updated: 2024/02/06 21:07:38 by srapin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/Dog.hpp"
#include "../inc/Cat.hpp"
#include "../inc/WrongDog.hpp"
#include "../inc/WrongCat.hpp"

void anim()
{
    std::cout << "Animals" << std::endl;
    
    const Animal* meta = new Animal();
    const Animal* d = new Dog();
    const Animal* c = new Cat();
    std::cout << "First animal is a " << d->getType() << ". It makes "  << std::endl;
    d->makeSound();
    std::cout << "Second animal is a " << c->getType() << ". It makes " << std::endl;
    c->makeSound();
    std::cout << "Third animal is am " << meta->getType() << ". It makes " << std::endl;
    meta->makeSound();
    
    delete meta;
    delete d;
    delete c;

    const Cat* c2 = new Cat();
    const Cat* c3 = c2;
    const Dog* d2 = new Dog();
    const Dog* d3(d2);

    c3->makeSound();
    d3->makeSound();
    delete c2;
    delete d2;
}

void wrongAnim()
{
    std::cout << "WrongAnimals" << std::endl;
    
    const WrongAnimal* meta = new WrongAnimal();
    const WrongAnimal* d = new WrongDog();
    const WrongAnimal* c = new WrongCat();
    std::cout << "First animal is a " << d->getType() << ". It makes "  << std::endl;
    d->makeSound();
    std::cout << "Second animal is a " << c->getType() << ". It makes " << std::endl;
    c->makeSound();
    std::cout << "Third animal is am " << meta->getType() << ". It makes " << std::endl;
    meta->makeSound();
    
    delete meta;
    delete d;
    delete c;

    const WrongCat* c2 = new WrongCat();
    const WrongCat* c3 = c2;
    const WrongDog* d2 = new WrongDog();
    const WrongDog* d3(d2);

    c3->makeSound();
    d3->makeSound();
    delete c2;
    delete d2;
}


int main()
{
    anim();
    wrongAnim();   
}
