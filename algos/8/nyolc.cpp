//8.1.1. Írjon függvényt, amely buborék illetve minimum kiválasztásos módszerrel rendez egy tömböt! Írjon segédfüggvényeket a minIndex, swap, print (tömb kiírás) feladatokra! 

#include <iostream>
using namespace std;

// Prints the array
void print(const double* arr, int size) {
    cout << "[ ";
    for (int i = 0; i < size; ++i)
        cout << arr[i] << " ";
    cout << "]";
}

// Returns the index of the minimum element in arr[0..size-1]
int minIndex(const double* arr, int size) {
    int minIdx = 0;
    for (int i = 1; i < size; ++i)
        if (arr[i] < arr[minIdx])
            minIdx = i;
    return minIdx;
}

// Swaps arr[id1] and arr[id2]
void swap(double* arr, int id1, int id2) {
    double tmp = arr[id1];
    arr[id1] = arr[id2];
    arr[id2] = tmp;
}

// Selection sort (minimum‐selection) on tomb[0..len-1]
void minSort(double* tomb, int len) {
    for (int i = 0; i < len; ++i) {
        // find min in tomb[i..len-1]
        int c = minIndex(tomb + i, len - i) + i;
        swap(tomb, i, c);
    }
}

// Bubble sort on tomb[0..len-1]
void bubbleSort(double* tomb, int len) {
    for (int i = 0; i < len - 1; ++i) {
        for (int j = 0; j < len - 1 - i; ++j) {
            if (tomb[j] > tomb[j + 1]) {
                swap(tomb, j, j + 1);
            }
        }
    }
}

int main() {
    double myArray[]  = { 22, 16, -7, -42, 6 };
    double myArray2[] = { 22, 16, -7, -42, 6 };
    int size = sizeof(myArray) / sizeof(myArray[0]);

    cout << "Original myArray: ";
    print(myArray, size);
    cout << endl;

    minSort(myArray, size);
    cout << "Min‐sorted myArray: ";
    print(myArray, size);
    cout << endl << endl;

    cout << "Original myArray2: ";
    print(myArray2, size);
    cout << endl;

    bubbleSort(myArray2, size);
    cout << "Bubble‐sorted myArray2: ";
    print(myArray2, size);
    cout << endl;

    return 0;
}
// 8.1.2. Ismerje meg és valósítson meg a következő rendező függvények közül kettőt! Beszúró rendezés, shell rendezése, radix rendezés, shaker rendezés, heap rendezés, comb rendezés. 8.2. Rekurzív függvények

// Below is a clean C++11 example that implements both **comb sort** and **(binary) insertion sort**, then demonstrates them on the same array. I’ve also included a simple `print()` helper to show the results.


#include <iostream>
#include <vector>
using namespace std;

// -----------------------------------------------------------------------------
// Helper: print array
void print(const vector<int>& arr) {
    cout << "[ ";
    for (int x : arr) cout << x << " ";
    cout << "]\n";
}

// -----------------------------------------------------------------------------
// Comb Sort
// Shrinks gap by factor ≈1.3 each pass; finishes with a final bubble-pass (gap=1).
void combSort(vector<int>& arr) {
    const double SHRINK = 1.3;
    int gap = arr.size();
    bool swapped = false;

    while (gap > 1 || swapped) {
        // update gap for next comb
        gap = int(gap / SHRINK);
        if (gap < 1) gap = 1;

        swapped = false;
        // one "comb" over the array
        for (size_t i = 0; i + gap < arr.size(); ++i) {
            if (arr[i] > arr[i + gap]) {
                swap(arr[i], arr[i + gap]);
                swapped = true;
            }
        }
    }
}

