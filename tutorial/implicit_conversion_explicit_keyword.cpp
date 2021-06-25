#include<iostream>
#include<string>

using String = std::string;

class Entity {
    private:
        String name;
        int age;
    public:
        Entity(const String& n_Name)
            : name(n_Name), age(-1)
            {}
        explicit Entity(const int& n_Age) //implicit conversion disabled
            : name("Unknown"), age(n_Age)
            {}
        const String& GetName() const {
            return name;
        }
        const int& GetAge() const {
            return age;
        }
};

void PrintEntity(const Entity& entity) {
    std::cout << entity.GetName() << " " << entity.GetAge() << std::endl;
}

int main() {
    Entity a = (String)"asuokasfgh";
    Entity b = (Entity)129784; // teraz trzeba napisać "(Entity)" przed zmienną lub po prostu używać normalnego konstruktora
    PrintEntity(a);
    PrintEntity(b);
    PrintEntity((Entity)428769);
    PrintEntity((String)"nice"); //można też "(Entity)"
    return 0;
}