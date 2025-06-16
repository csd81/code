//
// Created by d on 6/16/25.
//

#include "tantargy.h"
namespace egyetem {

    Tantargy::Tantargy() {
        kod ="";
        db =0;
        jegyek = nullptr;
        atlag = 0.0;
    }

    std::string Tantargy::get_kod() const {
        return kod;
    }

    void Tantargy::set_kod(const std::string &kod) {
        this->kod = kod;
    }

    unsigned int Tantargy::get_db() const {
        return db;
    }

    void Tantargy::set_db(const unsigned int db) {
        this->db = db;
    }

    double Tantargy::get_atlag() const {
        return atlag;
    }

    void Tantargy::set_atlag(const double atlag) {
        this->atlag = atlag;
    }

    const unsigned int * Tantargy::get_jegyek() const {
        return jegyek;
    }


    void Tantargy::set_jegyek(unsigned int * j) {
        jegyek=j;
    }

    void Tantargy::set_jegy(unsigned int i, int ertek) {
        jegyek[i] = ertek;
    }


    // Paraméteres konstruktor
    Tantargy::Tantargy(const std::string& k, unsigned int db) : kod(k), db(db) {
        jegyek = new unsigned int[db];
        for (int j = 0; j < db; j++){
            std::cout << j+1 << ". jegy?" << std::endl;
            std::cin >> jegyek[j];
        }
        atlag = atl();
    }

    // Másoló konstruktor
    Tantargy::Tantargy(const Tantargy& other): kod(other.kod), db(other.db) {
        jegyek = new unsigned int[other.db];
        for (unsigned int i = 0; i < other.db; i++) {
            jegyek[i] = other.jegyek[i];
        }
        atlag = atl();
    }

    // Destruktor
    Tantargy::~Tantargy() {
        delete[] jegyek;
        jegyek = nullptr;
    }
    // Értékadó operátor
    Tantargy& Tantargy::operator=(const Tantargy& other) {
        if (this != &other) {
            delete[] jegyek;
            this->kod = other.kod;
            this->db= other.db;
            this->jegyek = new unsigned int[other.db];
            for (unsigned int i = 0; i < other.db; i++) {
                this->jegyek[i] = other.jegyek[i];
            }
            atlag = atl();
        }
        return *this;
    }

    double Tantargy::atl(){
        if (db == 0) return 0.0;

        double atl = 0;

        for (unsigned int i = 0; i < db; i++){
            atl += (double)jegyek[i];
        }
        return atl / (double)db;
    }
}