// -----------------------------------------------------------------------------
// Binary Insertion Sort
// Uses binary search to find insertion point in the sorted prefix.
void insertionSort(vector<int>& arr) {
    for (size_t i = 1; i < arr.size(); ++i) {
        int key = arr[i];
        // find insertion position in [0..i-1]
        size_t lo = 0, hi = i;
        while (lo < hi) {
            size_t mid = lo + (hi - lo) / 2;
            if (key < arr[mid])
                hi = mid;
            else
                lo = mid + 1;
        }
        // shift elements right to make room for key
        for (size_t j = i; j > lo; --j) {
            arr[j] = arr[j - 1];
        }
        arr[lo] = key;
    }
}

// -----------------------------------------------------------------------------
// Demonstration
int main() {
    vector<int> original = {5, 8, 3, 4, 12, 45, 87};

    // Comb sort
    auto a1 = original;
    cout << "Before combSort:     "; print(a1);
    combSort(a1);
    cout << "After combSort:      "; print(a1);
    cout << "\n";

    // Insertion sort
    auto a2 = original;
    cout << "Before insertionSort:"; print(a2);
    insertionSort(a2);
    cout << "After insertionSort: "; print(a2);

    return 0;
}
/*
*```

**Key points:**

* **`combSort`** repeatedly reduces the comparison gap by ≈1.3 until it reaches 1, and does a final bubble‐style pass to ensure full ordering.
* **`insertionSort`** uses binary search to locate where each new element belongs in the already‐sorted prefix, then shifts elements to insert it.
* `print()` takes a `vector<int>&` and writes it in a nice `[ ... ]` format.

Feel free to swap in plain arrays if you prefer, but `std::vector` makes resizing and bounds clearer in modern C++.

*/// 8.2.1. Valósítsa meg a gyorsrendezést! Mindig írja ki, hogy milyen mélyen van a rekurzióban statikus változó segítségével, és hogy mely résztömböt rendezi éppen! A kiírásokat a rekurzió mélysége alapján tabulálja! 


#include <iostream>
#include <iomanip>
using namespace std;

// Print the array
void print(const double* arr, int size) {
    cout << "[ ";
    for (int i = 0; i < size; ++i) {
        // fixed precision for readability
        cout << fixed << setprecision(2) << arr[i] << " ";
    }
    cout << "]";
}

// Swap two elements in the array
void swap(double* arr, int i, int j) {
    double tmp = arr[i];
    arr[i] = arr[j];
    arr[j] = tmp;
}

// Hoare partition scheme: returns index j such that arr[left..j] ≤ pivot ≤ arr[j+1..right]
int partition(double* arr, int left, int right) {
    double pivot = arr[left + (right - left) / 2];
    int i = left - 1;
    int j = right + 1;
    while (true) {
        // move j left until arr[j] ≤ pivot
        do { --j; } while (arr[j] > pivot);
        // move i right until arr[i] ≥ pivot
        do { ++i; } while (arr[i] < pivot);
        if (i < j) {
            swap(arr, i, j);
        } else {
            return j;
        }
    }
}

// QuickSort with recursion-depth tracing
void quickSort(double* arr, int left, int right) {
    static int level = 0;
    ++level;

    // indent according to recursion level
    for (int t = 0; t < level - 1; ++t) cout << "\t";
    cout << "Begin quickSort level " << level
         << ", range [" << left << ", " << right << "]\n";

    if (left < right) {
        int split = partition(arr, left, right);
        quickSort(arr, left, split);
        quickSort(arr, split + 1, right);
    }

    for (int t = 0; t < level - 1; ++t) cout << "\t";
    cout << "End   quickSort level " << level
         << ", range [" << left << ", " << right << "]\n";

    --level;
}

int main() {
    double myArray[] = { 0, -6, 7, -42, 6, 9 };
    int size = sizeof(myArray) / sizeof(myArray[0]);

    cout << "Original array: ";
    print(myArray, size);
    cout << "\n\n";

    quickSort(myArray, 0, size - 1);

    cout << "\nFinal sorted array: ";
    print(myArray, size);
    cout << "\n";

    return 0;
}
// 8.2.2. Valósítsa meg a Fibonacci sort rekurzívan! 
// Az előző program szerint tabulálással jelölje, hogy milyen mélyen van a rekurzióban!  

