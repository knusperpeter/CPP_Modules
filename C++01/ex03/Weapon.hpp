#pragma once

# include <iostream>
# include <string>

class Weapon {

	public:

		Weapon();
		Weapon(std::string weapontype);

		const std::string& getType() const;
		void setType(std::string string);

	private:
		std::string type;

};