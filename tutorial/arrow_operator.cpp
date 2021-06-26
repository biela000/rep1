#include<iostream>
#include<string>
#include<memory>

using String = std::string;

class Entity {
    private:
        int x;
    public:
        Entity() {
            std::cout << "Stworzono" << std::endl;
        }
        Entity(int x)
            : x(x)
            {
                std::cout << "Stworzono" << std::endl;
            }
        ~Entity() {
            std::cout << "Zniszczono" << std::endl;
        }
        void Print() const {
            std::cout << "Hello!" << std::endl;
        }
        const int& GetX() const {
            return x;
        }
};

class ScopedPtr {
    private:
        Entity* ptr;
    public:
        ScopedPtr(Entity* e)
            : ptr(e)
            {}
        ~ScopedPtr() {
            delete ptr;
        }
        Entity* operator->() {
            return ptr;
        }
        const Entity* operator->() const {
            return ptr;
        }
};

struct Vector3 {
    float x, y, z;
};

int main() {
    std::unique_ptr<Entity> e = std::make_unique<Entity>();
    e->Print(); // == (*e).Print();
    std::cout << sizeof(e) << std::endl;
    std::unique_ptr<Entity> e0 = std::make_unique<Entity>(238);
    std::cout << e0->GetX() << std::endl;
    const ScopedPtr e1 = new Entity;
    e1->Print();
    std::cout << &((Vector3*)nullptr)->z << std::endl; // sprawdzanie gdzie w pamięci znajduje się z
    return 0;
}