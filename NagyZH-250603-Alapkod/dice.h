#ifndef DICE_H
#define DICE_H

//
// Az osztaly kodja nem modosithato!
//

// ez az osztaly reprezental egy kockadobast
class Dice
{
public:
    // helyreallitja a generator allapotat
    // nincs vele teendo a feladatban!
    static void seed(unsigned int newSeed);

    // visszaad egy veletlen erteket 1-tol 6-ig
    // (lasd a main() elejet a peldahoz)
    static int roll();
};

#endif // DICE_H
