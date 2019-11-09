using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class Grid : MonoBehaviour {

    public Ball m_Ball;
    public int xVal = 20;
    public int yVal = 10;

	// Use this for initialization
	void Start () {
		for(int x = 1; x < xVal; x++)
        {
            for (int y = 0; y < yVal; y++)
            {
                Ball ball = Instantiate(m_Ball, new Vector3(x, y),new Quaternion(0,0,0,0));
                ball.m_Index = new Vector2Int(x, y);
            }
        }

        Vector3 camPos = Camera.main.transform.position;
        Quaternion camRot = Camera.main.transform.rotation;

        Vector3 newCamPos = new Vector3(xVal / 2, camPos.y, camPos.z);

        Camera.main.transform.SetPositionAndRotation(newCamPos, camRot);
	}
	
	// Update is called once per frame
	void Update () {
		
	}
}
