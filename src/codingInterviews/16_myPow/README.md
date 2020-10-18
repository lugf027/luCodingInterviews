solution_0 原理：

![快速幂解析（二分法角度）](./intro.png)



简单表示：

```c
for (int i = n; i != 0; i /= 2, x *= x) {
    if (i % 2 != 0) {
        //i是奇数
        result *= x;
    }
}
```

