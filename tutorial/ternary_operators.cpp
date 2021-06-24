#include<iostream>
#include<string>

int s_Level = 5;
int s_Speed = 2;

int main() {
    s_Speed = s_Level > 5 ? s_Level > 10 ? 15 : 10 : 5;
    std::cout << s_Speed << std::endl;
    std::string rank = s_Level > 10 ? "Master" : "Beginner";
    std::cout << rank << std::endl;
    return 0;
}