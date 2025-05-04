// Program 20_8
// Pure virtual function
#include<iostream>
using namespace std;

class shipping_company {
public:
	virtual float shipping_cost(float) = 0;           
};

class VQT : public shipping_company {
public:
	float shipping_cost(float weight) {
		return 3.0 + 1.5*weight;
	}
};

class NatFast : public shipping_company {
public:
	float shipping_cost(float weight) {
		return 2.0*weight;
	}
};

class GovernmentPost : public shipping_company {
public:
	float shipping_cost(float weight) {
		if (weight < 2.0) {
			return 4.0;
		}
		else if (weight < 4.0) {
			return 8.0;
		}
		else if (weight < 6.0) {
			return 11.0;
		}
		else {
			return 2.0*weight;
		}
	}
};

shipping_company& select_company() {
	int option;
	cout << "Which shipping company do you use? " <<
		"Enter 1 for VQT, 2 for NatFast, 3 for Government Post: ";
	cin >> option;
	if (option == 1) {
		return *new VQT();
	}
	else if (option == 2) {
		return *new NatFast();
	}
	else {
		return *new GovernmentPost();
	}
}

int main() {
	float w;
	cout << "What is the package weight? ";
	cin >> w;
	shipping_company& x = select_company();

	cout << "Your package will cost " << x.shipping_cost(w) << " to ship." << endl;
}