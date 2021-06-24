#include<iostream>
#include<string>

class Entity {
    private:
        std::string name;
        mutable int debug_count = 0;
    public: 
        const std::string& GetName() const {
            debug_count++;
            return name;
        }
        void SetName(const std::string& n_Name) {
            name = n_Name;
        }
};

int main() {
    const Entity e;
    e.GetName();
    int x = 5;
    auto f = [=]() mutable { // można dać też x przez samą wartość oraz przekazać wszystkie rzeczy używając "&" lub "="
        x++;
        std::cout << x << std::endl;
    };
    // funkcja którą można szybko przyporządkować do jakiejś zmiennej (tutaj chyba f)
    f();
    std::cout << x << std::endl;
    return 0;
}