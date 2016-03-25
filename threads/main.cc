
#include <iostream>
#include <thread>

void call_from_thread() {
    std::cout << "Hello, World" << std::endl;
}

void call_from_thread2(std::string s) {
    std::cout << "Hello, " << s << std::endl;
}

int main() {
    //Launch a thread
    std::thread t1(call_from_thread);
    std::thread t2(call_from_thread2, "Rayed");

    //Join the thread with the main thread
    t1.join();
    t2.join();

    std::cout << "Finished" << std::endl;

    return 0;
}
