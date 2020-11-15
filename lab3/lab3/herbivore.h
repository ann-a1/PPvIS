#pragma once
#include "animal.h"

class Herbivore : public Animal {
public:
	Herbivore(std::string name, short speed_1_or_2, short gender_0b_1g, short size_1_to_3) : Animal(name, speed_1_or_2, gender_0b_1g, size_1_to_3, 1) {}
	Herbivore() : Animal() {
		type_of_entity = 2;
	}
};