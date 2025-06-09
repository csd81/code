// 2.43. Tippelés
// 2.43.1. Írjon időtippelő programot! A program állítson elő egy véletlen 
// számot 1 és 5 között és ezt írja ki a képernyőre! Ennyi időt kell majd 
// várni a felhasználónak. Ezután kérjen be két sztringet úgy, hogy méri a 
// bekérések között eltelt időt! Írja ki, hogy ténylegesen mennyi idő telt 
// el a két bekérés között! Ha a bemenet a „quit” sztring, akkor lépjen 
// ki a programból! 
// 2.43.1.


#include <iostream>
#include <string>
#include <chrono>
#include <thread>
#include <cstdlib>
#include <ctime>
#include <iomanip>



int main() {
    using namespace std;
    using namespace std::chrono;

    srand(static_cast<unsigned>(time(0)));

    string input;
    cout << "Press 'a' and enter to start the clock!" << endl;
    cout << "Do the same to stop it!" << endl;
    cout << "Type 'quit' to end program!" << endl;

    while (input != "quit") {
        int wait = rand() % 5 + 1; // 1 to 5
        cout << "\nWait for " << wait << " seconds!" << endl;

        cout << "Begin: ";
        cin >> input;
        if (input == "quit") break;

        auto start = steady_clock::now();

        cout << "End: ";
        cin >> input;
        auto end = steady_clock::now();

        if (input == "quit") break;

        duration<double> elapsed = end - start;
        cout << "You have waited " << fixed << setprecision(2)
             << elapsed.count() << " seconds instead of " << wait << ".\n";
    }

    return 0;
}
