#pragma once

#include<iostream>
#include "birds.h"

class Owl : public Bird {
public:
	Owl(std::string name, std::string wings_description, std::string plumage_description, std::string voice_description) : 
		Bird(name, wings_description, plumage_description, voice_description){}
	Owl() :Bird() {}
	friend std::ostream& operator<< (std::ostream& stream, Owl owl);
	};
std::ostream& operator<< (std::ostream& stream, Owl owl) {
	stream << "Owl: " << owl.animal_name << "; voice: " << owl.voice << "; wings: " << owl.wings << "; plumage: " << owl.plumage
		<< "; feed: " << owl.feed << "; motion: " << owl.motion << "; amount: " << owl.amount;
	return stream;
}