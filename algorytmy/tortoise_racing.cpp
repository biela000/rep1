#include<iostream>
#include<vector>

class Tortoise {
public:
    Tortoise(const Tortoise&) = delete;
    static Tortoise& Get() {
        static Tortoise tortoise;
        return tortoise;
    }
    static std::vector<int> race(int v1, int v2, int g) {
        return Get().Irace(v1, v2, g);
    }
private:
    std::vector<int> Irace(int v1, int v2, int g) {
        if (v1 >= v2) return std::vector<int>{ -1, -1, -1 };
        int diff = v2 - v1;
        int t = 3600.0 * ((double)g / (double)diff);        
        std::vector<int> v;
        v.reserve(3);
        v.emplace_back(t / 3600);
        v.emplace_back((t / 60) % 60);
        v.emplace_back(t % 60);
        return v;
    }
    Tortoise() {}
};

template<typename T>
std::ostream& operator<<(std::ostream& stream, const std::vector<T>& v) {
    for (const T& el : v) {
        stream << el << " ";
    }
    return stream;
}

int main() {
    std::cout << Tortoise::race(80, 91, 37) << std::endl;
    return 0;
}
