// 2.10.2. A szorzótáblához hasonló módon valósítsuk meg az egyedi összeadó táblát! Az első sor és az első oszlop értékeit szöveg fájlból olvassuk be! 

#include <iostream>
#include <fstream>
#include <vector>
#include <iomanip>
#include <limits>
#include <cstdint>

int main() {
    const int16_t MIN16 = std::numeric_limits<int16_t>::min();  // –32768
    const int16_t MAX16 = std::numeric_limits<int16_t>::max();  // +32767
    const int COLUMN_WIDTH = 12;

    std::ifstream infile("headers.txt");
    if (!infile) {
        std::cerr << "Error: could not open headers.txt\n";
        return 1;
    }

    // Read row- and column- headers
    std::vector<int> rows, cols;
    int x;
    // first line → rows
    for (std::string line; std::getline(infile, line); ) {
        std::istringstream iss(line);
        if (rows.empty()) {
            while (iss >> x) rows.push_back(x);
        } else {
            while (iss >> x) cols.push_back(x);
            break;  // we only expect two lines
        }
    }
    infile.close();

    if (rows.empty() || cols.empty()) {
        std::cerr << "Error: input file must have two lines of integers\n";
        return 1;
    }

    // Print header row
    std::cout << std::setw(COLUMN_WIDTH) << " " << "|";
    for (int r : rows) {
        std::cout << std::setw(COLUMN_WIDTH) << r << "|";
    }
    std::cout << "\n";

    // Separator
    int totalWidth = COLUMN_WIDTH + 1 + int(rows.size()) * (COLUMN_WIDTH + 1);
    for (int i = 0; i < totalWidth; ++i) std::cout << "-";
    std::cout << "\n";

    // Each data row
    for (int c : cols) {
        std::cout << std::setw(COLUMN_WIDTH) << c << "|";
        for (int r : rows) {
            int sum = r + c;
            // Detect 16-bit signed overflow:
            bool overflow = ( (r > 0 && c > 0 && sum < 0)
                           || (r < 0 && c < 0 && sum > 0)
                           || sum < MIN16 || sum > MAX16 );
            if (overflow) {
                std::cout << std::setw(COLUMN_WIDTH) << "x" << "|";
            } else {
                std::cout << std::setw(COLUMN_WIDTH) << sum << "|";
            }
        }
        std::cout << "\n";
    }

    return 0;
}
 