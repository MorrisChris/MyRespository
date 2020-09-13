using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public enum FireMode
{
    FireMode_FullAuto,
    FireMode_SemiAuto,
    FireMode_PumpAction
}

public enum WeaponState
{
    Weapon_Ready,
    Weapon_Empty,
    Weapon_Reloading,
    Weapon_BetweenShots
}

public class Weapon : MonoBehaviour
{
    public int I_Damage;
    public int I_FireRate;
    public int I_Capacity;
    public int I_AmmoInGun;

    private float _f_TimeBetweenShots;

    public FireMode FM_FireMode;

    float TimeToNextShot = 0;

    public WeaponState CurrentState;

    public float F_ReloadTime;
    public float F_TacReloadTime;

    float _f_TimeToReload;

    public Vector2 _v2_Recoil;
    public float _f_MaxVerticalRecoilPerShot;
    public float _f_MinVerticalRecoilPerShot;
    public float _f_MaxVerticalRecoil;
    public Transform WeaponTransform;

    float recoilSmoothing;


    // Start is called before the first frame update
    void Start()
    {
        _f_TimeBetweenShots = 60.0f / I_FireRate;
        CurrentState = WeaponState.Weapon_Ready;
        _v2_Recoil = Vector2.zero;
        WeaponTransform = transform.parent.transform;

        recoilSmoothing = _f_TimeBetweenShots * 100000;
    }

    // Update is called once per frame
    void Update()
    {
        I_AmmoInGun = Mathf.Clamp(I_AmmoInGun, 0, I_Capacity + 1);

        Debug.Log(I_AmmoInGun);

        if(I_AmmoInGun <= 0 && CurrentState != WeaponState.Weapon_Reloading)
        {
            Reload();
        }

        if(CurrentState == WeaponState.Weapon_Reloading)
        {
            if(Time.time > _f_TimeToReload)
            {
                if(I_AmmoInGun == 0)
                {
                    I_AmmoInGun = I_Capacity;
                }
                else if(I_AmmoInGun > 0)
                {
                    I_AmmoInGun = I_Capacity + 1;
                }

                CurrentState = WeaponState.Weapon_Ready;
            }
        }

        _v2_Recoil.y -= Time.deltaTime * recoilSmoothing;
    }

    public void Shoot()
    {
        if (TimeToNextShot < Time.time && CurrentState == WeaponState.Weapon_Ready)
        {
            TimeToNextShot = Time.time + _f_TimeBetweenShots;

            Vector3 StartPoint = Camera.main.ViewportToWorldPoint(new Vector3(0.5f, 0.5f, 0.0f));

            RaycastHit Hit;

            if (Physics.Raycast(StartPoint, Camera.main.transform.forward, out Hit))
            {
                GameObject hitObject = Hit.transform.gameObject;

                ITakeDamage damageableObject = hitObject.GetComponent<ITakeDamage>();

                if (damageableObject != null)
                {
                    damageableObject.ApplyDamage(I_Damage);


                }

                Head head = hitObject.GetComponent<Head>();

                if (head != null)
                {
                    damageableObject = head.transform.parent.GetComponent<ITakeDamage>();

                    damageableObject.Kill();
                }
            }

            I_AmmoInGun--;
            float recoilAmount = Random.Range(_f_MinVerticalRecoilPerShot, _f_MaxVerticalRecoilPerShot);
            _v2_Recoil = WeaponTransform.eulerAngles + recoilAmount * Vector3.right;
            ApplyVerticalRecoil();
        }
    }

    public void Reload()
    {
        if (CurrentState == WeaponState.Weapon_Reloading)
            return;

        CurrentState = WeaponState.Weapon_Reloading;
        if(I_AmmoInGun == 0)
        {
            _f_TimeToReload = Time.time + F_TacReloadTime;
        }
        else if(I_AmmoInGun > 0)
        {
            _f_TimeToReload = Time.time + F_ReloadTime;
        }
    }

    IEnumerator ShootAffect()
    {
        //put anything related to sound here
        yield return 0;
    }

    public void ApplyVerticalRecoil()
    {
        WeaponTransform.eulerAngles = Vector3.Lerp(WeaponTransform.eulerAngles, _v2_Recoil, recoilSmoothing * Time.deltaTime);
    }
}
