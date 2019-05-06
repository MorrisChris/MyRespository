#pragma once
class Timer
{
public:
    Timer();
    ~Timer();

    void Update(float deltaTime);

    void Draw();

private:
    float m_Time;
};

