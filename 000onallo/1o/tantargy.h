//
// Created by d on 6/16/25.
//

#ifndef TANTARGY_H
#define TANTARGY_H
#include <iostream>

namespace egyetem {
    class Tantargy{


    private:
        std::string kod;
        unsigned int db;
        unsigned int * jegyek;
        double atlag;
    public:
        Tantargy();
        Tantargy(const std::string& k, unsigned int db);
        ~Tantargy();
        Tantargy(const Tantargy& other);
        Tantargy& operator=(const Tantargy& other);
        double atl();


        void set_kod(const std::string &kod);
        void set_db(const unsigned int db);
        void set_atlag(const double atlag);
        void set_jegyek(unsigned int * j);
        void set_jegy(unsigned int i, int ertek);

        std::string get_kod() const;
        unsigned int get_db() const;
        double get_atlag() const;
        const unsigned int * get_jegyek() const;
    };
}

#endif //TANTARGY_H
