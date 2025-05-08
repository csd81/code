vector<Product*> readProducts(const string& filename) {
    vector<Product*> products;
    ifstream infile(filename);
    string line;

    while (getline(infile, line)) {
        size_t pos1 = line.find(' ');
        if (pos1 == string::npos) continue;

        string code = line.substr(0, pos1);

        if (code[0] == 'S') {
            int price = stoi(line.substr(pos1 + 1));
            products.push_back(new SingleProduct(code, price));

        } else if (code[0] == 'M' || code[0] == 'P') {
            size_t pos2 = line.find(' ', pos1 + 1);
            if (pos2 == string::npos) continue;

            int price = stoi(line.substr(pos1 + 1, pos2 - pos1 - 1));
            int secondValue = stoi(line.substr(pos2 + 1));

            if (code[0] == 'M') {
                products.push_back(new MultiProduct(code, price, secondValue));
            } else {
                products.push_back(new PackagedProduct(code, price, secondValue));
            }
        }
    }

    return products;
}
