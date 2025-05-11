#include <iostream>
#include <vector>
#include <limits>
#include <set>
#include <algorithm>

using namespace std;

struct Cell {
    int cost;
    int allocation = 0;
    bool allocated = false;
};

using Matrix = vector<vector<Cell>>;
using Path = vector<pair<int, int>>;

void printAllocation(const Matrix& matrix, const string& title) {
    cout << "\n" << title << "\n";
    for (const auto& row : matrix) {
        for (const auto& cell : row) {
            cout << (cell.allocated ? to_string(cell.allocation) : "x") << "\t";
        }
        cout << "\n";
    }
}

pair<int,int> getMinTwo(const vector<int>& vec) {
    int min1 = numeric_limits<int>::max();
    int min2 = numeric_limits<int>::max();
    for (int v : vec) {
        if (v < min1) {
            min2 = min1;
            min1 = v;
        } else if (v < min2) {
            min2 = v;
        }
    }
    return make_pair(min1, min2);
}

void vogelApproximation(Matrix& matrix, vector<int> supply, vector<int> demand) {
    int m = supply.size();
    int n = demand.size();

    vector<bool> rowDone(m, false);
    vector<bool> colDone(n, false);

    while (true) {
        // compute penalties
        vector<int> rowPenalty(m, -1);
        for (int i = 0; i < m; ++i) {
            if (rowDone[i]) continue;
            vector<int> costs;
            for (int j = 0; j < n; ++j) if (!colDone[j])
                    costs.push_back(matrix[i][j].cost);
            if (costs.size() >= 2) {
                auto mins = getMinTwo(costs);
                rowPenalty[i] = mins.second - mins.first;
            }
        }
        vector<int> colPenalty(n, -1);
        for (int j = 0; j < n; ++j) {
            if (colDone[j]) continue;
            vector<int> costs;
            for (int i = 0; i < m; ++i) if (!rowDone[i])
                    costs.push_back(matrix[i][j].cost);
            if (costs.size() >= 2) {
                auto mins = getMinTwo(costs);
                colPenalty[j] = mins.second - mins.first;
            }
        }

        // pick max penalty
        int maxPenalty = -1;
        int idx = -1;
        bool pickRow = true;
        for (int i = 0; i < m; ++i) {
            if (!rowDone[i] && rowPenalty[i] > maxPenalty) {
                maxPenalty = rowPenalty[i]; idx = i; pickRow = true;
            }
        }
        for (int j = 0; j < n; ++j) {
            if (!colDone[j] && colPenalty[j] > maxPenalty) {
                maxPenalty = colPenalty[j]; idx = j; pickRow = false;
            }
        }
        if (idx == -1) {
            // exactly one row and one column remain: fill it
            int r = find(rowDone.begin(), rowDone.end(), false) - rowDone.begin();
            int c = find(colDone.begin(), colDone.end(), false) - colDone.begin();
            if (r < m && c < n) {
                int alloc = min(supply[r], demand[c]);
                matrix[r][c].allocation = alloc;
                matrix[r][c].allocated = true;
                supply[r] -= alloc;
                demand[c] -= alloc;
            }
            break;
        }

        // locate cell for allocation
        int row=-1, col=-1;
        int minCost = numeric_limits<int>::max();
        if (pickRow) {
            row = idx;
            for (int j = 0; j < n; ++j) {
                if (!colDone[j] && matrix[row][j].cost < minCost) {
                    minCost = matrix[row][j].cost; col = j;
                }
            }
        } else {
            col = idx;
            for (int i = 0; i < m; ++i) {
                if (!rowDone[i] && matrix[i][col].cost < minCost) {
                    minCost = matrix[i][col].cost; row = i;
                }
            }
        }

        // allocate
        int qty = min(supply[row], demand[col]);
        matrix[row][col].allocation = qty;
        matrix[row][col].allocated = true;
        supply[row] -= qty;
        demand[col] -= qty;
        if (supply[row] == 0) rowDone[row] = true;
        if (demand[col] == 0) colDone[col] = true;

        bool allDone = true;
        for (bool b : rowDone) if (!b) allDone = false;
        for (bool b : colDone) if (!b) allDone = false;
        if (allDone) break;
    }
}

