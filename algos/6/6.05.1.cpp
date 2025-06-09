//  6.5.1. Írjon programot, amely kiértékel egy egyszerű matematikai kifejezést! A kifejezések lebegőpontos számokat, illetve négy matematikai operátort tartalmazhatnak: összeadás (+), kivonás (-), szorzás (*), osztás (/). A kifejezés nem tartalmaz zárójeleket. A kifejezést fájlból olvassa be! A program a beolvasott matematikai kifejezést és annak eredményét írja ki a képernyőre! Figyeljen az operátorok kiértékelési sorrendjére! Például 1 + 2 * 3 = 7 és nem 9. Az input fájl formátuma: Első sor: Az operandusok száma. Második sor: A matematikai kifejezés. A számok és operátorok egy-egy szóköz karakterrel vannak elválasztva. Példa bemenet: 6 2 + 3 * 54 - 64 / 10 + 60 Kimenet: 2 + 3 * 54 - 64 / 10 + 60 = 217.6 


// c++11
#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <string>
#include <iomanip>

// Evaluate tokens in two passes: first * and /, then + and -
double evalExpression(std::vector<std::string>& tokens) {
    // 1) * and /
    for (size_t i = 1; i < tokens.size() - 1; ) {
        if (tokens[i] == "*" || tokens[i] == "/") {
            double lhs = std::stod(tokens[i-1]);
            double rhs = std::stod(tokens[i+1]);
            double res = (tokens[i] == "*") ? (lhs * rhs) : (lhs / rhs);
            tokens[i-1] = std::to_string(res);
            tokens.erase(tokens.begin() + i, tokens.begin() + i + 2);
            // stay at same i (now points to next operator)
        } else {
            i += 2; // skip over the next number to the following operator
        }
    }
    // 2) + and -
    for (size_t i = 1; i < tokens.size() - 1; ) {
        if (tokens[i] == "+" || tokens[i] == "-") {
            double lhs = std::stod(tokens[i-1]);
            double rhs = std::stod(tokens[i+1]);
            double res = (tokens[i] == "+") ? (lhs + rhs) : (lhs - rhs);
            tokens[i-1] = std::to_string(res);
            tokens.erase(tokens.begin() + i, tokens.begin() + i + 2);
        } else {
            i += 2;
        }
    }
    // now tokens.size() == 1
    return std::stod(tokens[0]);
}

int main(int argc, char* argv[]) {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    std::ifstream fin;
    if (argc > 1) {
        fin.open(argv[1]);
        if (!fin) {
            std::cerr << "Cannot open file " << argv[1] << "\n";
            return 1;
        }
    }
    std::istream& in = (fin.is_open() ? fin : std::cin);

    int n;
    if (!(in >> n)) {
        std::cerr << "Failed to read the operand count\n";
        return 1;
    }
    std::vector<std::string> tokens;
    tokens.reserve(n * 2 - 1);

    // read the rest of the line: expression tokens
    std::string tok;
    for (int i = 0; i < 2*n-1; ++i) {
        in >> tok;
        tokens.push_back(tok);
    }

    // print original expression
    for (size_t i = 0; i < tokens.size(); ++i) {
        std::cout << tokens[i] << (i+1<tokens.size() ? ' ' : '\0');
    }

    // copy tokens for evaluation
    auto evalTokens = tokens;
    double result = evalExpression(evalTokens);

    // trim trailing zeros
    std::ostringstream oss;
    oss << std::fixed << std::setprecision(6) << result;
    std::string s = oss.str();
    // remove trailing zeros and possibly the dot
    s.erase(s.find_last_not_of('0') + 1, std::string::npos);
    if (!s.empty() && s.back() == '.') s.pop_back();

    std::cout << " = " << s << "\n";
    return 0;
}

