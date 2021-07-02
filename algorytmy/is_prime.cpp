#include<iostream>

bool isPrime(int num) {
    if (num < 2) return false;
    for (int i = 2; i * i <= num; ++i) { if (num % i == 0) return false; }
    return true;
}

int main() {
    std::cout << isPrime(512) << std::endl;
    return 0;
}