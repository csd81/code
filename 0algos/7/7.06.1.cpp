// c++11

// 7.6.1. Valósítsuk meg a Bellman-Ford algoritmust egy gráfon! Az algoritmus egy irányított gráf adott pontjától keresi meg a minimális költségű utakat a gráf többi pontjába. Először az egy, majd a kettő él hosszú legrövidebb utakat keresi meg és így tovább. Ha a gráf negatív kört tartalmaz, az algoritmus nem ad vissza jó értéket. 


// C++11
#include <iostream>
#include <vector>
#include <limits>

struct Edge {
    int u, v;
    int weight;
};

const int INF = std::numeric_limits<int>::max() / 2;

// Bellman–Ford:
//   Returns true if no negative cycle reachable from source.
//   Fills dist[0..N-1] with shortest distances (INF if unreachable).
bool BellmanFord(int N,
                 const std::vector<Edge>& edges,
                 int source,
                 std::vector<int>& dist)
{
    dist.assign(N, INF);
    dist[source] = 0;

    // Relax edges N-1 times
    for (int i = 1; i < N; ++i) {
        bool updated = false;
        for (auto const& e : edges) {
            if (dist[e.u] + e.weight < dist[e.v]) {
                dist[e.v] = dist[e.u] + e.weight;
                updated = true;
            }
        }
        if (!updated) 
            break;
    }

    // Check for negative cycles
    for (auto const& e : edges) {
        if (dist[e.u] + e.weight < dist[e.v]) {
            return false;  // negative cycle detected
        }
    }
    return true;
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int N;
    std::cout << "Add meg a csucsok szamat (N): ";
    std::cin >> N;

    std::vector<std::vector<int>> adj(N, std::vector<int>(N));
    std::cout << "Add meg az " << N << "x" << N 
              << " adjacencia-matrixot (0 = nincs el, egyeb szam = suly):\n";
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            std::cin >> adj[i][j];
        }
    }

    // Gyűjtsük össze az éleket
    std::vector<Edge> edges;
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            if (adj[i][j] != 0) {
                edges.push_back(Edge{i, j, adj[i][j]});
            }
        }
    }

    int source;
    std::cout << "Add meg a forras csucs szamat (0–" << N-1 << "): ";
    std::cin >> source;

    std::vector<int> dist;
    bool ok = BellmanFord(N, edges, source, dist);

    if (!ok) {
        std::cout << "\nA graf negativ korot tartalmaz, a Bellman–Ford eredmenyt nem lehet hasznalni.\n";
    } else {
        std::cout << "\nA forrastol (" << source << ") mért legkisebb tavolsagok:\n";
        for (int i = 0; i < N; ++i) {
            std::cout << "  -> " << i << ": ";
            if (dist[i] >= INF/2) 
                std::cout << "elérhetetlen\n";
            else 
                std::cout << dist[i] << "\n";
        }
    }

    return 0;
}

