using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class Grid : MonoBehaviour {

    public Ball m_Ball;

	// Use this for initialization
	void Start () {
		for(int x = -10; x < 11; x++)
        {
            for (int y = 0; y < 10; y++)
            {
                Ball ball = Instantiate(m_Ball, new Vector3(x, y),new Quaternion(0,0,0,0));
                ball.m_Index = new Vector2Int(x, y);
            }
        }
	}
	
	// Update is called once per frame
	void Update () {
		
	}
}
