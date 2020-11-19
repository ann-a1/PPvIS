#pragma once

#include<iostream>
#include "mammals.h"

class Placental : public Mammal {
public:
	Placental(std::string name, std::string skin_description, std::string voice_description): Mammal(name, skin_description, voice_description){}
	Placental() :Mammal(){}
	friend std::ostream& operator<< (std::ostream& stream, Placental pl);
};
std::ostream& operator<< (std::ostream& stream, Placental placental) {
	stream << "Placental: " << placental.animal_name << "; voice: " << placental.voice << "; skin: " << placental.skin
		<< "; feed: " << placental.feed << "; motion: " << placental.motion << "; amount: " << placental.amount;
	return stream;
}