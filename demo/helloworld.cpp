#include <iostream>
#include "PrimeChecker.hpp"

int main(int argc, char** argv) {
    if (argc == 2) {
        int number = std::stoi(argv[1]);
        PrimeChecker pc;
        std::cout << "Group 5; " << number << " is a prime number? " << pc.isPrime(number) << std::endl;
    }
    return 0;
}