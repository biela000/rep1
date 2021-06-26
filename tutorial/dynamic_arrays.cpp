#include<iostream>
#include<vector>

struct Vertex {
    float x, y, z;
};

std::ostream& operator<<(std::ostream& stream, const Vertex& v) {
    stream << v.x << " " << v.y << " " << v.z;
    return stream;
}

int main() {
    std::vector<Vertex> vertices;
    vertices.push_back({1, 2, 3});
    vertices.push_back({4, 5, 6});
    vertices.erase(vertices.end() - 1); // == vertice.erase(vertices.begin() + vertices.size() - 1)
    for (const Vertex& v : vertices) { // == for (int i = 0; i < vertices.size(); ++i)
        std::cout << v << std::endl;
    }
    return 0;
}