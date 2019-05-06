#include "stdafx.h"
#include "Timer.h"
#include<iostream>


Timer::Timer()
{
    m_Time = 0;
}


Timer::~Timer()
{
}

void Timer::Update(float deltaTime)
{
    m_Time += deltaTime;
}

void Timer::Draw()
{
    std::cout << m_Time<< "\n";
}