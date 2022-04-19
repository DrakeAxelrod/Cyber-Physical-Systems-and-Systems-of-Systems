#include <iostream>
#include "SensorReading.hpp"

int main(int argc, char **argv)
{
    if (argc == 2)
    {
        int number1 = std::stoi(argv[1]);
        int number2 = std::stoi(argv[2]);
        SensorReading sensor;
        std::cout << "Group5 " << number1 << " + " << number2 << " equals " << sensor.Addition(number1, number2) << std::endl;
        std::cout << "Group5 " << number1 << " * " << number2 << " equals " << sensor.Multiply(number1, number2) << std::endl;
    }
    return 0;
}