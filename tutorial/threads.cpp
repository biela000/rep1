#include<iostream>
#include<string>
#include<thread>

bool s_Finished = false;

void DoWork() {
    using namespace std::literals::chrono_literals;
    std::cout << "Started thread ID = " << std::this_thread::get_id() << std::endl;
    while (!s_Finished) {
        std::cout << "Working...\n";
        std::this_thread::sleep_for(1s); // używając "std::this_thread" możemy wydawać polecenia threadowi z którego aktualnie korzystamy
    }
}

int main() {
    std::thread worker(DoWork);
    std::cin.get();
    s_Finished = true;
    worker.join(); // po prostu czeka (zatrzymuje główny thread) dopóki dany thread nie skończy swojej pracy
    std::cout << "Skonczono!" << std::endl;
    std::cout << "Started thread ID = " << std::this_thread::get_id() << std::endl;
    std::cin.get();
    return 0;
}