#include<iostream>
using namespace std;

int* calcMultiplication(int arr[], int size)
{
	//int* temp = new int[size];
	//for (int i = 0; i < size; i++)
	//{
	//	temp[i] = (i == 0 ? arr[1] : arr[0]);
	//	int j = (i == 0 ? 2: 1);
	//	while (j < size)
	//	{
	//		if (i != j)
	//			temp[i] *= arr[j];
	//		j++;
	//	}
	//}
	//return temp;

	/*int* ptr = new  int[size];
	int product = arr[0];
	for (int i = 1; i < size - 1; i++)
	{
		ptr[i] = product;
		product *= arr[i];
	}
	ptr[size - 1] = product;
	product = arr[size - 1];
	for (int i = size - 2; i > 0; i--)
	{
		ptr[i] *= product;
		product *= arr[i];
	}
	ptr[0] = product;
	return ptr;*/


	int* ptr = new int[size];											// 1
	ptr[0] = 1;											// 1
	for (int i = 1; i < size; i++)											// n
		ptr[i] = ptr[i - 1] * arr[i - 1];											// n - 1
	int temp = arr[size - 1];											// 1
	for (int i = size - 2; i >= 0; i--)											// n
	{
		ptr[i] *= temp;											// n - 1
		temp *= arr[i];											// n - 1
	}
	return ptr;											// 1

	/*int* ptr = new int[size];
	int index = 3, multiple = 1;
	for (int i = 0; i < size; i++)
	{
		if (i != index)
			multiple *= arr[i];
	}
	ptr[index] = multiple;
	return ptr;*/
}

int main()
{
	const int SIZE = 5;
	int arr[SIZE] = { 1,2,3,4,5 };
	int* p = calcMultiplication(arr, SIZE);
	for (int i = 0; i < SIZE; i++)
		cout << p[i] << " ";
	return 0;
}
