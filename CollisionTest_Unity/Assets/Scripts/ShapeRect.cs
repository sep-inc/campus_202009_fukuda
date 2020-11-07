using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class ShapeRect : MonoBehaviour
{
    [SerializeField] private Vector2 size = new Vector2(2.0f, 2.0f);

    public bool HitTest(ShapeRect other)
    {
        // 2つの矩形のサイズの半分ずつの合計
        float sum_x = (size.x / 2.0f) + (other.size.x / 2.0f);
        float sum_y = (size.y / 2.0f) + (other.size.y / 2.0f);
        // 2つの矩形の距離
        Vector2 distance = new Vector2(Mathf.Abs(other.transform.position.x - transform.position.x), Mathf.Abs(other.transform.position.y - transform.position.y));
        
        // 2つの矩形の距離がサイズの合計より小さい場合、当たっている
        if(distance.x <= sum_x && distance.y <= sum_y)
        {
            return true;
        }
        return false;
    }

    private void OnDrawGizmos()
    {
        Gizmos.DrawWireCube(transform.position,size);
    }

}
