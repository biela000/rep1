#include<iostream>
#include<string>
#include<any> // dla małych rozmiarów union a dla większych pamięć zostanie zaalokowanana dynamicznie (void*) (na heapie)
#include<variant> // type-safe union (będzie szybsze niż std::any ponieważ nie występuje tu alokacja pamięci na heapie)

struct Struct {
    std::string s0, s1;
};

int main() {
    std::any data;
    data = 2;
    data = "asklhfvakdlvj";
    data = std::string("sfgiuasfh");
    std::string& value = std::any_cast<std::string&>(data); // jeśli data nie będzie stringiem to dostaniemy wyjątek
    std::variant<int, std::string> data0;
    data0 = 2;
    data0 = "oialhvcadhv";
    std::string value0 = std::get<std::string>(data0); // to zadziała ponieważ napisaliśmy że typ to musi być int albo std::string jeśli byśmy to próbowali zrobić z std::any to nie zadziała ponieważ nie zajdzie implicit conversion i data0 będzie dalej const char*
    std::cout << sizeof(data0) << "\n";
    std::cout << sizeof(data) << "\n";
    std::any a;
    a = Struct(); // alokuje na heapie ponieważ Struct zajmuje więcej niż 32 bajty
    Struct& s = std::any_cast<Struct&>(a);
    return 0;
}

// std::any jest praktycznie bezużyteczne (lepiej używać std::variant)