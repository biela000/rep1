#include<iostream>

int digital_root(int n) {
    int sum = 0;
    while (n > 0) {
        sum += n % 10;
        n /= 10;
    }
    if (sum < 10) {
        return sum;
    }
    return digital_root(sum);
}

int main() {
    int n;
    std::cin >> n;
    std::cout << digital_root(n) << std::endl;
    return 0;
}