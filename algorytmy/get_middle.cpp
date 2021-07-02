#include<iostream>
#include<string>

std::string get_middle(const std::string& s) {
    std::string res;
    if (!(s.size() % 2)) { res += s[s.size() / 2 - 1]; }
    res += s[s.size() / 2];
    return res;
}

int main() {
    std::cout << get_middle("test") << std::endl;
    return 0;
}