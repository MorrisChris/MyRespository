using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class TurretRotator : MonoBehaviour {

    public InputManager m_InputManager { get; set; }

    public GameObject m_Muzzle;

    public GameObject m_Bullet;

	// Use this for initialization
	void Awake () {
        m_InputManager = new InputManager();

        float position = GameObject.FindObjectOfType<Grid>().xVal / 2;

        Vector3 pos = new Vector3(position, transform.position.y, transform.position.z);
        Quaternion rot = transform.rotation;

        transform.SetPositionAndRotation(pos, rot);

        m_Muzzle = transform.GetChild(0).transform.GetChild(0).gameObject;
	}
	
	// Update is called once per frame
	void Update () {

        if(m_InputManager != null)
        {
            if(m_InputManager.RotateLeft())
            {
                transform.Rotate(new Vector3(0, 0, 1), 1);
            }
            if(m_InputManager.RotateRight())
            {
                transform.Rotate(new Vector3(0, 0, 1), -1);
            }

            if(m_InputManager.Shoot())
            {
                GameObject bullet;
                bullet = Instantiate(m_Bullet, m_Muzzle.transform.position, m_Muzzle.transform.rotation);

                Vector3 force = m_Muzzle.transform.up * 10;

                bullet.GetComponent<Rigidbody>().AddForce(force, ForceMode.Impulse);
            }
        }

	}
}
