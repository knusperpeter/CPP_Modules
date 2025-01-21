#pragma once

# include "Weapon.hpp"

class HumanA{

	public:

		HumanA(std::string name, Weapon& weapon);

		void attack();
		void setWeapon(Weapon& weapon);

	private:

		std::string Name;
		Weapon& Weapon_A;

};