#include<iostream>
#include<string>
#include<fstream>
#include<optional>

std::optional<std::string> ReadFileAsString(const std::string& filepath) {
    std::ifstream stream(filepath);
    if (stream) {
        std::string result;
        stream.close();
        return result;
    }
    return {};
}

int main() {
    std::optional<std::string> data = ReadFileAsString("data.txt");
    std::string value = data.value_or("Not present");
    std::optional<int> count;
    int c = count.value_or(100);
    if (data.has_value()) { // można też po prostu "if(data)"
        std::cout << "File read successfully!" << std::endl;
    }
    else {
        std::cout << "File could not be opened!" << std::endl;
    }
    return 0;
}