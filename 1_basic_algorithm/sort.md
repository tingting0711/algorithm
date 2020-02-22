# 排序

## 1 算法分类

- **比较类**排序：通过比较元素间的相对次序，来达到总体有序的方法。

  - O(N<sup>2</sup>)
    - 选择排序
    - 插入排序
    - 冒泡排序
  - O(Nlog<sub>2</sub>N)
    - 堆排序
    - 归并排序
    - 快速排序

- **非比较类**排序：通过非比较的方式进行排序

  - O(N + k)：N个 0~k 之间的数

    - 桶排序

    - 计数排序

    - 基数排序

      

## 2 算法性质分析

|  排序名称  |    平均时间复杂度    |    最坏时间复杂度    |     最好时间复杂度     | 空间复杂度 | 稳定性 |
| :--------: | :------------------: | :------------------: | :--------------------: | :--------: | :----: |
|  选择排序  |   O(N<sup>2</sup>)   |   O(N<sup>2</sup>)   |    O(N<sup>2</sup>)    |    O(1)    |  稳定  |
|  插入排序  |   O(N<sup>2</sup>)   |   O(N<sup>2</sup>)   | O(N) ~O(N<sup>2</sup>) |    O(1)    |  稳定  |
|  冒泡排序  |   O(N<sup>2</sup>)   |   O(N<sup>2</sup>)   | O(N) ~O(N<sup>2</sup>) |    O(1)    |  稳定  |
| 堆  排  序 | O(Nlog<sub>2</sub>N) | O(Nlog<sub>2</sub>N) |  O(Nlog<sub>2</sub>N)  |    O(1)    | 不稳定 |
|  归并排序  | O(Nlog<sub>2</sub>N) | O(Nlog<sub>2</sub>N) |  O(Nlog<sub>2</sub>N)  |     X      |  稳定  |
|  快速排序  | O(Nlog<sub>2</sub>N) |   O(N<sup>2</sup>)   |  O(Nlog<sub>2</sub>N)  |    O(1)    | 不稳定 |
| 桶  排  序 |       O(N + k)       |       O(N + k)       |        O(N + k)        |  O(N + k)  |        |
|  计数排序  |       O(N + k)       |       O(N + k)       |        O(N + k)        |  O(N + k)  |  稳定  |
|  基数排序  |       O(N + k)       |       O(N + k)       |        O(N + k)        |  O(N + k)  |        |

**稳定性**：相同元素的前后顺序是否会在排序后改变，若不变则称为稳定，否则不稳定。



## 3.1 冒泡排序 Bubble Sort

描述：

![bubbleSort](/Users/more/Desktop/19fall/algorithm2/1.%20%E5%9F%BA%E6%9C%AC%E7%AE%97%E6%B3%95/0x05%E6%8E%92%E5%BA%8F/img/bubbleSort.gif)

```c
#最初版O(N2)
void bubbleSort(verstor<int> &q)
{
		for(int i = q.size() - 1; i > 0; i--)
				for(int j = 0; j + 1 <= i; j++)
						if(q[j] < q[j + 1])swap(q[j], q[j + 1]);
}

#优化版O(N)
void bubbleSort(verstor<int> &q)
{
		for(int i = q.size() - 1; i > 0; i--)
				bool flag = false; //区间已有序
				for(int j = 0; j + 1 <= i; j++)
						if(q[j] < q[j + 1])swap(q[j], q[j + 1]);
				if(!flag)break;
}
```



## 3.2 选择排序 Selection Sort

描述：

![selectionSort](/Users/more/Desktop/19fall/algorithm2/1.%20%E5%9F%BA%E6%9C%AC%E7%AE%97%E6%B3%95/0x05%E6%8E%92%E5%BA%8F/img/selectionSort.gif)

```c
void selectionSort(verstor<int> &q)
{
		for(int i = 0; i < q.size(); i++)
				for(int j = i + 1; j <= q.size(); j++)
						if(q[i] > q[j])swap(q[i], q[j]);
}
```



## 3.3 插入排序 Insertion Sort

描述：从后往前排序

![insertionSort](/Users/more/Desktop/19fall/algorithm2/1.%20%E5%9F%BA%E6%9C%AC%E7%AE%97%E6%B3%95/0x05%E6%8E%92%E5%BA%8F/img/insertionSort.gif)

```
#从后往前排序
void insertionSort(verstor<int> &q)
{
		for(int i = 1; i < q.size(); i++)
				int t = q[i], j;
				for(j = i - 1; j >= 0 && q[j] > t; j--)
						q[j + 1] = q[j];
				q[j + 1] = t;
}
```



## 3.4 归并排序 Merge Sort

描述：

![mergeSort](./img/mergeSort.gif)

- top down
  - array     O(N + logN)
  - list         O(logN)
