#include <iostream>
#include <limits>

int main(void)
{
    constexpr unsigned int a = 44;
    constexpr int b = -56;

    std::cout << "unsigned int a = " << a << "\n";
    std::cout << "int b = " << b << "\n";
    std::cout << "a + b = " << a + b // Result is implicitly cast to unsigned.
              << "\n";
    std::cout << "a - b = " << a - b << "\n";
    std::cout << "b + a = "
              << b + a // Order of operations does not affect the implicit cast.
              << "\n";
    std::cout << "b - a = " << b - a << "\n";
    std::cout << "\n";

    constexpr auto c = (int)a;
    constexpr auto d = (unsigned)b;

    std::cout << "auto c = (int)a = " << c << "\n";
    std::cout << "auto d = (unsigned)b = " << d << "\n";
    std::cout << "\n";

    constexpr unsigned int e = std::numeric_limits<unsigned int>::max();

    std::cout << "unsigned int e = unsigned int max = " << e << "\n";
    std::cout << "e + 1 = " << e + 1 << "\n"; // Wrap around.
    std::cout << "\n";

    int f = std::numeric_limits<int>::max();

    std::cout << "int f = int max = " << f << "\n";
    std::cout << "f + 1 = " << f + 1 << "\n"; // Integer overflow.
    std::cout << "f + a = " << f + a << "\n"; // Implicit cast to unsigned.

    return (0);
}
