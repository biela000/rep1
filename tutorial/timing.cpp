#include<iostream>
#include<string>
#include<chrono>
#include<thread>
#include<functional>

bool f_Finished = false;

struct Timer {
    std::chrono::_V2::system_clock::time_point start, end;
    std::chrono::duration<float> duration;
    Timer() {
        start = std::chrono::high_resolution_clock::now();
    }
    ~Timer() {
        end = std::chrono::high_resolution_clock::now();
        duration = end - start;
        float ms = duration.count() * 1000.0f;
        std::cout << "Timer took: " << ms << std::endl;
    }
};

long double Fib(int quantity) {
    if (quantity <= 1) { return quantity; }
    return Fib(quantity - 1) + Fib(quantity - 2);
}

void Function() {
    Timer t;
    using namespace std::literals::chrono_literals;
    for (int i = 0; i < 100 && !f_Finished; ++i) {
        std::cout << "Hello!\n";
        std::this_thread::sleep_for(1s);
    }
}

double MeasureTime(const std::function<void()>& f) {
    using namespace std::literals::chrono_literals;
    auto start = std::chrono::high_resolution_clock::now();
    f();
    auto end = std::chrono::high_resolution_clock::now();
    std::chrono::duration<float> duration = end - start;
    return (duration.count() * 1000.0f);
}

int main() {
    using namespace std::literals::chrono_literals;
    auto start = std::chrono::high_resolution_clock::now(); // to długi typ więc użyłem "auto"
    std::cout << Fib(10) << std::endl;
    std::this_thread::sleep_for(1s);
    auto stop = std::chrono::high_resolution_clock::now();
    std::chrono::duration<float> duration = stop - start;
    std::cout << duration.count() << std::endl;
    std::thread thread(Function);
    std::cin.get();
    f_Finished = true;
    thread.join();
    std::cout << "Timer took: " << MeasureTime([](){
        for (int i = 0; i < 100; ++i) {
            std::cout << "Hello!\n";
        }
    }) << std::endl;
    return 0;
}