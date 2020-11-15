#include <iostream>
#include "field.h"

int main()
{
    Field A;
    std::string name;
    int x, y, number_in_cell, number_in_cell_prey, menu;
    bool game = 1;

    name = "cheetah";
    A.makeNewAnimal(short(1), name, bool(1), short(2), short(2));
    name = "tree1";
    A.makeNewPlant(name);
    name = "zebra";
    A.makeNewAnimal(short(2), name, bool(0), short(1), short(2));
    name = "deer";
    A.makeNewAnimal(short(2), name, bool(1), short(2), short(2));
    name = "lion";
    A.makeNewAnimal(short(1), name, bool(1), short(2), short(2));
    name = "tree2";
    A.makeNewPlant(name);
    name = "zebra";
    A.makeNewAnimal(short(2), name, bool(1), short(1), short(2));
    name = "cheetah";
    A.makeNewAnimal(short(1), name, bool(0), short(2), short(2));
    name = "lion";
    A.makeNewAnimal(short(1), name, bool(1), short(2), short(2));
    A.makeNewAnimal(short(1), name, bool(0), short(2), short(2));
    name = "zebra";
    A.makeNewAnimal(short(2), name, bool(1), short(2), short(2));
    name = "deer";
    A.makeNewAnimal(short(2), name, bool(0), short(2), short(2));
    A.makeNewAnimal(short(2), name, bool(1), short(2), short(2));

    while (game) {
        std::cout << A;
        for (short i = 0; i < 5; i++) {
        std::cout << "Choose menu item:\n1. Move animal;\n2. Breed animal;\n3. Increase plant;\n4. Feed animal;\n5. End game;\n";
        std::cin >> menu;
            switch (menu) {
            case 1:
                int direction;
                std::cout << "Enter coordinates of animal: x, y and number in cell\n";
                std::cin >> x >> y >> number_in_cell;
                std::cout << "Choose direction: 1 - straight, 2 - back, 3 - right, 4 - left\n";
                std::cin >> direction;
                switch (direction) {
                case 1:
                    A.moveStraight(x, y, number_in_cell);
                    break;
                case 2:
                    A.moveBack(x, y, number_in_cell);
                    break;
                case 3:
                    A.moveRight(x, y, number_in_cell);
                    break;
                case 4:
                    A.moveLeft(x, y, number_in_cell);
                    break;
                }
                std::cout << "was made\n";
                break;
            case 2:
                std::cout << "enter coordinates of animal: x and y\n";
                std::cin >> x >> y;
                A.breedAnimal(x, y);
                std::cout << "was made\n";
                break;
            case 3:
                std::cout << "enter coordinates of plant: x and y\n";
                std::cin >> x >> y;
                A.increasePlant(x, y);
                std::cout << "was made\n";
                break;
            case 4:
                std::cout << "enter coordinates: x, y, numder of hunter in cell and number of prey in cell\n";
                std::cin >> x >> y >> number_in_cell >> number_in_cell_prey;
                A.feedAnimal(x, y, number_in_cell, number_in_cell_prey);
                std::cout << "was made\n";
                break;
            case 5:
                game = 0;
                break;
            }
            if (game == 0) break;
        }
        A.completeDay();
    }
}
