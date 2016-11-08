#include <thread>
#include <future>
#include <chrono>
#include <iostream>
#include <atomic>

#include <cstring>
void Log(const char* s) {
    std::cout << s << std::flush;
}
#include "paror.c"


void help() {
    puts("Type:\n\t"
            "A - input the A event\n\t"
            "B - input the B event\n\t"
            "q or Q to quit");
}
bool input(std::atomic<bool> * running)
{
    char input = 0;
    while(*running) {
        input = getchar();
        switch( input ) {
            case 'q':
            case 'Q': return true;
            case 'A': PAROR_I_A(); break;
            case 'B': PAROR_I_B(); break;
            case '\n': break;
            default: help();
        }
    }
}

int main() {
    help();
    PAROR_reset();
    std::atomic<bool> running { true };
    std::future<bool> do_quit = std::async(std::launch::async, &input, &running);
    while(PAROR()) {
        static int count = 0;
        std::this_thread::sleep_for( std::chrono::milliseconds(1) );
        if(count++ >= 1000)
        {
            count = 0;
            PAROR_I_Second();
        }
    }
    running = false;
    do_quit.get();
}
