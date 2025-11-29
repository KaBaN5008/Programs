using namespace std;

#include <utility>
#include <type_traits>
#include <cstdlib>
#include <cstdint>

// Вспомогательная функция НОД (Евклид)
int64_t gcd_impl(int64_t a, int64_t b) {
    a = a < 0 ? -a : a;
    b = b < 0 ? -b : b;
    while (b != 0) {
        int64_t t = b;
        b = a % b;
        a = t;
    }
    return a;
}

// Вспомогательная функция НОК
int64_t lcm_impl(int64_t a, int64_t b) {
    if (a == 0 || b == 0) return 0;
    return a / gcd_impl(a, b) * b;
}

// 11. product — C++11
template<typename T>
auto product(T&& t) {
    return forward<T>(t);
}

template<typename T, typename... Ts>
auto product(T&& t, Ts&&... ts) {
    return forward<T>(t) * product(forward<Ts>(ts)...);
}

// 12. gcd — C++11
template<typename T>
auto gcd(T&& t) {
    return static_cast<int64_t>(abs(forward<T>(t)));
}

template<typename T, typename... Ts>
auto gcd(T&& t, Ts&&... ts) {
    return gcd_impl(abs(forward<T>(t)), gcd(forward<Ts>(ts)...));
}

// 13. lcm — C++11
template<typename T>
auto lcm(T&& t) {
    return static_cast<int64_t>(abs(forward<T>(t)));
}

template<typename T, typename... Ts>
auto lcm(T&& t, Ts&&... ts) {
    return lcm_impl(abs(forward<T>(t)), lcm(forward<Ts>(ts)...));
}

// 27. compileTimeFactorial — C++11
template<int N, typename = typename enable_if<N >= 0>::type>
struct Factorial {
    static constexpr uint64_t value = N * Factorial<N - 1>::value;
};

template<>
struct Factorial<0> {
    static constexpr uint64_t value = 1;
};

template<int... Values>
constexpr auto compileTimeFactorial() {
    static_assert(sizeof...(Values) == 1, "Exactly one integer required");
    return Factorial<Values...>::value;
}
