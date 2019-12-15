using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public interface ITakeDamage
{
    void ApplyDamage(int Damage);

    void Kill();
}
