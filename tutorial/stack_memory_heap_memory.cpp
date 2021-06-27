#include<iostream>
#include<string>

using String = std::string;

struct Vector3 {
    float x, y, z;
    Vector3(void)
        : x(10), y(20), z(30)
        {}
};

int main() {
    int value = 5;
    int arr[5];
    arr[0] = 1;
    arr[1] = 2;
    arr[2] = 3;
    arr[3] = 4;
    arr[4] = 5;
    Vector3 v;
    int* hvalue = new int;
    *hvalue = 5;
    // można też int* hvalue = new int(5);
    int* harr = new int[5];
    harr[0] = 1;
    harr[1] = 2;
    harr[2] = 3;
    harr[3] = 4;
    harr[4] = 5;
    //std::cout << &((Vector3*)nullptr)->z << std::endl;
    Vector3* vector = new Vector3();
    delete[] harr;
    delete hvalue, vector;
    return 0;
}