#include<iostream>
#include<string>

class Base {
    public:
        Base() {
            std::cout << "Base Stworzono!\n";
        }
        virtual ~Base() {
            std::cout << "Base Zniszczono\n";
        }
};

class Derived : public Base {
    private:
        int* d_Arr;
    public:
        Derived()
            : d_Arr(new int[5])
            {
                std::cout << "Derived Stworzono!\n";
            }
        ~Derived() {
            std::cout << "Derived Zniszczono\n";
            delete[] d_Arr;
        }
};

int main() {
    Base* b = new Base();
    delete b;
    std::cout << "---------------------------------------\n";
    Derived* d = new Derived();
    delete d;
    std::cout << "---------------------------------------\n";
    Base* poly = new Derived();
    delete poly;
    return 0;
}

// używając wirtualnych destruktorów nie zmieniamy tego którego oznaczyliśmy jako wirtualny tylko dodajemy kolejnego destruktora
// jeżeli piszemy klasę która może mieć kiedyś klasy dziedziczące to powinniśmy oznaczać destruktora jako wirtualny