// C++11
// 7.2.1. Készítsen programot, amely beolvassa a csillagtérképet egy fájlból, majd határozza meg, hogy legolcsóbban mekkora összegért lehet szállítani a felhasználó által megadott két bolygó között! Adja meg a legolcsóbb úthoz tartozó útvonalat is! Ötlet: használjon Dijkstra algoritmust! 
// 7.2.2. Kérjen be egy bolygó sorszámát, majd határozza meg, hogy a féregjáratokon keresztül hány bolygóhoz lehet onnan eljutni! 
// 7.2.3. Határozza meg, hogy hány darab komponens található a csillagtérképen! Az egy komponensben lévő bolygók között létezik útvonal, két külön komponensben lévő bolygó között nem létezik. Adja minden komponensben, az ott található bolygók számát! 7.3. Oázisok



#include <iostream>
#include <fstream>
#include <vector>
#include <queue>
#include <limits>
#include <stack>

using Cost = double;
const Cost INF = std::numeric_limits<Cost>::infinity();

int main() {
    std::ifstream fin("terkep.txt");
    if (!fin) {
        std::cerr << "Nem nyitható meg a 'terkep.txt' fájl!\n";
        return 1;
    }

    int N;
    fin >> N;
    // Mátrix beolvasása
    std::vector<std::vector<Cost>> adj(N, std::vector<Cost>(N, -1));
    for (int i = 0; i < N; ++i)
        for (int j = 0; j < N; ++j)
            fin >> adj[i][j];
    fin.close();

    // --- 7.2.1. Dijkstra + útvonal visszaépítés ---
    int src, dst;
    std::cout << "Add meg a kiindulo bolygo szamat (0–" << N-1 << "): ";
    std::cin >> src;
    std::cout << "Add meg a cel bolygo szamat (0–" << N-1 << "): ";
    std::cin >> dst;

    // Dijkstra: (dist, node)
    std::vector<Cost> dist(N, INF);
    std::vector<int> prev(N, -1);
    dist[src] = 0;
    using PC = std::pair<Cost,int>;
    std::priority_queue<PC, std::vector<PC>, std::greater<PC>> pq;
    pq.emplace(0, src);

    while (!pq.empty()) {
        auto [d,u] = pq.top(); pq.pop();
        if (d > dist[u]) continue;
        for (int v = 0; v < N; ++v) {
            if (adj[u][v] >= 0) {
                Cost nd = d + adj[u][v];
                if (nd < dist[v]) {
                    dist[v] = nd;
                    prev[v] = u;
                    pq.emplace(nd, v);
                }
            }
        }
    }

    if (dist[dst] == INF) {
        std::cout << "Nincs ut a " << src << " es " << dst << " kozott.\n";
    } else {
        std::cout << "\nLegolcsobb koltseg: " << dist[dst] << "\n";
        // útvonal visszafejtése
        std::vector<int> path;
        for (int u = dst; u != -1; u = prev[u])
            path.push_back(u);
        std::cout << "Utvonal: ";
        for (int i = (int)path.size()-1; i >= 0; --i) {
            std::cout << path[i] << (i>0 ? " -> " : "\n");
        }
    }

    // --- 7.2.2. Hány bolygó érhető el adott kezdőpontból? (BFS) ---
    int q;
    std::cout << "\nAdd meg a vizsgalando bolygo szamat (0–" << N-1 << "): ";
    std::cin >> q;
    std::vector<bool> vis(N,false);
    std::queue<int>   que;
    vis[q] = true;
    que.push(q);
    int reachable = 0;
    while (!que.empty()) {
        int u = que.front(); que.pop();
        ++reachable;
        for (int v = 0; v < N; ++v) {
            if (adj[u][v] >= 0 && !vis[v]) {
                vis[v] = true;
                que.push(v);
            }
        }
    }
    std::cout << "A " << q << ". bolygobol " << reachable
              << " darab bolygó elerheto.\n";

    // --- 7.2.3. Komponensek száma és méretei ---
    std::fill(vis.begin(), vis.end(), false);
    int components = 0;
    std::vector<int> compSizes;
    for (int i = 0; i < N; ++i) {
        if (!vis[i]) {
            // új komponens
            ++components;
            int size = 0;
            std::stack<int> stk;
            stk.push(i);
            vis[i] = true;
            while (!stk.empty()) {
                int u = stk.top(); stk.pop();
                ++size;
                for (int v = 0; v < N; ++v) {
                    if (adj[u][v] >= 0 && !vis[v]) {
                        vis[v] = true;
                        stk.push(v);
                    }
                }
            }
            compSizes.push_back(size);
        }
    }

    std::cout << "\nKomponensek szama: " << components << "\n";
    for (int i = 0; i < components; ++i) {
        std::cout << "  " << (i+1) << ". komponens merete: "
                  << compSizes[i] << " csomopont\n";
    }

    return 0;
}
