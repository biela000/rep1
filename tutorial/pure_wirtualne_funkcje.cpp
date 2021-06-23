#include<iostream>
#include<string>

class Printable {
    public:
        virtual std::string GetClassName() = 0;
};

class Entity : public Printable {
    public:
        virtual std::string GetName() { return "entity"; };
        virtual std::string GetClassName() override { return "Entity"; }
};

class Player : public Entity {
    private:
        std::string m_Name;
    public:
        Player(const std::string& name)
            : m_Name(name) {}
        std::string GetName() override { return m_Name; }
        virtual std::string GetClassName() override { return "Player"; }
};

void PrintName(Entity* entity) {
    std::cout << entity->GetName() << std::endl;
}

void Print(Printable* obj) {
    std::cout << obj->GetClassName() << std::endl;
}

int main() {
    Entity* e = new Entity();
    Print(e);
    Player* p = new Player("bih");
    Print(p);
    Entity* entity = p;
    Print(entity);
    return 0;
}

//żeby metoda GetName() działała musi być zaimplementowana w klasach dziedziczących (bo w klasie głównej jest "= 0")
//jeśli chcemy użyć klas dziedziczących po klasie z interfejsem to musimy w nich zawrzeć override'y interfejsu