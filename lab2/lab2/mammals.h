#pragma once

#include<iostream>
#include "animals.h"

class Mammal : public Animal {
protected:
	std::string skin;
public:
	Mammal(std::string name, std::string skin_description, std::string voice_description) : Animal(name, voice_description) {
		skin = skin_description;
	}
	Mammal(): Animal() {
		skin = "beautiful skin";
	}
	friend std::ostream& operator<< (std::ostream& stream, Mammal mammal);
};
std::ostream& operator<< (std::ostream& stream, Mammal mammal) {
	stream << "Mammal: " << mammal.animal_name << "; voice: " << mammal.voice << "; skin: " << mammal.skin << "; feed: " << mammal.feed << "; motion: "
		<< mammal.motion << "; amount: " << mammal.amount;
	return stream;
}