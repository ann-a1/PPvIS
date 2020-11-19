#include <iostream>
#include "owls.h"
#include "placentals.h"
#include "marsupials.h"
#include "snakes.h"
#include "turtles.h"

int main()
{
    std::string name = "polar", wings = "big", plumage = "white", voice = "oooh-oooh";
        Owl polar(name, wings, plumage, voice);
        std::cout << polar << std::endl;
        polar.move();
        polar.takeFood();
        polar.makeReproduction();
        std::cout << polar.makeVoice() << std::endl << polar;
}

