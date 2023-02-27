#include <stdio.h>

int Partition(int arr[], int low, int high) {
	int temp = arr[low];
	while (low < high) {
		while (low < high && arr[high] >= temp) {
			--high;
		}
		arr[low] = arr[high];
		while (low < high && arr[low] <= temp) {
			++low;
		}
		arr[high] = arr[low];
	}
	arr[low] = temp;
	return low;
}

void QuickSort(int ARR[], int first, int end) {
	int pivot;
	if (first < end) {
		pivot = Partition(ARR, first, end);
		QuickSort(ARR, first, pivot - 1);
		QuickSort(ARR, pivot + 1, end);
	}
}

int main() {
	int n = 7;
	int arr[10] = {49, 38, 65, 93, 76, 13, 27, 49};
	QuickSort(arr, 1, n);
	printf("快速排序后的结果为：\n");
	for (int i = 1; i <= n; i++) {
		printf("%d\n", arr[i]);
	}
	return 0;
}
