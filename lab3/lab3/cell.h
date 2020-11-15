#pragma once
#include <iostream>
#include "animal.h"
#include "plant.h"

class Cell {
	Animal animal[3];
	Plant plant;
	bool existence[4];
	Cell() {
		for (short i = 0; i < 3; i++) {
			animal[i] = Animal();
			existence[i] = 0;
		}
		plant = Plant();
		existence[3] = 0;

	}
	bool checkPlantFree() {
		if (this->existence[3]) return 0;
		else return 1;
	}
	bool checkForHerbivores() {
		for (int i = 0; i < 3; i++) {
			if (this->animal[i].takeAnimalType() == 1) return 0;
		}
		return 1;
	}
	bool cellIsEmpty(short i) {
		if (this->existence[i]) return 0;
		else return 1;
	}
	Animal showAnimal(int number_in_cell) {
		number_in_cell--;
		return this->animal[number_in_cell];
	}
	Plant showPlant() {
		return this->plant;
	}
	Cell addAnimal(Animal new_entity) {
		for (short i = 0; i < 3; i++) {
			if (this->cellIsEmpty(i)) {
				animal[i] = new_entity;
				existence[i] = 1;
		        return *this;
			}
		}
		return *this;
	}
	Cell deleteAnimal(short type) {
		for (short i = 0; i < 3; i++) {
			if (this->animal[i].takeAnimalType() == type) {
				this->animal[i] = Animal();
				return *this;
			}
		}
	}
	Cell deleteAnimalByNumber(int number_in_cell) {
		number_in_cell--;
		this->animal[number_in_cell] = Animal();
		return *this;
	}
	Cell changeAnimalInCell(int number_in_cell, Animal new_animal) {
		number_in_cell--;
		this->animal[number_in_cell] = new_animal;
		return *this;
	}
	Cell changePlantInCell(Plant new_plant) {
		this->plant = new_plant;
		return *this;
	}
	Cell addPlant(Plant plant) {
		this->plant = plant;
		existence[3] = 1;
		return *this;
	}
	Cell deletePlant() {
		this->plant = Plant();
		return *this;
	}

	friend class Field;
	friend std::ostream& operator<<(std::ostream& stream, Cell cell);
};

std::ostream& operator<<(std::ostream& stream, Cell cell) {
	stream <<std::endl << "1. " << cell.animal[0] << "2. " << cell.animal[1] <<"3. " << cell.animal[2] << "4. " << cell.plant << std::endl;
	return stream;
}