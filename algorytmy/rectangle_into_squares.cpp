#include<iostream>
#include<vector>

class SqInRect {
public:
    static SqInRect& Get() {
        static SqInRect sqinrect;
        return sqinrect;
    }
    SqInRect(const SqInRect&) = delete;
    static std::vector<int> sqInRect(int lng, int wdth) {
        return Get().IsqInRect(lng, wdth); 
    }
private:
    std::vector<int> IsqInRect(int lng, int wdth) {
        std::vector<int> v;
        if (lng == wdth) { return v; }
        while (lng > 0 && wdth > 0) {
            int min = lng < wdth ? lng : wdth;
            v.push_back(min);
            if (min == lng) { wdth -= min; }
            else if (min == wdth) { lng -= min; }
        }
        return v;
    }
    SqInRect() {}
};

std::ostream& operator<<(std::ostream& stream, const std::vector<int>& v) {
    for (const int& numb : v) {
        stream << numb << " ";
    }
    return stream; 
}

int main() {
    std::cout << SqInRect::sqInRect(5, 19) << std::endl; 
    return 0;
}
