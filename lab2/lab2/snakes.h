#pragma once

#include<iostream>
#include "reptils.h"

class Snake : public Reptile {
	std::string poison;
public:
	Snake(std::string name, std::string scale_description, std::string voice_description, std::string poison_description) :
		Reptile(name, scale_description, voice_description) {
		poison = poison_description;
	}
	Snake() :Reptile(){
		poison = "some poison";
	}
	friend std::ostream& operator<< (std::ostream& stream, Snake snake);
};
std::ostream& operator<< (std::ostream& stream, Snake snake) {
	stream << "Snake: " << snake.animal_name << "; voice: " << snake.voice << "; scale: " << snake.scale << "; poison: " << snake.poison
		<< "; feed: " << snake.feed << "; motion: " << snake.motion << "; amount: " << snake.amount;
	return stream;
}