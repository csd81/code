// C++11
//  7.4.1. Írjon programot, amely megmondja, hogy maximálisan mennyi sört lehet továbbítani a sörgyárból a kisorsolt városba, ehhez mely vezetékeket kell felhasználni és, hogy ezek a vezetékek milyen mértékben lesznek kihasználva! A program fájlból olvassa be a vezetékhálózatot és a felhasználótól kérdezze meg, hogy hol van a sörgyár és melyik a kisorsolt város! Ötlet: használjon Ford és Fulkerson algoritmust! 
//  7.4.2. Határozzuk meg, hogy ha csak egy városban lehet sörgyár (a helyét nem kötjük ki), akkor legfeljebb hány várost láthatunk el itallal? Ez azért fontos, mert a vezetékhálózat nem köt össze minden várost. 
//  7.4.3. Írjon függvényt, amely meghatározza, hogy egy adott csomópontból hova lehet eljuttatni a legnagyobb mennyiségű sört, és mekkora ez a mennyiség!  


// C++11
#include <iostream>
#include <fstream>
#include <vector>
#include <queue>
#include <limits>
#include <iomanip>

using Capacity = double;
const Capacity INF = std::numeric_limits<Capacity>::infinity();

// Edmonds–Karp: returns max flow, fills flow[u][v]
Capacity maxFlowEK(int N,
                   const std::vector<std::vector<Capacity>>& capacity,
                   int s, int t,
                   std::vector<std::vector<Capacity>>& flow)
{
    // residual capacities
    std::vector<std::vector<Capacity>> residual = capacity;
    flow.assign(N, std::vector<Capacity>(N, 0.0));
    Capacity maxFlow = 0.0;

    while (true) {
        // BFS to find shortest augmenting path
        std::vector<int> parent(N, -1);
        std::queue<int> q;
        q.push(s);
        parent[s] = s;
        while (!q.empty() && parent[t] == -1) {
            int u = q.front(); q.pop();
            for (int v = 0; v < N; ++v) {
                if (parent[v] == -1 && residual[u][v] > 0) {
                    parent[v] = u;
                    q.push(v);
                    if (v == t) break;
                }
            }
        }
        if (parent[t] == -1) break; // no more augmenting path

        // find bottleneck capacity
        Capacity bottleneck = INF;
        for (int v = t; v != s; v = parent[v]) {
            int u = parent[v];
            bottleneck = std::min(bottleneck, residual[u][v]);
        }

        // augment flow
        for (int v = t; v != s; v = parent[v]) {
            int u = parent[v];
            residual[u][v] -= bottleneck;
            residual[v][u] += bottleneck;
            flow[u][v] += bottleneck;
            flow[v][u] -= bottleneck;
        }
        maxFlow += bottleneck;
    }

    return maxFlow;
}

// BFS count of reachable nodes in original graph (capacity > 0)
int countReachable(int N,
                   const std::vector<std::vector<Capacity>>& capacity,
                   int src)
{
    std::vector<bool> vis(N, false);
    std::queue<int> q;
    vis[src] = true;
    q.push(src);
    int cnt = 0;
    while (!q.empty()) {
        int u = q.front(); q.pop();
        ++cnt;
        for (int v = 0; v < N; ++v) {
            if (!vis[v] && capacity[u][v] > 0) {
                vis[v] = true;
                q.push(v);
            }
        }
    }
    return cnt - 1; // exclude the source itself
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    // --- Input ---
    std::ifstream fin("pipes.txt");
    if (!fin) {
        std::cerr << "Nem lehet megnyitni a 'pipes.txt' fájlt.\n";
        return 1;
    }

    int N;
    fin >> N;
    std::vector<std::vector<Capacity>> capacity(N,
        std::vector<Capacity>(N, 0.0));
    for (int i = 0; i < N; ++i)
        for (int j = 0; j < N; ++j) {
            Capacity c;
            fin >> c;
            // -1 jelenti: nincs vezeték
            capacity[i][j] = (c < 0 ? 0.0 : c);
        }
    fin.close();

    // --- 7.4.1 Ford–Fulkerson maximum flow ---
    int brewery, city;
    std::cout << "Hol legyen a sörgyár? (0–" << N-1 << "): ";
    std::cin >> brewery;
    std::cout << "Melyik a kisorsolt város? (0–" << N-1 << "): ";
    std::cin >> city;

    std::vector<std::vector<Capacity>> flow;
    Capacity maxF = maxFlowEK(N, capacity, brewery, city, flow);

    std::cout << "\nMaximálisan szállítható sör: "
              << maxF << "\n";
    std::cout << "Használt vezetékek és kihasználtságuk:\n";
    for (int u = 0; u < N; ++u) {
        for (int v = 0; v < N; ++v) {
            if (capacity[u][v] > 0 && flow[u][v] > 0) {
                Capacity util = (flow[u][v] / capacity[u][v]) * 100.0;
                std::cout << "  " << u << " -> " << v
                          << " : flow=" << flow[u][v]
                          << ", cap=" << capacity[u][v]
                          << ", kihasználtság=" << std::fixed
                          << std::setprecision(1)
                          << util << "%\n";
            }
        }
    }

    // --- 7.4.2 Legtöbb ellátható város egy optimális sörgyárral ---
    int bestSrc = 0, bestCount = 0;
    for (int s = 0; s < N; ++s) {
        int cnt = countReachable(N, capacity, s);
        if (cnt > bestCount) {
            bestCount = cnt;
            bestSrc = s;
        }
    }
    std::cout << "\nHa tetszőleges városban lehet a sörgyár, akkor a "
              << bestSrc << ". helyről legfeljebb "
              << bestCount << " várost tudunk ellátni.\n";

    // --- 7.4.3 Legnagyobb mennyiség egy adott forrásból ---
    int s0;
    std::cout << "\nAdd meg a vizsgált forrást (0–" << N-1 << "): ";
    std::cin >> s0;
    int bestT = -1;
    Capacity bestFlow = 0.0;
    for (int t = 0; t < N; ++t) {
        if (t == s0) continue;
        std::vector<std::vector<Capacity>> ftmp;
        Capacity f = maxFlowEK(N, capacity, s0, t, ftmp);
        if (f > bestFlow) {
            bestFlow = f;
            bestT = t;
        }
    }
    if (bestT >= 0) {
        std::cout << "A forrásból " << s0
                  << " legtöbb sör " << bestFlow
                  << " mennyiségben a " << bestT
                  << ". városba juttatható el.\n";
    } else {
        std::cout << "Nincs elérhető célváros.\n";
    }

    return 0;
}

