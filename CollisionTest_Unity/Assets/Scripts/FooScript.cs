using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class FooScript : MonoBehaviour
{
    // 円
    [SerializeField] private ShapeCircle circle1 = default;
    [SerializeField] private ShapeCircle circle2 = default;

    // 矩形
    [SerializeField] private ShapeRect rect1 = default;
    [SerializeField] private ShapeRect rect2 = default;

    // 線分
    [SerializeField] private ShapeLine line1 = default;
    [SerializeField] private ShapeLine line2 = default;

    private void OnDrawGizmos()
    {
        // 円
        Gizmos.color = circle1.HitTest(circle2) ? Color.red : Color.white;
        Gizmos.DrawLine(circle1.transform.position, circle2.transform.position);
        Gizmos.color = circle1.HitTest(rect1) ? Color.red : Color.white;
        Gizmos.DrawLine(circle1.transform.position, rect1.transform.position);
        Gizmos.color = circle1.HitTest(rect2) ? Color.red : Color.white;
        Gizmos.DrawLine(circle1.transform.position, rect2.transform.position);

        // 矩形
        Gizmos.color = rect1.HitTest(rect2) ? Color.red : Color.white;
        Gizmos.DrawLine(rect1.transform.position, rect2.transform.position);

        // 線分
        Gizmos.color = line1.HitTest(line2) ? Color.red : Color.white;
        Gizmos.DrawLine(line1.start_point.transform.position, line1.end_point.transform.position);
        Gizmos.DrawLine(line2.start_point.transform.position, line2.end_point.transform.position);

    }
}
