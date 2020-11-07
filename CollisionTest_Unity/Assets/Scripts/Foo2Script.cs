using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class Foo2Script : MonoBehaviour
{
    // 球
    [SerializeField] private ShapeSphere sphere1 = default;
    [SerializeField] private ShapeSphere sphere2 = default;
    // キューブ
    [SerializeField] private ShapeAABB cube1 = default;
    [SerializeField] private ShapeAABB cube2 = default;
   
    private void OnDrawGizmos()
    {
        // 球
        Gizmos.color = sphere1.HitTest(sphere2) ? Color.red : Color.white;
        Gizmos.DrawWireSphere(sphere1.transform.position, sphere1.transform.localScale.x / 2.0f);
        Gizmos.DrawWireSphere(sphere2.transform.position, sphere2.transform.localScale.x / 2.0f);
        Gizmos.DrawLine(sphere1.transform.position, sphere2.transform.position);

        // キューブ
        Gizmos.color = cube1.HitTest(cube2) ? Color.red : Color.white;
        Gizmos.DrawWireCube(cube1.transform.position, cube1.size);
        Gizmos.DrawWireCube(cube2.transform.position, cube2.size);
        Gizmos.DrawLine(cube1.transform.position, cube2.transform.position);

    }

}
