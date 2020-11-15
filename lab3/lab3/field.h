#pragma once
#include <fstream>
#include <ctime>
#include <cstdlib>
#include "cell.h"
#include "plant.h"

class Field {
	Cell field[5][3];
public:
	Field moveStraight(int x, int y, int number_in_cell) {
		int y_max = y + this->field[x][y].showAnimal(number_in_cell).move_points;
		if (y_max > 2) y_max = 2;
		Animal animal(this->field[x][y].showAnimal(number_in_cell));
		this->field[x][y].deleteAnimalByNumber(number_in_cell);
		for (y_max; y_max >=y; y--) {
			if (!this->field[x][y_max].existence[2]) {
				this->field[x][y_max].addAnimal(animal);
				return *this;
			}
		}
		return *this;
	}

	Field moveBack(int x, int y, int number_in_cell) {
		int y_min = y - this->field[x][y].showAnimal(number_in_cell).move_points;
		if (y_min < 0) y_min = 0;
		Animal animal(this->field[x][y].showAnimal(number_in_cell));
		this->field[x][y].deleteAnimalByNumber(number_in_cell);
		for (y_min; y_min <= y; y_min++) {
			if (!this->field[x][y_min].existence[2]) {
				this->field[x][y_min].addAnimal(animal);
				return *this;
			}
		}
		return *this;
	}

	Field moveLeft(int x, int y, int number_in_cell) {
		int x_min = x - this->field[x][y].showAnimal(number_in_cell).move_points;
		if (x_min < 0) x_min = 0;
		Animal animal(this->field[x][y].showAnimal(number_in_cell));
		this->field[x][y].deleteAnimalByNumber(number_in_cell);
		for (x_min; x_min <= x; x_min++) {
			if (!this->field[x_min][y].existence[2]) {
				this->field[x_min][y].addAnimal(animal);
				return *this;
			}
		}
		return *this;
	}

	Field moveRight(int x, int y, int number_in_cell) {
		int x_max = x + this->field[x][y].showAnimal(number_in_cell).move_points;
		if (x_max > 4) x_max = 4;
		Animal animal(this->field[x][y].showAnimal(number_in_cell));
		this->field[x][y].deleteAnimalByNumber(number_in_cell);
		for (x_max; x_max >= x; x--) {
			if (!this->field[x_max][y].existence[2]) {
				this->field[x_max][y].addAnimal(animal);
				return *this;
			}
		}
		return *this;
	}

	Field makeNewAnimal(short type_1_2, std::string name, bool gender_0b_1g, short speed_1_2, short size_1_to_3) {
		std::srand(time(NULL));
		int x = rand() % 5;
		int y = rand() % 3;
		while (field[x][y].cellIsEmpty(short(2)) == 0) {
			x = rand() % 5;
			y = rand() % 3;
		}
		Animal predator(name, speed_1_2, gender_0b_1g, size_1_to_3, short(1));
		Animal herbivore(name, speed_1_2, gender_0b_1g, size_1_to_3, short(2));
		if (type_1_2 == 1) {
			field[x][y].addAnimal(predator);
		}
		else
			field[x][y].addAnimal(herbivore);
		x = rand() % 5;
		y = rand() % 3;
		return *this;
	}

	Field makeExistingAnimal(int x, int y, int number_in_cell, bool gender) {
		Animal temp = this->field[x][y].showAnimal(number_in_cell);
		std::srand(time(NULL));
		int new_x = rand() % 5;
		int new_y = rand() % 3;
		while (field[x][y].cellIsEmpty(short(2)) == 0) {
			new_x = rand() % 5;
			new_y = rand() % 3;
		}
		field[new_x][new_y].addAnimal(temp);
		return *this;
	}

	Field makeNewPlant(std::string name) {
		std::srand(time(NULL));
		int x = rand() % 5;
		int y = rand() % 3;
		while (field[x][y].checkPlantFree() == 0) {
			x = rand() % 5;
			y = rand() % 3;
		}
		Plant plant(name);
		field[x][y].addPlant(plant);
		return *this;
	}

	Field makeExistingPlant(int x, int y) {
		Plant temp = this->field[x][y].showPlant();
		std::srand(time(NULL));
		int new_x = rand() % 5;
		int new_y = rand() % 3;
		while (field[x][y].checkPlantFree() == 0) {
			new_x = rand() % 5;
			new_y = rand() % 3;
		}
		field[new_x][new_y].addPlant(temp);
		return *this;
	}

