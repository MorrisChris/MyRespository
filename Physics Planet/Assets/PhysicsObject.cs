using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class PhysicsObject : MonoBehaviour
{
    public float mass;
    public PlanetObject planetObject;

    public Vector3 netForce;
    float Gravity;
    Vector3 GravityDir;
    Vector3 GravityForce;

    Rigidbody PhysicsBody;

    // Start is called before the first frame update
    void Start()
    {
        Gravity = PhysicsUtils.CalculateGravity(this, planetObject);

        PhysicsBody = GetComponent<Rigidbody>();
    }

    // Update is called once per frame
    void Update()
    {
        GravityDir = (transform.position - planetObject.transform.position).normalized;

        netForce = GravityDir * Gravity;

        PhysicsBody.AddForce(netForce, ForceMode.Acceleration);
    }
}