#include <iostream>
#include <vector>
using namespace std;

// -----------------------------------------------------------------------------
// Prints the Fibonacci array so far
void print(const vector<long>& arr) {
    cout << "[ ";
    for (long x : arr)
        cout << x << " ";
    cout << "]\n";
}

// -----------------------------------------------------------------------------
// Recursively generate Fibonacci numbers into `arr`, starting at index `idx`.
// `first` and `second` are the two previous values.
// `remaining` is how many more to generate.
// Uses a static `level` to track recursion depth and tabulate the output.
void fibonacci(vector<long>& arr,
               long first,
               long second,
               int remaining,
               int idx)
{
    static int level = 0;
    if (remaining <= 0) return;

    ++level;
    // Indent according to depth
    for (int t = 0; t < level - 1; ++t) cout << "\t";
    cout << "Begin Fibonacci recursion at level " << level
         << ", filling index " << idx << "\n";

    // Compute next Fibonacci number and store it
    arr[idx] = first + second;

    // Recurse for the rest
    fibonacci(arr, second, first + second, remaining - 1, idx + 1);

    for (int t = 0; t < level - 1; ++t) cout << "\t";
    cout << "End   Fibonacci recursion at level " << level
         << ", filled index " << idx << "\n";

    --level;
}

// -----------------------------------------------------------------------------
// Driver
int main() {
    int maxIndex;
    cout << "Max index of the Fibonacci series? ";
    cin  >> maxIndex;

    if (maxIndex <= 0) {
        cout << "No elements to display.\n";
        return 0;
    }

    // Prepare array of size maxIndex
    vector<long> fib(maxIndex);

    // First two elements are 1, if they exist
    fib[0] = 1;
    if (maxIndex > 1) {
        fib[1] = 1;
        // Generate the remaining maxIndex-2 elements starting at index 2
        fibonacci(fib, 1, 1, maxIndex - 2, 2);
    }

    // Print final series
    cout << "\nFinal Fibonacci series (" << maxIndex << " elements): ";
    print(fib);

    return 0;
}



// 8.3.1. Feladat: Írjon programot, amely abc sorrendbe rendez neveket!
// Kérje be, hogy hány nevet akar rendezni, ezután kérje be a neveket!
// Rendezze a neveket buborék rendezéssel! Ötlet: használja az stricmp függvényt! 

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <cctype>

using namespace std;

// Convert a string to lowercase for comparison
string toLower(const string& s) {
    string t = s;
    transform(t.begin(), t.end(), t.begin(),
              [](unsigned char c){ return static_cast<char>(tolower(c)); });
    return t;
}

int main() {
    int n;
    cout << "Number of names: ";
    if (!(cin >> n) || n <= 0) {
        cerr << "Invalid count.\n";
        return 1;
    }

    vector<string> names(n);
    for (int i = 0; i < n; ++i) {
        cout << i+1 << ". name: ";
        cin >> names[i];
    }

    // Bubble‐sort using case‐insensitive comparison
    for (int i = 0; i < n - 1; ++i) {
        for (int j = 0; j < n - 1 - i; ++j) {
            if (toLower(names[j]) > toLower(names[j+1])) {
                swap(names[j], names[j+1]);
            }
        }
    }

    cout << "\nSorted names:\n";
    for (const auto& name : names) {
        cout << name << "\n";
    }

    return 0;
}
// 8.3.2. Módosítsa úgy a programot, hogy a különböző előtagok (Dr., prof., PhD., …) ne befolyásolják a sorrendet! 

 
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <cctype>

using namespace std;

// Helper: convert a string to lowercase
string toLower(const string& s) {
    string t = s;
    transform(t.begin(), t.end(), t.begin(),
        [](unsigned char c){ return static_cast<char>(tolower(c)); });
    return t;
}

