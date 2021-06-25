#include<iostream>
#include<string>
#include<memory>
#include<cstring>

using String = std::string;

struct Vector2 {
    float x, y;
};

class Str {
    private:
        char* buffer;
        unsigned int size;
    public:
        Str(const char* string) {
            size = strlen(string);
            buffer = new char[size + 1];
            memcpy(buffer, string, size);
            buffer[size] = '\0';
            // tutaj niby trzeba pamiętać o tym null znaku na końcu ciągu ale w sumie bez tego też działa
        }
        // Str(const Str& string) = delete; // w ten sposób można usunąć copy constructor
        // Str(const Str& string) : buffer(string.buffer), size(string.size) // domyślny copy constructor
        // Deep copying
        Str(const Str& string) {
            size = string.size;
            buffer = new char[size + 1];
            memcpy(buffer, string.buffer, size);
            buffer[size] = '\0';
        }
        ~Str() {
            delete[] buffer;
        }
        unsigned int GetSize() const {
            return size;
        } 
        char& operator[](const unsigned int& a) const {
            return buffer[a];
        }
        friend std::ostream& operator<< (std::ostream& stream, const Str& string);
};

std::ostream& operator<< (std::ostream& stream, const Str& string) {
    stream << string.buffer;
    return stream;
}

int main() {
    std::shared_ptr<Vector2> a = std::make_shared<Vector2>();
    std::shared_ptr<Vector2> b = a;
    b->x = 5;
    std::cout << a << " " << b << " " << a->x << " " << b->x << std::endl;
    Str string("aaaaaaaaa"); // == Str string = "aaaaaaaaa"; (znowu implicit conversion tutaj wchodzi)
    std::cout << string << std::endl;
    string[0] = 'b';
    std::cout << string << std::endl;
    Str string2 = string;
    std::cout << string2 << std::endl;
    return 0;
}