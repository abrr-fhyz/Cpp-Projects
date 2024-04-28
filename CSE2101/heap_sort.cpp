#include <iostream>

using namespace std;

void printArray(int arr[], int n){
	int idx = 0;
	while(idx < n){
		cout << arr[idx] << " ";
		idx++;
	}
	cout << endl;
}


void heapify(int arr[], int upperBound, int lowerBound){

	//set lowerBound as the root node
	int largestIdx = lowerBound;
	int leftIdx = 2*lowerBound;
	int rightIdx = 2*lowerBound + 1;

	if(leftIdx < upperBound && arr[leftIdx] > arr[largestIdx]){
		largestIdx = leftIdx;
	}
	if(rightIdx < upperBound && arr[rightIdx] > arr[largestIdx]){
		largestIdx = rightIdx;
	}

	// root node is not the lowerbound
	if(largestIdx != lowerBound){
		swap(arr[lowerBound], arr[largestIdx]);
		heapify(arr, upperBound, largestIdx);
	}

}

void heapSort(int arr[], int sizeOfArray){

	//rearrange the array in maxHeap format
	for(int idx = sizeOfArray/2 - 1; idx >= 0; idx--){
		heapify(arr, sizeOfArray, idx);
		cout << "\tHeaping:";
		printArray(arr, sizeOfArray);
	}

	//sort the array
	for(int idx = sizeOfArray - 1; idx > 0; idx --){
		swap(arr[0], arr[idx]); //move root to the end because it is sorted
		cout << "\tSorting:";
		printArray(arr, sizeOfArray);
		heapify(arr, idx, 0); //heapify the formatted heap
	}
}


int main(){
	int n;
	cin >> n;
	int arr[n];
	for(int i=0; i<n; i++){
		cin >> arr[i];
	}
	cout << "unsorted array: " << endl;
	printArray(arr, n);
	heapSort(arr, n);
	cout << "sorted array: " << endl;
	printArray(arr, n);
}
