#include<iostream>
#include<string>
#define nl "\n"

class Base {
    public:
        Base() {
            std::cout << "Stworzono Base!" << nl;
        }
        virtual ~Base() {
            std::cout << "Zniszczono Base!" << nl;
        }
};

class Derived : public Base {
    public:
        Derived() {
            std::cout << "Stworzono Derived!" << nl;
        }
        ~Derived() {
            std::cout << "Znisczono Derived!" << nl;
        }
};

class AnotherClass : public Base {
    AnotherClass() {
        std::cout << "Stworzono AnotherClass!" << nl;
    }
    ~AnotherClass() {
        std::cout << "Zniszczono AnotherClass!" << nl;
    }
};

struct Vector4 {
    float x, y, z, w;
};

int main() {
    double b = 5.3;
    int a = (int)b + 2.3; // C style casting
    std::cout << a << nl;
    double s = static_cast<int>(b) + 5.3; // C++ style casting
    std::cout << s << nl;
    Derived* derived = new Derived();
    Base* base = derived;
    AnotherClass* ac = dynamic_cast<AnotherClass*>(base);
    if (!ac) {
        std::cout << "To nie ta klasa!" << nl;
    }
    else {
        std::cout << "To ta klasa!" << nl;
    }
    delete derived;
    Vector4 v = { 1, 2, 3, 4 };
    float* arr = reinterpret_cast<float*>(&v);
    std::cout << arr[2] << nl;
    float r = *(reinterpret_cast<float*>(reinterpret_cast<char*>(&v) + 4));
    std::cout << r << nl;
    return 0;
}

// C style casting może zrobić wszystko co robi C++ style casting
// reinterpret_cast() robi tak jakby type punning (zreinterpretuj ten adres pamięci jako)
// const_cast() dodaje/usuwa (głównie usuwa) tylko const
// C++ casting sprawia że nasz kod jest bardziej solidny
// dynamic_cast() pozwala nam na sprawdzenie czy casting jest legalny (jeśli nie to zwraca null)