#include<iostream>
#include<string> 

struct Vector2 {
    float x, y;
};

struct Vector4 {
    union {
        struct {
            float x, y, z, w;
        };
        struct {
            Vector2 a, b;
        };
    };
    /*Vector2& GetA() const {
        return *(Vector2*)&x;
    }*/
};

void PrintVector2(const Vector2& vector) {
    std::cout << vector.x << " " << vector.y << std::endl;
}

int main() {
    struct Union {
        union {
            float a;
            int b;
        };
    };
    Union u;
    u.a = 2.0f;
    std::cout << u.a << " " << u.b << std::endl; // u.b będzie tak jakby pamięcią zawierającą float'a przekonwertowaną jakby zawierała inta
    Vector4 vector = { 1, 2, 3, 4 };
    PrintVector2(vector.a);
    PrintVector2(vector.b);
    // dzięki temu że unions że structy w union okupują dokładnie tą samą pamięć możemy odwołać się do niej na dwa sposoby i modyfikować ją również na dwa sposoby
    // dzięki temu że zarówno structy jak i union w Vector4 są anonimowe możliwe jest dla nas niezmienianie nazewnictwa
    return 0;
}

// unions po to po prostu structy/klasy które mogą mieć tylko jedną zmienną jakby (kiedy zdefiniujemy na przykład cztery floaty to obiekt dalej będzie miał 4 bajty a odwołując się do byle jakiego float'a odwołujemy się do tego samego adresu pamięci zmieniając wartość wszystkich)
// unions przydają się do type punning'u
// unions zazwyczaj są anonimowe i nie przechowują żadnych metod mimo że mogą to robić