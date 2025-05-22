// C++11
// 7.1.1. Egy nagyváros közepén található a tűzoltó állomás. 
// Sajnos gyakran megesik, hogy a tűz helyszínére tartó tűzoltó autók nem azon az útvonalon haladnak, 
// amerre a leghamarabb kiérnének, mivel a sofőrök nem képesek a legrövidebb utat meghatározni. 
// Írjon útvonaltervező programot, amely egy mátrixban tárolt úthálózat alapján 
// megtervezi a legrövidebb útvonalat a tűzoltó állomás és a tűz helyszíne között!
//  Ötlet: használjon Dijkstra algoritmust! 

// 7.2. Bolygóközi futárszolgálat A Bolygóközi Kézbesítő Vállalat különböző bolygók között bonyolít le szállításokat. Mivel a távolságok hatalmasak, ezért a közlekedést térkapukon keresztül oldják meg. Az egyes bolygók közelében féregjárat nyílások helyezkednek el, minden járat egy másik bolygó közelében ér véget. A közlekedés eme járatrendszerek belsejében zajlik. A járatok nyílásai a közeli bolygó kormányzatának a tulajdonában állnak, így a járatba való belépésért díjat szednek. A járat használatáért fizetendő összeg függ a belépési pontot birtokló kormányzattól, valamint a cél állomástól (a népszerűbb célállomások felé tartó járműveket jobban megsarcolják). Adott egy csillagtérkép, amelyen feltüntettük, hogy mely bolygók között létezik féregjárat, és az egyes járatokért mekkora díjat kell fizetni. A térkép adjacencia mátrixban van tárolva, ahol -1 jelzi azt, ha két bolygó között nincs közvetlen járat, egyébként pedig az egyes tarifákat tároljuk a mátrix celláiban.

#include <iostream>
#include <vector>
#include <queue>
#include <limits>
#include <iomanip>

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int e, n;
    const long INF = std::numeric_limits<long>::max() / 2;

    std::cout << "Enter number of edges and number of nodes: ";
    std::cin >> e >> n;

    // Mátrix inicializálása
    std::vector<std::vector<long>> mat(n+1, std::vector<long>(n+1, INF));
    for (int i = 1; i <= n; ++i) {
        mat[i][i] = 0;
    }

    std::cout << "Now enter each edge as: u v w\n";
    for (int i = 0; i < e; ++i) {
        int u, v;
        long w;
        std::cout << "  Edge " << (i+1) << ": ";
        std::cin >> u >> v >> w;
        mat[u][v] = std::min(mat[u][v], w);
        mat[v][u] = std::min(mat[v][u], w);
    }

    // Dijkstra inicializálás
    std::vector<long> dist(n+1, INF);
    dist[1] = 0;
    using pli = std::pair<long,int>;
    std::priority_queue<pli, std::vector<pli>, std::greater<pli>> pq;
    pq.emplace(0, 1);
    std::vector<bool> visited(n+1, false);

    // Dijkstra főciklus
    while (!pq.empty()) {
        auto [d, u] = pq.top(); pq.pop();
        if (visited[u]) continue;
        visited[u] = true;
        for (int v = 1; v <= n; ++v) {
            if (mat[u][v] < INF && !visited[v]) {
                long nd = d + mat[u][v];
                if (nd < dist[v]) {
                    dist[v] = nd;
                    pq.emplace(nd, v);
                }
            }
        }
    }

    // Eredmény kiírása
    std::cout << "\nNode    :";
    for (int i = 1; i <= n; ++i)
        std::cout << std::setw(4) << i;
    std::cout << "\nDistance:";
    for (int i = 1; i <= n; ++i) {
        if (dist[i] >= INF/2) std::cout << std::setw(4) << "∞";
        else                  std::cout << std::setw(4) << dist[i];
    }
    std::cout << "\n";

    return 0;
}