int main() {
    int n;
    cout << "Number of names: ";
    if (!(cin >> n) || n <= 0) {
        cerr << "Invalid count.\n";
        return 1;
    }

    // read prefixes and names
    vector<string> prefix(n), name(n);
    for (int i = 0; i < n; ++i) {
        cout << i+1 << ". prefix: ";
        cin >> prefix[i];
        cout << i+1 << ". name:   ";
        cin >> name[i];
    }

    // Bubble‐sort by name only (case‐insensitive), ignoring prefixes
    for (int i = 0; i < n - 1; ++i) {
        for (int j = 0; j < n - 1 - i; ++j) {
            if (toLower(name[j]) > toLower(name[j+1])) {
                swap(name[j],     name[j+1]);
                swap(prefix[j],   prefix[j+1]);
            }
        }
    }

    // Print sorted list
    cout << "\nSorted names:\n";
    for (int i = 0; i < n; ++i) {
        cout << prefix[i] << " " << name[i] << "\n";
    }
    return 0;
}
 // C++11
// 8.4.1. Valósítson meg egy kétszeresen láncolt listát, amely ID alapján csökkenő sorrendben tartalmazza a rekordokat! Használjon őrszemeket a lista két végén! A listát egy struktúra reprezentálja, amely az őrszemeket tartalmazza! A lista elem tartalmazza az előre, hátra mutató mezőket és egy mutatót az adat struktúrára! Az adat struktúra tartalmazza következő mezőket: ID, méret, származási hely. 

 
#include <iostream>
#include <string>

// The payload stored in each node
struct DataType {
    int     ID;
    double  size;
    std::string origin;
};

// A node in the doubly‐linked list.
// Each node holds a pointer to a DataType.
struct ListNode {
    DataType*   data;
    ListNode*   prev;
    ListNode*   next;

    ListNode(DataType* d = nullptr)
      : data(d), prev(nullptr), next(nullptr) {}
};

// The list itself, with head/tail sentinels and insert/clear/print operations.
class List {
public:
    List() {
        // Initialize empty list: head ↔ tail
        head.next = &tail;
        tail.prev = &head;
    }

    ~List() {
        clear();
    }

    // Insert in descending order by ID
    void insert(DataType* d) {
        // Find first node with ID <= d->ID
        ListNode* cur = head.next;
        while (cur != &tail && cur->data->ID > d->ID) {
            cur = cur->next;
        }
        // Insert new node before cur
        ListNode* node = new ListNode(d);
        node->prev      = cur->prev;
        node->next      = cur;
        cur->prev->next = node;
        cur->prev       = node;
    }

    // Remove all elements (but not the sentinel nodes)
    void clear() {
        ListNode* cur = head.next;
        while (cur != &tail) {
            ListNode* toDelete = cur;
            cur = cur->next;
            delete toDelete;
        }
        head.next = &tail;
        tail.prev = &head;
    }

    // Print the list from head→tail (excluding sentinels)
    void print() const {
        std::cout << "List (descending by ID):\n";
        for (ListNode* cur = head.next; cur != &tail; cur = cur->next) {
            std::cout << "  (ID: " << cur->data->ID
                      << ", size: " << cur->data->size
                      << ", origin: " << cur->data->origin
                      << ")\n";
        }
    }

private:
    ListNode head;  // dummy head sentinel
    ListNode tail;  // dummy tail sentinel
};

// -----------------------------------------------------------------------------
// Demo for 8.4.1
int main() {
    List myList;

    DataType testData[] = {
        { 1,  2.3, "Hu" },
        { 7, 12.3, "Ro" },
        { 0, 45.3, "Eu" },
        { 5, 14.1, "Gb" }
    };

    for (auto& d : testData) {
        std::cout << "Inserting (ID: " << d.ID
                  << ", size: " << d.size
                  << ", origin: " << d.origin << ")\n";
        myList.insert(&d);
        myList.print();
        std::cout << "\n";
    }

    // Clean up is automatic in List destructor
    return 0;
}

// c++11
// 8.4.2. Egészítse ki a lista struktúrát egy egésszel, amely az elemek számát mutatja a listában!
// Módosítsa a függvényeket, hogy azok kezeljék az új adattagot! 
 

