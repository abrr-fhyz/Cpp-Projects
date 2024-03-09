#include<iostream>
using namespace std;



int get_max(int arr[], int n)
{
	int mx = arr[0];
    for (int i = 1; i < n; i++)
        if (arr[i] > mx)
            mx = arr[i];
    return mx;
}


void print(int arr[], int n)
{
	for(int i=0; i<n; i++)
		cout << arr[i] << " ";
	cout << endl;
}

void counting_sort(int arr[], int n, int exponent)
{
	int output[n];
    int i, count[10] = { 0 };

    for (i = 0; i < n; i++)
        count[(arr[i] / exponent) % 10]++; //considers least digit, the right most side

    for (i = 1; i < 10; i++)
        count[i] += count[i - 1]; //cumilative sum

    for (i = n - 1; i >= 0; i--) {
        output[count[(arr[i]/exponent)%10]-1] = arr[i];
        count[(arr[i]/exponent)%10]--;
    }
    // output[ count[(arr[i]/exp)%10] -1 ] = arr[i]
    // count[(arr[i]/exp)%10] --



    for (i = 0; i < n; i++)
        arr[i] = output[i];
    print(arr, n);
}

void radix_sort(int array[], int n)
{
	int mx = get_max(array, n);
	for(int i=1; mx/i > 0; i*=10)
		counting_sort(array, n, i);
}

int main()
{
	int n;
	cin >> n;
	int array[n];
	for(int i=0; i<n; i++)
		cin >> array[i];
	print(array, n);
	radix_sort(array, n);
	print(array, n);
	return 0;
}