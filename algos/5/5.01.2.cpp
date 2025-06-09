// c++11
// 5.1.2. Valósítsa meg a vermet dinamikus tömbbel! Ha betelt a tömb, foglaljon le egy nagyobbat 5.2. Verem

#include <iostream>

class DynamicIntStack {
    int *store;
    int elemnum;    // next free index
    int capacity;

    // Double the capacity
    void increaseCapacity() {
        int newCap = capacity * 2;
        int *temp = new int[newCap];
        for (int i = 0; i < elemnum; ++i) {
            temp[i] = store[i];
        }
        delete[] store;
        store = temp;
        capacity = newCap;
        std::cout << "[Resized to capacity " << capacity << "]\n";
    }

public:
    DynamicIntStack() : elemnum(0), capacity(1) {
        store = new int[capacity];
    }
    ~DynamicIntStack() {
        delete[] store;
    }

    bool isEmpty() const {
        return elemnum == 0;
    }
    bool isFull() const {
        return elemnum == capacity;
    }

    void push(int v) {
        if (isFull()) {
            increaseCapacity();
        }
        store[elemnum++] = v;
    }

    bool pop(int &out) {
        if (isEmpty()) return false;
        out = store[--elemnum];
        return true;
    }
};

int main() {
    DynamicIntStack stack;
    char choice;
    int value;

    do {
        std::cout << "\nMenu:\n"
                  << " 1) Push\n"
                  << " 2) Pop\n"
                  << " 3) Is Empty?\n"
                  << " 4) Exit\n"
                  << "Enter choice: ";
        std::cin >> choice;
        switch (choice) {
            case '1':
                std::cout << "Value to push: ";
                std::cin >> value;
                stack.push(value);
                std::cout << "Pushed " << value << "\n";
                break;
            case '2':
                if (stack.pop(value))
                    std::cout << "Popped " << value << "\n";
                else
                    std::cout << "Stack is empty!\n";
                break;
            case '3':
                std::cout << (stack.isEmpty() ? "Stack is empty\n" : "Stack is not empty\n");
                break;
            case '4':
                std::cout << "Exiting.\n";
                break;
            default:
                std::cout << "Invalid choice.\n";
        }
    } while (choice != '4');

    return 0;
}
