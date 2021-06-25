#include<iostream>
#include<string>

using String = std::string;

/*{

}*/ //to jest scope

class Entity {
    public:
        Entity() {
            std::cout << "Stworzono obiekt Entity!" << std::endl;
        }
        ~Entity() {
            std::cout << "Zniszczono obiekt Entity!" << std::endl;
        }
};

class ScopedPtr {
    private:
        Entity* ptr;
    public:
        ScopedPtr(Entity* ptr)
            : ptr(ptr)
            {}
        ~ScopedPtr() {
            delete ptr;
        }
};

/*int* CreateArray() {
    int arr[50];
    arr[0] = 50;
    return arr;
}*/

int main() {
    {   
        ScopedPtr ptr = new Entity();
        //Entity e; // obiekt zaalokowany na stacku - jeśli zaalokujemy obiekt na heapie to nie zostanie on zniszczony po skończeniu się scope'a tylko po zakończeniu działania aplikacji
    }
    //std::cout << ptr << std::endl; // nie działa ponieważ został on tak jakby zaalokowany na stacku (jest usuwany po końcu scope'a)
    /*int* arr = CreateArray();
    std::cout << arr[0] << std::endl; // nie zadziała ponieważ obiekt tablica zostanie znisczona po zakończeniu działania funkcji CreateArray() przez to że tablica została stworzona na stacku aby działało musielibyśmy stworzyć tablicę na heapie "int* arr = new int[50];"
    */// delete[] arr;
    return 0;
}