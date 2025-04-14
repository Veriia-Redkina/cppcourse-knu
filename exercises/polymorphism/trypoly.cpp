#include "Polygons.hpp"
#include <iostream>

int main() {
    // create a Pentagon, call its perimeter method
    Pentagon pent(10.0); // довжина сторони 10
    std::cout << "Pentagon perimeter: " << pent.computePerimeter() << std::endl;

    // create a Hexagon, call its perimeter method
    Hexagon hex(10.0);
    std::cout << "Hexagon perimeter: " << hex.computePerimeter() << std::endl;

    // create a Hexagon, call the perimeter method through a reference to Polygon
    Hexagon hex_2{10.0};
    RegularPolygon &poly = hex_2;
    std::cout << "Hexagon perimeter: " << hex_2.computePerimeter() << std::endl
              << "Hexagon (as Polygon) perimeter: " << poly.computePerimeter() << std::endl;
   
    // retry virtual method

}
