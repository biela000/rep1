#include<iostream>
#include<vector>
#include<string>
#include<fstream>
#include<cstdlib>

using String = std::string;

struct Row {
    String r_Name;
    double r_X;
    double r_Y;
    Row(String string) {
        string.erase(string.begin(), string.begin() + string.find("PL") + 4);
        r_Name = string.substr(0, string.find("  "));
        string.erase(string.begin(), string.begin() + string.find("  ") + 2);
        r_X = atof(string.substr(0, string.find("  ")).c_str());
        string.erase(string.begin(), string.begin() + string.find("  ") + 2);
        r_Y = atof(string.substr(0, string.find("  ")).c_str());
    }
};

std::ostream& operator<<(std::ostream& stream, const Row& row) {
    stream << row.r_Name << " " << row.r_X << " " << row.r_Y;
    return stream;
}

const std::pair<double, double>* Find(const String& name, const std::vector<Row>& vector) {
    for (Row r : vector) {
        if (r.r_Name == name) {
            std::pair<double, double>* p = new std::pair<double, double>;
            p->first = r.r_X;
            p->second = r.r_Y;
            return p;
        }
    }
}

int main() {
    std::fstream f;
    f.open("miasta.txt", std::ios::in);
    String s;
    std::vector<Row> v;
    while (getline(f, s)) {
        v.reserve(1);
        v.emplace_back(s);
    }
    for (Row r : v) {
        std::cout << r << std::endl;
    }
    String u_name;
    std::cout << "Podaj miasto: "; std::cin >> u_name;
    const std::pair<double, double>* cord = Find(u_name, v);
    std::cout << "Koordynaty: " << cord->first << " " << cord->second << std::endl;
    delete cord;
    f.close();
    return 0;
}