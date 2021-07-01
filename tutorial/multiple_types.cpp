#include<iostream>
#include<string>
#include<variant>
#include<fstream>

std::variant<std::string, int> ReadFile(const std::string& filepath) {
    std::ifstream stream(filepath);
    if (stream) {
        std::string value;
        stream.close();
        return value;
    }
    return -1;
}

int main() {
    std::variant<std::string, int> data;
    std::cout << sizeof(int) << "\n";
    std::cout << sizeof(std::string) << "\n";
    std::cout << sizeof(data) << "\n";
    data = "aksjhajhsf";
    std::cout << std::get<std::string>(data) << "\n";
    data = 2;
    std::cout << data.index() << "\n"; // zwraca index typu którym aktualnie jest zmienna (typy są mapowane więc w naszym przypadku std::string będzie miało index 0 a int index 1)
    if (auto* value = std::get_if<std::string>(&data)) { // jeżeli typem jest string zwróci nam adres pamięci zmiennej a jeśli nie to zwraca nullptr
        std::string& v = *value;
    }
    else {
        std::cout << "To nie string!\n";
    }
    std::cout << std::get<int>(data) << "\n";
    auto g = ReadFile("dataa.txt");
    if (auto* value = std::get_if<std::string>(&g)) {
        std::string& s = *value;
        std::cout << "Plik zostal otwarty poprawnie!\n";
    }
    else {
        std::cout << "Plik nie mogl zostac otwarty\n";
        std::cout << *std::get_if<int>(&g) << "\n";
    }
    return 0;
}