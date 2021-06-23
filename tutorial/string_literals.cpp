#include<iostream>
#include<string>

int main() {
    using namespace std::string_literals;
    const char* example = "example"; // u8"example" UTF-8 1 byte
    const wchar_t* example1 = L"example"; // 2 bytes on windows, 4 bytes on linux/mac
    const char16_t* example2 = u"example"; //UTF-16 2 bytes
    const char32_t* example3 = U"example"; //UTF-32 4 bytes
    std::string example0 = "example"s + "bigg"; //działa
    //std::string notworking = "example" + "bigg"; //nie działa
    const char* another = R"(Line1
    Line2
    Line3
    Line4)";
    //jest wrażliwe na entery i inne odstępy w kodzie
    std::cout << another << std::endl;
    return 0;
}