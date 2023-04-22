#include <iostream>

// Shape Interface
class Shape {
public:
    virtual void draw() = 0;
};

// Concrete Shapes
class Circle : public Shape {
public:
    void draw() {
        std::cout << "Drawing a Circle" << std::endl;
    }
};

class Rectangle : public Shape {
public:
    void draw() {
        std::cout << "Drawing a Rectangle" << std::endl;
    }
};

class Triangle : public Shape {
public:
    void draw() {
        std::cout << "Drawing a Triangle" << std::endl;
    }
};

// ShapeFactory Interface
class ShapeFactory {
public:
    virtual Shape* createShape() = 0;
};

// Concrete Shape Factories
class CircleFactory : public ShapeFactory {
public:
    Shape* createShape() {
        return new Circle();
    }
};

class RectangleFactory : public ShapeFactory {
public:
    Shape* createShape() {
        return new Rectangle();
    }
};

class TriangleFactory : public ShapeFactory {
public:
    Shape* createShape() {
        return new Triangle();
    }
};

// Abstract GUI Factory Interface
class GUIFactory {
public:
    virtual Button* createButton() = 0;
    virtual Menu* createMenu() = 0;
    virtual TextBox* createTextBox() = 0;
};

// Concrete GUI Factories
class WindowsGUIFactory : public GUIFactory {
public:
    Button* createButton() {
        return new WindowsButton();
    }

    Menu* createMenu() {
        return new WindowsMenu();
    }

    TextBox* createTextBox() {
        return new WindowsTextBox();
    }
};

class MacGUIFactory : public GUIFactory {
public:
    Button* createButton() {
        return new MacButton();
    }

    Menu* createMenu() {
        return new MacMenu();
    }

    TextBox* createTextBox() {
        return new MacTextBox();
    }
};

class LinuxGUIFactory : public GUIFactory {
public:
    Button* createButton() {
        return new LinuxButton();
    }

    Menu* createMenu() {
        return new LinuxMenu();
    }

    TextBox* createTextBox() {
        return new LinuxTextBox();
    }
};

// GUI Components
class Button {
public:
    virtual void paint() = 0;
};

class WindowsButton : public Button {
public:
    void paint() {
        std::cout << "Painting a Windows Button" << std::endl;
    }
};

class MacButton : public Button {
public:
    void paint() {
        std::cout << "Painting a Mac Button" << std::endl;
    }
};

class LinuxButton : public Button {
public:
    void paint() {
        std::cout << "Painting a Linux Button" << std::endl;
    }
};

class Menu {
public:
    virtual void paint() = 0;
};

class WindowsMenu : public Menu {
public:
    void paint() {
        std::cout << "Painting a Windows Menu" << std::endl;
    }
};

class MacMenu : public Menu {
public:
    void paint() {
        std::cout<< "Painting a Mac Menu" << std::endl;
    }
};

class LinuxMenu : public Menu {
public:
    void paint() {
        std::cout << "Painting a Linux Menu" << std::endl;
    }
};

class TextBox {
public:
    virtual void paint() = 0;
};

class WindowsTextBox : public TextBox {
public:
    void paint() {
        std::cout << "Painting a Windows TextBox" << std::endl;
    }
};

class MacTextBox : public TextBox {
public:
    void paint() {
        std::cout << "Painting a Mac TextBox" << std::endl;
    }
};

class LinuxTextBox : public TextBox {
public:
    void paint() {
        std::cout << "Painting a Linux TextBox" << std::endl;
    }
};

// Client Code
int main() {
    // Using Factory Method
    ShapeFactory* shapeFactory = new CircleFactory();
    Shape* shape = shapeFactory->createShape();
    shape->draw();

    // Using Abstract Factory
    GUIFactory* guiFactory = nullptr;
    #ifdef _WIN32
        guiFactory = new WindowsGUIFactory();
    #elif __APPLE__
        guiFactory = new MacGUIFactory();
    #elif __linux__
        guiFactory = new LinuxGUIFactory();
    #endif

    Button* button = guiFactory->createButton();
    Menu* menu = guiFactory->createMenu();
    TextBox* textBox = guiFactory->createTextBox();

    button->paint();
    menu->paint();
    textBox->paint();

    return 0;
}

