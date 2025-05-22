// c++11
// 5.9.1. Kérjünk be egy kifejezést, ami több nyitó és zárójelet tartalmaz!
// Verem segítségével írjuk ki az összetartozó zárójelpárok indexeit,
// és közben döntsük el, hogy helyes-e a zárójelezés!  


#include <iostream>
#include <string>
#include <stack>

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    std::string expr;
    std::cout << "Enter expression with parentheses: ";
    std::getline(std::cin, expr);

    std::stack<int> st;
    bool error = false;

    for (int i = 0; i < static_cast<int>(expr.size()); ++i) {
        char c = expr[i];
        if (c == '(') {
            st.push(i);
        } else if (c == ')') {
            if (st.empty()) {
                std::cout << "Error: unmatched ')' at index " << i << "\n";
                error = true;
                break;
            }
            int openIdx = st.top();
            st.pop();
            std::cout << "Matched parentheses: '(' at index "
                      << openIdx << " with ')' at index " << i << "\n";
        }
    }

    if (!error) {
        if (!st.empty()) {
            while (!st.empty()) {
                std::cout << "Error: unmatched '(' at index " << st.top() << "\n";
                st.pop();
            }
        } else {
            std::cout << "All parentheses matched correctly.\n";
        }
    }

    return 0;
}