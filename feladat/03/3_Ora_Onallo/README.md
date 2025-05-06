Itt van a szöveg formázva, áttekinthető szerkezetben, programozási feladatleírásként:

---

## Feladatleírás

A feladat elkezdéséhez a mellékelt projekt tartalmaz kódokat. A megoldás során bizonyos feladatoknál ezekhez a kódokhoz is hozzá kell nyúlni. A teszteléshez a `main` függvényben a nem használt kódokat ki lehet kommentezni.

### Megadott osztályok

* **`Szamsor` osztály**
  Egy dinamikusan foglalt tömböt tárol egész számokból, pár alapvető függvénnyel. A tömb méretét a konstruktora adja meg.

* **`Szemely` osztály**
  Egy közös feladatban is használt osztály.

> ⚠️ Fontos: Ügyelj arra, hogy minden lefoglalt memória megfelelően fel legyen szabadítva!

---

## Új osztály: `Rendezveny`

Származtass egy `Rendezveny` osztályt a `Szamsor` osztályból, amely egy egyhetes rendezvény adatait tárolja.

* Az ősosztály által létrehozott dinamikus tömb mérete **mindig 7** legyen
  (egy-egy szám a hét minden napjához, ami az adott napi létszámot jelenti).

* Tartalmazzon egy `Szemely*` mutatót, amely a rendezvény kiemelt vendégére mutat (feltéve ha van, ezért mutató).

  * A kiemelt vendéget lehessen:

    * **beállítani**
    * **lekérdezni**

---

## Implementálandó függvények

1. **`void kiir()`**
   A `Rendezveny` osztályban. Írja ki az összes adatot.

2. **Másoló konstruktor**
   Készíts másoló konstruktort a `Rendezveny` osztályhoz.

3. **`void legjobbNap()`**
   A `Rendezveny` osztályban. Írja ki, hogy a rendezvény **hanyadik napján** volt a legnagyobb létszám.

4. **Globális függvény a `main.cpp`-ben:**

   ```cpp
   void kisebbAtlag(const Szamsor& a, const Szamsor& b);
   ```

   * Paraméterként kap két `Szamsor` objektumot.
   * A függvény írja ki, hogy:

     * az elsőnek,
     * a másodiknak, vagy
     * **mindkettőnek azonos**
       az átlaga-e.

 
