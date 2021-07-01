#include<iostream>
#include<string>
#include<memory>
#include<chrono>
#include<array>

class Timer {
private:
    std::chrono::_V2::system_clock::time_point startTimePoint, stopTimePoint;
    std::chrono::duration<float> duration;
    float ms;
public:
    Timer() {
        startTimePoint = std::chrono::high_resolution_clock::now();
    }
    ~Timer() {
        /*stopTimePoint = std::chrono::high_resolution_clock::now();
        auto start = std::chrono::time_point_cast<std::chrono::milliseconds>(startTimePoint).time_since_epoch().count();
        auto stop = std::chrono::time_point_cast<std::chrono::milliseconds>(stopTimePoint).time_since_epoch().count();
        auto duration = stop - start;
        us = duration * 1000.0f;
        std::cout << "Time (us): " << us << std::endl;
        std::cout << "Time (ms): " << duration << std::endl;*/ // Daje wynik w longu
        stopTimePoint = std::chrono::high_resolution_clock::now();
        duration = stopTimePoint - startTimePoint;
        ms = duration.count() * 1000.0f;
        std::cout << "Time: " << ms << std::endl;
    }
};

int main() {
    int value = 0;
    {
        Timer t;
        for (int i = 0; i < 1000000; ++i) {
            value += 2;
        }
    }
    std::cout << value << std::endl;
    struct Vector2 {
        float x, y;
    };
    std::cout << "Make shared\n";
    {
        Timer t;
        std::array<std::shared_ptr<Vector2>, 1000> sharedPtrs;
        for (int i = 0; i < sharedPtrs.size(); ++i) {
            sharedPtrs[i] = std::make_shared<Vector2>();
        }
    }
    std::cout << "New shared\n";
    {
        std::array<std::shared_ptr<Vector2>, 1000> sharedPtrs;
        Timer t;
        for (int i = 0; i < sharedPtrs.size(); ++i) {
            sharedPtrs[i] = std::shared_ptr<Vector2>(new Vector2());
        }
    }
    std::cout << "Make unique\n";
    {
        std::array<std::unique_ptr<Vector2>, 1000> uniquePtrs;
        Timer t;
        for (int i = 0; i < uniquePtrs.size(); ++i) {
            uniquePtrs[i] = std::make_unique<Vector2>();
        }
    }
    return 0;
}