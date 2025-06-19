 
 
- A `printAll` metódus írja ki az összes szereplő minden adatát.





Tudjanak a szereplők akciókat végrehajtani egymáson. Ez két, függetlenül pontozott feladatrészből áll.

### 1. Arena::performAction

Kapja meg az akció végrehajtóját és a célpontot.  
Nem kell kiírni semmit. Az okozott hatás a két fél karakterosztályától függ az alábbiak szerint:

- A **katona** megtámadja a célpontját, akinek az életereje annyival csökken, amennyi a katona ereje.  
  Ha van a célpontnak páncélja, akkor az semlegesít annyit, amennyi a páncél értéke.  
  A célpont **mindig sérül legalább 1-et**.

- A **mágus** is megtámadja a célpontját, akinek az életereje annyival csökken, amennyi a mágus varázsereje.  
  A páncél itt **nem számít**.

- A **pap** gyógyítja a célpontját, akinek az életereje annyival nő, amennyi a pap varázsereje.

- **Soha** nem csökkenhet az életerő 0 alá, és nem nőhet a maximális fölé.

- Ha egy szereplő életereje **0-ra csökken**, **elesik**. Innentől **nem gyógyítható** és **nem tud akciózni** (nincs hatása).

### 2. ActionList osztály

- Konstruktorban szöveges fájlt vár.
- Beolvassa és eltárolja a végrehajtó-célpont párokat.
- Az azonosítók nem tartalmaznak whitespace-t.
- A `printSome` metódus kiír néhány akciót (nem az összeset).
- Az `Arena` osztályban legyen `performList` metódus, ami végrehajtja az összes akciót az `ActionList`-ből.

