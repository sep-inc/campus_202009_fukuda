using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class ShapeAABB : MonoBehaviour
{
    [SerializeField] public Vector3 size = new Vector3(1, 1, 1);

    public bool HitTest(ShapeAABB other)
    {
        // 2つのキューブのサイズの半分ずつの合計
        Vector3 sum_size = new Vector3((size.x / 2.0f) + (other.size.x / 2.0f),
            (size.y / 2.0f) + (other.size.y / 2.0f),
            (size.z / 2.0f) + (other.size.z / 2.0f));
        // 2つのキューブの距離
        Vector3 distance =
            new Vector3(Mathf.Abs(other.transform.position.x - transform.position.x),
            Mathf.Abs((other.transform.position.y - transform.position.y)),
            Mathf.Abs((other.transform.position.z - transform.position.z)));

        // 2つのキューブの距離がサイズの合計値よりも小さい場合、当たっている
        if(distance.x <= sum_size.x && distance.y <= sum_size.y && distance.z <= sum_size.z)
        {
            return true;
        }
        return false;
    }
}
