#include <iostream>
#include <vector>
#include <stack>

// Forward declaration of classes
class Receiver;
class Command;
class Invoker;

// Receiver class
class Receiver {
public:
    void action() {
        std::cout << "Receiver: executing action" << std::endl;
    }
    void undoAction() {
        std::cout << "Receiver: undoing action" << std::endl;
    }
};

// Command class
class Command {
public:
    virtual ~Command() {}
    virtual void execute() = 0;
    virtual void undo() = 0;
};

// ConcreteCommand class
class ConcreteCommand : public Command {
public:
    ConcreteCommand(Receiver* receiver) : receiver(receiver) {}
    virtual void execute() override {
        receiver->action();
    }
    virtual void undo() override {
        receiver->undoAction();
    }
private:
    Receiver* receiver;
};

// Invoker class
class Invoker {
public:
    void addCommand(Command* command) {
        commandList.push_back(command);
        executeCommands();
    }
    void executeCommands() {
        for (auto& command : commandList) {
            command->execute();
        }
    }
    void undoLastCommand() {
        if (!commandList.empty()) {
            Command* lastCommand = commandList.back();
            commandList.pop_back();
            lastCommand->undo();
            undoStack.push(lastCommand);
        }
    }
    void redoLastCommand() {
        if (!undoStack.empty()) {
            Command* lastCommand = undoStack.top();
            undoStack.pop();
            lastCommand->execute();
            commandList.push_back(lastCommand);
        }
    }
private:
    std::vector<Command*> commandList;
    std::stack<Command*> undoStack;
};

// Main function
int main() {
    Receiver* receiver = new Receiver();
    Command* command1 = new ConcreteCommand(receiver);
    Command* command2 = new ConcreteCommand(receiver);
    Command* command3 = new ConcreteCommand(receiver);
    Invoker* invoker = new Invoker();
    
    // Add commands to the invoker
    invoker->addCommand(command1);
    invoker->addCommand(command2);
    invoker->addCommand(command3);
    
    // Execute commands
    invoker->executeCommands();
    
    // Undo last command
    invoker->undoLastCommand();
    
    // Redo last command
    invoker->redoLastCommand();
    
    return 0;
}
