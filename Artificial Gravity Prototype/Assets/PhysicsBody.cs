using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class PhysicsBody : MonoBehaviour {

    public Rigidbody m_RigidBody;
    public Collider m_Collider;
    public float m_Mass;
    public float m_GravityMultiplier = 1.0f;

    float gravity = 9.81f; //Gravity is 9.81 meters per second

    public float m_Force { get; private set; }

    /*
        Drag = -0.5 * C * p * A(v)squared

        C (drag cooefficient) = 0.5 for a sphere
        p (air density) = 1.29kg/(m)cubed
        A (front area of the object (4 * Pi * radius squared for capsule)
        v (velocity)
    */

    public Vector3 m_Drag;

    float DragCoefficient = 0.5f;
    float AirDensity = 1.29f;
    float Area;

    // Use this for initialization
    void Awake () {


        m_RigidBody = GetComponent<Rigidbody>();
        m_Collider = GetComponent<Collider>();

        m_Mass = m_RigidBody.mass;




        if(m_Collider is CapsuleCollider || m_Collider is SphereCollider)
        {
            SphereCollider sphereCollider = m_Collider as SphereCollider;
            float radius = sphereCollider.radius;
            Area = 4 * Mathf.PI * radius;
        }
	}
	
	// Update is called once per frame
	void FixedUpdate () {

        m_Force = m_Mass * (gravity * m_GravityMultiplier);

        Vector3 Velocity = m_RigidBody.velocity;

        m_Drag = -0.5f * DragCoefficient * AirDensity * Area * Velocity;

        m_RigidBody.AddForce((m_Force * Vector3.down) - m_Drag, ForceMode.Acceleration);
	}
}
