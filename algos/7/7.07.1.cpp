// c++11
// 7.7.1. Valósítsa meg a Kruskal algoritmust! Tárolja halmazban az épülő feszítőfa csúcsait! Használja az UNIÓ, HOLVAN halmazműveleteket annak eldöntésére, hogy egy új él felvétele okoz-e kört a feszítőfában! Ötlet: Az algoritmus elején a gráf minden pontja egy önálló halmazt jelent. A HOLVAN művelet megadja, hogy egy elem, melyik halmazban található, az UNIÓ művelet két halmazt egyesít. Ha egy élet akarunk hozzáadni a feszítőfához, akkor meg kell vizsgálni, hogy az él két pontja ugyanabba a halmazba tartozik-e. Ha igen, akkor az él felvétele kört okozna, így a következő legkisebb súlyú élt kell vizsgálni. A halmazokat (nem bináris) fákkal reprezentáljuk. Az UNIÓ művelet két ilyen fát egyesít oly módon, hogy az első fa a gyökere a második fa gyökerének egy új gyereke lesz. A HOLVAN művelet megadja a fa gyökerét. 



// C++11
#include <iostream>
#include <vector>
#include <algorithm>

// Disjoint Set Union (Union-Find) with path compression and union by rank
struct DSU {
    std::vector<int> parent, rank;
    DSU(int n): parent(n), rank(n, 0) {
        for(int i = 0; i < n; ++i) parent[i] = i;
    }
    int find(int x) {
        return parent[x] == x
             ? x
             : parent[x] = find(parent[x]);
    }
    bool unite(int a, int b) {
        a = find(a);
        b = find(b);
        if (a == b) return false;
        if (rank[a] < rank[b]) std::swap(a,b);
        parent[b] = a;
        if (rank[a] == rank[b]) ++rank[a];
        return true;
    }
};

// Edge structure
struct Edge {
    int u, v;
    int weight;
    bool operator<(Edge const& other) const {
        return weight < other.weight;
    }
};

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    // 1) Beolvassuk a gráf csúcs- és élsúlymátrixát
    int N;
    std::cout << "Add meg a csucsok szamat (N): ";
    std::cin >> N;

    std::vector<std::vector<int>> adj(N, std::vector<int>(N));
    std::cout << "Add meg az " << N << "x" << N 
              << " adjacencia-matrixot (0 = nincs el, mas szam = sully):\n";
    for(int i = 0; i < N; ++i) {
        for(int j = 0; j < N; ++j) {
            std::cin >> adj[i][j];
        }
    }

    // 2) Éllista összeállítása (csak egyszer – ha irányítatlan, i<j)
    std::vector<Edge> edges;
    for(int i = 0; i < N; ++i) {
        for(int j = i+1; j < N; ++j) {
            if (adj[i][j] != 0) {
                edges.push_back(Edge{i, j, adj[i][j]});
            }
        }
    }

    // 3) Élek súly szerinti rendezése
    std::sort(edges.begin(), edges.end());

    // 4) DSU inicializálása
    DSU dsu(N);

    // 5) Kruskal: végig az éleken, ha két végpont külön halmazban, hozzáadjuk az MST-hez és egyesítjük őket
    std::vector<Edge> mst;
    int totalWeight = 0;
    for(auto &e : edges) {
        if (dsu.unite(e.u, e.v)) {
            mst.push_back(e);
            totalWeight += e.weight;
            if ((int)mst.size() == N-1) break;
        }
    }

    // 6) Eredmény kiírása
    if ((int)mst.size() != N-1) {
        std::cout << "A graf nem osszefuggo, nem lehet MST-t epiteni.\n";
    } else {
        std::cout << "\nKruskal-algoritmus eredmenye:\n";
        std::cout << "MST osszsuly: " << totalWeight << "\n";
        std::cout << "MST elemei (u, v : suly):\n";
        for(auto &e : mst) {
            std::cout << "  (" << e.u << ", " << e.v 
                      << ") : " << e.weight << "\n";
        }
    }

    return 0;
}

