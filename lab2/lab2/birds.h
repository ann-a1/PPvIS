#pragma once

#include<iostream>
#include "animals.h"

class Bird : public Animal {
protected:
	std::string wings;
	std::string plumage;
public:
	Bird(std::string name, std::string wings_description, std::string plumage_description, std::string voice_description): Animal(name, voice_description) {
		plumage = plumage_description;
		wings = wings_description;
		voice = voice_description;
	}
	Bird(): Animal(){
		wings = "two beautiful wings";
		plumage = "beautiful plumage";
	}
	friend std::ostream& operator<< (std::ostream& stream, Bird bird);
};
std::ostream& operator<< (std::ostream& stream, Bird bird) {
	stream << "bird: " << bird.animal_name << "; voice: " << bird.voice << "; wings: " << bird.wings << "; plumage: " << bird.plumage
		<< "; feed: " << bird.feed << "; motion: " << bird.motion << "; amount: " << bird.amount;
	return stream;
}
