#include<iostream>

struct Vector2 {
    float x, y;
    Vector2()
        : x(0), y(0)
        {}
    Vector2(float x, float y)
        : x(x), y(y)
        {}
    Vector2 Add(const Vector2& a) const {
        return Vector2(x + a.x, y + a.y);
    }
    Vector2 Multiply(const Vector2& a) const {
        return Vector2(x * a.x, y * a.y);
    }
    Vector2 operator+(const Vector2& b) const {
        return Add(b);
    }
    Vector2 operator*(const Vector2& b) const {
        return Multiply(b);
    }
    bool equals(const Vector2& a) const {
        return x == a.x && y == a.y;
    }
    bool operator==(const Vector2& b) const {
        return equals(b);
    }
    bool operator!=(const Vector2& b) const {
        return !equals(b);
        //return (*this == b);
    }
};

void PrintVector(const Vector2& a) {
    std::cout << a.x << " " << a.y << std::endl;
}

std::ostream& operator<<(std::ostream& stream, const Vector2& b) {
    stream << b.x << " " << b.y << std::endl;
    return stream;
}

std::istream& operator>>(std::istream& stream, Vector2& b) { // zmienna nie może być const ponieważ zostanie tu zmieniona
    stream >> b.x >> b.y;
    return stream;
}

int main() {
    Vector2 position(4.0f, 4.0f);
    Vector2 speed(0.5f, 1.5f);
    Vector2 powerup(1.1f, 1.1f);
    Vector2 result1 = position.Add(speed.Multiply(powerup));
    Vector2 result2 = position + speed * powerup;
    std::cout << result1 << result2;
    Vector2 test;
    std::cout << test;
    std::cin >> test;
    std::cout << test;
    std::cout << result1.equals(result2) << std::endl;
    std::cout << (result1 == result2) << std::endl;
    std::cout << (result1 != result2) << std::endl;
    return 0;
}