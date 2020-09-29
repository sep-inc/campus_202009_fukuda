using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class BarScript : MonoBehaviour
{
    float bar_speed = 0.3f;
    // Start is called before the first frame update
    void Start()
    {   
    }

    // Update is called once per frame
    void Update()
    {
        Transform BarTrans = GameObject.Find("Bar").transform;
        Vector3 pos = BarTrans.position;

        // 左キーで左に移動
        if (Input.GetKey(KeyCode.LeftArrow))
        {
            if(pos.x > -25.0f + 3.5f)
            {
                this.transform.Translate(-bar_speed, 0.0f, 0.0f);
            }
        }

        // 右キーで右に移動
        if (Input.GetKey(KeyCode.RightArrow))
        {
            if(pos.x < 25.0f - 3.5f)
            {
                this.transform.Translate(bar_speed, 0.0f, 0.0f);
            }            
        }

    }
}
