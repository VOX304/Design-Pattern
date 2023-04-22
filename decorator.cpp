#include <iostream>

class Coffee {
public:
    virtual double getCost() = 0;
    virtual std::string getDescription() = 0;
};

class Espresso : public Coffee {
public:
    double getCost() {
        return 2.0;
    }
    std::string getDescription() {
        return "Espresso";
    }
};

class CoffeeDecorator : public Coffee {
public:
    CoffeeDecorator(Coffee* coffee) {
        this->coffee = coffee;
    }
    double getCost() {
        return coffee->getCost();
    }
    std::string getDescription() {
        return coffee->getDescription();
    }
private:
    Coffee* coffee;
};

class Cream : public CoffeeDecorator {
public:
    Cream(Coffee* coffee) : CoffeeDecorator(coffee) {
    }
    double getCost() {
        return CoffeeDecorator::getCost() + 0.5;
    }
    std::string getDescription() {
        return CoffeeDecorator::getDescription() + ", Cream";
    }
};

int main() {
    Coffee* espresso = new Espresso();
    std::cout << espresso->getDescription() << " costs $" << espresso->getCost() << std::endl;

    Coffee* espressoWithCream = new Cream(espresso);
    std::cout << espressoWithCream->getDescription() << " costs $" << espressoWithCream->getCost() << std::endl;

    delete espresso;
    delete espressoWithCream;
    return 0;
}
