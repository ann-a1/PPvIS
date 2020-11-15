#pragma once
#include <iostream>
#include "entity.h"

class Animal : public Entity {
protected:
	short move_points;
	short size;
	bool gender;
protected:
	Animal(std::string name, short speed_1_or_2, short gender_0b_1g, short size_1_to_3, short t) : Entity(name, t) {
		move_points = speed_1_or_2;
		size = size_1_to_3;
		gender = gender_0b_1g;
	}
	Animal() : Entity() {
		move_points = 0;
		size = 0;
		gender = 0;
	}
public:
	Animal(const Animal& other) {
		this->entity_name = other.entity_name;
		this->type_of_entity = other.type_of_entity;
		this->life_points = other.life_points;
		move_points = other.move_points;
		size = other.size;
		gender = other.gender;
	}
	Animal loseLifePoints(short size) {
		std::srand(time(NULL));
		life_points -= rand() % (4 * size);
		return *this;
	}
	Animal addLifePoints() {
		std::srand(time(NULL));
		life_points += rand() % 18;
		return *this;
	}
	Animal loseLifeHours() {
		this->life_points -= 25;
		return *this;
	}
	virtual short takeLifePoints() {
		return life_points;
	}
	short takeAnimalType() {
		return this->type_of_entity;
	}
	bool showGender() {
		return this->gender;
	}
	friend class Cell;
	friend class Field;
	friend std::ostream& operator<<(std::ostream& stream, Animal animal);
};
std::ostream& operator<<(std::ostream& stream, Animal animal) {
	stream << animal.entity_name << "; gender: " << animal.gender << "; life: " << animal.life_points << "; size: " <<
		animal.size << "; speed: " << animal.move_points << std::endl;
	return stream;
}