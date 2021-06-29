#include<iostream>
#include<string>
#include<algorithm>

namespace apple {
    inline namespace functions { // jeśli nested namespace jest inline to jej członkowie są traktowani jakby byli członkami tej wyższej namespace
        void print(const std::string& string) {
        std::cout << string << std::endl;
        }
    }
}

namespace orange::functions {
//    namespace functions {
        void print(std::string string) {
            std::reverse(string.begin(), string.end());
            std::cout << string << std::endl;
        }
//    }
}

int main() {
    using namespace apple; // "using apple::print;" pozwala nam na użycie tylko jednej funkcji
    namespace o = orange::functions;
    o::print("Hello!");
    print("Bye!");
    return 0;
}

// basically namespaces są po to aby uniknąć problemów z nazywaniem
// w C namespaces nie istnieją przez co każda funkcja z customowej biblioteki musi mieć w swojej nazwie coś związanego z biblioteką ponieważ może być więcej funkcji o podobnej nazwie
// można zagnieżdżać namespaces