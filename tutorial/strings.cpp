#include<iostream>
#include<string>

void PrintString(const std::string& string) {
    std::cout << string << std::endl;
}

int main() {
    const char* name = "Unknown";
    std::cout << name << std::endl;
    char name2[8] = {'U', 'n', 'k', 'n', 'o', 'w', 'n', '\0'};
    std::cout << name2 << std::endl;
    std::string example = "Example";
    bool contains = example.find('m') != std::string::npos;
    std::cout << contains << std::endl;
    PrintString(example);
    return 0;
}