#include<iostream>
#include<string>

using String = std::string;

template<typename T, int size>
class Array {
    private:
        T array[size];
    public:
        int GetSize() const {
            return size;
        }
};

template<typename T> // template'y są kompilowane dopiero w momencie kiedy są wywoływane (tak jakby compiler pisze za nas kod z odpowiednim typem) można napisać tutaj w nawiasach zarówno class jak i typename - niczym się to nie różni ale lepiej utrzymywać porządek w kodzie i używać w template'ach typename a definiując klasy class
void Print(T value) {
    std::cout << value << std::endl;
}

int main() {
    Print(5); // to jest tak jakby implicit conversion znowu bo można też napisać Print<int>(5);
    Array<int, 5> arr;
    std::cout << arr.GetSize() << std::endl;
    return 0;
}