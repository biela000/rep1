#include<iostream>
#include<string>
#include<vector>

void HelloWorld() {
    std::cout << "Hello World!" << std::endl;
}

void HelloWorldValue(int a) {
    std::cout << "Hello World! Value: " << a << std::endl;
}

void ForEach(const std::vector<int>& v, void(*f)(int)) {
    for (const int& value : v) {
        f(value);
    }
}

int main() {
    typedef void(*HelloWorldFunction)();
    auto f = HelloWorld; // == auto f = &HelloWorld;
    f();
    void(*function)(/*argumenty*/) = HelloWorld;
    function();
    HelloWorldFunction f0 = HelloWorld;
    f0();
    void(*f1)(int) = HelloWorldValue;
    f1(5);
    std::vector<int> values = {1, 2, 3, 4, 5};
    ForEach(values, [](int value){std::cout << "Value: " << value << std::endl;});
    // uzywając tutaj "[]" można przekazać jakby rzeczy ze "świata zewnętrznego" (lambdy)
    return 0;
}

// wskaźniki funkcji to basically sposób w który można przypisać funkcję do zmiennej