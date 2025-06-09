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

// c++11
// 7.5.1. Döntsük el egy gráfról, hogy páros-e, ehhez segítségnek használjunk szomszédossági mátrixot és szélességi keresést! A szélességi keresés a gráf egy adott csúcsából kiindulva bejárjanak szomszédjait, ezután azok szomszédjait és így tovább. Az algoritmus implementációjában segíthet, ha a nem meglátogatott csúcsokat egy sor adatszerkezetbe rakjuk, a meglátogatni kívánt csúcsokat pedig kivesszünk ebből a listából és belerakjuk egy átmenetibe, így az algoritmust addig kell futtatni, míg van kivehető elem a sorból. 7.6. Belmann-Ford algoritmus

// C++11
#include <iostream>
#include <vector>
#include <queue>

int main() {
    std::ios::sync_with_stdio(false);
 //   std::cin.tie(nullptr);

    int N;
    std::cout << "Add meg a csucsok szamat (N): ";
    std::cin >> N;

    // Szomszédossági mátrix beolvasása
    std::vector<std::vector<int>> adj(N, std::vector<int>(N));
    std::cout << "Add meg az " << N << "x" << N << " szomszedossagi matrixot (0 vagy 1):\n";
    for (int i = 0; i < N; ++i)
        for (int j = 0; j < N; ++j)
            std::cin >> adj[i][j];

    // szin[i] = -1: nem bejarva, 0 vagy 1: a két osztalyba
    std::vector<int> color(N, -1);
    std::queue<int> q;
    bool isBipartite = true;

    // Ha a graf nem összefüggő, inditsunk BFS-t minden komponensre
    for (int start = 0; start < N && isBipartite; ++start) {
        if (color[start] != -1) 
            continue;
        color[start] = 0;
        q.push(start);

        while (!q.empty() && isBipartite) {
            int u = q.front(); 
            q.pop();
            for (int v = 0; v < N; ++v) {
                if (adj[u][v] == 0) 
                    continue;               // nincs él u és v között
                if (color[v] == -1) {
                    // szinezzuk ellentett szinre
                    color[v] = color[u] ^ 1;
                    q.push(v);
                }
                else if (color[v] == color[u]) {
                    // szomszedos csucsokba kerult ugyanaz a szin
                    isBipartite = false;
                    break;
                }
            }
        }
    }

    if (isBipartite) {
        std::cout << "\nA graf páros (bipartit).\n";
        std::cout << "Első osztály (szin=0):";
        for (int i = 0; i < N; ++i)
            if (color[i] == 0) 
                std::cout << ' ' << i;
        std::cout << "\nMásodik osztály (szin=1):";
        for (int i = 0; i < N; ++i)
            if (color[i] == 1) 
                std::cout << ' ' << i;
        std::cout << "\n";
    } else {
        std::cout << "\nA graf nem páros.\n";
    }

    return 0;
}
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
