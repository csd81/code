//  3.21.1. Írjon programot, amely számokat olvas be fájlból, majd 
// kiszámítja ezek átlagát és mediánját! A program írja ki a képernyőre 
// a számokat, az átlagot, és a mediánt is! A medián kiszámításához 
// először sorba kell rendeznie a számokat. Páratlan számú adat esetén a 
// medián ebben a sorban a középső elem, páros számú adat esetén a két 
// középső elem átlaga. Az input fájl formátuma: Első sor: Az adatok 
// száma. Második sor: A számok, egy-egy szóköz karakterrel elválasztva. 
// Példa bemenet: 

// 4 2 5 3 4 2 5 1 3 5 1 5 5 5 4 4 3 4 4 2 5 5 1 5 5 3 2 5 2 5 

// Kimenet: 
// 30 numbers:
// 4 2 5 3 4 2 5 1 3 5 1 5 5 5 4 4 3 4 4 2 5 5 1 5 5 3 2 5 2 5
// The average is 3.63333
// The median is: 4.00000



#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <algorithm>
#include <numeric>
#include <iomanip>

const std::string DEFAULT_INPUT = "datas.txt";

// Adatok beolvasása fájlból
int readNumbers(const std::string& filename, std::vector<int>& numbers) {
    std::ifstream file(filename);
    if (!file) {
        std::cerr << "Error opening file: " << filename << "\n";
        return 0;
    }

    int count;
    file >> count;
    numbers.resize(count);

    for (int i = 0; i < count; ++i) {
        file >> numbers[i];
    }

    return count;
}

// Átlag számítása
double average(const std::vector<int>& nums) {
    if (nums.empty()) return 0.0;
    long long sum = std::accumulate(nums.begin(), nums.end(), 0LL);
    return static_cast<double>(sum) / nums.size();
}

// Medián számítása
double median(std::vector<int> nums) {
    if (nums.empty()) return 0.0;

    std::sort(nums.begin(), nums.end());
    size_t n = nums.size();
    if (n % 2 == 1) {
        return nums[n / 2];
    } else {
        return (nums[n / 2 - 1] + nums[n / 2]) / 2.0;
    }
}

int main(int argc, char* argv[]) {
    std::string filename = (argc > 1) ? argv[1] : DEFAULT_INPUT;
    std::vector<int> numbers;

    int count = readNumbers(filename, numbers);
    if (count == 0) return 1;

    std::cout << count << " numbers:\n";
    for (int num : numbers) {
        std::cout << num << " ";
    }
    std::cout << "\n";

    std::cout << std::fixed << std::setprecision(5);
    std::cout << "The average is " << average(numbers) << "\n";
    std::cout << "The median is: " << median(numbers) << "\n";

    return 0;
}
