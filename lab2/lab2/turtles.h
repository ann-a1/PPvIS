#pragma once

#include<iostream>
#include "reptils.h"

class Turtle : public Reptile {
	std::string shell;
public:
	Turtle(std::string name, std::string scale_description, std::string shell_description, std::string voice_description):
		Reptile(name, scale_description, voice_description) {
		shell = shell_description;
	}
	Turtle() : Reptile() {
		shell = "beautiful shell";
	}
	friend std::ostream& operator<< (std::ostream& stream, Turtle turtle);
};
std::ostream& operator<< (std::ostream& stream, Turtle turtle) {
	stream << "turtle: " << turtle.animal_name << "; voice: " << turtle.voice << "; scale: " << turtle.scale << "; shell: " << turtle.shell
		<< "; feed: " << turtle.feed << "; motion: " << turtle.motion << "; amount: " << turtle.amount;
	return stream;
}