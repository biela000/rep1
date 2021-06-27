#include<iostream>
#include<string>
#include<typeinfo>
#include<vector>
#include<unordered_map>

using String = std::string;

class Device {};

class DeviceManager {
    private:
        std::unordered_map<String, std::vector<Device*>> devices;
    public:
        const std::unordered_map<String, std::vector<Device*>>& GetDevices() const {
            return devices;
        }
};

const char* GetName() {
    return "aklshfas";
}

/*
auto GetName() -> const char* { // chyba po prostu używamy auto i definiujemy typ używając operatora strzałki
    return "aklshfas";
}
*/

int main() {
    auto var = 5.0f;
    std::cout << typeid(var).name() << std::endl;
    auto a = var;
    auto name = GetName(); // tutaj lepiej akurat użyć String ponieważ zachodzi tu implicit conversion więc i tak będzie działać ale z funkcjami ze stringa
    std::vector<String> v;
    v.reserve(2);
    v.emplace_back("Apple");
    v.emplace_back("Orange");
    for (auto it = v.begin() /* == std::vector<std::string>::iterator it = v.begin()*/; it != v.end(); ++it) {
        std::cout << *it << std::endl;
    }
    using DeviceMap = std::unordered_map<String, std::vector<Device*>>;
    typedef std::unordered_map<String, std::vector<Device*>> DeviceMap;
    DeviceManager dm;
    const std::unordered_map<String, std::vector<Device*>>& device = dm.GetDevices();
    const DeviceMap& dv = dm.GetDevices();
    const auto& dva = dm.GetDevices();
    return 0;
}

// basically auto raczej powinniśmy używać tylko wtedy kiedy mamy długą nazwę typu (lub oczywiście kiedy musimy bo nie znamy typu ale to dopiero w bardzo bardzo skomplikowanych rzeczach) w przeciwnym wypadku jedynie zmniejsza to czytelność kodu 