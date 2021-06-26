#include<iostream>
#include<vector>

struct Vertex {
    float x, y, z;
    Vertex(float x, float y, float z)
        : x(x), y(y), z(z)
        {}
    Vertex(const Vertex& v)
        : x(v.x), y(v.y), z(v.z)
        {
            std::cout << "Skopiowano obiekt" << std::endl;
        }
};

int main() {
    std::vector<Vertex> vertices; // jeśli damy tu "(3)" to zrobi to 3 Vertex obiekty 
    vertices.reserve(3); // to nam daje po prostu pamięć a nie od razu ją zajmuje jakimiś obiektami
    vertices.emplace_back(1, 2, 3); // to sprawia że musimy przekazać same argumenty konstruktora ponieważ zamiast w mainie obiekt zostanie od razu stworzony w pamięci wektora dzięki czemu nie będzie trzeba go kopiować
    vertices.emplace_back(4, 5, 6);
    vertices.emplace_back(7, 8, 9);
    return 0;
}