#include<iostream>
#include<string>
#include<tuple>

struct Person {
    std::string name;
    int age;
};

std::tuple<std::string, int> CreatePerson() {
    return { "sjahfasvbav", 234 };
}

int main() {
    std::tuple<std::string, int> person = CreatePerson();
    std::string& name = std::get<0>(person);
    int& age = std::get<1>(person);
    std::string name0;
    int age0;
    std::tie(name0, age0) = CreatePerson();
    auto[name1, age1] = person; // tylko >=c++17 - structured bindings
    std::cout << name1 << " " << age1 << std::endl;
    return 0;
}