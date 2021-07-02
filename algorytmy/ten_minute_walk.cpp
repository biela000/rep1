#include<iostream>
#include<vector>
#include<algorithm>

bool isValidWalk(std::vector<char> walk) {
    if (walk.size() != 10) {
        return false;
    }
    int count[2] = {  };
    for (int i = 0; i < walk.size(); ++i) {
        switch (walk[i]) {
            case 'n':
                count[0]++;
                break;
            case 's':
                count[0]--;
                break;
            case 'e':
                count[1]++;
                break;
            case 'w':
                count[1]--;
                break;
            default:
                break;
        }
    }
    if (count[0] != 0 || count[1] != 0) {
        return false;
    }
    return true;
}

int main() {
    std::vector<char> v{'n','s','n','s','n','s','n','s','n','s'};
    std::cout << isValidWalk(v) << std::endl;
    return 0;
}