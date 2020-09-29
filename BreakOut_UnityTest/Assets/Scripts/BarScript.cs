using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class BarScript : MonoBehaviour
{
    float bar_speed = 0.3f;     // バーの速度
    float bar_width;            // バーの横幅
    float right_frame_pos_x;    // 右側の外枠のX座標
    float left_frame_pos_x;     // 左側の外枠のX座標
    Transform BarTrans;

    // Start is called before the first frame update
    void Start()
    {
        BarTrans = GetComponent<Transform>();
        bar_width = GetComponent<Transform>().localScale.x / 2.0f;
        right_frame_pos_x = GameObject.Find("RightFrame").transform.position.x;
        left_frame_pos_x = GameObject.Find("LeftFrame").transform.position.x;
    }

    // Update is called once per frame
    void Update()
    {
        Vector3 pos = BarTrans.position;

        // 左キーで左に移動
        if (Input.GetKey(KeyCode.LeftArrow))
        {
            if(pos.x > left_frame_pos_x + bar_width)
            {
                this.transform.Translate(-bar_speed, 0.0f, 0.0f);
            }
        }

        // 右キーで右に移動
        if (Input.GetKey(KeyCode.RightArrow))
        {
            if(pos.x < right_frame_pos_x - bar_width)
            {
                this.transform.Translate(bar_speed, 0.0f, 0.0f);
            }            
        }

    }
}
