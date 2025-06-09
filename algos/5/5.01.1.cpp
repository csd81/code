// c++11
// 5.1.1. Készítsen egy verem osztályt, amely statikus, 5 nagyságú egész tömbben tárol értékeket! valósítsa meg a következő metódusokat: init, push, pop, isFull, isEmpty! Ötlet: egyértelműen definiálja, hogy a verem mutató az első szabad elemre vagy az utolsó használt elemre mutat-e! 

#include <iostream>

class IntStack {
    static const int CAPACITY = 5;
    int elems[CAPACITY];
    int elemnum;  // index of next free slot (0…CAPACITY)

public:
    // Initialize to empty
    void init() {
        elemnum = 0;
    }

    // Returns true if no space left
    bool isFull() const {
        return elemnum == CAPACITY;
    }

    // Returns true if nothing to pop
    bool isEmpty() const {
        return elemnum == 0;
    }

    // Pushes n onto stack; returns false if full
    bool push(int n) {
        if (isFull()) return false;
        elems[elemnum++] = n;
        return true;
    }

    // Pops top into n; returns false if empty
    bool pop(int &n) {
        if (isEmpty()) return false;
        n = elems[--elemnum];
        return true;
    }
};

int main() {
    IntStack s;
    s.init();

    char choice;
    int value;

    do {
        std::cout << "\nMenu:\n"
                  << "  1) Push\n"
                  << "  2) Pop\n"
                  << "  3) Is Full?\n"
                  << "  4) Is Empty?\n"
                  << "  5) Exit\n"
                  << "Enter choice: ";
        std::cin >> choice;

        switch (choice) {
            case '1':
                std::cout << "Value to push: ";
                std::cin >> value;
                if (s.push(value))
                    std::cout << "Pushed " << value << "\n";
                else
                    std::cout << "Stack is full!\n";
                break;

            case '2':
                if (s.pop(value))
                    std::cout << "Popped " << value << "\n";
                else
                    std::cout << "Stack is empty!\n";
                break;

            case '3':
                std::cout << (s.isFull() ? "Stack is full\n" : "Stack is not full\n");
                break;

            case '4':
                std::cout << (s.isEmpty() ? "Stack is empty\n" : "Stack is not empty\n");
                break;

            case '5':
                std::cout << "Exiting.\n";
                break;

            default:
                std::cout << "Invalid choice.\n";
        }
    } while (choice != '5');

    return 0;
}

