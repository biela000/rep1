#include<iostream>
#include<string>
#include<memory>

using String = std::string;

// unique_ptr - basically scope pointer nie da się ich kopiować bo jak zrobimy jego kopię to kiedy pamięć zostanie usunięta jego kopia nie będzie miała się do czego odnieść (cały pointer po prostu jest na stacku)
// shared_ptr - basically usuwa się kiedy wszystkie shared_pointery wskazujące na ten sam blok pamięci umierają (skończy się scope w którym są)
// weak_ptr - basically jest shared pointerem który nie liczy się do liczby referencji która jeśli jest równa zero to powoduje znisczenie shared pointera

struct Entity {
    Entity() {
        std::cout << "Stworzono obiekt!" << std::endl;
    }
    ~Entity() {
        std::cout << "Usunieto obiekt!" << std::endl;
    }
    void Print() {
        std::cout << "brrr" << std::endl;
    }
};

int main() { 
    {
        std::weak_ptr<Entity> entity;
        {
            //std::unique_ptr<Entity> e(new Entity()); // konstruktor jest zrobiony z użyciem "explicit" więc trzeba to tak zrobić nie można "std::unique_ptr<Entity> e = new Entity()"
            std::unique_ptr<Entity> e = std::make_unique<Entity>(); // lepiej używać tego niż tamtego wyżej ponieważ daje to większe bezpieczeństwo jeśli chodzi o wyjątki
            e->Print();
            std::shared_ptr<Entity> e0 = std::make_shared<Entity>(); // tutaj lepiej używać tego ponieważ shared pointery muszą jeszcze zaalokować jeszcze swój control blok a to sprawia że robią to wszystko razem w przeciwnym wypadku wydajność byłaby znacznie gorsza
            entity = e0;
        }
    }
    return 0;
}