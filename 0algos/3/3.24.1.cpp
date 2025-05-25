// 3.24. Egyszerű sztringfordító
// 3.24.1. Írjon programot, amely beolvas egy fájlból utasításokat és 
// végrehajtja a benne foglaltakat! Az utasítások három integer típusú 
// változót használhatnak: A, B, C. A script elején a változók értéke 0. A 
// lehetséges utasítások a következők: GET Op: Op lehet egy változó (A, B, 
// or C), ez a parancs beolvas egy tízes számrendszerbeli számot a 
// billentyűzetről, és az Op-ban tárolja. WRITE Op: Op értékét a 
// képernyőre írja. ADD Op1 Op2: Hozzáadja Op2-t Op1-hez, azaz Op1 = Op1 + 
// Op2. SUB Op1 Op2: Kivonja Op2-t Op1-ből, azaz Op1 = Op1 - Op2. MUL Op1 Op2: 
// Megszorozza Op1-et Op2-vel, azaz Op1 = Op1 * Op2. DIV Op1 Op2: Elosztja Op1-et 
// Op2-vel, azaz Op1 = Op1 / Op2. STOP: Ez a parancs a script végét jelzi. 
// Minden sorban csak egy parancs szerepel. Ha a sor # karakterrel kezdődik, azt 
// a sort megjegyzésnek tekintjük. Ezeknek a soroknak a végét is egy # 
// karakter jelzi. Az első # után egy szóköz karakter következik. A program 
// írja ki ezeket a sorokat a képernyőre, a # karakterek kivételével! 
// Például ha a sor a következő „# This is a comment! #”, a program a 
// következőt írja ki: „This is a comment!” Példa bemenet: # Type A: # GET 
// A # Type B: # GET B ADD A B # The sum: # WRITE A STOP Kimenet: Type A: 1 Type 
// B: 2 The sum: 3 
// 3.24.1.

#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <map>

#define DEFAULT_INPUTFILE "script.txt"

void get(std::istream& in, std::map<char, int>& vars) {
    std::string op;
    in >> op;
    int value;
    std::cin >> value;
    vars[op[0]] = value;
}

void write(std::istream& in, const std::map<char, int>& vars) {
    std::string op;
    in >> op;
    std::cout << vars.at(op[0]) << std::endl;
}

void add(std::istream& in, std::map<char, int>& vars) {
    std::string op1, op2;
    in >> op1 >> op2;
    vars[op1[0]] += vars[op2[0]];
}

void sub(std::istream& in, std::map<char, int>& vars) {
    std::string op1, op2;
    in >> op1 >> op2;
    vars[op1[0]] -= vars[op2[0]];
}

void mul(std::istream& in, std::map<char, int>& vars) {
    std::string op1, op2;
    in >> op1 >> op2;
    vars[op1[0]] *= vars[op2[0]];
}

void div(std::istream& in, std::map<char, int>& vars) {
    std::string op1, op2;
    in >> op1 >> op2;
    if (vars[op2[0]] != 0) {
        vars[op1[0]] /= vars[op2[0]];
    } else {
        std::cerr << "Error: Division by zero\n";
    }
}

void writeComment(const std::string& line) {
    auto first = line.find('#');
    auto last = line.rfind('#');
    if (first != std::string::npos && last != std::string::npos && last > first) {
        std::string comment = line.substr(first + 1, last - first - 1);
        std::cout << comment << std::endl;
    }
}

void run(std::istream& in) {
    std::map<char, int> vars = {{'A', 0}, {'B', 0}, {'C', 0}};
    std::string line;

    while (std::getline(in, line)) {
        if (line.empty()) continue;

        std::istringstream iss(line);
        std::string command;
        iss >> command;

        if (command == "#") {
            writeComment(line);
        } else if (command == "GET") {
            get(iss, vars);
        } else if (command == "WRITE") {
            write(iss, vars);
        } else if (command == "ADD") {
            add(iss, vars);
        } else if (command == "SUB") {
            sub(iss, vars);
        } else if (command == "MUL") {
            mul(iss, vars);
        } else if (command == "DIV") {
            div(iss, vars);
        } else if (command == "STOP") {
            break;
        }
    }
}

int main(int argc, char* argv[]) {
    std::string filename = (argc > 1) ? argv[1] : DEFAULT_INPUTFILE;
    std::ifstream infile(filename);

    if (!infile) {
        std::cerr << "Error opening file: " << filename << std::endl;
        return 1;
    }

    run(infile);
    return 0;
}

