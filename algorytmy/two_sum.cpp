#include<iostream>
#include<vector>

std::pair<size_t, size_t> two_sum(const std::vector<int>& numbers, int target) {
    for (int i = 0; i < numbers.size() - 1; ++i) {
        for (int o = i + 1; o < numbers.size(); ++o) {
            if (numbers[i] + numbers[o] == target) { return std::make_pair(i, o); }
        }
    }
}

int main() {
    auto[first, second] = two_sum(std::vector<int>{ 1, 2, 3 }, 3);
    std::cout << first << " " << second << std::endl;
    return 0;
}