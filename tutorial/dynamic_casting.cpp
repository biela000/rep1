#include<iostream>
#include<string>

class Entity {
    public:
        virtual void PrintName() {
            std::cout << "Name" << std::endl;
        }
};

class Player : public Entity {

};

class Enemy : public Entity {

};

int main() {
    Player* player = new Player(); // player
    Entity* entity = player; // implicit conversion, entity
    Entity* entity1 = new Enemy(); // entity
    Player* p = (Player*)entity1; // jeśli są jakieś funkcje wyłączne dla klasy Player to dostaniemy tutaj crasha ponieważ obiekt entity jest domyślnie Enemy
    Player* p1 = dynamic_cast<Player*>(entity1); // jeśli jest zrobione implicit conversion przy Entity do Playera lub jest to po prostu obiekt Player to cast zwróci adres pamięci wskaźnika Player do którego tutaj chcemy rzutować
    if (p1) {
        std::cout << "Mozna jak najpardziej" << std::endl;
    }
    else {
        std::cout << "Nie" << std::endl;
    }
    delete player, entity1;
    return 0;
}

// dynamic_cast<>() to bardziej funkcja niż normalny cast
// dynamic_cast jest wykorzystywany głównie do rzeczy które mają związek z dziedziczeniem
// dynamic_cast działa na podstawie runtime type information - jeśli to wyłaczymy to dynamic_cast będzie nam wyrzucał wyjątek (w większości przypadków)