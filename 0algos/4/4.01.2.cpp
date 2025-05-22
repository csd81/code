// c++11
// 4.1.2. Írjon függvényt, amely a lista első elemét törli! Írjon függvényt, amely ellenőrzi, hogy az tömb konzisztens-e, vagyis a benne lévő indexek a megengedett tartományban vannak-e, a start elemtől indulva nem jelentkezik kör! 

#include <iostream>
#include <vector>
#include <unordered_set>
#include <iomanip>

void printList(int head,
               const std::vector<int>& nextIdx,
               const std::vector<double>& data)
{
    std::cout << "[";
    for (int cur = head; cur != -1; cur = nextIdx[cur]) {
        std::cout << std::fixed << std::setprecision(2) << data[cur];
        if (nextIdx[cur] != -1) std::cout << ", ";
    }
    std::cout << "]\n";
}

// Deletes the first node in the list.
// head: index of first element (or -1 if empty).
// nextIdx: array of next‐indices; after removal, nextIdx[oldHead] is set to -1.
void deleteFirst(int& head, std::vector<int>& nextIdx) {
    if (head == -1) return;
    int old = head;
    head = nextIdx[old];
    nextIdx[old] = -1;
}

// Returns true if the list starting at head is well‐formed:
// 1) all visited indices are in [0..n-1]
// 2) no index is visited twice (no cycle)
// 3) traversal ends at -1
bool isConsistent(const std::vector<int>& nextIdx, int head) {
    int n = nextIdx.size();
    std::unordered_set<int> seen;
    int cur = head;
    while (cur != -1) {
        // 1) range check
        if (cur < 0 || cur >= n) {
            std::cerr << "Index out of bounds: " << cur << "\n";
            return false;
        }
        // 2) cycle check
        if (seen.count(cur)) {
            std::cerr << "Cycle detected at index: " << cur << "\n";
            return false;
        }
        seen.insert(cur);
        cur = nextIdx[cur];
    }
    return true;
}

int main() {
    // Initial data
    std::vector<double> data   = { 34, 12.55, 893.2, 2, 11.6, 47.5, 45.3 };
    std::vector<int>    nextIdx= { -1,   0,      4,     1,   6,    3,    5   };
    int head = 2;  // start at index 2

    std::cout << "Original list: ";
    printList(head, nextIdx, data);

    // Delete first element
    deleteFirst(head, nextIdx);
    std::cout << "After deleteFirst: ";
    if (!isConsistent(nextIdx, head)) {
        std::cout << "List is inconsistent!\n";
        return 1;
    }
    printList(head, nextIdx, data);

    return 0;
}

