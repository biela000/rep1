#include<iostream>
#include<string>
#include<vector>
#include<functional>
#include<algorithm>

void ForEach(const std::vector<int>& v, const std::function<void(int)>& f) {
    for (const int& value : v) {
        f(value);
    }
}

int main() {
    std::vector<int> values = {1, 2, 3, 4, 5};
    //ForEach(values, [](int value){std::cout << "Value: " << value << std::endl;});
    auto it = std::find_if(values.begin(), values.end(), [](int value){return value > 2;});
    std::cout << *it << std::endl;
    int a = 5;
    auto lambda = [=](int value) mutable {
        a = 5; // jeśli nie ma mutable w nagłówku to error
        std::cout << "Value: " << value << " " << a << std::endl;
    };
    ForEach(values, lambda);
    return 0;
}

// lambdy to sposób w który możemy stworzyć anonimową funkcję (praktycznie tworzymy funkcję bez tworzenia funkcji) stosujemy to kiedy chcemy przechować nasz kawałek kodu raczej w zmiennej niż normalnej funkcji ponieważ jest na tyle prosty lub nieważny
// jeśli mamy jakiś function pointer to możemy użyć lambd