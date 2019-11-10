using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class PhysicsBody : MonoBehaviour {

    public Rigidbody m_RigidBody;
    public Collider m_Collider;
    public float m_Mass;
    public float m_GravityMultiplier = 1.0f;

    float gravity = 9.81f; //Gravity is 9.81 meters per second

    public Vector3 m_Weight;

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




        if(m_Collider is SphereCollider)
        {
            SphereCollider sphereCollider = GetComponent<SphereCollider>();
            float radius = transform.localScale.x;
            Area = Mathf.PI * radius * radius;
        }
        else if (m_Collider is CapsuleCollider)
        {
            CapsuleCollider capsuleCollider = GetComponent<CapsuleCollider>();
            float radius = transform.localScale.x;
            Area = Mathf.PI * radius * radius;
        }
        else if(m_Collider is BoxCollider)
        {
            BoxCollider boxCollider = GetComponent<BoxCollider>();
            float length = transform.localScale.x;
            float width = transform.localScale.z;
            Area = length * width;
        }
    }
	
	// Update is called once per frame
	void FixedUpdate () {

        Vector3 gravityForce = new Vector3(0, gravity, 0);

        m_Weight = m_Mass * (gravityForce * m_GravityMultiplier);

        Vector3 Velocity = m_RigidBody.velocity;

        Vector3 VelocitySquared = new Vector3(Velocity.x * Velocity.x,
            Velocity.y * Velocity.y,
            Velocity.z * Velocity.z);

        m_Drag = 0.5f * DragCoefficient * AirDensity * VelocitySquared * Area;

        m_RigidBody.AddForce((m_Drag - m_Weight), ForceMode.Acceleration);
        //m_RigidBody.AddForce(-m_Drag, ForceMode.Acceleration);
	}
}
