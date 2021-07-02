#include<iostream>
#include<vector>
#include<string>

std::string odd_or_even(const std::vector<int>& arr) {
    int sum = 0;
    for (const int& arr_element : arr) { sum += arr_element; }
    return sum % 2 == 0 ? "even" : "odd";
}

int main() {
    std::cout << odd_or_even(std::vector<int>{ 1, 2, 3 }) << std::endl;
    return 0;
}