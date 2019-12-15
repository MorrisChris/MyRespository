using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public enum FireMode
{
    FireMode_FullAuto,
    FireMode_SemiAuto,
    FireMode_PumpAction
}

public class Weapon : MonoBehaviour
{
    public int I_Damage;
    public int I_FireRate;

    private float _i_TimeBetweenShots;

    public FireMode FM_FireMode;

    // Start is called before the first frame update
    void Start()
    {
        _i_TimeBetweenShots = I_FireRate / 60;
    }

    // Update is called once per frame
    void Update()
    {
        
    }

    public void FullAuto()
    {
        StartCoroutine(ShootAffect());

        Vector3 StartPoint = Camera.main.ViewportToWorldPoint(new Vector3(0.5f, 0.5f, 0.0f));

        RaycastHit Hit;

        if(Physics.Raycast(StartPoint, Camera.main.transform.forward, out Hit))
        {
            GameObject hitObject = Hit.transform.gameObject;

            ITakeDamage damageableObject = hitObject.GetComponent<ITakeDamage>();

            if(damageableObject != null)
            {
                damageableObject.ApplyDamage(I_Damage);


            }

            Head head = hitObject.GetComponent<Head>();

            if(head != null)
            {
                damageableObject = head.transform.parent.GetComponent<ITakeDamage>();

                damageableObject.Kill();
            }
        }
    }

    IEnumerator ShootAffect()
    {
        yield return _i_TimeBetweenShots;
    }
}
