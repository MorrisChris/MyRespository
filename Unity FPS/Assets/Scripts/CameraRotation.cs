using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class CameraRotation : MonoBehaviour
{

    enum RotationDirection
    {
        Up,
        Down,
        Both
    }

    InputManager m_InputManager;

    // Use this for initialization
    void Start()
    {
        m_InputManager = transform.parent.GetComponent<InputManager>();
    }

    // Update is called once per frame
    void FixedUpdate()
    {
        float min = -45;
        float max = 45;

        //Vector3 startRot = transform.localRotation.eulerAngles;
        float mouseDir = -m_InputManager.MouseVertical();
        RotationDirection rotateDir = RotationDirection.Both;
        if (transform.localRotation.eulerAngles.x >= max)
        {
            rotateDir = RotationDirection.Down;
        }
        else if (transform.localRotation.eulerAngles.x <= min)
        {
            rotateDir = RotationDirection.Up;
        }
        else if(transform.localRotation.eulerAngles.x > min || transform.localRotation.eulerAngles.x < max)
        {
            rotateDir = RotationDirection.Both;
        }
        Debug.Log(mouseDir);

        if(mouseDir > 0 && 
            (rotateDir == RotationDirection.Up || rotateDir == RotationDirection.Both))
        {
            transform.Rotate(m_InputManager.MouseVertical(), 0, 0);
        }
        else if(mouseDir < 0 && 
            (rotateDir == RotationDirection.Down || rotateDir == RotationDirection.Both))
        {
            transform.Rotate(m_InputManager.MouseVertical(), 0, 0);
        }


    }
}
