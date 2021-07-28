#include <cstdio>
#include<iostream>
#include<string>
#include<vector>

class PeakData {
public:
    static PeakData& Get() {
        static PeakData peakdata;
        return peakdata;
    }
    static PeakData pick_peaks(const std::vector<int>& v) {
        return Get().Ipick_peaks(v);
    }
    const std::vector<int>& GetPos() const {
        return pos;
    }
    const std::vector<int>& GetPeaks() const {
        return peaks;
    }
private:
    static std::vector<int> pos, peaks;
    PeakData Ipick_peaks(std::vector<int> v) {
        static PeakData result;
        if (v.empty()) return result;
        for (int i = 1; i < v.size() - 1; ++i) {
            if (v[i] > v[i - 1] && v[i] > v[i + 1]) {
                result.peaks.push_back(v[i]);
                result.pos.push_back(i);
            }
        }
        return result;
    }
    PeakData() {};
};

int main() {
    return 0;
}
