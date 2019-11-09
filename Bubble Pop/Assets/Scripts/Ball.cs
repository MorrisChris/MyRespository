using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class Ball : MonoBehaviour {

    public Vector2Int m_Index;

    public MeshRenderer m_Renderer;

	// Use this for initialization
	void Awake () {
        int ballColor = Random.Range(1, 5);
        m_Renderer = GetComponent<MeshRenderer>();

        switch(ballColor)
        {
            case 1:
                m_Renderer.material.color = Color.blue;
                break;
            case 2:
                m_Renderer.material.color = Color.red;
                break;
            case 3:
                m_Renderer.material.color = Color.green;
                break;
            case 4:
                m_Renderer.material.color = Color.yellow;
                break;

        }

    }
	
	// Update is called once per frame
	void Update () {
		
	}

    private void OnCollisionEnter(Collision collision)
    {
        if(GetComponent<Rigidbody>())
        {
            Ball otherBall = collision.collider.GetComponent<Ball>();
            if(otherBall)
            {
                Destroy(otherBall.gameObject);
                Destroy(this.gameObject);
            }
        }
    }
}
