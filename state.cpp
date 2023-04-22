#include <iostream>
#include <string>

// Forward declaration of Context class
class Context;

// Abstract base class for State
class State {
public:
    virtual void insertCoin(Context* context) = 0;
    virtual void dispenseDrink(Context* context) = 0;
};

// Concrete implementation of ReadyState
class ReadyState : public State {
public:
    void insertCoin(Context* context) override;
    void dispenseDrink(Context* context) override {
        std::cout << "Please insert a coin before dispensing a drink." << std::endl;
    }
};

// Concrete implementation of DispensingState
class DispensingState : public State {
public:
    void insertCoin(Context* context) override {
        std::cout << "Please wait, currently dispensing a drink." << std::endl;
    }
    void dispenseDrink(Context* context) override;
};

// Concrete implementation of RefillingState
class RefillingState : public State {
public:
    void insertCoin(Context* context) override {
        std::cout << "Sorry, the machine is currently being refilled. Please try again later." << std::endl;
    }
    void dispenseDrink(Context* context) override {
        std::cout << "Sorry, the machine is currently being refilled. Please try again later." << std::endl;
    }
};

// Context class that contains the current state
class Context {
public:
    Context() : currentState(new ReadyState()) {}
    void setState(State* state) {
        delete currentState;
        currentState = state;
    }
    void insertCoin() {
        currentState->insertCoin(this);
    }
    void dispenseDrink() {
        currentState->dispenseDrink(this);
    }
private:
    State* currentState;
};

void ReadyState::insertCoin(Context* context) {
    std::cout << "Coin inserted. Dispensing drink..." << std::endl;
    context->setState(new DispensingState());
}

void DispensingState::dispenseDrink(Context* context) {
    std::cout << "Drink dispensed. Thank you for your purchase." << std::endl;
    context->setState(new ReadyState());
}

int main() {
    Context vendingMachine;
    
    vendingMachine.insertCoin(); // Outputs "Please insert a coin before dispensing a drink."
    vendingMachine.dispenseDrink(); // Outputs "Please insert a coin before dispensing a drink."
    
    vendingMachine.setState(new RefillingState());
    vendingMachine.insertCoin(); // Outputs "Sorry, the machine is currently being refilled. Please try again later."
    vendingMachine.dispenseDrink(); // Outputs "Sorry, the machine is currently being refilled. Please try again later."
    
    vendingMachine.setState(new ReadyState());
    vendingMachine.insertCoin(); // Outputs "Coin inserted. Dispensing drink..."
    vendingMachine.dispenseDrink(); // Outputs "Drink dispensed. Thank you for your purchase."
    
    return 0;
}
