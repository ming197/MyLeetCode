# [Binary Indexed Tree](https://halfrost.com/binary_indexed_tree/)

[维基百科](https://zh.m.wikipedia.org/zh-sg/%E6%A0%91%E7%8A%B6%E6%95%B0%E7%BB%84)

## 预备函数

定义一个 $\mathrm{lowbit}$ 函数，返回参数转为二进制后,最后一个1的位置所代表的数值。

```c++
int lowbit(int x)
{
    return x&(-x);
}
```

## 树状数组

定义一个数组 BIT，用以维护${\displaystyle A}$的前缀和，则：
${\displaystyle BIT_{i} = \sum_{j=i-lowbit(i)+1}^{i} A_{j}}$

```c++
void build()
{ 
    for (int i = 1; i <= MAX_N; i++)
    {
        BIT[i] = A[i - 1];
        for (int j = i - 2; j >= i - lowbit(i); j--)
            BIT[i] += A[j];
    }
}
//注：这里的求和将汇集到非终端结点（D00形式）
//BIT中仅非终端结点i值是 第0~i元素的和
//终端结点位置的元素和，将在求和函数中求得
//BIT中的index，比原数组中大1
```

## 修改

假设现在要将${\displaystyle A[i]}$的值增加delta，那么，需要将${\displaystyle BIT[i]}$覆盖的区间包含${\displaystyle A[i]}$的值都加上delta，需要计算的次数与数据规模N的位元数有关，即这部分的时间复杂度是${\displaystyle O(\log {N})}$。

```c++
void edit(int i, int delta)
{
    for (int j = i; j <= MAX_N; j += lowbit(j))
        BIT[j] += delta;
}
```

## 求和

```c++
int sum (int k)
{
    int ans = 0;
    for (int i = k; i > 0; i -= lowbit(i))
        ans += BIT[i];
    return ans;
}
```
