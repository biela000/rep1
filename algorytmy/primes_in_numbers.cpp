#include<iostream>
#include<string>
#include<vector>
#include<cmath>
#include<algorithm>
#include<cstring>

std::vector<int> GenPrime(const int& n) {
    int arr[n + 1];
    memset(arr, 0, n + 1);
    for (int i = 2; i <= std::sqrt(n); ++i) {
        for (int o = 2; i * o < n + 1; ++o) { arr[i * o] = 1; }
        for (int o = i; arr[o] != 0 && o < n + 1; ++o) { i = o; }       
    }
    std::vector<int> v;
    for (int i = 2; i < n + 1; ++i) {
        if (arr[i] != 1) { 
            v.reserve(1);
            v.emplace_back(i);
        }
    }
    return v;
}

class PrimeDecomp {
public:
    PrimeDecomp(const PrimeDecomp&) = delete;
    static PrimeDecomp& Get() {
        static PrimeDecomp pd;
        return pd;
    }
    static std::string factors(int lst) {
        return Get().Ifactors(lst);
    }
private:
    std::string Ifactors(int lst) {
        std::vector<int> numbers;
        std::vector<int> v = GenPrime(lst);
        while (lst > 1) {
            for (const int& num : v) {
                if (lst % num == 0) { 
                    lst /= num;
                    numbers.reserve(1);
                    numbers.emplace_back(num);
                    break;
                }
            }
        }
        std::sort(numbers.begin(), numbers.end());
        std::string res = "";
        for (int i = 0; i < numbers.size();) {
            int tmp = std::count(numbers.begin(), numbers.end(), numbers[i]);
            if (tmp > 1) {
                res += '(' + std::to_string(numbers[i]) + "**" + std::to_string(tmp) + ')';
            }
            else {
                res += '(' + std::to_string(numbers[i]) + ')';
            }
            i += tmp;
        }
        return res;
    }
    PrimeDecomp() {}
};

int main() {
    std::cout << PrimeDecomp::factors(7919) << std::endl;
    return 0;
}
