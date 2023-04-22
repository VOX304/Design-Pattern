#include <iostream>
#include <vector>

// Iterator Interface
class Iterator {
public:
    virtual bool hasNext() = 0;
    virtual int next() = 0;
};

// Concrete Iterator
class VectorIterator : public Iterator {
public:
    VectorIterator(std::vector<int> vec) : vector_(vec) {
        position_ = 0;
    }

    bool hasNext() override {
        return position_ < vector_.size();
    }

    int next() override {
        int val = vector_[position_];
        position_++;
        return val;
    }

private:
    std::vector<int> vector_;
    int position_;
};

// Collection Interface
class Collection {
public:
    virtual Iterator* createIterator() = 0;
};

// Concrete Collection
class VectorCollection : public Collection {
public:
    VectorCollection(std::vector<int> vec) : vector_(vec) {}

    Iterator* createIterator() override {
        return new VectorIterator(vector_);
    }

private:
    std::vector<int> vector_;
};

// Client
void clientCode(Collection* collection) {
    Iterator* iterator = collection->createIterator();

    while (iterator->hasNext()) {
        std::cout << iterator->next() << " ";
    }

    std::cout << std::endl;

    delete iterator;
}

// Main Function
int main() {
    std::vector<int> vec = {1, 2, 3, 4, 5};
    Collection* collection = new VectorCollection(vec);

    std::cout << "Traversing in order: ";
    clientCode(collection);

    std::cout << "Traversing in reverse order: ";
    std::reverse(vec.begin(), vec.end());
    collection = new VectorCollection(vec);
    clientCode(collection);

    delete collection;

    return 0;
}
