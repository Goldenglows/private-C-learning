#include <stdio.h>
#include <stdlib.h>
#include <math.h>

//插入排序
/*
是一种简单直观的排序算法，
它的基本思想是：将未排序的元素一个一个插入已排序的序列中，
直到所有元素都有序为止。
具体实现过程是：首先将第一个元素看作已排序的序列，
然后依次将后面的元素插入已排序的序列中。
*/
/*
void insertionSort(int arr[], int size) {
	for (int i = 1; i < size; i++) {
		int key = arr[i];
		int j = i - 1;
		while (j >= 0 && arr[j] > key) {
			arr[j + 1] = arr[j];//所有大于38的要右移一位
			j--;
		}
		arr[j + 1] = key;
	}
}
*/
	
//希尔排序
/*
是一种改进版的插入排序算法，
它通过将待排序的元素分组，然后依次对每个分组进行插入排序，
从而使得整个序列逐渐有序。
具体实现过程是：首先将相距一定间隔的元素分为一组，
对每组进行插入排序；然后将间隔逐渐缩小，
重复上述操作，直到间隔缩小到1为止。
*/
/*
void shellSort(int arr[], int size) {
	int gap = size / 2;
	while (gap > 0) {
		for (int i = gap; i < size; i++) {
			int temp = arr[i];
			int j = i - gap;
			while (j >= 0 && arr[j] > temp) {
				arr[j + gap] = arr[j];
				j -= gap;
			}
			arr[j + gap] = temp;
		}
		gap /= 2;
	}
}
*/

//冒泡排序
/*
是一种基本的排序算法，它重复地遍历待排序的数组，
每次比较相邻的两个元素，如果它们的顺序错误就交换它们的位置，
直到整个序列变得有序。
*/
/*
void bubbleSort(int arr[], int size) {
	for (int i = 0; i < size - 1; i++) {
		for (int j = 0; j < size - i - 1; j++) {
			if (arr[j] > arr[j + 1]) {
				int temp = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = temp;
			}
		}
	}
}
*/

//快速排序
/*
是一种基于分治思想的排序算法。
它的基本思想是选择一个基准元素，将数组分成两部分，
一部分所有元素都小于基准元素，另一部分所有元素都大于基准元素，
然后对这两部分分别递归进行快速排序。
*/
void swap(int* a, int* b) {
	int temp = *a;
	*a = *b;
	*b = temp;
}

int partition(int arr[], int low, int high) {
	int n = arr[high];
	int i = low - 1;
	for (int j = low; j < high; j++) {
		if (arr[j] <= n) {
			i++;
			swap(&arr[i], &arr[j]);
		}
	}
	swap(&arr[i + 1], &arr[high]);
	return i + 1;
}

void quickSort(int arr[], int low, int high) {
	if (low < high) {
		int pi = partition(arr, low, high);
		quickSort(arr, low, pi - 1);
		quickSort(arr, pi + 1, high);
	}
}

//简单选择排序
/*
是一种简单但低效的排序算法，
其基本思想是每次从未排序的部分中选择最小的元素，
并将其放到已排序部分的末尾。
*/
/*
void selectionSort(int arr[], int size) {
	int i, j, minIndex;
	for (i = 0; i < size - 1; i++) {
		minIndex = i;
		for (j = i + 1; j < size; j++) {
			if (arr[j] < arr[minIndex]) {
				minIndex = j;
			}
		}
		swap(&arr[minIndex], &arr[i]);
	}
}
*/

//堆排序
/*
是一种基于堆数据结构的排序算法，
其基本思想是将待排序序列构造成一个大顶堆或小顶堆，
然后依次将堆顶元素取出，直到堆为空，就得到了一个有序序列。
*/
/*
void heapify(int arr[], int size, int root) {
	int largest = root;
	int left = 2 * root + 1;
	int right = 2 * root + 2;

	if (left < size && arr[left] > arr[largest]) {
		largest = left;
	}

	if (right < size && arr[right] > arr[largest]) {
		largest = right;
	}

	if (largest != root) {
		swap(&arr[root], &arr[largest]);
		heapify(arr, size, largest);
	}
}

void heapSort(int arr[], int size) {
	for (int i = size / 2 - 1; i >= 0; i--) {
		heapify(arr, size, i);
	}

	for (int i = size - 1; i >= 0; i--) {
		swap(&arr[0], &arr[i]);
		heapify(arr, i, 0);
	}
}
*/

//归并排序
/*
是一种基于分治思想的排序算法，
其基本思想是将待排序序列分成两个子序列，
分别对两个子序列进行排序，
然后将两个排好序的子序列合并成一个有序序列。
*/

