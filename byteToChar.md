```c#
using System.Collections;
using System.Collections.Generic;
using UnityEngine;
using System.Text; //System.Text에 있는 Encoding 사용

public class arrayTest : MonoBehaviour
{
    [Header("byte[] to char[]")]
    public byte[] buffer = new byte[64];
    public char[] str;

    [Header("char[] to byte[]")]
    public byte[] buf;
    public char[] ch;

    void Start()
    {
        // byte[] to char[]
        buffer = Encoding.UTF8.GetBytes("sdfasdf");
        Debug.Log("buffer:" + buffer);
        str = Encoding.UTF8.GetString(buffer).ToCharArray();  //문자열로 변환 후 char 배열로 변환해야 함
        for (int i = 0; i < str.Length; i++)
        {
            Debug.Log(str[i]);
        }

        //char[] to byte[]
        ch = "hiasdf00".ToCharArray();
        buf = Encoding.UTF8.GetBytes(ch);

        Debug.Log("buf:" + buf);


        //another Encoding type
        byte[] tmp1 = Encoding.ASCII.GetBytes(ch);
        Debug.Log(tmp1);

        string s_tmp1 = Encoding.ASCII.GetString(tmp1);
        Debug.Log(s_tmp1);
    }
}
```
