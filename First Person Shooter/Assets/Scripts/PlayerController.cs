using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public enum ButtonState
{
    ButtonState_Pressed,
    ButtonState_Held,
    ButtonState_Released
}

public class PlayerController
{
    public bool MoveLeft()
    {
        return Input.GetKey(KeyCode.A) || Input.GetKey(KeyCode.LeftArrow);
    }

    public bool MoveRight()
    {
        return Input.GetKey(KeyCode.D) || Input.GetKey(KeyCode.RightArrow);
    }

    public bool MoveForward()
    {
        return Input.GetKey(KeyCode.W) || Input.GetKey(KeyCode.UpArrow);
    }

    public bool MoveBackward()
    {
        return Input.GetKey(KeyCode.S) || Input.GetKey(KeyCode.DownArrow);
    }

    public float Turn()
    {
        return Input.GetAxis("Mouse X");
    }

    public float LookUpDown()
    {
        return Input.GetAxis("Mouse Y");
    }

    public ButtonState Fire()
    {
        if (Input.GetMouseButtonDown(0))
        {
            return ButtonState.ButtonState_Pressed;
        }
        else if (Input.GetMouseButton(0))
        {
            return ButtonState.ButtonState_Held;
        }
        else
        {
            return ButtonState.ButtonState_Released;
        }
    }

    public bool Reload()
    {
        return Input.GetKey(KeyCode.R);
    }
}
