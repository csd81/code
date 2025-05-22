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
