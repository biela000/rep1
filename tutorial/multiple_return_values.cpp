#include<iostream>
#include<string>
#include<array>
#include<vector>
#include<tuple>

struct FullName {
    std::string f_name;
    std::string l_name;
};

// pierwszym sposobem jest przekazanie kilku referncji (lub wskaźników co pozwala na przekazanie nullptr jako argument a potem sprawdzenie w funkcji czy wskaźnik przchowuje jakiś adres pamięci "if(nazwa_wskaźnika)") jako argumentów i potem zmienieniu ich wartości w funkcji - jedna z najbardziej optymalnych metod do robienia takich rzeczy
void GetFullName(std::string& f_name, std::string& l_name) {
    f_name = "imie";
    l_name = "nazwisko";
}
// drugim sposobem jest zwracanie wskaźnika do tablicy - ten sposób jest dość niekomfortowy ponieważ w naszym kodzie będziemy się cały czas musieli odnosić z użyciem tablicy a sama tablica jest alokowana na heapie co sprawia że jest mnie wydajna poza tym nie znamy jej rozmiaru
std::string* GetFullNameArr(void) {
    /*std::string* arr = new std::string[2];
    arr[0] = "imie";
    arr[1] = "nazwisko";
    return arr;*/
    return new std::string[2] {"imie", "nazwisko"};
}
// używając biblioteki array możemy uniknąć alokowania na heapie oraz możemy mieć dostęp do rozmiaru tablicy
std::array<std::string, 2> GetFullNameStdArr(void) {
    return std::array<std::string, 2> {"imie", "nazwisko"};
}
// możemy też zwrócić tablicę przydzielaną dynamicznie
std::vector<std::string> GetFullNameVec(void) {
    /*std::vector<std::string> v;
    v.reserve(2);
    v.emplace_back("imie");
    v.emplace_back("nazwisko");*/ // można to niby troszkę zoptymalizować
    return std::vector<std::string> {"imie", "nazwisko"};
}
// możemy też zwrócić typ tuple który pozwala nam na przechowywanie x zmiennych o możliwie różnych typach - problemem tutaj jest to że jeśli chcemy uzyskać dostęp do elementów zwróconego tuple'a w kodzie musimy użyć "std::get<index>(tuple_name)"
std::tuple<std::string, std::string> GetFullNameTup(void) {
    return std::make_pair("imie", "nazwisko");
}
// możemy też użyć "std::pair" która pozwala nam na przechowanie dwóch zmiennych nie zależnie od ich typów - jeśli chcemy uzyskać dostęp do elementów pary możemy użyć "std::get" lub "pair.first, pair.second"
std::pair<std::string, std::string> GetFullNamePair(void) {
    return std::make_pair("imie", "nazwisko");
}
// jednym z lepszych sposobów jest jednak stworzenie swojego własnego structa który będzie zawierał potrzebną ilość zmiennych ponieważ wtedy możemy się odnosić do zmiennych używając naszych nazw bez żadnego zbędnego kopiowania (praktycznie możemy zwrócić tuple'a ale z naszymi własnymi nazwami)
FullName GetFullNameStruct(void) {
    return {"imie", "nazwisko"};
}