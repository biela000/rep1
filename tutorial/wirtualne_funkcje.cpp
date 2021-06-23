#include<iostream>
#include<string>

class Entity {
    public:
        virtual std::string GetName() { return "Entity"; }
};

class Player : public Entity {
    private:
        std::string m_Name;
    public:
        Player(const std::string& name)
            : m_Name(name) {}
        std::string GetName() override { return m_Name; }
};

void PrintName(Entity* entity) {
    std::cout << entity->GetName() << std::endl;
}

int main() {
    Entity* e = new Entity();
    PrintName(e);
    Player* p = new Player("bih");
    PrintName(p);
    Entity* entity = p;
    PrintName(entity);
    return 0;
}

//kiedy metoda ma dopisane słowo "virtual" to znaczy że zostanie stworzona v-tabela w które umieszczone będą wszystkie takie same metody z innymi obiektami dziedziczącymi bo klasie z funkcją wirtualną
//słowo "override" nie jest wymagane ale warto go używać dla czytelności kodu i bezpieczeństwa