#include<iostream>
#include<string>
#include<array>
#include<algorithm>
#include<functional>

int main() {
    std::array<int, 5> arr = { 3, 5, 1, 4, 2 };
    std::sort(arr.begin(), arr.end(), [](const int& a, const int& b){ 
        if (a == 1) {
            return false;
        }
        if (b == 1) {
            return true;
        }
        return a < b; //jeśli a > b to idzie na początek tablicy
    }); // jako trzeci argument można tu też użyć "std::greater<int>()" z biblioteki <functional>
    for (int& value : arr) {
        std::cout << value << std::endl;
    }
    return 0;
}
