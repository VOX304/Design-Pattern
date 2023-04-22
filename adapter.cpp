#include <iostream>

// Existing interface
class Shape {
public:
    virtual void draw() = 0;
};

// Adaptee
class Rectangle {
public:
    void display() {
        std::cout << "Rectangle display function is called." << std::endl;
    }
};

// Adapter
class RectangleAdapter : public Shape {
public:
    RectangleAdapter(Rectangle* rect) {
        m_rect = rect;
    }

    void draw() override {
        m_rect->display();
    }

private:
    Rectangle* m_rect;
};

int main() {
    Rectangle rect;
    RectangleAdapter adapter(&rect);
    adapter.draw();
    return 0;
}
