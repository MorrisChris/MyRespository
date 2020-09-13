using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class Rotator : MonoBehaviour
{
    public GameObject ParentPlanet;

    // Start is called before the first frame update
    void Start()
    {
        
    }

    // Update is called once per frame
    void Update()
    {
        Vector3 RaycastDir = (ParentPlanet.transform.position - transform.position).normalized;
        RaycastHit raycastHit;
        Debug.DrawRay(transform.position, RaycastDir,Color.red);
        if (Physics.Raycast(transform.position,RaycastDir, out raycastHit, 100))
        {
            transform.LookAt(ParentPlanet.transform, -RaycastDir);
        }
    }
}