	Field breedAnimal(int x, int y) {
		for (int i = 1; i < 4; i++) {
			for (int j = 2; j < 4; j++) {
				if (field[x][y].showAnimal(i).entity_name == field[x][y].showAnimal(j).entity_name &&
					field[x][y].showAnimal(i).showGender() != field[x][y].showAnimal(j).showGender()) {
					Animal temp = field[x][y].showAnimal(i);
					field[x][y].addAnimal(temp);
					return *this;
				}
			}
		}
		return *this;
	}

	Field increasePlant(int x, int y) {
		Plant temp(field[x][y].plant);
		int temp_x_min = x--, temp_x_max = x++, temp_y_min = y--, temp_y_max = y++;
		if (field[temp_x_min][y].checkPlantFree()) {
			field[temp_x_min][y].addPlant(temp);
			return *this;
		}
		if (field[temp_x_max][y].checkPlantFree()) {
			field[temp_x_max][y].addPlant(temp);
			return *this;
		}
		if (field[x][temp_y_min].checkPlantFree()) {
			field[x][temp_y_min].addPlant(temp);
			return *this;
		}
		if (field[x][temp_y_max].checkPlantFree()) {
			field[x][temp_y_max].addPlant(temp);
			return *this;
		}
		if (field[temp_x_min][y].plant.takeLifePoints() < 100 || field[temp_x_min][y].plant.takeLifePoints() > 0) {
			field[temp_x_min][y].plant.RefillLifePoints();
			return *this;
		}
		if (field[temp_x_max][y].plant.takeLifePoints() < 100 || field[temp_x_max][y].plant.takeLifePoints() > 0) {
			field[temp_x_max][y].plant.RefillLifePoints();
			return *this;
		}
		if (field[x][temp_y_min].plant.takeLifePoints() < 100 || field[x][temp_y_min].plant.takeLifePoints() > 0) {
			field[x][temp_y_min].plant.RefillLifePoints();
			return *this;
		}
		if (field[x][temp_y_max].plant.takeLifePoints() < 100 || field[x][temp_y_max].plant.takeLifePoints() > 0) {
			field[x][temp_y_max].plant.RefillLifePoints();
			return *this;
		}
		return *this;
	}

	Field feedAnimal(int x, int y, int number_of_hunter, int number_of_prey) {
		Animal temp_hunter(this->field[x][y].showAnimal(number_of_hunter));
		if (temp_hunter.type_of_entity == 2) {
			if (temp_hunter.type_of_entity == this->field[x][y].showAnimal(number_of_prey).type_of_entity ||
				temp_hunter.size < this->field[x][y].showAnimal(number_of_prey).size) return *this;
			if (temp_hunter.move_points < this->field[x][y].showAnimal(number_of_prey).move_points) {
				std::srand(time(NULL));
				short chance = rand() % 7;
				if (chance == 3) return *this;
			}
			temp_hunter.addLifePoints();
			this->field[x][y].changeAnimalInCell(number_of_hunter, temp_hunter);
			this->field[x][y].deleteAnimalByNumber(number_of_prey);
		}
		if (temp_hunter.type_of_entity == 1) {
			if (number_of_prey != 4) return *this;
			Plant temp_plant(this->field[x][y].plant);
			temp_plant.loseLifePoints(temp_hunter.size);
			temp_hunter.addLifePoints();
			this->field[x][y].changeAnimalInCell(number_of_hunter, temp_hunter);
			this->field[x][y].changePlantInCell(temp_plant);
			return *this;
			}
		return *this;
	}

	Field completeDay() {
		for (int i = 0; i < 5; i++) {
			for (int j = 0; j < 3; j++) {
				for (int number_in_cell = 1; number_in_cell < 4; number_in_cell++) {
					if (this->field[i][j].existence[number_in_cell]) {
						Animal temp_animal(this->field[i][j].showAnimal(number_in_cell));
						temp_animal.loseLifeHours();
						if (temp_animal.takeLifePoints() <= 0) this->field[i][j].deleteAnimalByNumber(number_in_cell);
						this->field[i][j].changeAnimalInCell(number_in_cell, temp_animal);
					}
				}
				if (this->field[i][j].existence[3]) {
					Plant plant(this->field[i][j].showPlant());
					plant.loseLifePoints(short(1));
					this->field[i][j].changePlantInCell(plant);
				}
			}
		}
		return *this;
	}

	friend std::ostream& operator<<(std::ostream& stream, Field field);
};
std::ostream& operator<<(std::ostream& stream, const Field field) {
	stream << std::endl << std::endl << "Field" << std::endl;
	for (short i = 0; i < 5; i++) {
		for (short j = 0; j < 3; j++) {
			stream << "cell " << i << " " << j << ":" << field.field[i][j];
		}
	}
	return stream;
}