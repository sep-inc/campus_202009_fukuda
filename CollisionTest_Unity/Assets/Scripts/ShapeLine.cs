using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class ShapeLine : MonoBehaviour
{
    [SerializeField] public GameObject start_point; // 始点のオブジェクト
    [SerializeField] public GameObject end_point;   // 終点のオブジェクト

    
    public bool HitTest(ShapeLine other)
    {
        // 線分1の始点、終点
        Vector2 s1 = start_point.transform.position;
        Vector2 e1 = end_point.transform.position;
        // 線分2の始点、終点
        Vector2 s2 = other.start_point.transform.position;
        Vector2 e2 = other.end_point.transform.position;

        // 線分1のベクトル
        var vec1 = e1 - s1;
        // 線分2のベクトル
        var vec2 = e2 - s2;

        /*
         * 線分1、2の始点と互いの始点、終点とのベクトルの外積の
         * 結果が異なる符号同士なら交差している
        */
        if(Cross(vec1,s2 - s1) * Cross(vec1,e2 - s1) < 0 && 
            Cross(vec2,s1 - s2) * Cross(vec2,e1 - s2) < 0)
         {
             return true;
         }
         return false;
    }

    // 2次元ベクトルの外積を返す関数
    private static float Cross(Vector2 vector1_,Vector2 vector2_)
    {
        return vector1_.x * vector2_.y - vector1_.y * vector2_.x;
    }
    
}

