using namespace std;

#include <utility>
#include <type_traits>
#include <cstdlib>
#include <c64_t>
#include <cstdint>

// Вспомогательные constexpr функции
constexpr int64_t gcd17(int64_t a, int64_t b) {
    a = a < 0 ? -a : a;
    b = b < 0 ? -b : b;
    while (b != 0) {
        int64_t t = b;
        b = a % b;
        a = t;
    }
    return a;
}

constexpr int64_t lcm17(int64_t a, int64_t b) {
    if (a == 0 || b == 0) return 0;
    a = a < 0 ? -a : a;
    b = b < 0 ? -b : b;
    return a / gcd17(a, b) * b;
}

// 11. product — C++17+
template<typename... Args>
auto product(Args&&... args) {
    return (forward<Args>(args) * ...);
}

// 12. gcd — C++17+
template<typename... Args>
auto gcd(Args&&... args) {
    static_assert(sizeof...(Args) >= 1, "At least one argument required");
    return (gcd17(static_cast<int64_t>(abs(forward<Args>(args))), ...));
}

// 13. lcm — C++17+
template<typename... Args>
auto lcm(Args&&... args) {
    static_assert(sizeof...(Args) >= 1, "At least one argument required");
    return (lcm17(static_cast<int64_t>(abs(forward<Args>(args))), ...));
}

// 27. compileTimeFactorial — C++17+
template<unsigned N>
constexpr uint64_t factorial17 = N <= 1 ? 1 : N * factorial17<N - 1>;

template<int... Values>
constexpr auto compileTimeFactorial() {
    static_assert(sizeof...(Values) == 1, "Exactly one compile-time integer required");
    constexpr int n = (Values + ...);
    static_assert(n >= 0, "Factorial of negative number is not defined");
    return factorial17<static_cast<unsigned>(n)>;
}
