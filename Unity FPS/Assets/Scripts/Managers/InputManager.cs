using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class InputManager : MonoBehaviour {

	public bool MoveForward()
    {
        return Input.GetKey(KeyCode.W);
    }

    public bool MoveBackward()
    {
        return Input.GetKey(KeyCode.S);
    }

    public bool StrafeLeft()
    {
        return Input.GetKey(KeyCode.A);
    }

    public bool StrafeRight()
    {
        return Input.GetKey(KeyCode.D);
    }

    public float MouseVertical()
    {
        return Input.GetAxis("Mouse Y");
    }
    
    public float MouseHorizontal()
    {
        return Input.GetAxis("Mouse X");
    }
}
