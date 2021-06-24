#include<iostream>

class Entity {
    private:
        int* m_X, m_Y; // tylko m_X jest wskaźnikiem (żeby m_Y było wskaźnikiem musi być gwiazdka przed nazwą (*m_Y))
        mutable int var;
    public:
        const int* const GetX() const {
            return m_X;
        }
        int GetY() const {
            var = 2; // dzięki mutable możemy zmieniać wartości zmiennych w const metodach
            return m_Y;
        }
        void Set(int x, int y) {
            *m_X = x;
            m_Y = y;
        }
};

void PrintEntity(const Entity& e) {
    std::cout << e.GetX() << ", " << e.GetY() << std::endl;
}
// jeśli nie byłoby "const" przy funkcjach get w klasie to nie ma gwarancji że nie będziemy próbowali zmieniać stałej referencji

int main() {
    Entity e;
    const int a = 5;
    int* ptr = new int;
    *ptr = 2;
    ptr = (int*)&a; //w ten sposób można obejść consta
    std::cout << *ptr << std::endl;
    *ptr += 5;
    std::cout << *ptr << std::endl;
    std::cout << a << std::endl;
    std::cout << ptr << std::endl;
    std::cout << &a << std::endl;
    const int* b = new int; // nie można robić rzeczy typu "*b = 5;"
    b = &a;
    std::cout << *b << std::endl;
    std::cout << a << std::endl;
    int* const c = new int; // nie można robić rzeczy typu "c = &a;"
    //int const* == const int*
    const int* const d = new int; // połączenie dwóch poprzednich
    return 0;
}