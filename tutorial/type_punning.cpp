#include<iostream>
#include<string>

struct Entity {
    int x, y;
    int* GetPosition() {
        return &x;
    }
};

int main() {
    int a = 5;
    double value = a; // implicit conversion
    std::cout << value << std::endl;
    int b = 50;
    double ptr = *(double*)&b; // bierzemy o cztery bajty więcej (nie nasza pamięć) od adresu tego inta co może nawet spowodować crasha ponieważ na tej pamięci może znajdować się coś innego (oczywiście nie nadpisujemy tej pamięci ponieważ zapisaliśmy jej wartość w innej zmiennej ale still)
    std::cout << ptr << std::endl;
    Entity e = { 5, 8 };
    int* position = (int*)&e; // to jest tak jakby array ponieważ wskazujemy na adres pierwszej zmiennej w strutcie przez co możemy odwołać się do innych intów używając kwadratowych nawiasów
    position[0] = 7;
    position[1] = 12;
    std::cout << e.x << " " << e.y << std::endl;
    std::cout << position[0] << " " << position[1] << std::endl;
    int y = *((int*)((char*)&e + 4)); // char jest jednobajtowy więc dodając cztery przechodzimy do początku następnego inta którego potem rzutując na int pointer bierzemy całego do zmiennej y dereferencując go (możnaby tu też teoretycznie ominąć rzutowanie na chara i zrobić "*((int*)(&e) + 1)";)
    std::cout << y << std::endl;
    int* arr = e.GetPosition();
    arr[0] = 5;
    arr[1] = 2;
    std::cout << arr[0] << " " << arr[1] << std::endl;
    return 0;
}