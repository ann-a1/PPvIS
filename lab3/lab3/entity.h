#pragma once
#include <iostream>
#include <ctime>
#include <cstdlib>
#include "cell.h"
#include "field.h"

class Entity {
public:
	std::string entity_name;
protected:
	short life_points;
	short type_of_entity;

	Entity(std::string name, short t) {
		entity_name = name;
		type_of_entity = t;
		life_points = 100;
	}
	Entity() {
		entity_name = "0";
		life_points = 0;
		if (type_of_entity != 1 && type_of_entity != 2 && type_of_entity != 3) type_of_entity = 0;
	}
	Entity(const Entity& other): entity_name(other.entity_name), life_points(other.life_points), type_of_entity(other.type_of_entity){}
public:
	 virtual short takeLifePoints() {
		return life_points;
	}
	
	friend std::ostream& operator<<(std::ostream& stream, Entity entity);
};
std::ostream& operator<<(std::ostream& stream, Entity entity) {
	stream << entity.entity_name << " life: " << entity.life_points;
	return stream;
}