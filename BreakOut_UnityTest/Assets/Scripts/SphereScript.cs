using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class SphereScript : MonoBehaviour
{
    float speed = 1000.0f;   // 球の速度
    bool is_move = false;   // 球が動いているかどうかの変数
    int hp = 3;             // 球のHP
    float sphere_offset_pos_y = 5.0f;   // バーと親子関係になっている際の座標のオフセット値
    GameObject bar_obj; 
    Rigidbody rb;
    Vector3 force;

    // Start is called before the first frame update
    void Start()
    {
        // Rigidbodyの取得
        rb = this.GetComponent<Rigidbody>();
        // 初速の設定
        force = new Vector3(speed, speed, 0.0f);
        // バーを取得
        bar_obj = GameObject.Find("Bar");
    }


    // Update is called once per frame
    void Update()
    {
        // 球が動いていないなら（初期状態）
        if(is_move == false)
        {
            // バーと親子関係にする
            transform.parent = bar_obj.transform;
            // 球発射処理
            if (Input.GetKeyDown(KeyCode.Space))
            {
                is_move = true;
                // 親子関係の解除
                transform.parent = null;
                rb.AddForce(force);
            }
        }

        // Hpが0になったら球を消す
        if(hp == 0)
        {
            Destroy(gameObject);
        }
        
        
    }

    private void OnTriggerEnter(Collider other)
    {
        // 下の壁（tag : Finish）に当たったら
        if (other.CompareTag("Finish"))
        {
            // バーの現在地に移動
            transform.position = new Vector3(bar_obj.transform.position.x, bar_obj.transform.position.y + sphere_offset_pos_y, 0.0f);
            // 球の速度、回転をリセット
            rb.velocity = Vector3.zero;
            rb.angularVelocity = Vector3.zero;
            rb.ResetInertiaTensor();
            // Hpを減らす
            hp--;
            is_move = false;
        }
    }
}
