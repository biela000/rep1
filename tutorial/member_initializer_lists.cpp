#include<iostream>
#include<string>

class Example {
    public:
        Example() {
            std::cout << "Zrobione!" << std::endl;
        }
        Example(int x) {
            std::cout << "Stworzono ze zmienna x!" << std::endl;
        }
};

class Entity {
    private:
        std::string name;
        int score;
        Example example;
    public:
        Entity() 
            : name("Unknown"), score(0), example(8) // najlepiej zawsze w takiej kolejności w jakiej zostały zadeklarowane wcześniej
            {}
        Entity(const std::string& n_Name) 
            : name(n_Name)
            {}
        const std::string GetName() const {
            return name;
        }
};
// lepiej używać tych rzeczy bo inaczej marnujemy wydajność trochę

int main() {
    Entity e;
    std::cout << e.GetName() << std::endl;
    Entity e0("kashfja");
    std::cout << e0.GetName() << std::endl;
    return 0;
}