#include<iostream>
#include<vector>
typedef unsigned long long ull;

ull Fib(int n) {
    if (n == 0) { return 0; }
    if (n == 1) { return 1; }
    return Fib(n - 1) + Fib(n - 2);
}

class ProdFib {
public:
    ProdFib(const ProdFib&) = delete;
    static ProdFib& Get() {
        static ProdFib pf;
        return pf;
    }
    static std::vector<ull> productFib(const ull& prod) {
        return Get().IproductFib(prod);
    }
private:
    ProdFib() {}
    std::vector<ull> IproductFib(ull prod) {
        for (int i = 0;; ++i) {
            if (Fib(i) * Fib(i + 1) == prod) {
                return std::vector<ull>{ Fib(i), Fib(i + 1), 1 };
            }
            else if (Fib(i) * Fib(i + 1) > prod) {
                return std::vector<ull>{ Fib(i), Fib(i + 1), 0 };
            }
        }
    }
};

std::ostream& operator<<(std::ostream& stream, const std::vector<ull>& v) {
    for (const ull& num : v) {
        stream << num << " ";
    }
    return stream;
}

int main() {
    std::cout << ProdFib::productFib(800) << std::endl; 
    return 0;
}
