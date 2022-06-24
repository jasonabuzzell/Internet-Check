#include <windows.h>
#include <wininet.h>
#include <iostream>
#include <ctime>
#pragma comment(lib, "Wininet.lib")

using namespace std;

int main() {
    cout << "Internet Check starting...\n\n";
    bool state = false;
    while (true) {
        time_t now = time(0);
        char* date_time = ctime(&now);
        bool ping = system("ping google.com | find \"Reply\" > nul");
        if (ping && !state) { // First time Internet dropped
            cout << "Internet Dropped:\n  From: " << date_time;
            state = true;
        } else if (!ping && state) { // First time Internet connected
            cout << "  To:   " << date_time << "\n";
            state = false;
        }
    }

    return 1;
}