#pragma once
#include <iostream>
#include "entity.h"

class Plant: public Entity {
public:
	Plant(std::string name): Entity(name, 3){}
	Plant() : Entity() {
		life_points = 0;
		type_of_entity = 3;
	}
	Plant(const Plant& other) {
		this->entity_name = other.entity_name;
		this->life_points = other.life_points;
		type_of_entity = other.type_of_entity;
	}
	Plant RefillLifePoints() {
		life_points = 100;
		return *this;
	}
	Plant loseLifePoints(short size) {
		std::srand(time(NULL));
		short points_to_lose = rand() % (8 * size);
		life_points = life_points - points_to_lose;
		return *this;
	}
	virtual short takeLifePoints() {
		return life_points;
	}
	friend class Cell;
	friend std::ostream& operator<<(std::ostream& stream, Plant plant);
};
std::ostream& operator<<(std::ostream& stream, Plant plant) {
	stream << plant.entity_name << "; life: " << plant.life_points << std::endl;
	return stream;
}