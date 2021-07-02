#include<iostream>
#include<vector>
#include<algorithm>

class Same {
public:
    Same(const Same&) = delete;
    static Same& Get() {
        static Same same;
        return same;
    }
    static bool comp(std::vector<int>&a, std::vector<int>&b) {
        return Get().Icomp(a, b);
    }
private:
    Same() {}
    bool Icomp(std::vector<int>&a, std::vector<int>& b) {
        if (a.size() != b.size()) { return false; }
        std::sort(a.begin(), a.end());
        std::sort(b.begin(), b.end());
        for (int i = 0; i < a.size(); ++i) {
            if (b[i] != a[i] * a[i]) { return false; }
        }
        return true;
    }
};

int main() {
    std::vector<int> a{ 121, 144, 19, 161, 19, 144, 19, 11 };
    std::vector<int> b{ 121, 14641, 20736, 361, 25921, 361, 20736, 361 };
    std::cout << Same::comp(a, b) << std::endl;
    return 0;
}