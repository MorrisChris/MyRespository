using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class Player : MonoBehaviour
{
    PlayerController _pc_Controller;

    public Rigidbody RB_PhysicsBody;
    public float F_Speed = 10;

    public Transform T_HeadTransform;
    float _f_HeadAngle = 0;

    public Weapon CurrentWeapon;

    // Start is called before the first frame update
    void Start()
    {
        _pc_Controller = new PlayerController();

        RB_PhysicsBody = GetComponent<Rigidbody>();

        T_HeadTransform = GetComponentInChildren<Head>().transform;

        Cursor.lockState = CursorLockMode.Locked;
    }

    // Update is called once per frame
    void FixedUpdate()
    {
        if(_pc_Controller.MoveForward())
        {
            RB_PhysicsBody.AddForce(transform.forward * F_Speed, ForceMode.Acceleration);
        }

        if(_pc_Controller.MoveBackward())
        {
            RB_PhysicsBody.AddForce(-transform.forward * F_Speed, ForceMode.Acceleration);
        }

        if (_pc_Controller.MoveLeft())
        {
            RB_PhysicsBody.AddForce(-transform.right * F_Speed, ForceMode.Acceleration);
        }

        if (_pc_Controller.MoveRight())
        {
            RB_PhysicsBody.AddForce(transform.right * F_Speed, ForceMode.Acceleration);
        }

        transform.Rotate(new Vector3(0, _pc_Controller.Turn(), 0));

        _f_HeadAngle += -_pc_Controller.LookUpDown();

        _f_HeadAngle = Mathf.Clamp(_f_HeadAngle, -45, 45);

        T_HeadTransform.localEulerAngles = new Vector3(_f_HeadAngle, 0, 0);
    }

    private void Update()
    {
        if(_pc_Controller.Fire() == ButtonState.ButtonState_Held)
        {
            CurrentWeapon.Shoot();
        }
        if(_pc_Controller.Fire() == ButtonState.ButtonState_Pressed)
        {
            CurrentWeapon.Shoot();
        }
        if(_pc_Controller.Reload())
        {
            CurrentWeapon.Reload();
        }
    }
}
