#pragma once

#include<iostream>
#include "mammals.h"

class Marsupial : public Mammal {
	std::string bag;
public:
	Marsupial(std::string name, std::string skin_description, std::string voice_description, std::string bag_description) :
		Mammal(name, skin_description, voice_description) {
		bag = bag_description;
	}
	Marsupial() : Mammal() {
		bag = "some bag";
	}
	friend std::ostream& operator<< (std::ostream& stream, Marsupial marsupial);
};
std::ostream& operator<< (std::ostream& stream, Marsupial marsupial) {
	stream << "Marsupial: " << marsupial.animal_name << "; voice: " << marsupial.voice << "; skin: " << marsupial.skin << "; bag: " << marsupial.bag
		<< "; feed: " << marsupial.feed << "; motion: " << marsupial.motion << "; amount: " << marsupial.amount;
	return stream;
}