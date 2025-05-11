#include <iostream>
#include <vector>
#include <algorithm>
#include <limits>
#include <iomanip>
#include <cassert> // for assertions

using namespace std;

// Function to find the minimum cost cell in a given cost matrix
pair<int, int> findMinCostCell(const vector<vector<int>>& cost, const vector<bool>& supplyDone, const vector<bool>& demandDone) {
    int minCost = numeric_limits<int>::max();
    int minRow = -1;
    int minCol = -1;

    for (int i = 0; i < cost.size(); ++i) {
        if (supplyDone[i]) continue; // Skip row if supply is fulfilled
        for (int j = 0; j < cost[0].size(); ++j) {
            if (demandDone[j]) continue; // Skip column if demand is fulfilled
            if (cost[i][j] < minCost) {
                minCost = cost[i][j];
                minRow = i;
                minCol = j;
            }
        }
    }
    return {minRow, minCol};
}

// Function to calculate the penalty for each row and column
pair<vector<int>, vector<int>> calculatePenalties(const vector<vector<int>>& cost, const vector<bool>& supplyDone, const vector<bool>& demandDone) {
    int numRows = cost.size();
    int numCols = cost[0].size();
    vector<int> rowPenalties(numRows, 0);
    vector<int> colPenalties(numCols, 0);

    for (int i = 0; i < numRows; ++i) {
        if (supplyDone[i]) continue; // Skip if supply is done.
        int min1 = numeric_limits<int>::max();
        int min2 = numeric_limits<int>::max();
        for (int j = 0; j < numCols; ++j) {
             if (demandDone[j]) continue; // Skip if demand is done.
            if (cost[i][j] < min1) {
                min2 = min1;
                min1 = cost[i][j];
            } else if (cost[i][j] < min2) {
                min2 = cost[i][j];
            }
        }
        if (min2 != numeric_limits<int>::max()) { // Ensure we found two smallest
             rowPenalties[i] = min2 - min1;
        }
        else{
            rowPenalties[i] = 0;
        }
    }

    for (int j = 0; j < numCols; ++j) {
        if (demandDone[j]) continue;  // Skip if demand is done.
        int min1 = numeric_limits<int>::max();
        int min2 = numeric_limits<int>::max();
        for (int i = 0; i < numRows; ++i) {
            if (supplyDone[i]) continue; // Skip if supply is done.
            if (cost[i][j] < min1) {
                min2 = min1;
                min1 = cost[i][j];
            } else if (cost[i][j] < min2) {
                min2 = cost[i][j];
            }
        }
        if (min2 != numeric_limits<int>::max()){
            colPenalties[j] = min2 - min1;
        }
        else{
             colPenalties[j] = 0;
        }
    }
    return {rowPenalties, colPenalties};
}

// Function to find the cell with the maximum penalty
pair<int, int> findMaxPenaltyCell(const vector<int>& rowPenalties, const vector<int>& colPenalties) {
    int maxPenalty = -1;
    int maxRow = -1;
    int maxCol = -1;

    for (int i = 0; i < rowPenalties.size(); ++i) {
        if (rowPenalties[i] > maxPenalty) {
            maxPenalty = rowPenalties[i];
            maxRow = i;
        }
    }

    for (int j = 0; j < colPenalties.size(); ++j) {
        if (colPenalties[j] > maxPenalty) {
            maxPenalty = colPenalties[j];
            maxRow = -1; // Reset row, we found a col with larger penalty
            maxCol = j;
        }
    }
    return {maxRow, maxCol};
}

