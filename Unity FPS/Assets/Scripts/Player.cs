using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class Player : MonoBehaviour {

    InputManager m_InputManager;
    Rigidbody m_PhysicsBody;

    float m_Speed = 10;
    float m_TurnSpeed = 10;

	// Use this for initialization
	void Start () {
        m_InputManager = GetComponent<InputManager>();
        m_PhysicsBody = GetComponent<Rigidbody>();
	}
	
	// Update is called once per frame
	void FixedUpdate () {

        #region Player Movement
        if (m_InputManager.MoveForward())
        {
            m_PhysicsBody.AddForce(m_Speed * transform.forward, ForceMode.Force);
        }
        if (m_InputManager.MoveBackward())
        {
            m_PhysicsBody.AddForce(m_Speed * -transform.forward, ForceMode.Force);
        }
        if (m_InputManager.StrafeLeft())
        {
            m_PhysicsBody.AddForce(m_Speed * -transform.right, ForceMode.Force);
        }
        if(m_InputManager.StrafeRight())
        {
            m_PhysicsBody.AddForce(m_Speed * transform.right, ForceMode.Force);
        }

        transform.Rotate(new Vector3(0,1,0), m_InputManager.MouseHorizontal());

        float magnitude = m_PhysicsBody.velocity.magnitude;

        if (magnitude > m_Speed)
        {
            m_PhysicsBody.AddForce((magnitude - m_Speed) * -m_PhysicsBody.velocity, ForceMode.Force);
        }

        #endregion


	}

    private void Update()
    {

    }
}