int calculateOpportunityCost(const Matrix& matrix, const Path& loop) {
    // alternate + and - on the loop, ignoring any duplicate closure point
    int cost = 0;
    int len = loop.size();
    // if last point equals first, ignore last
    if (len > 1 && loop.front() == loop.back()) --len;
    for (int i = 0; i < len; ++i) {
        int r = loop[i].first, c = loop[i].second;
        cost += ((i % 2) == 0 ? 1 : -1) * matrix[r][c].cost;
    }
    return cost;
}

bool findRectanglePath(int sr, int sc, const Matrix& matrix, Path& result,
                       Path current, set<pair<int,int>> visited, bool rowMode) {
    int m = matrix.size(), n = matrix[0].size();

    if (rowMode) {
        int r = current.back().first;
        for (int j = 0; j < n; ++j) {
            auto next = make_pair(r, j);
            if (next == current.back() || visited.count(next)) continue;
            if (matrix[r][j].allocated) {
                // can we close loop?
                if (next == make_pair(sr, sc) && current.size() >= 4) {
                    result = current;
                    return true;
                }
                current.push_back(next);
                visited.insert(next);
                if (findRectanglePath(sr, sc, matrix, result, current, visited, !rowMode))
                    return true;
                visited.erase(next);
                current.pop_back();
            }
        }
    } else {
        int c = current.back().second;
        for (int i = 0; i < m; ++i) {
            auto next = make_pair(i, c);
            if (next == current.back() || visited.count(next)) continue;
            if (matrix[i][c].allocated) {
                if (next == make_pair(sr, sc) && current.size() >= 4) {
                    result = current;
                    return true;
                }
                current.push_back(next);
                visited.insert(next);
                if (findRectanglePath(sr, sc, matrix, result, current, visited, !rowMode))
                    return true;
                visited.erase(next);
                current.pop_back();
            }
        }
    }
    return false;
}

void steppingStone(Matrix& matrix) {
    while (true) {
        int m = matrix.size(), n = matrix[0].size();
        int bestDelta = 0;
        Path bestLoop;

        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (matrix[i][j].allocated) continue;
                Path loop, current = {{i, j}};
                set<pair<int,int>> visited = {{i, j}};
                if (findRectanglePath(i, j, matrix, loop, current, visited, true)) {
                    int delta = calculateOpportunityCost(matrix, loop);
                    if (delta < bestDelta) {
                        bestDelta = delta;
                        bestLoop = loop;
                    }
                }
            }
        }
        if (bestDelta >= 0) break;
        int theta = numeric_limits<int>::max();
        for (size_t k = 1; k < bestLoop.size(); k += 2) {
            auto [r, c] = bestLoop[k];
            theta = min(theta, matrix[r][c].allocation);
        }
        for (size_t k = 0; k < bestLoop.size(); ++k) {
            auto [r, c] = bestLoop[k];
            if (k % 2 == 0) {
                matrix[r][c].allocation += theta;
                matrix[r][c].allocated = true;
            } else {
                matrix[r][c].allocation -= theta;
                if (matrix[r][c].allocation == 0)
                    matrix[r][c].allocated = false;
            }
        }
    }
}

int totalCost(const Matrix& matrix) {
    int sum = 0;
    for (const auto& row : matrix)
        for (const auto& cell : row)
            if (cell.allocated)
                sum += cell.cost * cell.allocation;
    return sum;
}

int main() {
    vector<int> supply = {20, 30, 25, 10};
    vector<int> demand = {30, 20, 25, 10};

    Matrix costMatrix = {
        {{8}, {6}, {10}, {9}},
        {{9}, {7}, {4},  {2}},
        {{3}, {4}, {2},  {5}},
        {{5}, {6}, {8},  {6}}
    };

    vogelApproximation(costMatrix, supply, demand);
    printAllocation(costMatrix, "Initial Vogel Allocation:");
    cout << "Initial cost: " << totalCost(costMatrix) << "\n";

    steppingStone(costMatrix);
    printAllocation(costMatrix, "Optimized Allocation (Stepping Stone):");
    cout << "Final cost: " << totalCost(costMatrix) << "\n";

    return 0;
}
