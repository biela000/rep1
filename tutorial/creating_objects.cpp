#include<iostream>
#include<string>

using String = std::string;

class Entity {
    private:
        String name;
    public:
        Entity()
            : name("Unknown")
        {}
        Entity(const String& n_Name)
            : name(n_Name)
        {}
        const String& GetName() const {
            return name;
        }
};

int main() {
    // Na stacku
    Entity e; // Entity e("asifashjf") == Entity e = Entity("asifashjf")
    std::cout << e.GetName() << std::endl;
    // Na heapie
    Entity* entity = new Entity;
    std::cout << entity->GetName() << std::endl;
    delete entity;
    return 0;
}

// zmienne zadeklarowane na stacku zostają zniszczone po np. końcu funkcji w której zostały zadeklarowane ale kiedy tylko jesteśmy w stanie powinniśmy je tworzyć na stacku
// zmienne zadeklarowane na heapie zostają zniszczone kiedy użytkownik się na to zdecyduje
// na stacku są szybsze i na heapie musimy samodzielnie usunąć obiekty