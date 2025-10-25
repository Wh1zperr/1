#include <iostream>
#include <limits>
#include <cmath>



bool isPythagoreanTriple(int a, int b, int c) {
    // Проверяем все комбинации a² + b² = c²
    long long a2 = (long long)a * a;
    long long b2 = (long long)b * b;
    long long c2 = (long long)c * c;

    return (a2 + b2 == c2) || (a2 + c2 == b2) || (b2 + c2 == a2);
}
