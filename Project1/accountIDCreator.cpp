#include "accountIDCreator.h"

RandomAccountIDCreator::RandomAccountIDCreator()
    : generator(std::random_device{}()), distribution(0, 9999999999LL) {}

std::string RandomAccountIDCreator::generateAccountID() {
    long long number;
    do {
        number = distribution(generator);
    } while (generatedNumbers.count(number) > 0);
    generatedNumbers.insert(number);
    return "TR" + std::to_string(number);
}

bool RandomAccountIDCreator::allNumbersGenerated() const {
    return generatedNumbers.size() >= 10000000000; // 10 billion possible numbers
}
