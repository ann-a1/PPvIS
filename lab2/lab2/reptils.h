#pragma once

#include<iostream>
#include "animals.h"

class Reptile: public Animal {
protected:
	std::string scale;
public:
	Reptile(std::string name, std::string scale_description, std::string voice_description) : Animal(name, voice_description) {
		scale = scale_description;
	}
	Reptile(): Animal() {
		scale = "beautiful scale";
	}
	friend std::ostream& operator<< (std::ostream& stream, Reptile reptile);
};
std::ostream& operator<< (std::ostream& stream, Reptile reptile) {
	stream << "Reptil: " << reptile.animal_name << "; voice: " << reptile.voice << "; scale: " << reptile.scale
		<< "; feed: " << reptile.feed << "; motion: " << reptile.motion << "; amount: " << reptile.amount;
	return stream;
}