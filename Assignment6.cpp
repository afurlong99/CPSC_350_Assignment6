#include <iostream>
#include <time.h>
#include <chrono>
using namespace std;
//#include <bits/stdc++.h>

// Swap method for multiple algorithms
void swap(double *xp, double *yp)
{
    int temp = *xp;
    *xp = *yp;
    *yp = temp;
}

// Selection Sort
void SelectionSort(double numbers[], int numbersSize) {
  time_t startTime = time(NULL);
  time_t endTime;
    int indexSmallest = 0;
    double temp = 0;  // Temporary variable for swap
    for (int i = 0; i < numbersSize - 1; ++i) {
        // Find index of smallest remaining element
        indexSmallest = i;
        for (int j = i + 1; j < numbersSize; ++j) {
            if (numbers[j] < numbers[indexSmallest]) {
                indexSmallest = j;
            }
        }
        // Swap numbers[i] and numbers[indexSmallest]
        temp = numbers[i];
        numbers[i] = numbers[indexSmallest];
        numbers[indexSmallest] = temp;
    }
    endTime = time(NULL);
    cout << "SelectionSort" << endl;
    cout << "Start Time : " << startTime << endl;
    cout << "End Time : " << endTime << endl;
    cout << "Difference: "<< endTime-startTime<<endl;
}

// Insertion Sort
void InsertionSort(double numbers[], int numbersSize) {
   int temp = 0; // Temporary variable for swap
   int j = 0;
   for (int i = 1; i < numbersSize; ++i) {
      j = i;
      // Insert numbers[i] into sorted part
      // stopping once numbers[i] in correct position
      while (j > 0 && numbers[j] < numbers[j - 1]) {
         // Swap numbers[j] and numbers[j - 1]
         temp = numbers[j];
         numbers[j] = numbers[j - 1];
         numbers[j - 1] = temp;
         --j;
      }
   }
};

// Quick Sort

int Partition(double numbers[], int lowIndex, int highIndex) {
   // Pick middle element as pivot
   int midpoint = lowIndex + (highIndex - lowIndex) / 2;
   int pivot = numbers[midpoint];

   bool done = false;
   while (!done) {
      // Increment lowIndex while numbers[lowIndex] < pivot
      while (numbers[lowIndex] < pivot) {
         lowIndex += 1;
      }

      // Decrement highIndex while pivot < numbers[highIndex]
      while (pivot < numbers[highIndex]) {
         highIndex -= 1;
      }

      // If zero or one elements remain, then all numbers are
      // partitioned. Return highIndex.
      if (lowIndex >= highIndex) {
         done = true;
      }
      else {
         // Swap numbers[lowIndex] and numbers[highIndex]
         int temp = numbers[lowIndex];
         numbers[lowIndex] = numbers[highIndex];
         numbers[highIndex] = temp;

         // Update lowIndex and highIndex
         lowIndex += 1;
         highIndex -= 1;
      }
   }

   return highIndex;
}

//Merge Sort

void Merge(double numbers[], int i, int j, int k) {
   int mergedSize = k - i + 1;                // Size of merged partition
   int mergePos = 0;                        // Position to insert merged number
   double* mergedNumbers;
   mergedNumbers = (double*)malloc(mergedSize*sizeof(double));   // Dynamically allocates temporary array                                     // for merged numbers
   int leftPos = i;                          // Initialize left partition position
   int rightPos = j + 1;                      // Initialize right partition position

   // Add smallest element from left or right partition to merged numbers
   while (leftPos <= j && rightPos <= k) {
      if (numbers[leftPos] <= numbers[rightPos]) {
         mergedNumbers[mergePos] = numbers[leftPos];
         ++leftPos;
      }
      else {
         mergedNumbers[mergePos] = numbers[rightPos];
         ++rightPos;

      }
      ++mergePos;
   }

   // If left partition is not empty, add remaining elements to merged numbers
   while (leftPos <= j) {
      mergedNumbers[mergePos] = numbers[leftPos];
      ++leftPos;
      ++mergePos;
   }

   // If right partition is not empty, add remaining elements to merged numbers
   while (rightPos <= k) {
      mergedNumbers[mergePos] = numbers[rightPos];
      ++rightPos;
      ++mergePos;
   }

   // Copy merge number back to numbers
   for (mergePos = 0; mergePos < mergedSize; ++mergePos) {
      numbers[i + mergePos] = mergedNumbers[mergePos];
   }
}

void mergeSort(double arr[], int low, int high) {

	if(low < high) {
		int mid = (low + high) / 2;
		mergeSort(arr, low, mid);
		mergeSort(arr, mid+1, high);
		Merge(arr, low, mid, high);
	}
}

int partition (double arr[], int low, int high)
{
    double pivot = arr[high];  // selecting last element as pivot
    int i = (low - 1);  // index of smaller element

    for (int j = low; j <= high- 1; j++)
    {
        // If the current element is smaller than or equal to pivot
        if (arr[j] <= pivot)
        {
            i++;    // increment index of smaller element
            swap(&arr[i], &arr[j]);
        }
    }
    swap(&arr[i + 1], &arr[high]);
    return (i + 1);
}/*
    a[] is the array, p is starting index, that is 0,
    and r is the last index of array.  */
void quicksort(double a[], int p, int r)
{
    if(p < r)
    {
        int q;
        q = partition(a, p, r);
        quicksort(a, p, q-1);
        quicksort(a, q+1, r);
    }
}

void bubbleSort(double numbers[], int numbersSize)
{
    time_t startTime = time(NULL);
    time_t endTime;
    int i, j;
    for (i = 0; i < numbersSize-1; i++)

    // Last i elements are already in place
    for (j = 0; j < numbersSize-i-1; j++)
        if (numbers[j] > numbers[j+1])
            swap(&numbers[j], &numbers[j+1]);
            endTime = time(NULL);
            cout << "BubbleSort" << endl;
            cout << "Start Time : " << startTime << endl;
            cout << "End Time : " << endTime << endl;
            cout << "Difference: "<< endTime-startTime<<endl;
}
