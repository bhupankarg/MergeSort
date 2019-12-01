#include <iostream>
#include <vector>
using namespace std;

void merge(vector<int>& arr, int low, int mid, int high)
{
	vector<int> auxArr;
	int i = low, j = mid + 1;
	while(i <= mid && j <= high)
	{
		if(arr[i] < arr[j])
			auxArr.push_back(arr[i++]);
		else
			auxArr.push_back(arr[j++]);
	}
	while(i <= mid) auxArr.push_back(arr[i++]);
	while(j <= high) auxArr.push_back(arr[j++]);
	for(i = low, j = 0; j < auxArr.size(); i++, j++)
		arr[i] = auxArr[j];
}

void mergeSort(vector<int>& arr, int low, int high)
{
	if(low < high)
	{
		int mid = (low + high) / 2;
		mergeSort(arr, low, mid);
		mergeSort(arr, mid+1, high);
		merge(arr, low, mid, high);
	}
}

int main()
{
	vector<int> arr = { 23, 12, 69, 15, 3, 8, 36, 27, 20, 19 };
	cout << "Array before sorting..." << endl;
	for(int i = 0; i < arr.size(); i++)
		cout << arr[i] << " ";
	cout << endl;
	mergeSort(arr, 0, arr.size()-1);
	cout << "Array after sorting..." << endl;
	for(int i = 0; i < arr.size(); i++)
		cout << arr[i] << " ";
	cout << endl;
	return 0;
}