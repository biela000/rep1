#include<iostream>
#include<string>

uint32_t s_AllocCount = 0;

void* operator new(size_t size) {
    s_AllocCount++;
    std::cout << "Allocating: " << size << " bytes!\n";
    return malloc(size);
}

#define STRING_VIEW 1
#if STRING_VIEW == 1
void PrintString(std::string_view s) {
    std::cout << s << std::endl;
}
#else
void PrintString(std::string_view s) {
    std::cout << s << std::endl;
}
#endif

int main() {
    const char* string = "ahkjs fvfhakv";
    PrintString(string);
    #if 0
    std::string first = string.substr(0, 5);
    std::string second = string.substr(6, 7);
    #else
    std::string_view first(string, 3); // std::string_view to jest basically pointer do części istniejącego już w pamięci stringa (substringa stringa)
    std::string_view second(string + 4, 9);
    #endif
    std::cout << s_AllocCount << std::endl;
    return 0;
}

// aktualnie raczej nie ma sensu używać std::string_view (i zamieniać stringi na const char*) ponieważ wszystkie alokacje są chyba na stacku więc problem z wydajnością nie jest aż tak wielki (aczkolwiek zawsze można używać std::string_view żeby co najwyżej przyspieszyć odrobinkę procesy)