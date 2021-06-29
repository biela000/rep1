#include<iostream>
#include<string>

int main() {
    int** arr = new int*[50];
    for (int i = 0; i < 50; ++i) {
        arr[i] = new int[10];
    }
    arr[0/*adres tablicy*/][0/*tablica*/] = 5;
    for (int y = 0; y < 50; ++y) {
        for (int x = 0; x < 10; ++x) {
            arr[y][x] = 2;
        }
    }
    for (int i = 0; i < 50; ++i) {
        delete[] arr[i];
    }
    delete[] arr;
    //alokowanie trójwymiarowej tablicy
    /*int*** array = new int**[10];
    for (int i = 0; i < 10; ++i) {
        array[i] = new int*[10];
        for (int o = 0; o < 10; ++o) {
            array[i][o] = new int[10];
        }
    }*/
    return 0;
}

// problem z kilkuwymiarowymi tablicami jest taki że tak jakby każda właściwa tablica jest rozrzucona randomowo po pamięci co sprawia że mogą pojawiać się cache missy (będzie o wiele wolniej)
// lepiej ogólnie raczej używać jednak tablic jednowymiarowych - jest to szybsze i można ogarniać iterowanie robiąc na przykład "arr[x + y * n]" bo to mnożenie przez n jest tak jakby tym samym co zrzucenie o jeden rząd (to wszystko na dwóch pętlach tutaj a "n" jest równe wielkości tablicy)