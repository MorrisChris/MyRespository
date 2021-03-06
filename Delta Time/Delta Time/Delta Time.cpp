// Delta Time.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"

#include<iostream>
#include<chrono>
#include<Windows.h>

#include "Timer.h"

using namespace std;

#define SAFE_DELETE(pPtr) {delete pPtr; pPtr = NULL;}

int main()
{
    std::unique_ptr<Timer> timer(new Timer());

    auto oldTime = chrono::steady_clock::now();

    while (true)
    {
        auto newTime = chrono::steady_clock::now();

        double deltaTime = chrono::duration_cast<chrono::milliseconds>(newTime - oldTime).count();

        //Most precise deltaTime on computer this was made on
        deltaTime /= 200;

        oldTime = newTime;

        timer->Update(deltaTime);
        timer->Draw();
    }

    return 0;
}

