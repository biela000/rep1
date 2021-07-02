#include<iostream>
#include<string>
#include<cstdlib>

class Random {
public:
    Random(const Random&) = delete;
    int operator=(const int&) = delete; // (nie wiem czy tak się usuwa operator = ale no)
    static Random& Get() {
        static Random r_Instance; // jeśli umieścimy to tutaj zamiast w private to nie będziemy musieli deklarować singletona zawsze przed jego użyciem
        return r_Instance;
    }
    static int RandomGen(const std::pair<int, int>& range) { return Get().IRandomGen(range); } // "r_Instance.IRandomGen(range)" też by zadziałało
private:
    int IRandomGen(const std::pair<int, int>& range) {
        srand(time(NULL));
        auto[min, max] = range;
        return rand() % (max - min) + min + 1;
    }
    Random() {}
    float m_Member = 0.0f;
};

namespace RandomNamespace {
    static int RandomGen(const std::pair<int, int>& range) {
        srand(time(NULL));
        auto[min, max] = range;
        return rand() % (max - min) + min + 1;
    }
}

// między funkcyjnością namespace a singletona nie ma żadnej różnicy (trzymanie wszystkiego w klasie tylko bardziej porządkuje nasz kod i daje nam możliwość utworzenia zmiennej przechowującej instance klasy (np. "auto& ran = Random::Get();"))

int main() {
    std::cout << Random::RandomGen(std::make_pair(1, 100)) << std::endl;
    return 0;
}

// Random to klasa/struct która ma tylko jeden obiekt
// Randomy to sposób zorganizowania globalnych zmiennych oraz funkcji statycznych (jest trochę jak namespace)