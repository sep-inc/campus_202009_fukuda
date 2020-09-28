using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class SphereScript : MonoBehaviour
{
    float speed = 100.0f;
    Rigidbody rb;
    Vector3 force;

    int hp = 3;

    // Start is called before the first frame update
    void Start()
    {
        // Rigidbodyの取得
        rb = this.GetComponent<Rigidbody>();
        // 初速の設定
        force = new Vector3(10.0f * speed, 10.0f * speed, 0.0f);
    }


    // Update is called once per frame
    void Update()
    {
        // 球が動いていないなら（初期状態）
        if(rb.velocity == new Vector3(0.0f,0.0f,0.0f))
        {
            Vector3 bar_pos = GameObject.Find("Bar").transform.position;
            // X座標をバーのX座標に合わせる
            this.transform.position = new Vector3(bar_pos.x, 0.0f, 0.0f);
            // 球発射処理
            if (Input.GetKeyDown(KeyCode.Space))
            {
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
            Vector3 tmp = GameObject.Find("Sphere").transform.position;
            // 初期位置へ戻す
            GameObject.Find("Sphere").transform.position = new Vector3(0.0f, 0.0f, 0.0f);

            // 球の速度、回転をリセット
            rb.velocity = Vector3.zero;
            rb.angularVelocity = Vector3.zero;
            rb.ResetInertiaTensor();
            // Hpを減らす
            hp--;
        }
    }
}
