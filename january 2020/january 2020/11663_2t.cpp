#include<stdio.h>
#include<stdlib.h>
#pragma warning(disable:4996)

void selectionSort(int arr[], int size);
int lowerBound(int arr[], int size, int target);

int main() {
	int *arr, n, m;
	scanf("%d %d", &n, &m);

	arr = (int*)malloc(sizeof(int) * n);

	for (int i = 0; i < n; i++) {
		scanf("%d", &arr[i]);
	}

	selectionSort(arr, n);

	while (m--) {
		int s, e;
		scanf("%d %d", &s, &e);

		int lo = lowerBound(arr, n, s);
		int hi = lowerBound(arr, n, e);

		if (lo == arr[n - 1]) {
			printf("0\n");
			continue;
		}

		if (hi == arr[n - 1]) {
			printf("%d\n", n - (lo - arr[0]));
		}
		else if (arr[hi - arr[0]] > e) {
			hi--;
			printf("%d\n", (hi - arr[0]) - (lo - arr[0]) + 1);
		}
		else
			printf("%d\n", (hi - arr[0]) - (lo - arr[0]) + 1);
	}

	free(arr);
}

void selectionSort(int arr[], int size) {
	for (int i = 0; i < size; i++) {
		int idx = i;
		for (int j = i + 1; j < size; j++) {
			if (arr[j] < arr[idx]) {
				int temp = arr[j];
				arr[j] = arr[idx];
				arr[idx] = temp;
			}
		}
	}
}
int lowerBound(int arr[], int size, int target)
{
	int mid, start, end;
	start = 0, end = size - 1;

	while (end > start) // end�� start���� ���ų� �۾�����, �� ���� Lower Bound�̹Ƿ� �ݺ��� �����Ѵ�.
	{
		mid = (start + end) / 2;
		if (arr[mid] >= target) // �߰����� ���ϴ� ������ ũ�ų� ���� ���, ������ �߰������� �����Ͽ� �ٽ� Ž���Ѵ�.
			end = mid;
		else start = mid + 1; // �߰����� ���ϴ� ������ ���� ���, ���۰��� �߰���+1�� �����Ͽ� �ٽ� Ž���Ѵ�.
	}
	return end;
}