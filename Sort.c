/*
 * Title: Implement sorting algorithms
 * Project aim: learning algorithm design & function pointer
 * by: SajadSojoudi@gmail.com
*/
#define _CRT_SECURE_NO_WARNINGS


// C program for implementation of sort algorithms
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

clock_t starttime, endtime;
struct sort_t
{
	char algorithm_name[33];
	int (*func) (int [], int);
};

void swap(int* xp, int* yp)
{
	int temp = *xp;
	*xp = *yp;
	*yp = temp;
}

void selectionSort(int arr[], int n)
{
	int i, j, min_idx;

	// One by one move boundary of unsorted subarray
	for (i = 0; i < n - 1; i++)
	{
		// Find the minimum element in unsorted array
		min_idx = i;
		for (j = i + 1; j < n; j++)
			if (arr[j] < arr[min_idx])
				min_idx = j;

		// Swap the found minimum element with the first element
		swap(&arr[min_idx], &arr[i]);
	}
}

void bubbleSort(int arr[], int n)
{
	int i, j;
	for (i = 0; i < n - 1; i++)

		// Last i elements are already in place   
		for (j = 0; j < n - i - 1; j++)
			if (arr[j] > arr[j + 1])
				swap(&arr[j], &arr[j + 1]);
}

void insertionSort(int arr[], int n)
{
	int i, key, j;
	for (i = 1; i < n; i++) {
		key = arr[i];
		j = i - 1;

		/* Move elements of arr[0..i-1], that are
		  greater than key, to one position ahead
		  of their current position */
		while (j >= 0 && arr[j] > key) {
			arr[j + 1] = arr[j];
			j = j - 1;
		}
		arr[j + 1] = key;
	}
}


/* This function takes last element as pivot, places
the pivot element at its correct position in sorted
array, and places all smaller (smaller than pivot)
to left of pivot and all greater elements to right
of pivot */
int partition(int arr[], int low, int high)
{
	int pivot = arr[high]; // pivot
	int i = (low - 1); // Index of smaller element and indicates the right position of pivot found so far

	for (int j = low; j <= high - 1; j++)
	{
		// If current element is smaller than the pivot
		if (arr[j] < pivot)
		{
			i++; // increment index of smaller element
			swap(&arr[i], &arr[j]);
		}
	}
	swap(&arr[i + 1], &arr[high]);
	return (i + 1);
}
/* The main function that implements QuickSort
arr[] --> Array to be sorted,
low --> Starting index,
high --> Ending index */
void quickSort(int arr[], int high)
{
	high -= 1;
	int low = 0;
	if (low < high)
	{
		/* pi is partitioning index, arr[p] is now
		at right place */
		int pi = partition(arr, low, high);

		// Separately sort elements before
		// partition and after partition
		quickSort(arr, low, pi - 1);
		quickSort(arr, pi + 1, high);
	}
}

// To heapify a subtree rooted with node i which is
// an index in arr[]. n is size of heap
void heapify(int arr[], int n, int i)
{
	int largest = i; // Initialize largest as root
	int l = 2 * i + 1; // left = 2*i + 1
	int r = 2 * i + 2; // right = 2*i + 2

	// If left child is larger than root
	if (l < n && arr[l] > arr[largest])
		largest = l;

	// If right child is larger than largest so far
	if (r < n && arr[r] > arr[largest])
		largest = r;

	// If largest is not root
	if (largest != i) {
		swap(&arr[i], &arr[largest]);

		// Recursively heapify the affected sub-tree
		heapify(arr, n, largest);
	}
}

// main function to do heap sort
void heapSort(int arr[], int n)
{
	// Build heap (rearrange array)
	for (int i = n / 2 - 1; i >= 0; i--)
		heapify(arr, n, i);

	// One by one extract an element from heap
	for (int i = n - 1; i > 0; i--) {
		// Move current root to end
		swap(&arr[0], &arr[i]);

		// call max heapify on the reduced heap
		heapify(arr, i, 0);
	}
}





/* Function to print an array */
void printArray(int arr[], int size)
{
	int i;
	for (i = 0; i < size; i++)
		printf("%d ", arr[i]);
	printf("\n");
}


int main()
{
	int alg_num = 10;
	double totaltime;

	struct sort_t sort_functions[10];

		strcpy(sort_functions[0].algorithm_name, "merge");
		sort_functions[0].func = &selectionSort;

		strcpy(sort_functions[1].algorithm_name, "insertion");
		sort_functions[1].func = &insertionSort;

		strcpy(sort_functions[2].algorithm_name, "bubble");
		sort_functions[2].func = &bubbleSort;

		strcpy(sort_functions[3].algorithm_name, "quick");
		sort_functions[3].func = &quickSort;

		strcpy(sort_functions[4].algorithm_name, "heap");
		sort_functions[4].func = &heapSort;

		strcpy(sort_functions[5].algorithm_name, "selectionSort");
		sort_functions[5].func = &selectionSort;

		strcpy(sort_functions[6].algorithm_name, "counting");
		sort_functions[6].func = &selectionSort;

		strcpy(sort_functions[7].algorithm_name, "radix");
		sort_functions[7].func = &selectionSort;

		strcpy(sort_functions[8].algorithm_name, "bucket");
		sort_functions[8].func = &selectionSort;

		strcpy(sort_functions[9].algorithm_name, "tree");
		sort_functions[9].func = &selectionSort;
		
	printf("\n 0 : Merge sort \n 1 : Insertion Sort \n 2 : Bubble Sort\n 3 : Quick Sort \n 4 : Heap Sort \n 5 : Selection Sort \n 6 : Countiong Sort \n 7 : Radix Sort \n 8 : Bucket Sort \n 9 : Tree Sort\nWhich sorting algorithm you want to run:");
	scanf("%d", &alg_num);

	//int arr[] = { 64, 25, 12, 22, 11 };
	
	FILE * f = fopen("./ran.txt", "r");
	if (f == NULL)
	{
		printf("fopen failed\n");
		exit(-1);
	}

	int arr[50000];
	int i = 0;

	while (!feof(f))
	{
		fscanf (f, "%d", &arr[i]);
		i++;
	}
	int fclose(FILE * f);
	
	

	int n = sizeof(arr) / sizeof(arr[0]);

	// calculating clock when sorting starts..
	starttime = clock();

	if (alg_num >= 0 && alg_num <= 9)
	{
		printf("\nRuning the algorithm...\n");
		sort_functions[alg_num].func(arr, n);
	}
	else
	{
		printf("\n\nAlgorithm Number is Wrong!\n");
		return 0;
	}
	endtime = clock();

	printf("Sorted array: \n");

	printArray(arr, n);

	printf("\nStart time : %f", (float)starttime);
	printf("\nEnd Time : %f", (float)endtime);

	totaltime = ((double)(endtime - starttime)) / CLOCKS_PER_SEC;
	printf("\n\nTotal time of execution for %s = %f\n", sort_functions[alg_num].algorithm_name, totaltime);
	return 0;
}
