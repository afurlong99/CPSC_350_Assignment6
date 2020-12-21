#include "Assignment6.cpp"
#include <iostream>
#include <string>
#include <fstream>
#include <istream>

using namespace std;

// File input
 int main(int argc,char* argv[]) {

  if (argc > 1) {
    cout << "You Have entered: " << argv[1] <<". Preparing output file. " <<endl;
      }
  else {
    cout << "No file name entered."<< "\n";
    return -1;
      }
  ifstream txtF(argv[1]);
  int loop = 0;
  double* array1;
  double* array2;
  double* array3;
  double* array4;
  double* array5;
  string line;
  int lineCounter = 0;
  int size;
  if (txtF.is_open())
    {
      cout<< "File is Opened" << endl;
        while(getline(txtF, line))
        {
            if (lineCounter == 0)
            {
              // Adding the five arrays, one for each sorting methods
                size = stoi(line);
                cout << "size: " << size << endl;
                array1 = (double*)malloc(size*sizeof(double));
                array2 = (double*)malloc(size*sizeof(double));
                array3 = (double*)malloc(size*sizeof(double));
                array4 = (double*)malloc(size*sizeof(double));
                array5 = (double*)malloc(size*sizeof(double));
            }
            else
            {
                array1[loop] = stod(line);
                array2[loop] = stod(line);
                array3[loop] = stod(line);
                array4[loop] = stod(line);
                array5[loop] = stod(line);
//                cout << array1[loop] << endl;
                loop++;
            }
          lineCounter++;
        }
        txtF.close();
    }
      time_t startTime;
      time_t endTime;

// Inputing start and end times as well as showing results for each sorting algorithms
      startTime = time(NULL);
      SelectionSort(array1,size);
      endTime = time(NULL);
      cout << "SelectionSort" << endl << "Start Time : " << startTime  << "\n End Time : " << endTime << endl << "Difference: "<< endTime-startTime<<endl;

      startTime = time(NULL);
      InsertionSort(array2,size);
      endTime = time(NULL);
      cout << "InsertionSort" << endl << "Start Time : " << startTime  << "\n End Time : " << endTime << endl << "Difference: "<< endTime-startTime<<endl;

      startTime = time(NULL);
      bubbleSort(array3, size);
      endTime = time(NULL);
      cout << "BubbleSort" << endl << "Start Time : " << startTime  << "\n End Time : " << endTime << endl << "Difference: "<< endTime-startTime<<endl;

      startTime = time(NULL);
      quicksort(array4,0,size-1);
      endTime = time(NULL);
      cout << "QuickSort" << endl << "Start Time : " << startTime  << "\n End Time : " << endTime << endl << "Difference: "<< endTime-startTime<<endl;

      startTime = time(NULL);
      mergeSort(array5,0,size-1);
      endTime = time(NULL);
      cout << "MergeSort" << endl << "Start Time : " << startTime  << "\n End Time : " << endTime << endl << "Difference: "<< endTime-startTime<<endl;
 }
