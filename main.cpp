#include <iostream>
#include <Windows.h>
using std::cout;
using std::endl;
using std::cin;
static int n;
volatile int min;
volatile int max;
volatile int arithmeticMean;
DWORD WINAPI min_max(void* iArr)
{
	int* arr = (int*)iArr;
	min = arr[0];
	max = arr[0];
	for (int i = 0; i < n; i++) {
		if (min > arr[i]) {
			min = arr[i];
		}
		Sleep(7);
		if (max < arr[i]) {
			max = arr[i];
		}
		Sleep(7);
	}
	cout << "Min: " << min << " Max: " << max << endl;
	return 0;
}
/* DWORD WINAPI average(void* iArr)
{
} */
int main() {
	HANDLE hThread1;
	DWORD IDThread1;
	cout << "Input size of the array: " << endl;
	cin >> n;
	int* arr = new int[n];
	cout << "Input the elements of the array:" << endl;
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}
	hThread1 = CreateThread(NULL, 0, min_max, arr, 0, &IDThread1);
	if (hThread1 == NULL) {
		delete[] arr;
		return GetLastError();
	}
	WaitForSingleObject(hThread1, INFINITE);
	delete[] arr;
	return 0;
}