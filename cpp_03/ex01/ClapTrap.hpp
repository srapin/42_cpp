/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srapin <srapin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/01 04:20:40 by srapin            #+#    #+#             */
/*   Updated: 2024/02/06 02:04:08 by srapin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CLAP_TRAP_HPP
# define CLAP_TRAP_HPP

# include <iostream>
# include <string>

class ClapTrap
{
  protected:
	int _hitPoint;
	int _energyPoint;
	int _attackDamage;
	std::string _name;
	ClapTrap();
	ClapTrap(int hp, int ep, int ad);
	ClapTrap(std::string name, int hp, int ep, int ad);
	void setName(std::string Name);
	void setHitPoints(int HitPoints);
	void setEnergyPoints(int EnergyPoints);
	void setAttackDamage(int AttackDamage);
	bool checkCapacity(bool attack);

  public:
	void doClassics(ClapTrap &other, unsigned int rep);
	virtual void doSpecifics();
	virtual std::string getName() const;
	int getEnergyPoints() const;
	int getHitPoints() const;
	int getAttackDamage() const;
	virtual void attack(const std::string &target);
	virtual void takeDamage(unsigned int amount);
	virtual void beRepaired(unsigned int amount);

	ClapTrap(std::string name);
	ClapTrap(const ClapTrap &copy);
	~ClapTrap();
	ClapTrap &operator=(const ClapTrap &assign);

};

std::ostream &operator<<(std::ostream &new_out, ClapTrap const &fixed);

#endif