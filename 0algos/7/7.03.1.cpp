// C++11
// 7.3.1. A Szahara egyik szegletében 11 oázis található. Nem mindegyik között van közvetlen út és az utak sokszor kacskaringósak, hogy elkerüljék a futóhomokot és más veszélyeket. 10 beduin törzs él külön oázisokban, a 11., a szent oázis lakatlan. A törzsek egyszer csak észreveszik, hogy mindegyikük oázisa a kiszáradás szélén áll. Összegyűltek hát, hogy megoldást találjanak a problémára. A szent oázisban annyi víz van, amely képes elegendő vízzel ellátni a törzseket. Megállapodnak abban, hogy közösen építenek egy csővezeték rendszert az utak mellett, amelyen keresztül elegendő vízhez jut minden törzs. Ismerjük az oázisok közötti utak távolságát. Írjon programot, amely megtervez egy, az oázisokat összekötő csőhálózatot úgy, hogy a lehető legkevesebb cső felhasználásával minden kiszáradó oázis vízhez juthasson. A csövek kapacitása elég nagy, tehát az egyszerre szállítandó víz mennyiségével nem kell foglalkozni. Ötlet: használjon Prim algoritmust! 7.4. Sörhálózat A Kétfarkú Kutyapárt megnyerte a választásokat, így ígéretükhöz híven az ivóvíz hálózat mellé ingyen sör hálózatot alakítanak ki. Mindenkinek persze nem jut az ingyen sörből, de az év egy napján leállítják a vízszolgáltatást és a vízvezetékeken keresztül egy szerencsés kisorsolt városban megindul a sörszolgáltatás. A városok közötti vízvezetéknek ismert a szállítási kapacitása, valamint hogy az egyes vezetékek mely városokat kötnek össze. A hálózat egyik csomópontja a sörgyár.


#include <iostream>
#include <vector>
#include <limits>
#include <iomanip>

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    const double INF = std::numeric_limits<double>::infinity();

    // ===== Beolvasás =====
    int N;
    std::cout << "Add meg az oazisok szamat (N=11): ";
    std::cin >> N;
    std::vector<std::vector<double>> cost(N, std::vector<double>(N));
    std::cout << "Add meg az " << N << "x" << N << " adjacencia-matrixot (-1 = nincs ut):\n";
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            std::cin >> cost[i][j];
            if (cost[i][j] < 0) 
                cost[i][j] = INF;
        }
    }

    // ===== Prim algoritmus =====
    std::vector<bool> inMST(N, false);
    std::vector<double> minEdge(N, INF);
    std::vector<int> parent(N, -1);

    // Kezdjük 0. nodussal
    minEdge[0] = 0.0;

    double totalWeight = 0.0;
    std::vector<std::pair<int,int>> mstEdges;

    for (int k = 0; k < N; ++k) {
        // Ki a következő legkisebb élű nem-MST csúcs?
        int u = -1;
        for (int i = 0; i < N; ++i) {
            if (!inMST[i] && (u == -1 || minEdge[i] < minEdge[u])) {
                u = i;
            }
        }
        // Hozzáadjuk az MST-hez
        inMST[u] = true;
        if (parent[u] != -1) {
            totalWeight += minEdge[u];
            mstEdges.emplace_back(parent[u], u);
        }
        // Frissítjük a szomszédok minimális élértékeit
        for (int v = 0; v < N; ++v) {
            if (!inMST[v] && cost[u][v] < minEdge[v]) {
                minEdge[v] = cost[u][v];
                parent[v]  = u;
            }
        }
    }

    // ===== Eredmény kiírása =====
    std::cout << "\nPrim algoritmus eredmenye:\n";
    std::cout << "Minimalis osszsuly: " << totalWeight << "\n";
    std::cout << "MST elemei (u -> v : suly):\n";
    for (auto &e : mstEdges) {
        int u = e.first, v = e.second;
        std::cout << "  " << std::setw(2) << u
                  << " -> " << std::setw(2) << v
                  << " : " << cost[u][v] << "\n";
    }

    return 0;
}
