using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class ShapeCircle : MonoBehaviour
{
    [SerializeField] private float radius = 1.0f;

    // 円との当たり判定
    public bool HitTest(ShapeCircle other)
    {
        // 2つの円の半径の合計値
        float sum_radius = radius + other.radius;
        // 2つの円の距離
        float distance =
            Mathf.Sqrt(Mathf.Pow(other.transform.position.x - transform.position.x, 2) +
            Mathf.Pow(other.transform.position.y - transform.position.y, 2));

        // 2つの円の距離が、半径の合計値より小さい場合、当たっている
        if (distance <= sum_radius)
        {
            return true;
        }
        return false;
    }

    // 矩形との当たり判定
    public bool HitTest(ShapeRect other)
    {
        // 矩形の左上頂点
        Vector2 rect_vertex1 = 
            new Vector2(other.transform.position.x - (other.transform.localScale.x / 2.0f), other.transform.position.y - (other.transform.localScale.y / 2.0f));

        // 矩形の右下頂点
        Vector2 rect_vertex2 =
            new Vector2(other.transform.position.x + (other.transform.localScale.x / 2.0f), other.transform.position.y + (other.transform.localScale.y / 2.0f));

        // 矩形の横幅 + 円のサイズ分の矩形との当たり判定
        if(rect_vertex1.x - radius <= transform.position.x &&
            transform.position.x <= rect_vertex2.x + radius &&
            rect_vertex1.y <= transform.position.y &&
            transform.position.y <= rect_vertex2.y)
        {
            return true;
        }
        // 矩形の縦幅 + 円のサイズ分の矩形との当たり判定
        if(rect_vertex1.x <= transform.position.x &&
            transform.position.x <= rect_vertex2.x &&
            rect_vertex1.y - radius <= transform.position.y &&
            transform.position.y <= rect_vertex2.y + radius)
        {
            return true;
        }

        // 左上頂点
        float distance = Mathf.Sqrt(Mathf.Pow(transform.position.x - rect_vertex1.x, 2) + Mathf.Pow(transform.position.y - rect_vertex1.y, 2));
        if(distance <= radius)
        {
            return true;
        }
        // 右上頂点
        distance = Mathf.Sqrt(Mathf.Pow(transform.position.x - rect_vertex2.x, 2) + Mathf.Pow(transform.position.y - rect_vertex1.y, 2));
        if(distance <= radius)
        {
            return true;
        }
        // 左下頂点
        distance = Mathf.Sqrt(Mathf.Pow(transform.position.x - rect_vertex1.x, 2) + Mathf.Pow(transform.position.y - rect_vertex2.y, 2));
        if (distance <= radius)
        {
            return true;
        }
        // 右下頂点
        distance = Mathf.Sqrt(Mathf.Pow(transform.position.x - rect_vertex2.x, 2) + Mathf.Pow(transform.position.y - rect_vertex2.y, 2));
        if (distance <= radius)
        {
            return true;
        }

        return false;
    }

    private void OnDrawGizmos()
    {
        Gizmos.DrawWireSphere(transform.position, radius);
    }

}
