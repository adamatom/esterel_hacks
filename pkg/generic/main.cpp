#include <thread>
#include <future>
#include <chrono>
#include <iostream>

#include <cstring>
void Log(const char* s) {
    std::cout << s << std::flush;
}
#include "runbeepboop.c"

int main() {
    RUNBEEPBOOP_reset();
    while(RUNBEEPBOOP()) {
        std::this_thread::sleep_for( std::chrono::milliseconds(1) );
        RUNBEEPBOOP_I_ms();
    }
}
