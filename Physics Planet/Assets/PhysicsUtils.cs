using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public static class PhysicsUtils
{
    

    public static float CalculateGravity(PhysicsObject smallObject, PlanetObject bigObject)
    {
        float G = GetG();

        float R = Vector3.Distance(smallObject.transform.position, bigObject.transform.position);
        float gravity = (G * ((smallObject.mass * bigObject.mass) / (R * R)));

        return gravity;
    }

    public static float GetG()
    {
        return 6.67f * Mathf.Pow(10, -11);
    }
}