- bottom up 省去栈空间
  - array      O(N)
  - list          O(1)

```
void mergeSort(vector<int> &q, int l, int r)
{
		if(l >= r)return;
		int mid = (l + r)/2;
		mergeSort(q, l, mid);
		mergeSort(1, mid + 1, r);
		
		static vector<int>w;
		w.clear();
		
		int i = l, j = mid + 1;
		while(i <= mid && j <= r)
		{
				if(q[i] <= q[j])
						w.push_back(q[i++]);
				else
						w.push_back(q[j++]);
		}
		while(i <= mid)w.push_back(q[i++]);
		while(j <= r)w.push_back(q[j++]);
		for(i = l, j = 0; j < w.size(); i++, j++)q[i] = w[j];
}
```



## 3.5 快速排序 Quick Sort

描述：分而治之

![quickSort](./img/quickSort.gif)

```
void quickSort(vector<int>&q, int l, int r)
{
		if(l >= r)return; 
		int x = q[l + r >> 1], i = l - 1, j = r + 1;
		while(i < j)
		{
				do i++;while(q[i] < x);
				do j--;while(q[j] > x);
				if(i < j)swap(q[i], q[j]);
				else quickSort(q, l, j), quickSort(q, j + 1, r);
		}
}
```



## 3.6 堆排序 Heap Sort

描述：

![heapSort](/Users/more/Desktop/19fall/algorithm2/1.%20%E5%9F%BA%E6%9C%AC%E7%AE%97%E6%B3%95/0x05%E6%8E%92%E5%BA%8F/img/heapSort.gif)



```
void down(vector<int>&heap, int size, int u)
{
		int t = u, left = u * 2, right = u * 2 + 1;
		if(left <= size && heap[left] > heap[t])t = left;
		if(right <= size && heap[right] > heap[t]) t = right;
		if(t != u)
		{
				swap(heap[u], heap[t]);
				down(heap, size, t);
		}
}
void up(vector<int>&heap, int size, int u)
{
		while(u / 2 && heap[u / 2] < heap[u])
		{
				swap(heap[u / 2], heap[u]);
				u /= 2;
		}
}
void insert(vector<int>&heap, int &size, int x)
{
		heap[++size] = x;
		up(heap, size, x);
}
void remove_top(vector<int>&heap, int &size)
{
		heap[1] = heap[size];
		size --;
		down(heap, size, 1);
}
void heap_sort(vector<int>&q, int size)
{
		for(int i = 1; i <= size; i++)up(q, size, i);
		for(int i = 1; i <= size; i++)
		{
				swap(q[1], q[size]);
				size --;
				down(q, size, 1);
		}
}

```



## 3.7 计数排序 Counting Sort

描述：数据范围略小或约等于数据的个数

![countingSort](/Users/more/Desktop/19fall/algorithm2/1.%20%E5%9F%BA%E6%9C%AC%E7%AE%97%E6%B3%95/0x05%E6%8E%92%E5%BA%8F/img/countingSort.gif)

```
void countingSort(vector<int>&q, int n)
{
		vector<int>cnt(101, 0);
		for(int i = 0; i < n; i++)cnt[q[i]]++;
		for(int i = 0, k = 0; i < 100; i++)
		{
				while(cnt[i])
				{
						q[k++] = i;
						cnt[i]--;
				}
		}
}
```



## 3.8 桶排序 Bucket Sort

描述：将超大范围数据映射到若干个桶，使得桶间有序，桶内无序，对于桶内元素再做排序算法。

![bucketSort](/Users/more/Desktop/19fall/algorithm2/1.%20%E5%9F%BA%E6%9C%AC%E7%AE%97%E6%B3%95/0x05%E6%8E%92%E5%BA%8F/img/bucketSort.png)



## 3.9 基数排序 Radix Sort

描述：

![radixSort](/Users/more/Desktop/19fall/algorithm2/1.%20%E5%9F%BA%E6%9C%AC%E7%AE%97%E6%B3%95/0x05%E6%8E%92%E5%BA%8F/img/radixSort.gif)

```
void get(int x, int i)
{
		// /、%很慢， 基数排序常数很大，不实用
		while(i--)x /= 10;  
		return x % 10;
}
void radixSort(vector<int>&q, int n)
{
		vector<vector<int>>cnt(10);
		for(int i = 0; i < 3; i++)
		{
				for(int j = 0; j < 10; j++)cnt[j].clear();
				
				for(int j = 1; j <= n; j++)
						cnt[get(q[j], i)].push_back(q[j]);
						
				for(int j = 0, k = 1; j <= 10; j++)
						for(int x:cnt[j])
								q[k++] = x;
		}
}
```



## 4 参考资料

- https://www.cnblogs.com/onepixel/p/7674659.html



