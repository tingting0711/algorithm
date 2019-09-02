# 数学知识

## 质数

**定义**：在**大于1**的整数中， 如果只包含1和本身这两个约数，称为质数/素数。

> 试除法 O(N)  / O(sqrt(N))  

```
# O(N)
bool is_prime(int n)
{
	if(n < 2)return false;
	for(int i = 2; i < n i++)
	{
		if(n % i == 0)return false;
	}
	return true;
}

# O(sqrt(N)) 
bool is_prime(int n)
{
	if(n < 2)return false;
	for(int i = 2; i <= n / i; i++)  # i <= sqrt(n)比较慢 或 i * i <= n  i*i存在溢出风险,为负数
	{
		if(n % i == 0)return false;
	}
	return true;
}
```

> 分解质因数 O(logN)   ~  O(sqrt(N))  

```
void divide(int x)
{
	for(int i = 2; i <= n / i; i++)
		if(n % i == 0) #i一定是质数
		{
			int s = 0;
			while(n % i == 0)
			{
				n /= i;
				s ++;
			}
			cout<<i<<" "<<s<<endl;
		}
	if(n > 1)cout<<n<<" "<<1<<endl;
	cout<<endl;
}
```

> 筛质数  O(NlogN)  ~  O(N)   埃氏筛法

```
const int N = 1000010;
int primes[N], cnt;
bool st[N];

#O(NlogN)
void get_primes(int n)
{
	for(int i = 2; i <= n; i++)
	{
		if(!st[i])
		{
			primes[cnt++] = n;
		}
		for(int j = i + i; i <= n; j += i)st[j] = true;
	}
}

#埃氏筛法
#O(NlnloglogN) ~= O(N) 当一个数不是质数时，不需要筛掉其倍数
void get_primes(int n)
{
	for(int i = 2; i <= n; i++)
	{
		if(!st[i])
		{
			primes[cnt++] = n;
			for(int j = i + i; i <= n; j += i)st[j] = true;
		}
	}
}
```

> 筛质数  O(NlogN)  ~  O(N)   线性筛法

```
# n 只会被最小质因子筛掉
void get_primes(int n)
{
	for(int i = 2; i <= n; i++)
	{
		if(!st[i])primes[cnt ++] = i;
		for(int j = 0; primes[j] <= n / i; j++)
		{
			st[primes[j] * i] = true;    //primes[j]一定是primes[j] * i的最小质因子
			if(i % primes[j] == 0)break; //primes[j]一定是i的最小质因子
		}
	}
}

#每个数都只会被它的最小质因子筛除，每个数只有一个最小质因子，故时间为线性
```

当 N = 10<sup>6</sup> 时，埃氏筛法和线性筛法一致； 当 N = 10<sup>7</sup>时，线性比埃氏快一倍

- i % pj == 0
  - pj一定是i的最小质因子， pj一定是pj*i 的最小质因子
- i % pj != 0
  - pj一定小于i的所有质因子，pj也一定是 pj*i的最小质因子



## 约数

> 试除法  O(sqrt(N))

```
#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

vector<int> get_divisors(int n)
{
	vector<int>res;
	for(int i = 1; i <= n / i; i++)
	if(n % i == 0)
	{
		res.push_back(i);
		if(i != n / i)res.push_back(n / i);
	}
}
```

> 约数个数

如果N = P1<sup>a1</sup> * P2<sup>a2</sup> * …… *Pk<sup>ak</sup>， 则N有(a1 + 1) * (a2 + 1) * ...... * (ak + 1)个约数



> 约数之和

如果N = P1<sup>a1</sup> * P2<sup>a2</sup> * …… *Pk<sup>ak</sup>， 则约数之和为(p1<sup>0</sup> + p1<sup>1</sup> + … + p1<sup>a1</sup> ) *… *  (pk<sup>0</sup> + pk<sup>1</sup> + … + pk<sup>ak</sup> )



> 欧几里得算法  — 辗转相除法  O(logN)

```
int gcd(int a, int b)
{
	return b ? gcd(b, a % b) : a;
}
```



## 欧拉函数

fi(n) = 1 ~ n中所有和n互质的个数

eg: fi(6) =( 1, 5 )= 2

![欧拉函数](/Users/more/Desktop/19fall/刷题/github/algorithm/4_math/欧拉函数.png)

> 公式法求欧拉函数 O(sqrt(N))

```
int main()
{
	int n;
	cin>>n;
	while(n --)
	{
		int a;
		cin>>a;
		int res = a;
		for(int i = 2; i <= a / i; i++)
		{
			if(a % i ==0)
			{
				res = res / i * (i - 1);
				while(a % i ==0) a /= i;
			}
		}
		if(a > 1)res = res / a * (a - 1);
		cout<<res<<endl;
	}
}
```

> 筛法求欧拉函数 O(N) 

```
#求1~N中所有数的欧拉函数

#include<iostream>
#include<algorithm>
using namespace std;
typedef long long LL;
const int N = 1000010;
int primes[N], cnt;
int phi[N];
bool st[N];

LL get_eulers(int n)
{
	for(int i = 2; i <= n; i++)
	{
		if(!st[i])
		{
			primes[cnt ++] = i;
			phi[i] = i - 1;
			for(int j = 0; primes[j] <= n / i; j++)
			{
				st[primes[j] * i] = true;
				if(i % primes[j] == 0)break;
			}
		}
	}
}
```




## 快速幂



## 扩展欧几里得算法



## 中国剩余定理



## 高斯消元



## 求组合数



## 容斥原理



## 博弈论

