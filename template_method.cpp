#include <iostream>

// Abstract class that defines the basic structure of building a house
class HouseBuilder {
public:
    // Template method that defines the algorithm for building a house
    void buildHouse() {
        buildFoundation();
        buildFrame();
        buildWalls();
        addWindows();
        addDoors();
        buildRoof();
    }
    
    // Abstract methods that must be implemented by subclasses
    virtual void buildFoundation() = 0;
    virtual void buildFrame() = 0;
    virtual void buildWalls() = 0;
    virtual void buildRoof() = 0;
    
    // Default implementations that can be overridden by subclasses
    virtual void addWindows() {
        std::cout << "Adding windows...\n";
    }
    
    virtual void addDoors() {
        std::cout << "Adding doors...\n";
    }
};

// Concrete class that implements the HouseBuilder interface for building a wooden house
class WoodenHouseBuilder : public HouseBuilder {
public:
    void buildFoundation() override {
        std::cout << "Building foundation with wood logs...\n";
    }
    
    void buildFrame() override {
        std::cout << "Building frame with wood logs...\n";
    }
    
    void buildWalls() override {
        std::cout << "Building walls with wood planks...\n";
    }
    
    void buildRoof() override {
        std::cout << "Building roof with wooden shingles...\n";
    }
};

// Concrete class that implements the HouseBuilder interface for building a brick house
class BrickHouseBuilder : public HouseBuilder {
public:
    void buildFoundation() override {
        std::cout << "Building foundation with cement, iron rods, and sand...\n";
    }
    
    void buildFrame() override {
        std::cout << "Building frame with steel beams...\n";
    }
    
    void buildWalls() override {
        std::cout << "Building walls with bricks and mortar...\n";
    }
    
    void buildRoof() override {
        std::cout << "Building roof with tiles...\n";
    }
};

int main() {
    HouseBuilder* builder1 = new WoodenHouseBuilder();
    builder1->buildHouse();
    delete builder1;
    
    HouseBuilder* builder2 = new BrickHouseBuilder();
    builder2->buildHouse();
    delete builder2;
    
    return 0;
}
