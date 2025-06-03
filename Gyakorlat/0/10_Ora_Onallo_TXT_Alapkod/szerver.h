#include "karakter.h"
#include <vector>


class Szerver {
private:
    std::vector<Karakter*> karakterek;
public:
    Szerver() = default;
    ~Szerver();

    void betolt();
    void listaz() const;
    Karakter* legtobbElet() const;
    std::string csata(const std::string& nev1, const std::string& nev2) const;
    void tornaSzimulacio() const;
};
