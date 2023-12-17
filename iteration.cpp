#include <iostream>
#include <cmath>
using namespace std;

double g(double x) {
	return 0.25 * pow(x, 3) + x - 1.2502;
}

double iterativeMethod(double x0, int maxIterations, double eps) {
	double currentX = x0;

	for (int i = 1; i < maxIterations; ++i) {
		double nextX = g(currentX);

		if (fabs(nextX - currentX) < eps) {
			return nextX;
		}
		currentX = nextX;
	}
	return currentX;

}
int main() {
	double a = 0;
	double b = 2;
	int maxIterations = 1000;
	double eps = 1e-9;
	double x0 = (a + b) / 2.0;
	double x = iterativeMethod(x0, maxIterations, eps);
	cout << x << endl;
	return 0;
}