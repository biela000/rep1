#include<iostream>
#include<string>
#define PR_DEBUG 1
#define PR_RELEASE 0
#define WAIT std::cin.get() // zły przykład makra
// #define LOG(x) // to makro zostanie zastąpione w kodzie pustym miejscem
#if PR_DEBUG == 1
#define LOG(x) std::cout << x << std::endl // już lepszy
#elif defined(PR_RELEASE) && PR_RELEASE == 1
#define LOG(x)
#endif
/*
#define MAIN int main() \
{\
    std::cin.get();\
    return 0;\
}
*/
int main() {
    LOG("Hello");
    WAIT;
    return 0;
}