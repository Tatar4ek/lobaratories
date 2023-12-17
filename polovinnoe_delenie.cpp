#include <iostream>
#include <cmath>
using namespace std;
const double epsilon = 1e-5;

double f(double x) {
	return 0.25 * pow(x, 3) + x - 1.2502;
}

int main() {
	double a, b, c;
	a = 0;
	b = 2;
	while (b - a > epsilon) {
		c = (a + b) / 2;
		if (f(b) * f(c) < 0)
			a = c;
		else
			b = c;
	}
	cout << (a + b) / 2 << endl;
	return 0;
}