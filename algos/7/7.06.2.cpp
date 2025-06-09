// 7.6.2. Számítsuk ki egy fa átmérőjét! Egy fa átmérője alatt a fa bármely két csúcsa között futó legrövidebb utak közül a leghosszabbat értjük. Ötlet: Ha lefuttatjuk a fa minden pontjára a Belmann-Ford algoritmust, akkor ebből már csak a legkisebb elemet kell kiválasztani. 

// C++11
#include <iostream>
#include <vector>
#include <queue>
#include <limits>

// BFS returns the farthest distance from src to any other node
int bfs_max_dist(int src,
                 const std::vector<std::vector<int>>& adj_list)
{
    int N = adj_list.size();
    std::vector<int> dist(N, -1);
    std::queue<int> q;

    dist[src] = 0;
    q.push(src);

    int maxd = 0;
    while (!q.empty()) {
        int u = q.front(); q.pop();
        for (int v : adj_list[u]) {
            if (dist[v] == -1) {
                dist[v] = dist[u] + 1;
                maxd = std::max(maxd, dist[v]);
                q.push(v);
            }
        }
    }
    return maxd;
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int N;
    std::cout << "Add meg a csucsok szamat (N): ";
    std::cin >> N;

    std::vector<std::vector<int>> adj_mat(N, std::vector<int>(N));
    std::cout << "Add meg az " << N << "x" << N
              << " adjacencia-matrixot (0 = nincs el, 1 = van el):\n";
    for (int i = 0; i < N; ++i)
        for (int j = 0; j < N; ++j)
            std::cin >> adj_mat[i][j];

    // Alakítsuk at szomszédsági listára
    std::vector<std::vector<int>> adj_list(N);
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            if (adj_mat[i][j] != 0) {
                adj_list[i].push_back(j);
            }
        }
    }

    // 7.6.2. Fa átmérője: minden pontból BFS, vesszük a legnagyobb távolságot
    int diameter = 0;
    for (int i = 0; i < N; ++i) {
        int d = bfs_max_dist(i, adj_list);
        diameter = std::max(diameter, d);
    }

    std::cout << "\nA fa atmeroje: " << diameter << "\n";
    return 0;
}

