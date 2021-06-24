#include<iostream>

int main() {
    int a = 2;
    int* ptr = new int; // == int* ptr = (*int)malloc(sizeof(int)) (jak jakaś klasa to nie zostanie użyty żaden konstruktor)
    *ptr = 200000;
    std::cout << *ptr << std::endl;
    // możemy zrobić "int* a = new(x) int;" co sprawia że decydujemy o tym której dokładnie pamięci chcemy użyć (tak naprawdę to nie jest już alokowanie pamięci)
    delete ptr;
    return 0;
}