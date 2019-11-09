using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class Cluster
{
    Cluster()
    {

    }

    void AddToCluster(Ball ball)
    {
        if (!(m_BallsInCluster.Contains(ball)))
        {
            m_BallsInCluster.Add(ball);
        }
    }

    void CheckSurroundingBalls(Ball ball)
    {
        Vector2 index = ball.m_Index;

        
    }

    List<Ball> m_BallsInCluster;
}
