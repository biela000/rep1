#include<iostream>
#include<string>
#include<algorithm>
#include<vector>

struct Weight2 {
    std::string w1;
    int w2 = 0;
};

class WeightSort {
public:
    WeightSort(const WeightSort&) = delete;
    static WeightSort& Get() {
        static WeightSort ws;
        return ws;
    }
    static std::string orderWeight(const std::string& strng) {
        return Get().IorderWeight(strng);
    }
private:
    std::string IorderWeight(std::string strng) {
        strng += ' ';
        std::vector<std::string> s;
        while (!strng.empty()) {
            s.push_back(strng.substr(0, strng.find(' ')));
            strng.erase(0, strng.find(' ') + 1);
        }
        Weight2 arr[s.size()];
        for (int i = 0; i < s.size(); ++i) {
            arr[i].w1 = s[i];
            for (const char& c : s[i]) {
                arr[i].w2 += c - 48;
            }
        }
        for (int i = 0; i < s.size(); ++i) {
            for (int o = i; o < s.size(); ++o) {
                if (arr[o].w2 <= arr[i].w2) {
                    if (arr[o].w2 < arr[i].w2 || (arr[o].w1 < arr[i].w1 && arr[o].w2 == arr[i].w2))
                        std::swap(arr[o], arr[i]);
                }
            }
        }
        std::string res = " ";
        for (int i = 0; i < s.size(); ++i) {
            if (i != s.size() - 1) res += arr[i].w1 + ' ';
            else res += arr[i].w1;
        }
        res.erase(res.begin(), res.begin() + 1);
        return res; 
    }
    WeightSort() {}
};

int main() {
    std::cout << WeightSort::orderWeight("2000 10003 1234000 44444444 9999 11 11 22 123") << std::endl; 
    return 0;
}
