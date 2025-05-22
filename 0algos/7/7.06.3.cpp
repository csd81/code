// c++11
// 7.6.3. Adott egy valuta átváltási táblázat (adjacencia mátrix). x valutát y-ra szeretnénk váltani, keressük meg azt az átváltási sorozatot, amelyben a legtöbb y valutát kapjuk. Nem biztos, hogy a direkt átváltás a legjobb. Pl.: 1 dollárért kapunk 2 eurót, azonban 1 dollárért kaphatunk 6 frankot is, 1 frankért fél dollárt, így a dollár – frank - euró lesz a legjobb átváltás. Az átváltási táblázat főátlója csupa egyes, hiszen 1 dollár átváltva dollárra 1 dollárt kapunk. A főátlóra szimmetrikusan pedig egymás reciprokjai kell, hogy szerepeljenek, mert ha 1 euró = 2 dollár, akkor 1 dollár = 1/2 euró. 7.7. Kruskal algoritmus

// C++11
#include <iostream>
#include <vector>
#include <limits>
#include <iomanip>
#include <algorithm>


int main() {
    std::ios::sync_with_stdio(false);
//    std::cin.tie(nullptr);

    int N;
    std::cout << "Add meg a valutak szamat (N): ";
    std::cin >> N;

    // Beolvassuk az NxN atvaltas rate matrixot
    std::vector<std::vector<double>> rate(N, std::vector<double>(N));
    std::cout << "Add meg az " << N << "x" << N
              << " atvaltas aranyokat (fopartra 1.0):\n";
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            std::cin >> rate[i][j];
        }
    }

    int src, dst;
    std::cout << "Melyik a kezdo valuta (0–" << N-1 << "): ";
    std::cin >> src;
    std::cout << "Melyik a cel valuta   (0–" << N-1 << "): ";
    std::cin >> dst;

    // edges list
    struct Edge { int u, v; double w; };
    std::vector<Edge> edges;
    edges.reserve(N*N);
    for (int u = 0; u < N; ++u) {
        for (int v = 0; v < N; ++v) {
            if (u != v && rate[u][v] > 0) {
                edges.push_back({u, v, rate[u][v]});
            }
        }
    }

    // Modified Bellman-Ford to maximize product
    const double NEG_INF = 0.0;
    std::vector<double> best(N, NEG_INF);
    std::vector<int> prev(N, -1);

    best[src] = 1.0;
    // Relax edges up to N-1 times
    for (int iter = 0; iter < N-1; ++iter) {
        bool updated = false;
        for (auto &e : edges) {
            if (best[e.u] > 0 && best[e.u] * e.w > best[e.v]) {
                best[e.v] = best[e.u] * e.w;
                prev[e.v] = e.u;
                updated = true;
            }
        }
        if (!updated) break;
    }

    if (best[dst] <= 0) {
        std::cout << "\nNem lehet atvaltani a " << src
                  << " valutat a " << dst << " valutara.\n";
        return 0;
    }

    // Útvonal visszaépítése
    std::vector<int> path;
    for (int cur = dst; cur != -1; cur = prev[cur]) {
        path.push_back(cur);
    }
    std::reverse(path.begin(), path.end());

    // Eredmény kiírása
    std::cout << "\nLegjobb atvaltas: ";
    std::cout << std::fixed << std::setprecision(6)
              << "1 unit " << src << " -> " << best[dst]
              << " unit " << dst << "\n";
    std::cout << "Atvaltasi sorozat: ";
    for (size_t i = 0; i < path.size(); ++i) {
        std::cout << path[i] << (i+1<path.size() ? " -> " : "\n");
    }

    return 0;
}

