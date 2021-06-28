#include<iostream>
#include<string>
#include<array>

using String = std::string;

template<const size_t S>
void PrintArray(const std::array<int, S>& arr) {
    for (int i = 0; i < arr.size(); ++i) {
        std::cout << arr[i] << " ";
    }
}

int main() {
    std::array<int, 50> array{};
    PrintArray(array);
    return 0;
}