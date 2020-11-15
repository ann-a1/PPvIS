#pragma once
#include "animal.h"

class Predator : public Animal {
public:
	Predator(std::string name, short speed_1_2, short gender_0b_1g, short size_1_to_3) : Animal(name, speed_1_2, gender_0b_1g, size_1_to_3, 1) {
	}
	Predator() : Animal() {
		type_of_entity = 1;
	}
};