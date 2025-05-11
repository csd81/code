
#include <iostream>
#include <vector>
#include <limits>
#include <algorithm>
using namespace std;

struct Cell {
    int cost;
    int allocation = 0;
    bool allocated = false;
};

using Matrix = vector<vector<Cell>>;

// Include declarations
void vogelApproximation(Matrix& matrix, vector<int> supply, vector<int> demand);
void steppingStone(Matrix& matrix);

// Allocation print
void printAllocation(const Matrix& matrix) {
    cout << "\nFinal Allocation Matrix:\n";
    for (const auto& row : matrix) {
        for (const auto& cell : row) {
            cout << (cell.allocated ? to_string(cell.allocation) : "x") << "\t";
        }
        cout << "\n";
    }
}

// Simplified Vogel for test only (assumes balanced input)
void vogelApproximation(Matrix& matrix, vector<int> supply, vector<int> demand) {
    int m = supply.size(), n = demand.size();
    vector<bool> rowDone(m, false), colDone(n, false);

    while (true) {
        vector<int> rowPenalty(m, -1), colPenalty(n, -1);

        for (int i = 0; i < m; ++i) {
            if (rowDone[i]) continue;
            vector<int> rowCosts;
            for (int j = 0; j < n; ++j)
                if (!colDone[j]) rowCosts.push_back(matrix[i][j].cost);
            if (rowCosts.size() >= 2) {
                sort(rowCosts.begin(), rowCosts.end());
                rowPenalty[i] = rowCosts[1] - rowCosts[0];
            }
        }

        for (int j = 0; j < n; ++j) {
            if (colDone[j]) continue;
            vector<int> colCosts;
            for (int i = 0; i < m; ++i)
                if (!rowDone[i]) colCosts.push_back(matrix[i][j].cost);
            if (colCosts.size() >= 2) {
                sort(colCosts.begin(), colCosts.end());
                colPenalty[j] = colCosts[1] - colCosts[0];
            }
        }

        int maxPenalty = -1, index = -1;
        bool isRow = true;
        for (int i = 0; i < m; ++i)
            if (!rowDone[i] && rowPenalty[i] > maxPenalty)
                maxPenalty = rowPenalty[i], index = i, isRow = true;
        for (int j = 0; j < n; ++j)
            if (!colDone[j] && colPenalty[j] > maxPenalty)
                maxPenalty = colPenalty[j], index = j, isRow = false;

        if (index == -1) break;

        int row = -1, col = -1, minCost = numeric_limits<int>::max();
        if (isRow) {
            row = index;
            for (int j = 0; j < n; ++j)
                if (!colDone[j] && matrix[row][j].cost < minCost)
                    minCost = matrix[row][j].cost, col = j;
        } else {
            col = index;
            for (int i = 0; i < m; ++i)
                if (!rowDone[i] && matrix[i][col].cost < minCost)
                    minCost = matrix[i][col].cost, row = i;
        }

        int alloc = min(supply[row], demand[col]);
        matrix[row][col].allocation = alloc;
        matrix[row][col].allocated = true;
        supply[row] -= alloc;
        demand[col] -= alloc;
        if (supply[row] == 0) rowDone[row] = true;
        if (demand[col] == 0) colDone[col] = true;
    }
}

int main() {
    vector<int> supply = {20, 30, 25};
    vector<int> demand = {10, 25, 25, 15};

    Matrix matrix = {
        {{19}, {30}, {50}, {10}},
        {{70}, {30}, {40}, {60}},
        {{40}, {8},  {70}, {20}}
    };

    cout << "Initial Feasible Solution (Vogel's Method):\n";
    vogelApproximation(matrix, supply, demand);
    printAllocation(matrix);

    cout << "\nApplying Stepping Stone Optimization...\n";
    steppingStone(matrix);
    printAllocation(matrix);

    return 0;
}
