using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class InputManager{
    public bool RotateLeft()
    {
        return Input.GetKey(KeyCode.A) || Input.GetKey(KeyCode.LeftArrow);
    }

    public bool RotateRight()
    {
        return Input.GetKey(KeyCode.D) || Input.GetKey(KeyCode.RightArrow);
    }

    public bool Shoot()
    {
        return Input.GetKeyDown(KeyCode.Space);
    }
}
