#include "SensorReading.hpp"
#include "cyphy.hpp"
#include <iostream>

int main(int argc, char **argv) {
  hello("Group5");
  if (argc == 3) {
    int number1 = std::stoi(argv[1]);
    int number2 = std::stoi(argv[2]);
    SensorReading sensor;
    std::cout << "Group5 " << number1 << " + " << number2 << " equals "
              << sensor.Addition(number1, number2) << std::endl;
    std::cout << "Group5 " << number1 << " * " << number2 << " equals "
              << sensor.Multiply(number1, number2) << std::endl;
  } else
    std::cout << "Enter 2 arguments." << std::endl;
  return 0;
}
