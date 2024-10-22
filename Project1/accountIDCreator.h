
#pragma once
#include <random>
#include <string>
#include <set>

class RandomAccountIDCreator {
private:
    std::set<long long> generatedNumbers;
    std::mt19937 generator;
    std::uniform_int_distribution<long long> distribution;

public:
    class RandomAccountIDCreator();
    std::string generateAccountID();
    bool allNumbersGenerated() const;
};
