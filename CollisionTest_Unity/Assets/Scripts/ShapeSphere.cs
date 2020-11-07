using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class ShapeSphere : MonoBehaviour
{
    [SerializeField] private float radius = 0.5f;

   public bool HitTest(ShapeSphere other)
    {
        // 2つの球の半径の合計値
        float sum_radius = radius + other.radius;
        // 2つの球の距離
        float distance = 
            Mathf.Sqrt(Mathf.Pow(other.transform.position.x - transform.position.x, 2) +
            Mathf.Pow(other.transform.position.y - transform.position.y, 2) +
            Mathf.Pow(other.transform.position.z - transform.position.z, 2));

        // 2つの球の距離が半径の合計値よりも小さい場合、当たっている
        if(distance <= sum_radius)
        {
            return true;
        }
        return false;
    }

}
