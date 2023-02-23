#include <stdio.h>
#include <stdlib.h>
#include <math.h>

//��������
/*
��һ�ּ�ֱ�۵������㷨��
���Ļ���˼���ǣ���δ�����Ԫ��һ��һ������������������У�
ֱ������Ԫ�ض�����Ϊֹ��
����ʵ�ֹ����ǣ����Ƚ���һ��Ԫ�ؿ�������������У�
Ȼ�����ν������Ԫ�ز���������������С�
*/
/*
void insertionSort(int arr[], int size) {
	for (int i = 1; i < size; i++) {
		int key = arr[i];
		int j = i - 1;
		while (j >= 0 && arr[j] > key) {
			arr[j + 1] = arr[j];//���д���38��Ҫ����һλ
			j--;
		}
		arr[j + 1] = key;
	}
}
*/
	
//ϣ������
/*
��һ�ָĽ���Ĳ��������㷨��
��ͨ�����������Ԫ�ط��飬Ȼ�����ζ�ÿ��������в�������
�Ӷ�ʹ����������������
����ʵ�ֹ����ǣ����Ƚ����һ�������Ԫ�ط�Ϊһ�飬
��ÿ����в�������Ȼ�󽫼������С��
�ظ�����������ֱ�������С��1Ϊֹ��
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

//ð������
/*
��һ�ֻ����������㷨�����ظ��ر�������������飬
ÿ�αȽ����ڵ�����Ԫ�أ�������ǵ�˳�����ͽ������ǵ�λ�ã�
ֱ���������б������
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

//��������
/*
��һ�ֻ��ڷ���˼��������㷨��
���Ļ���˼����ѡ��һ����׼Ԫ�أ�������ֳ������֣�
һ��������Ԫ�ض�С�ڻ�׼Ԫ�أ���һ��������Ԫ�ض����ڻ�׼Ԫ�أ�
Ȼ����������ֱַ�ݹ���п�������
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

//��ѡ������
/*
��һ�ּ򵥵���Ч�������㷨��
�����˼����ÿ�δ�δ����Ĳ�����ѡ����С��Ԫ�أ�
������ŵ������򲿷ֵ�ĩβ��
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

//������
/*
��һ�ֻ��ڶ����ݽṹ�������㷨��
�����˼���ǽ����������й����һ���󶥶ѻ�С���ѣ�
Ȼ�����ν��Ѷ�Ԫ��ȡ����ֱ����Ϊ�գ��͵õ���һ���������С�
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

//�鲢����
/*
��һ�ֻ��ڷ���˼��������㷨��
�����˼���ǽ����������зֳ����������У�
�ֱ�����������н�������
Ȼ�������ź���������кϲ���һ���������С�
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

//��������
/*
��ʵ��ʹ����Ͱ�ĸ�����ΰ���λ��ʮλ����λ...����
ÿ�ν����ַ�����Ӧ��Ͱ�У��ٽ�Ͱ�е����ְ�˳��ȡ���Ż����顣
*/
// ��ȡһ������ָ��λ���ϵ�����
/*
int get_digit(int number, int digit) {
	int i;
	for (i = 0; i < digit - 1; i++) {
		number /= 10;
	}
	return number % 10;
}

// ����������
void radix_sort(int* arr, int len) {
	int i, j, k;
	int bucket[10][len], count[10];
	int max_digit = 1, digit;

	// ��ȡ����������λ��
	for (i = 0; i < len; i++) {
		digit = 1;
		while (arr[i] / 10 >= digit) {
			digit *= 10;
		}
		if (digit > max_digit) {
			max_digit = digit;
		}
	}

	// ��������
	for (digit = 1; digit <= max_digit; digit *= 10) {
		for (i = 0; i < 10; i++) {
			count[i] = 0;
		}

		// �����ַ�����Ӧ��Ͱ��
		for (i = 0; i < len; i++) {
			bucket[get_digit(arr[i], digit)][count[get_digit(arr[i], digit)]] = arr[i];
			count[get_digit(arr[i], digit)]++;
		}

		// ��Ͱ�е����ְ�˳��ȡ���Ż�����
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

	//��������
	/*
	printf("��������Ľ���ǣ�");
	printf("\n");
	insertionSort(arr, size);
	for (int i = 0; i < size; i++) {
		printf("%d ", arr[i]);
	}
	printf("\n");

	//ϣ������
	printf("ϣ������Ľ���ǣ�");
	printf("\n");
	shellSort(arr, size);
	for (int i = 0; i < size; i++) {
		printf("%d ", arr[i]);
	}
	printf("\n");

	//ð������
	printf("ð������Ľ���ǣ�");
	printf("\n");
	bubbleSort(arr, size);
	for (int i = 0; i < size; i++) {
		printf("%d ", arr[i]);
	}
	printf("\n");

	*/

	//��������
	printf("��������Ľ���ǣ�");
	printf("\n");
	quickSort(arr, 0, size - 1);
	for (int i = 0; i < size; i++) {
		printf("%d ", arr[i]);
	}
	printf("\n");

	/*
	//��ѡ������
	printf("��ѡ������Ľ���ǣ�");
	printf("\n");
	selectionSort(arr, size);
	for (int i = 0; i < size; i++) {
		printf("%d ", arr[i]);
	}
	printf("\n");

	//������
	printf("������Ľ���ǣ�");
	printf("\n");
	heapSort(arr, size);
	for (int i = 0; i < size; i++) {
		printf("%d ", arr[i]);
	}
	printf("\n");

	//�鲢����
	/*
	printf("�鲢����Ľ���ǣ�");
	printf("\n");
	mergeSort(arr, 0, size - 1);
	for (int i = 0; i < size; i++) {
		printf("%d ", arr[i]);
	}
	printf("\n");
	*/

	
	//��������
	/*
	printf("��������Ľ���ǣ�");
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