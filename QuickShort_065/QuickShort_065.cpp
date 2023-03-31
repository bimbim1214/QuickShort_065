#include <iostream>
using namespace std;

//array of integers to hold values
int arr[20];
int cmp_count = 0; //number of comparasion
int mov_count = 0; //number of data movement
int n;

void input() {
	while (true)
	{
		cout << "masukan panjanng element array: ";
		cin >> n;

		if (n <= 20)
			break;
		else
			cout << "\nMasukan panjang array adalah 20" << endl;
	}

	cout << "\n-------------------" << endl;
	cout << "\nEnter array element" << endl;
	cout << "\n-------------------" << endl;

	for (int i = 0; i < n; i++)
	{
		cout << "<" << (i + 1) << ">";
		cin >> arr[i];
	}
}
// swap the element at index x with the element at index y
void swap(int x, int y)
{
	int temp;

	temp = arr[x];
	arr[x] = arr[y];
	arr[y] = temp;
}

void q_short(int low, int high)
{
	int pivot, i, j;
	if (low > high)//langkah 1
		return;
	//partition the list into two parts
	//one containing element less that or aqual to pivot
	//outher containing element greather than pivot

	pivot = arr[low];//lagkah 2

	i = low + 1;//langkah 3
	j = high;// langkah 4

	while (i <= j)//langkah 10
	{
		//search for an element greater than pivot
		while ((arr[i] <= pivot) && (i <= high))//langkah 7
		{
			i++;//langkah 8
			cmp_count++;
		}
		cmp_count++;//search for an element greater than pivot
		while ((arr[j] > pivot) && (j >= low))//langkah 7
		{
			j--;//langkah 8
			cmp_count++;
		}
		cmp_count++;
		if (i < j)//langkah 9
			//if the greater element is in the left of the element 
		{
			//swap the element at index i whit the element at index j
			swap(i, j);
			mov_count++;
		}
	}
	// j now containt the index of the ast element in the sorted list
	if (low < j)//langkah 11
	{
		//move the pivot to ist correct position in the list
		swap(low, j);
		mov_count++;
	}
	//sort the list on the left of pivot uising quck sort
	q_short(low, j - 1);//langkah 12

	// sort teh list on the right of pivot using quick sort
	q_short(j + i, high);//langkah 13
}


void display() {
	cout << "\n----------" << endl;
	cout << "sorted array" << endl;
	cout << "------------" << endl;

	for (int i = 0; i < n; i++)
	{
		cout << arr[i] << " ";
	}

	cout << "\n\nNumber of comparasions: " << cmp_count << endl;
	cout << "number of data movement: " << mov_count << endl;
}

