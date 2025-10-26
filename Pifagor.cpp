#include <iostream>
#include <limits>
#include <cmath>
#include <cstddef>



bool isPythagoreanTriple(int a, int b, int c) {
    // Проверяем все комбинации a² + b² = c²
    long long a2 = (long long)a * a;
    long long b2 = (long long)b * b;
    long long c2 = (long long)c * c;

    return (a2 + b2 == c2) || (a2 + c2 == b2) || (b2 + c2 == a2);
}

// Задаём границу переполнения
size_t get_max_boundary()
{
    return std::numeric_limits<size_t>::max();
}

// Проверка умножения на переполнение
size_t multiply(const size_t a, const size_t b) {
    if (a > get_max_boundary() / b) {
        throw std::overflow_error("multiplication overflow");
    }
    return a * b;
}

// Проверка суммы на переполнение
size_t sum(const size_t a, const size_t b)
{
    if (a > get_max_boundary() - b)
    {
        throw std::overflow_error("addition overflow");
    }
    return a + b;
}

// Проверка вычисления Пифагоровой тройки на переполнение
bool isPyth(const size_t a, const size_t b, const size_t c)
{
    try {
        size_t a2 = multiply(a, a);
        size_t b2 = multiply(b, b);
        size_t c2 = multiply(c, c);

        if (a2 == sum(b2, c2)) return true;
        if (b2 == sum(a2, c2)) return true;
        if (c2 == sum(a2, b2)) return true;
        return false;
    }
    catch (const std::overflow_error&) {
        throw; // Перебрасываем исключение дальше
    }
}

int main()
{
    size_t counter = 0;
    size_t a = 0, b = 0, c = 0;

    // Считываем первые два числа с проверкой ошибок
    std::cin >> a >> b;
    if (std::cin.fail()) {
        if (std::cin.eof()) {
            std::cout << 0 << "\n";  // Меньше 3 чисел - троек нет
            return 0;
        }
        else {
            std::cerr << "Error reading sequence\n";
            return 1;
        }

    }

    // Теперь точно есть как минимум 2 числа, можно читать третье
    while (std::cin >> c) {
    try {
        if (isPyth(a, b, c)) {
            counter++;
        }
    }
    catch (const std::overflow_error& e) {  // Только переполнение!
        std::cerr << "Error: " << e.what() << "\n";
        return 2;
    }
