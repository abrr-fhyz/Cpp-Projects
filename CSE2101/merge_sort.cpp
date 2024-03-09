#include <iostream>
using namespace std;

void print(int arr[], int n)
{
	for(int i=0; i<n; i++)
		cout << arr[i] << " ";
	cout << endl;
}

void merge_function(int arr1[], int arr2[], int n1, int n2, int arr3[])
{
	int cnt1 = 0, cnt2 = 0, idx = 0;
	while(cnt1 < n1 && cnt2 < n2)
	{
		if(arr1[cnt1] < arr2[cnt2])
		{
			arr3[idx] = arr1[cnt1];
			cnt1++;
		}
		else
		{
			arr3[idx] = arr2[cnt2];
			cnt2++;
		}
		idx++;
	}
	//transfer the remaining elements of arr1 into arr3 if any
	while(cnt1 < n1)
	{
		arr3[idx] = arr1[cnt1];
		cnt1++;
		idx++;
	}
	//transfer the remaining elements of arr2 into arr3 if any
	while(cnt2 < n2)
	{
		arr3[idx] = arr2[cnt2];
		cnt2++;
		idx++;
	}
}

void merger(int arr[], int low, int mid, int high)
{
	int index = 0;
	//seperate the first half of the parent array 
	int arr1[100], arr2[100], arr3[100];
	for(int i=low; i<=mid; i++){
		arr1[index] = arr[i];
		index++;
	}
	int n1 = index;
	index = 0;
	//seperate the second half of the parent array
	for(int i=mid+1; i<=high; i++){
		arr2[index] = arr[i];
		index++;
	}
	int n2 = index;
	merge_function(arr1, arr2, n1, n2, arr3);
	//transfer the output array into the parent array
	for(int i=low; i<=high; i++){
		arr[i] = arr3[i-low];
	}
}


void merge_sort(int arr[], int low, int high){
	//base case
	if(low == high)
		return;
	int mid = (low + high) / 2;
	//recursive call
	merge_sort(arr, low, mid);
	merge_sort(arr, mid + 1, high);
	//merge all the arrays
	merger(arr, low, mid, high);
}


int main()
{
	int n;
	cout << "Enter number of elements: ";
	cin >> n;
	int arr[n];
	for(int i=0; i<n; i++)
		cin >> arr[i];
	merge_sort(arr, 0, n-1);
	print(arr, n);
	return 0;
}