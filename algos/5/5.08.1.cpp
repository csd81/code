// c++11
// 5.8.1. Egy rádióadó periodikusan ismétli ugyanazt az adást, minden adás végén egy speciális jelet ad (#). Az adássorozat egy szekvenciális karakter tömbben van, döntsük el egy sor adatszerkezetet használva, hogy volt-e hiba valamelyik adásban! Hiba az adásban: nem mindig ugyanazt a jelsorozatot adta le az adó. 5.9. Zárójelezés

// c++11
#include <iostream>
#include <string>
#include <queue>

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    // Example input; you can replace these with std::getline/std::cin if desired.
    std::string signal = "abcdefg#abcdefg#abfdgcdefg#abdfcdefg#abcdfdefg#abcdefg#adfcvbcdefg#abcde fg#abcdefg#aega";
    std::string pattern = "abcdefg";

    // Split signal on '#' into a queue of messages
    std::queue<std::string> q;
    std::string current;
    for (char c : signal) {
        if (c == '#') {
            if (!current.empty()) {
                q.push(current);
                current.clear();
            }
        } else {
            current += c;
        }
    }
    // In case there's no trailing '#'
    if (!current.empty()) {
        q.push(current);
    }

    // Process the queue: check each segment against the pattern
    int idx = 1;
    while (!q.empty()) {
        const std::string& msg = q.front();
        bool ok = (msg == pattern);
        std::cout << idx << ". \"" << msg << "\" -> "
                  << (ok ? "OK" : "Wrong") << "\n";
        q.pop();
        ++idx;
    }

    return 0;
}
