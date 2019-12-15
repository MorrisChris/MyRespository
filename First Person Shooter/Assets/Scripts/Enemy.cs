using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class Enemy : MonoBehaviour, ITakeDamage
{
    int Health = 100;

    // Start is called before the first frame update
    void Start()
    {
        
    }

    // Update is called once per frame
    void Update()
    {
        if(Health <= 0)
        {
            Kill();
        }
    }

    public void ApplyDamage(int Damage)
    {
        Health -= Damage;
    }

    public void Kill()
    {
        Destroy(this.gameObject);
    }
}