#include <iostream>
#include <string>

// -----------------------------------------------------------------------------
// The payload stored in each node
struct DataType {
    int     ID;
    double  size;
    std::string origin;
};

// A node in the doubly–linked list
struct ListNode {
    DataType    data;
    ListNode*   prev;
    ListNode*   next;

    ListNode(const DataType& d = DataType{})
      : data(d), prev(nullptr), next(nullptr) {}
};

// The list itself, with head/tail sentinels and a count of elements
class List {
public:
    List()
      : _count(0)
    {
        // initialize empty list:
        _head.next = &_tail;
        _tail.prev = &_head;
    }

    ~List() {
        clear();
    }

    // Insert in ascending order by ID
    void insert(const DataType& d) {
        // find first node with data.ID >= d.ID
        ListNode* cur = _head.next;
        while (cur != &_tail && cur->data.ID < d.ID) {
            cur = cur->next;
        }
        // insert new node before cur
        ListNode* node = new ListNode(d);
        node->prev      = cur->prev;
        node->next      = cur;
        cur->prev->next = node;
        cur->prev       = node;

        ++_count;
    }

    // Remove all elements
    void clear() {
        ListNode* cur = _head.next;
        while (cur != &_tail) {
            ListNode* toDelete = cur;
            cur = cur->next;
            delete toDelete;
        }
        _head.next = &_tail;
        _tail.prev = &_head;
        _count = 0;
    }

    // Print the entire list and the count
    void display() const {
        std::cout << "List elements (" << _count << "): ";
        ListNode* cur = _head.next;
        while (cur != &_tail) {
            std::cout
                << "(ID: "   << cur->data.ID
                << ", size: " << cur->data.size
                << ", origin: " << cur->data.origin
                << ")";

            cur = cur->next;
            if (cur != &_tail)
                std::cout << " <-> ";
        }
        std::cout << "\n";
    }

    // Return the number of elements
    int size() const { return _count; }

private:
    ListNode _head;   // dummy head (no data)
    ListNode _tail;   // dummy tail (no data)
    int      _count;  // number of real elements
};

// -----------------------------------------------------------------------------
// Demonstration of 8.4.2:
int main() {
    List myList;

    DataType testData[] = {
        { 1,  2.3, "Hu" },
        { 7, 12.3, "Ro" },
        { 0, 45.3, "Eu" },
        { 5, 14.1, "Gb" }
    };

    for (const auto& d : testData) {
        std::cout << "Inserting (ID: " << d.ID
                  << ", size: " << d.size
                  << ", origin: " << d.origin << ")\n";
        myList.insert(d);
        myList.display();
        std::cout << "\n";
    }

    std::cout << "Final count: " << myList.size() << "\n";

    // teardown happens in destructor
    return 0;
}
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



// C++11
// 8.6.1. Írjon programot, amely szavakat rendez növekvő sorrendbe az strcmp függvény használata nélkül! 
// A szavak csak nagybetűkből állnak. 
// A program olvassa be fájlból a szavakat, és írja ki azokat a képernyőre növekvő sorrendben. 
// Ha egy szó megegyezik egy másik, hosszabb szó elejével, akkor a hosszabb szó szerepel később.
// Például: SO < SOAP.
//  A szavak maximális hossza 15 karakter.
// Használjon dinamikus tömböket a szavak tárolásához!
// A sorrendnél a betűk ASCII kódja számít.
// Az input fájl formátuma: Első sor: A szavak száma. A többi sor egy-egy szót tartalmaz.
// Példa bemenet: 7 WARIOR APPLE SZOKOZSHIP BOOK SZOKOZ PHISIC LIMON
// Kimenet: Read words: 1.: WARIOR 2.: APPLE 3.: SOAP 4.: BOOK 5.: SO 6.: PHISIC 7.: LIMON *************** Sorted words : 1.: APPLE 2.: BOOK 3.: LIMON 4.: PHISIC 5.: SO 6.: SOAP 7.: WARIOR


