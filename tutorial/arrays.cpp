#include<iostream>
#include<array>

class Example {
    public:
        int example[5];
        int count = sizeof(example) /*rozmiar tablicy w bajtach*/ / sizeof(int) /*rozmiar typu tablicy*/;
        Example() {
            for (int i = 0; i < 5; ++i) {
                example[i] = 5;
            }
        }
};

//tablica "example" będzie znajdowała się pod adresem obiektu Example
//sprawdzenie wielkości można zrobić tylko w ten sposób zaalokowanej tablicy ponieważ w przypadku dynamicznego alokowania dostaniemy rozmiar pointera do pierwszego elementu tablicy (w tym przypadku int - 4 bajty)
//nie powinno się jednak w ten sposób działać na wielkości bo na przykład jeśli będziemy chcieli przekazać tablicę jako int pointer to dostaniemy znowu rozmiar 4 bajty zamiast właściwej wielkości

class Example2 {
    public:
        int* example2 = new int[5];
        Example2() {
            for (int i = 0; i < 5; ++i) {
                example2[i] = 5;
            }
        }
};

//tablica "example2" będzie znajdowała się pod innym adresem niż obiekt Example2

int main() {
    int arr[5];
    int* ptr = arr;
    arr[0] = 5;
    *ptr = 6;
    arr[4] = 29;
    *(ptr + 4) = 30;
    std::cout << arr[0] << std::endl;
    std::cout << arr << std::endl;
    std::cout << *(ptr + 4) << std::endl;
    int* tab = new int[5];
    delete[] tab;
    std::array<int, 5> arr2; //tutaj możemy używać arr2.size() (te struktury są podobno szybsze niż normalne tablice)
    return 0;
}

//wszystko co zostanie alokowane używając słowa "new" będzie istniało dopóki nie zostanie usunięte przez użytkownika
//żeby zwrócić tablicę w funkcji musi ona być wcześniej zadeklarowana słowem "new"