/*
void merge(int arr[], int left, int mid, int right) {
	int i, j, k;
	int n1 = mid - left + 1;
	int n2 = right - mid;
	int L[n1], R[n2];

	for (i = 0; i < n1; i++) {
		L[i] = arr[left + i];
	}

	for (j = 0; j < n2; j++) {
		R[j] = arr[mid + 1 + j];
	}

	i = 0;
	j = 0;
	k = left;

	while (i < n1 && j < n2) {
		if (L[i] <= R[j]) {
			arr[k] = L[i];
			i++;
		}
		else {
			arr[k] = R[j];
			j++;
		}
		k++;
	}

	while (i < n1) {
		arr[k] = L[i];
		i++;
		k++;
	}

	while (j < n2) {
		arr[k] = R[j];
		j++;
		k++;
	}
}

void mergeSort(int arr[], int left, int right) {
	if (left < right) {
		int mid = left + (right - left) / 2;
		mergeSort(arr, left, mid);
		mergeSort(arr, mid + 1, right);
		merge(arr, left, mid, right);
	}
}
*/

//基数排序
/*
该实现使用了桶的概念，依次按个位、十位、百位...排序，
每次将数字放入相应的桶中，再将桶中的数字按顺序取出放回数组。
*/
// 获取一个数在指定位数上的数字
/*
int get_digit(int number, int digit) {
	int i;
	for (i = 0; i < digit - 1; i++) {
		number /= 10;
	}
	return number % 10;
}

// 基数排序函数
void radix_sort(int* arr, int len) {
	int i, j, k;
	int bucket[10][len], count[10];
	int max_digit = 1, digit;

	// 获取数组中最大的位数
	for (i = 0; i < len; i++) {
		digit = 1;
		while (arr[i] / 10 >= digit) {
			digit *= 10;
		}
		if (digit > max_digit) {
			max_digit = digit;
		}
	}

	// 进行排序
	for (digit = 1; digit <= max_digit; digit *= 10) {
		for (i = 0; i < 10; i++) {
			count[i] = 0;
		}

		// 将数字放入相应的桶中
		for (i = 0; i < len; i++) {
			bucket[get_digit(arr[i], digit)][count[get_digit(arr[i], digit)]] = arr[i];
			count[get_digit(arr[i], digit)]++;
		}

		// 将桶中的数字按顺序取出放回数组
		k = 0;
		for (i = 0; i < 10; i++) {
			for (j = 0; j < count[i]; j++) {
				arr[k] = bucket[i][j];
				k++;
			}
		}
	}
}
*/


int main()
{
	int arr[] = { 6,7,5,2,6,1 };
	int size = sizeof(arr) / sizeof(int);

	//插入排序
	/*
	printf("插入排序的结果是：");
	printf("\n");
	insertionSort(arr, size);
	for (int i = 0; i < size; i++) {
		printf("%d ", arr[i]);
	}
	printf("\n");

	//希尔排序
	printf("希尔排序的结果是：");
	printf("\n");
	shellSort(arr, size);
	for (int i = 0; i < size; i++) {
		printf("%d ", arr[i]);
	}
	printf("\n");

	//冒泡排序
	printf("冒泡排序的结果是：");
	printf("\n");
	bubbleSort(arr, size);
	for (int i = 0; i < size; i++) {
		printf("%d ", arr[i]);
	}
	printf("\n");

	*/

	//快速排序
	printf("快速排序的结果是：");
	printf("\n");
	quickSort(arr, 0, size - 1);
	for (int i = 0; i < size; i++) {
		printf("%d ", arr[i]);
	}
	printf("\n");

	/*
	//简单选择排序
	printf("简单选择排序的结果是：");
	printf("\n");
	selectionSort(arr, size);
	for (int i = 0; i < size; i++) {
		printf("%d ", arr[i]);
	}
	printf("\n");

	//堆排序
	printf("堆排序的结果是：");
	printf("\n");
	heapSort(arr, size);
	for (int i = 0; i < size; i++) {
		printf("%d ", arr[i]);
	}
	printf("\n");

	//归并排序
	/*
	printf("归并排序的结果是：");
	printf("\n");
	mergeSort(arr, 0, size - 1);
	for (int i = 0; i < size; i++) {
		printf("%d ", arr[i]);
	}
	printf("\n");
	*/

	
	//基数排序
	/*
	printf("基数排序的结果是：");
	printf("\n");
	radix_sort(arr, size);
	int i;
	for (i = 0; i < size; i++) {
		printf("%d ", arr[i]);
	}
	printf("\n");
	*/

	return 0;

}