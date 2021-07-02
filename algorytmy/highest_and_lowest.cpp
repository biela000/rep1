#include<iostream>
#include<string>

std::string highAndLow(const std::string& numbers) {
    int max = INT32_MIN;
    int min = INT32_MAX;
    std::string numbers0 = numbers + ' ';
    while (!numbers0.empty()) {
        if (max < atoi(numbers0.substr(0, numbers0.find(' ')).c_str())) { max = atoi(numbers0.substr(0, numbers0.find(' ')).c_str()); }
        if (min > atoi(numbers0.substr(0, numbers0.find(' ')).c_str())) { min = atoi(numbers0.substr(0, numbers0.find(' ')).c_str()); }
        numbers0.erase(0, numbers0.find(' ') + 1);
    }
    return std::to_string(max) + ' ' + std::to_string(min);
}

int main() {
    std::cout << highAndLow("4 5 29 54 4 0 -214 542 -64 1 -3 6 -6") << std::endl;
    return 0;
}