#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

// Compare two uppercase-only words lexicographically by ASCII,
// with shorter word coming first if it's a prefix of the longer.
bool wordLess(const string& A, const string& B) {
    size_t la = A.size(), lb = B.size();
    size_t lm = min(la, lb);
    for (size_t i = 0; i < lm; ++i) {
        if (A[i] < B[i]) return true;
        if (A[i] > B[i]) return false;
    }
    return la < lb;
}

int main(int argc, char* argv[]) {
    const char* filename = (argc > 1 ? argv[1] : "words.txt");
    ifstream infile(filename);
    if (!infile) {
        cerr << "Error opening file: " << filename << "\n";
        return 1;
    }

    int N;
    infile >> N;
    vector<string> words;
    words.reserve(N);

    // Read words
    for (int i = 0; i < N; ++i) {
        string w;
        infile >> w;
        words.push_back(w);
    }

    // Print as read
    cout << "Read words:\n";
    for (int i = 0; i < N; ++i) {
        cout << "\t" << (i+1) << ".: " << words[i] << "\n";
    }

    // Sort using our custom comparator
    sort(words.begin(), words.end(), wordLess);

    // Print sorted
    cout << "\n***************\n";
    cout << "Sorted words:\n";
    for (int i = 0; i < N; ++i) {
        cout << "\t" << (i+1) << ".: " << words[i] << "\n";
    }

    return 0;
}

// 8.7.1. James nagyon feledékeny, ezért emlékeztetőket szokott írni magának. Egy emlékeztető egy dátumot tartalmaz (év, hónap, nap), egy időpontot (órát), és egy emlékeztető kulcsszót. Az emlékeztetők összekeveredtek, ezért programot kell írni azok rendezésére. Az emlékeztetőket fájlból olvassa be! Írja ki a képernyőre a rendezett emlékeztetősorozatot! Tárolja az emlékeztetőket struktúrában, illetve dinamikus tömbökben! Az input fájl formátuma: Első sor: az emlékeztetők száma. A további sorok az emlékeztetőket tárolják a következő formátumban: Év Hónap Nap Óra Kulcsszó Az év, hónap, nap és óra értékei pozitív egészek. A szó maximális hossza 20 karakter. A sorokban az adatok szóköz karakterekkel vannak elválasztva. Példa bemenet: 2 2008 11 20 12 Bank 2008 10 16 16 Dentist Kimenet: Year: 2008 Month: 10 Day: 16 Hour: 16 Dentist Year: 2008 Month: 11 Day: 20 Hour: 12 Bank 

 
#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <algorithm>

struct Memo {
    int     year;
    int     month;
    int     day;
    int     hour;
    std::string keyword;
};

// Comparison: ascending by year, then month, day, hour
bool memoLess(const Memo& a, const Memo& b) {
    if (a.year   != b.year)   return a.year   < b.year;
    if (a.month  != b.month)  return a.month  < b.month;
    if (a.day    != b.day)    return a.day    < b.day;
    return a.hour  < b.hour;
}

int main(int argc, char* argv[]) {
    const char* filename = (argc > 1 ? argv[1] : "memo1.txt");
    std::ifstream infile(filename);
    if (!infile) {
        std::cerr << "Error opening file: " << filename << "\n";
        return 1;
    }

    int n;
    infile >> n;
    std::vector<Memo> memos;
    memos.reserve(n);

    for (int i = 0; i < n; ++i) {
        Memo m;
        infile >> m.year
               >> m.month
               >> m.day
               >> m.hour
               >> m.keyword;
        memos.push_back(std::move(m));
    }

    // sort ascending by date/time
    std::sort(memos.begin(), memos.end(), memoLess);

    // print sorted
    for (const auto& m : memos) {
        std::cout
            << "Year: "  << m.year
            << " Month: " << m.month
            << " Day: "   << m.day
            << " Hour: "  << m.hour
            << " "        << m.keyword
            << "\n";
    }

    return 0;
}
 