// Function to perform Vogel's Approximation Method (VAM) to find an initial feasible solution
vector<vector<int>> vogelApproximationMethod(vector<vector<int>> cost, vector<int> supply, vector<int> demand) {
    int numRows = cost.size();
    int numCols = cost[0].size();
    vector<vector<int>> allocation(numRows, vector<int>(numCols, 0));
    vector<bool> supplyDone(numRows, false);
    vector<bool> demandDone(numCols, false);

    int numAllocated = 0; // Keep track of how many cells have allocations.
    while (numAllocated < numRows + numCols - 1) { // Loop until we have a basic feasible solution
        pair<vector<int>, vector<int>> penalties = calculatePenalties(cost, supplyDone, demandDone);
        pair<int, int> maxPenaltyCell = findMaxPenaltyCell(penalties.first, penalties.second);

        int row = maxPenaltyCell.first;
        int col = maxPenaltyCell.second;

        if (row == -1) {
            // Maximum penalty was in a column
            for (int i = 0; i < numRows; ++i) {
                if (!supplyDone[i] && !demandDone[col]) {
                    row = i;
                    break; //take the first available row.
                }
            }
        }
        if (col == -1){
             for (int j = 0; j < numCols; ++j) {
                if (!demandDone[j] && !supplyDone[row]) {
                    col = j;
                    break; //take the first available column
                }
            }
        }

        int quantity = min(supply[row], demand[col]);
        allocation[row][col] = quantity;
        supply[row] -= quantity;
        demand[col] -= quantity;
        numAllocated++;

        if (supply[row] == 0) {
            supplyDone[row] = true;
        }
        if (demand[col] == 0) {
            demandDone[col] = true;
        }
    }
    return allocation;
}

// Function to calculate the total transportation cost
int calculateTotalCost(const vector<vector<int>>& cost, const vector<vector<int>>& allocation) {
    int totalCost = 0;
    for (int i = 0; i < cost.size(); ++i) {
        for (int j = 0; j < cost[0].size(); ++j) {
            totalCost += cost[i][j] * allocation[i][j];
        }
    }
    return totalCost;
}

// Function to find a loop in the allocation (Stepping Stone Method)
// Returns true if a loop is found, false otherwise.  The loop is returned in the 'path' vector.
bool findLoop(const vector<vector<int>>& allocation, int row, int col, vector<pair<int, int>>& path, vector<vector<bool>>& visited) {
    int numRows = allocation.size();
    int numCols = allocation[0].size();

    if (row < 0 || row >= numRows || col < 0 || col >= numCols) {
        cerr << "Error: Invalid row or column in findLoop: row=" << row << ", col=" << col << endl;
        return false; // Or throw an exception
    }
    if (visited[row][col]) return false;

    visited[row][col] = true;
    path.push_back({row, col});

    // Base case: Check if we've found a loop back to the starting point with at least 4 points.
    if (path.size() >= 4 && path[0] == make_pair(row, col)) {
        return true;
    }

    // Recursive exploration of possible paths
    // Explore moving horizontally first
    int prevRow = path.size() > 1 ? path[path.size() - 2].first : -1; //row of the previous node.
    if (path.size() < 2 || prevRow != row) { // We can only move horizontally if we came from a different row
        for (int j = 0; j < numCols; ++j) {
            if (j != col && allocation[row][j] > 0 && !visited[row][j]) { //optimization: check for > 0
                if (findLoop(allocation, row, j, path, visited)) {
                    return true;
                }
            }
            else if (j != col && path.size() >= 4 && path[0] == make_pair(row, j)) { //check for the loop
                path.push_back({row, j});
                return true;
            }
        }
    }

    // Explore moving vertically
    int prevCol = path.size() > 1 ? path[path.size() - 2].second : -1;
    if (path.size() < 2 || prevCol != col) { // We can only move vertically if we came from a different col
        for (int i = 0; i < numRows; ++i) {
            if (i != row && allocation[i][col] > 0 && !visited[i][col]) {
                if (findLoop(allocation, i, col, path, visited)) {
                    return true;
                }
            }
            else if (i != row && path.size() >= 4 && path[0] == make_pair(i, col)) { //check for the loop
                path.push_back({i, col});
                return true;
            }
        }
    }

    // If no loop is found from this cell, backtrack
    path.pop_back();
    return false;
}

