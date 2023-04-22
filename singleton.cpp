#include <iostream>

using namespace std;

class Printer {
    
private:
    Printer() {}  // private constructor to prevent instantiation from outside
    ~Printer() {}; // private detructor to prevent instantiation from outside

    // delete copy constructor and assignment operator to prevent duplication
    Printer(const Printer&) = delete;
    Printer& operator=(const Printer&) = delete;
    
public:
    //public function to take out the instance 
    static Printer& getInstance() {
        static Printer instance;
        return instance;
    }

    void print(const std::string& document){
        cout << "Printing: " << document << '\n';
    }

    static void destroyInstance() {
        Printer& printer = getInstance();
        delete &printer;
    }
};

int main() {
    Printer& printer = Printer::getInstance();
    printer.print("Hello, world!");

    Printer b; //Error
    return 0;
}
