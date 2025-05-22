// c++11
// 8.5.1. Valósítsa meg a kupacrendezést! 
// A kupac legyen tömbbel reprezentálva! 
// Minden tömbelem mutasson egy fejhallgató típusú struktúrára, amelynek az adattagjai: azonosító - egész, név - sztring, ár - lebegőpontos. 
// Írja meg a következő függvényeket: egy fejhallgató adatainak kiírása, kupac kiírása (minden fejhallgató külön sorba, az azonos mezők egy oszlopban legyenek), a mutató tömb két elemének felcserélése, felszivárog, kupacépítés, kupacrendezés!  



#include <iostream>
#include <iomanip>
#include <vector>
#include <string>

struct Headphone {
    int         ID;
    std::string name;
    float       price;
};

// Swap two pointers in the heap array
void exchange(std::vector<Headphone*>& heap, int i, int j) {
    std::swap(heap[i], heap[j]);
}

// Restore max-heap property in subtree rooted at `parent`
void downHeap(std::vector<Headphone*>& heap, int size, int parent) {
    int largest = parent;
    int left    = 2 * parent + 1;
    int right   = 2 * parent + 2;

    if (left < size && heap[left]->ID > heap[largest]->ID)
        largest = left;
    if (right < size && heap[right]->ID > heap[largest]->ID)
        largest = right;

    if (largest != parent) {
        exchange(heap, parent, largest);
        downHeap(heap, size, largest);
    }
}

// Build a max-heap out of the array
void buildHeap(std::vector<Headphone*>& heap) {
    int n = heap.size();
    for (int i = n/2 - 1; i >= 0; --i) {
        downHeap(heap, n, i);
    }
}

// Heapsort: repeatedly remove max and rebuild heap
void heapSort(std::vector<Headphone*>& heap) {
    buildHeap(heap);
    for (int sz = heap.size(); sz > 1; --sz) {
        exchange(heap, 0, sz - 1);
        downHeap(heap, sz - 1, 0);
    }
}

// Print a single headphone
void printHeadphone(const Headphone* h) {
    std::cout << "[ "
              << "ID:"   << std::setw(3) << h->ID << "  "
              << "name:" << std::setw(10) << h->name << "  "
              << "price:" << std::setw(8) << std::fixed << std::setprecision(2) << h->price
              << " ]\n";
}

// Print the entire heap/array with columns aligned
void printHeap(const std::vector<Headphone*>& heap) {
    std::cout << std::left
              << std::setw(6)  << "ID"
              << std::setw(12) << "Name"
              << std::setw(8)  << "Price"
              << "\n"
              << std::string(26, '-') << "\n";
    for (const auto* h : heap) {
        std::cout << std::setw(6)  << h->ID
                  << std::setw(12) << h->name
                  << std::setw(8)  << std::fixed << std::setprecision(2) << h->price
                  << "\n";
    }
}

int main() {
    // Create some headphones
    Headphone a{23, "Genius",  2710.0f};
    Headphone b{ 7, "MS",      3250.0f};
    Headphone c{63, "Verano",  1160.0f};
    Headphone d{11, "LG",      6980.0f};
    Headphone e{ 9, "Samsung", 2370.0f};
    Headphone f{42, "Ele",     1260.0f};
    Headphone g{12, "Azona",   1230.0f};

    // Array of pointers
    std::vector<Headphone*> heap = { &a, &b, &c, &d, &e, &f, &g };

    std::cout << "Unordered heap:\n";
    printHeap(heap);

    heapSort(heap);

    std::cout << "\nSorted array (ascending by ID):\n";
    printHeap(heap);

    return 0;
}


