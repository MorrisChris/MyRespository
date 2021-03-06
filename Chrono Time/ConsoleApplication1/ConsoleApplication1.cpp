// ConsoleApplication1.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <time.h>
#include <chrono>
#include <Windows.h>

using namespace std;

int main()
{
    //The time when the game starts
    auto start = chrono::steady_clock::now();

    while (true)
    {
        //The time at the start of the loop
        auto time = chrono::steady_clock::now();

        //The time at the start subtracted from the time of the loop (milliseconds)
        auto timeSinceStart = chrono::duration_cast<chrono::milliseconds>(time - start).count();
        //The time at the start subtracted from the time of the loop (seconds)
        auto timeSinceStartSeconds = chrono::duration_cast<chrono::seconds>(time - start).count();

        //Delay execution for 1 second
        Sleep(1000);

        //Output the time in seconds
        std::cout << "Time: " << timeSinceStartSeconds;

        //Stop the execution after 10 seconds
        if (timeSinceStartSeconds >= 10)
        {
            break;
        }
    }

    system("pause");
    return 0;
}

