// 7.7.2. A minimális költségű feszítőfa helyett keresünk maximális költségűt!
// Egy kommunikációs hálózat tartalmazza a számítógépeket és az azok közötti kétirányú kapcsolatokat.
// Mindegyik kapcsolathoz sávszélesség tartozik.
// Bármely, két gépet összekötő hálózatrész sávszélessége alatt az egyes vezetékszakaszok sávszélességének minimumát értjük. Ha két gép között több úton is létesíthető kapcsolat, akkor az összeköttetés sávszélessége ezek közül a maximum. A teljes hálózat sávszélessége alatt az azt alkotó gépek közötti sávszélességek minimumát értjük. Ha a gráf nem összefüggő, akkor 0 a sávszélesség. Írjunk programot, amely beolvassa a hálózat adatait, majd meghatározza a sávszélességét! 8. Rendezési feladatok 8.1.Tömbrendezés

// C++11
#include <iostream>
#include <vector>
#include <algorithm>
#include <limits>

// Disjoint Set Union (Union-Find) with path compression and union by rank
struct DSU {
    std::vector<int> parent, rank;
    DSU(int n): parent(n), rank(n, 0) {
        for (int i = 0; i < n; ++i) parent[i] = i;
    }
    int find(int x) {
        return parent[x] == x ? x : parent[x] = find(parent[x]);
    }
    // Returns true if merged (were in different sets)
    bool unite(int a, int b) {
        a = find(a); b = find(b);
        if (a == b) return false;
        if (rank[a] < rank[b]) std::swap(a, b);
        parent[b] = a;
        if (rank[a] == rank[b]) ++rank[a];
        return true;
    }
};

struct Edge {
    int u, v, w;
};

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int N;
    std::cout << "Add meg a gepek szamat (N): ";
    std::cin >> N;

    std::vector<std::vector<int>> adj(N, std::vector<int>(N));
    std::cout << "Add meg az " << N << "x" << N
              << " adjacencia-matrixot (0 = nincs kapcsolat, egyeb = sávszél):\n";
    for (int i = 0; i < N; ++i)
        for (int j = 0; j < N; ++j)
            std::cin >> adj[i][j];

    // Build edge list (undirected)
    std::vector<Edge> edges;
    for (int i = 0; i < N; ++i) {
        for (int j = i+1; j < N; ++j) {
            if (adj[i][j] > 0) {
                edges.push_back({i, j, adj[i][j]});
            }
        }
    }

    // Sort edges by descending bandwidth
    std::sort(edges.begin(), edges.end(),
              [](Edge const &a, Edge const &b){
                  return a.w > b.w;
              });

    DSU dsu(N);
    int edges_used = 0;
    int bandwidth = std::numeric_limits<int>::max();

    // Kruskal-like: pick highest-bandwidth edges first
    for (auto &e : edges) {
        if (dsu.unite(e.u, e.v)) {
            // track the minimum bandwidth in the chosen edges
            bandwidth = std::min(bandwidth, e.w);
            if (++edges_used == N-1) break;
        }
    }

    if (edges_used < N-1) {
        std::cout << "\nA hálózat nem összefüggő, sávszélesség: 0\n";
    } else {
        std::cout << "\nA hálózat sávszélessége (maximális minimális út): "
                  << bandwidth << "\n";
    }

    return 0;
}
