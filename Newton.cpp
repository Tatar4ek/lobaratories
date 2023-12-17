#include <iostream>
#include <cmath>

using namespace std;

double equation(double x) {
    return 0.25 * pow(x, 3) + x - 1.2502;
}

double derivative(double x) {
    return 0.75 * pow(x, 2) + 1;
}

double newtonMethod(double x0, double tolerance, int maxIterations) {
    double x = x0;

    for (int i = 0; i < maxIterations; i++) {
        double fx = equation(x);
        double dfx = derivative(x);

        double deltaX = -fx / dfx;
        x += deltaX;

        if (abs(deltaX) < tolerance) {
            return x;
        }
    }

    return NAN; // Решение не найдено
}

int main() {
    setlocale(LC_ALL, "RUS");

    double x0 = 0.2;
    double tolerance = 1e-8;
    int maxIterations = 100;

    double solution = newtonMethod(x0, tolerance, maxIterations);

    if (isnan(solution)) {
        cout << "Решение не найдено." << endl;
    }
    else {
        cout << "Решение: " << solution << endl;
    }

    return 0;
}