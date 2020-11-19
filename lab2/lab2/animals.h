#pragma once

#include <iostream>

class Animal {
protected:
	std::string animal_name;
	std::string voice;
	short food;
	short motion;
	short amount;
public:
	Animal(std::string name, std::string voice_description) {
		animal_name = name;
		voice = voice_description;
		food = 0;
		motion = 0;
		amount = 2;
	}
	Animal() {
		animal_name = "some animal";
		voice = "some animal voice";
		food = 0;
		motion = 0;
		amount = 2;
	}
	short takeFood() {
		food++;
		return food;
	}
	short makeReproduction() {
		amount++;
		return amount;
	}
	std::string makeVoice() {
		return voice;
	}
	virtual short move() {
		motion ++;
		return motion;
	}
	friend std::ostream& operator<< (std::ostream& stream, Animal animal);
};
std::ostream& operator<< (std::ostream& stream, Animal animal) {
	stream << "animal: " << animal.animal_name << "; voice: " << animal.voice << "; feed: " << animal.food << "; motion: " << animal.motion 
		<< "; amount: " << animal.amount;
	return stream;
}