// Function to perform the Stepping Stone Method to optimize the solution
vector<vector<int>> steppingStoneMethod(vector<vector<int>> cost, vector<vector<int>> allocation, vector<int> supply, vector<int> demand) {
    int numRows = cost.size();
    int numCols = cost[0].size();
    bool isOptimal = false;
    int iteration = 0;

    while (!isOptimal) {
        isOptimal = true; // Assume optimal until proven otherwise
        iteration++;
        if (iteration > 100) {
            cerr << "Warning: Stepping Stone Method did not converge after 100 iterations.  Check for degeneracy or cycling." << endl;
            break; // Add a safeguard to prevent infinite loops
        }
        for (int i = 0; i < numRows; ++i) {
            for (int j = 0; j < numCols; ++j) {
                if (allocation[i][j] == 0) { // Check only unallocated cells
                    vector<pair<int, int>> path;
                    vector<vector<bool>> visited(numRows, vector<bool>(numCols, false)); // Create visited matrix inside the loop
                    if (findLoop(allocation, i, j, path, visited)) {
                        // Calculate the change in cost if we allocate to this cell
                        int costChange = 0;
                        for (int k = 0; k < path.size(); ++k) {
                            int sign = (k % 2 == 0) ? 1 : -1; // Alternate signs for the loop
                            costChange += sign * cost[path[k].first][path[k].second];
                        }
                        if (costChange < 0) {
                            isOptimal = false; // Not optimal, we can improve
                            // Find the minimum allocation in the negative cells of the loop
                            int minAllocation = numeric_limits<int>::max();
                            int minRow = -1;
                            int minCol = -1;
                            for (int k = 1; k < path.size(); k += 2) { // Only consider negative cells
                                if (allocation[path[k].first][path[k].second] < minAllocation)
                                {
                                    minAllocation = allocation[path[k].first][path[k].second];
                                    minRow = path[k].first;
                                    minCol = path[k].second;
                                }
                            }
                            if (minAllocation == numeric_limits<int>::max())
                            {
                                cerr << "Error: No negative cell found in the loop." << endl;
                                return allocation;
                            }
                            assert(minAllocation >= 0);

                            // Adjust allocations along the loop
                            for (int k = 0; k < path.size(); ++k) {
                                int sign = (k % 2 == 0) ? 1 : -1;
                                int newAllocation = allocation[path[k].first][path[k].second] + sign * minAllocation;
                                if (newAllocation < 0) {
                                    cerr << "Error: Negative allocation detected at ("
                                         << path[k].first << ", " << path[k].second << ")" << endl;
                                    cerr << "minAllocation = " << minAllocation << ", sign = " << sign << endl;
                                    cerr << "allocation[path[k].first][path[k].second] = " << allocation[path[k].first][path[k].second] << endl;

                                    return allocation;
                                }
                                allocation[path[k].first][path[k].second] = newAllocation;
                                assert(allocation[path[k].first][path[k].second] >= 0);
                            }
                            // The supply and demand should remain balanced, so we don't need to update them.
                            break; // Important: Only need to find one improving loop
                        }
                    }
                }
            }
            if (!isOptimal) break; // Exit outer loop if not optimal
        }
    }
    return allocation;
}

// Function to display the allocation table
void displayAllocation(const vector<vector<int>>& allocation) {
    cout << "Allocation Table:\n";
    for (const auto& row : allocation) {
        for (int val : row) {
            cout << setw(4) << val << " ";
        }
        cout << endl;
    }
}

// Function to display the cost matrix
void displayCostMatrix(const vector<vector<int>>& cost) {
    cout << "Cost Matrix:\n";
    for (const auto& row : cost) {
        for (int val : row) {
            cout << setw(4) << val << " ";
        }
        cout << endl;
    }
}

// Function to display the supply and demand
void displaySupplyDemand(const vector<int>& supply, const vector<int>& demand) {
    cout << "Supply:\n";
    for (int val : supply) {
        cout << setw(4) << val << " ";
    }
    cout << endl;
    cout << "Demand:\n";
    for (int val : demand) {
        cout << setw(4) << val << " ";
    }
    cout << endl;
}

int main() {
    // Example usage:
    vector<vector<int>> cost = {
        {2, 3, 1, 4},
        {1, 2, 3, 2},
        {3, 2, 4, 1}
    };
    vector<int> supply = {8, 10, 7};
    vector<int> demand = {5, 8, 4, 8};

    cout << "Initial Data:\n";
    displayCostMatrix(cost);
    displaySupplyDemand(supply, demand);

    vector<vector<int>> initialAllocation = vogelApproximationMethod(cost, supply, demand);
    cout << "\nInitial Allocation (VAM):\n";
    displayAllocation(initialAllocation);
    int initialCost = calculateTotalCost(cost, initialAllocation);
    cout << "Initial Cost: " << initialCost << endl;

    vector<vector<int>> finalAllocation = steppingStoneMethod(cost, initialAllocation, supply, demand);
    cout << "\nFinal Allocation (Stepping Stone):\n";
    displayAllocation(finalAllocation);
    int finalCost = calculateTotalCost(cost, finalAllocation);
    cout << "Final Cost: " << finalCost << endl;

    return 0;
}

