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
    public float _f_MaxVerticalRecoil;
    public float _f_MinVerticalRecoil;
    public float _f_MaxHorizontalRecoil;
    public float _f_MinHorizontalRecoil;
    public Transform WeaponTransform;


    // Start is called before the first frame update
    void Start()
    {
        _f_TimeBetweenShots = 60.0f / I_FireRate;
        CurrentState = WeaponState.Weapon_Ready;
        _v2_Recoil = Vector2.zero;
        WeaponTransform = transform.parent.transform;
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
                if(I_AmmoInGun > 0)
                {
                    I_AmmoInGun = I_Capacity + 1;
                }

                CurrentState = WeaponState.Weapon_Ready;
            }
        }

        ApplyVerticalRecoil();
    }

    public void Shoot()
    {
        if (TimeToNextShot < Time.time && CurrentState == WeaponState.Weapon_Ready)
        {
            TimeToNextShot = Time.time + _f_TimeBetweenShots;
            StartCoroutine(ShootAffect());

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
            _v2_Recoil.y += Random.Range(_f_MinVerticalRecoil, _f_MaxVerticalRecoil);
            _v2_Recoil.x += Random.Range(_f_MinHorizontalRecoil, _f_MaxHorizontalRecoil);
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
        yield return _f_TimeBetweenShots;
    }

    public void ApplyVerticalRecoil()
    {
        if(_v2_Recoil.y > 0 || _v2_Recoil.y < 0)
        {
            Quaternion maxRecoil = Quaternion.Euler(_v2_Recoil.y, 0, 0);
            WeaponTransform.rotation = Quaternion.Slerp(WeaponTransform.rotation, maxRecoil, Time.deltaTime * _f_TimeBetweenShots);
            _v2_Recoil.y -= Time.deltaTime;
        }
        else
        {
            _v2_Recoil.y = 0;
            Quaternion minRecoil = Quaternion.Euler(0, 0, 0);
            WeaponTransform.rotation = Quaternion.Slerp(WeaponTransform.rotation, minRecoil, Time.deltaTime / 2);

        }
    }
}
