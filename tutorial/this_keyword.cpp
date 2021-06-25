#include<iostream>
#include<string>

using String = std::string;

class Entity {
    public:
        int x, y;
        int GetX() const { // tutaj this jest typu "const Entity* const" poprzez słowo kluczowe "const" na końcu definicji metody
            return this->x;
        }
        int GetY() const {
            return this->y;
        }
        void PrintEntity() {
            std::cout << x << " " << y << std::endl;
        }
        Entity(int x, int y) {
            this->x = x; // == (*this).x = x;
            this->y = y;
            PrintEntity();
        }
};

int main() {
    Entity entity(10, 20); 
    return 0;
}