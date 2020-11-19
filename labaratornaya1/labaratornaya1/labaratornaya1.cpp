#include <iostream>
#include "Vector.h"

int main()
{
    Point A(3, 7, 6);
    Point* adrA = &A;
    Point B(8, 10, 5);
    Point* adrB = &B;

    Point C(1, 9, 2);
    Point* adrC = &C;
    Point D(10, 4, 9);
    Point* adrD = &D;

    Vector AB(adrA, adrB);
    std::cout << AB << std::endl;

    Vector CD(adrC, adrD);
    std::cout << CD << std::endl;

    Vector EF(1, 8, 2, 7, 9, 3);
    std::cout << EF << std::endl;

    Vector a = AB +  EF;
    std::cout << "a: " << a << std::endl;

    Vector b = AB - CD;
    std::cout << "b: " << b << std::endl;

    Vector c = AB * CD;
    std::cout << "c: " << c << std::endl;

    Vector d = AB * (-2);
    std::cout << "d: " << d << std::endl;

    std::cout << (AB / CD) << std::endl;
    std::cout << (AB / EF) << std::endl;
    std::cout << (d / AB) << std::endl;
    std::cout << (d / EF) << std::endl;
    std::cout << (AB ^ CD) << std::endl;
    std::cout << (a ^ b) << std::endl;
    std::cout << (c ^ EF) << std::endl;

    d += c;
    std::cout << "new d: " << d << std::endl;
    c -= AB;
    std::cout << "new c: " << c << std::endl;
    b *= a;
    std::cout << "new b: " << b << std::endl;
    a *= 3;
    std::cout << "new a: " << a << std::endl;
    Vector y = a;
    if (y == a) std::cout << "yes" << std::endl;
    if (a != AB) std::cout << "yes" << std::endl;
    y.getbegin();
    Vector z;
    std::cin >> z;
    std::cout << z;
}
