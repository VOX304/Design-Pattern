#include <iostream>
#include <list>
#include <string>

// Component interface
class Component {
public:
    virtual void add(Component* component) = 0;
    virtual void remove(Component* component) = 0;
    virtual void display() = 0;
};

// Leaf class
class File : public Component {
public:
    File(std::string name) : name(name) {}

    void add(Component* component) override {}
    void remove(Component* component) override {}
    void display() override {
        std::cout << "File: " << name << std::endl;
    }

private:
    std::string name;
};

// Composite class
class Folder : public Component {
public:
    Folder(std::string name) : name(name) {}

    void add(Component* component) override {
        children.push_back(component);
    }
    void remove(Component* component) override {
        children.remove(component);
    }
    void display() override {
        std::cout << "Folder: " << name << std::endl;
        for (auto child : children) {
            child->display();
        }
    }

private:
    std::string name;
    std::list<Component*> children;
};

// Client code
int main() {
    // Create a file
    Component* file = new File("file.txt");

    // Create a folder and add the file to it
    Component* folder = new Folder("Folder 1");
    folder->add(file);

    // Create another folder and add the first folder to it
    Component* folder2 = new Folder("Folder 2");
    folder2->add(folder);

    // Display the contents of the second folder (which should show both the file and the first folder)
    folder2->display();

    // Clean up memory
    delete file;
    delete folder;
    delete folder2;

    return 0;
}
