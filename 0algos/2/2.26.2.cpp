// 2.26.2. Demonstrálja, hogy a * és a & ellentétes hatású műveletek! 

// 2.26.2. 


// A kifejezés:

// ```c
// printf("The volume of the cube is: %d\n", *&*&volume);
// ```

// valóban **demonstrálja, hogy a `*` (dereferencia) és a `&` (címképzés) egymás inverzei**, azaz "ellentétes hatású műveletek".

// ---

// ### 🔍 Magyarázat lépésenként

// Tegyük fel:

// ```c++
// int volume = 125;
// ```

// A kifejezés:

// ```c++
// *&*&volume
// ```

// így értelmezhető:

// 1. `&volume` → a `volume` változó címe (pl. `0x7ffeefbff5a4`)
// 2. `*&volume` → először `&volume`, majd `*` visszaadja a `volume` értékét, tehát `125`
// 3. `*&*&volume` → ugyanaz, mint `volume`, hiszen minden `*` és `&` pár kioltja egymást.

// ---

// ### ✅ Tehát ez teljesen helyes példa arra, hogy:

// ```cpp
// *&x == x
// ```

// bármilyen változóra `x`.

// ---

// ### Példa C++11 verzióban:

// ```cpp
#include <iostream>
using namespace std;

int main() {
    int volume = 125;
    cout << "The volume of the cube is: " << *&*&volume << endl;
    return 0;
}
// ```

// ---

// Ez a kimenetet adja:

// ```
// The volume of the cube is: 125
// ```

// 💡 **Összefoglalás**: A `&` és a `*` egymás ellentétei – egy változó címét veszed, majd az azon a címen levő értéket olvasod ki.


 