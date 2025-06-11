#ifndef TOMBALAP_H
#define TOMBALAP_H

// TombAlap: közös ősosztály az azonos típusú tömbök számára (interfész szerep)
// A sablon paramétere a tárolt típus (Tipus)
// Nincs adattagja, csak tisztán virtuális metódusokat tartalmaz
template <class Tipus>
class TombAlap
{
public:
    // Destruktor (virtuális, alapértelmezett implementáció)
    virtual ~TombAlap() = default;

    // Tisztán virtuális metódusok:

    // meret: visszaadja a tömb méretét
    virtual int meret() const = 0;

    // beallit: beállítja a tömb adott indexű elemét a kapott értékre
    virtual void beallit(int index, const Tipus &adat) = 0;

    // leker: visszaadja a tömb adott indexű elemének másolatát
    virtual Tipus leker(int index) const = 0;

    // elem: visszaadja az adott indexű elemre mutató referenciát (nem const verzió)
    virtual Tipus &elem(int index) = 0;

    // elem: visszaadja az adott indexű elemre mutató const referenciát (const verzió)
    virtual const Tipus &elem(int index) const = 0;

    // operator []: nem virtuális, hanem a megfelelő elem() metódust hívja meg
    Tipus &operator [](int index)
    {
        return elem(index);
    }

    const Tipus &operator [](int index) const
    {
        return elem(index);
    }
};

#endif // TOMBALAP_H
