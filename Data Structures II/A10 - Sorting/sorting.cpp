//*****************************************************************************************************
//
//		File:			    AVLDriver.cpp
//
//		Student:			Muazuddin Mohammed
//
//		Assignment:	 	    Program  #10 & 11
//
//		Course Name:		Data Structures II
//
//		Course Number:		COSC 3100 - Z1
//
//		Due:			    April 25, 2025
//
//
//		This file defines and implements all sorting algorithms in DS2.
//
//
//*****************************************************************************************************

#include <iostream>
#include <vector>
#include <chrono>
#include <fstream>
#include <algorithm>
#include <cstdlib>
#include <ctime>
#include <list>

//*****************************************************************************************************

using namespace std :: chrono;
using namespace std;

//*****************************************************************************************************

class SortUtility
{
private:
    SortUtility() = delete;
public:
    static void selectionSort( vector <int> & arr, int size )
    {
        int minIndex = 0;

        for (int i = 0; i < size - 1; i++)
        {
            minIndex = i;

            for (int j = i + 1; j < size; j++)
            {
                if (arr[j] < arr[minIndex])
                {
                    minIndex = j;
                }
            }

            swap(arr[i], arr[minIndex]);
        }
    }

    //*****************************************************************************************************

    static void insertionSort( vector <int> & arr, int size )
    {
        int key = 0;
        int j = 0;

        for (int i = 1; i < size; i++)
        {
            key = arr[i];
            j = i - 1;

            while (j >= 0 && arr[j] > key)
            {
                arr[j + 1] = arr[j];
                j = j - 1;
            }

            arr[j+1] = key;
        }
    }

    //*****************************************************************************************************

    static void merge( vector <int> & arr, int left, int mid, int right )
    {
        int n1 = mid - left + 1,
            n2 = right - mid,
            i = 0,
            j = 0,
            k = left;
        vector <int> L(n1), R(n2);

        for (i = 0; i < n1; i++)
            L[i] = arr[left + i];

        for (j = 0; j < n2; j++)
            R[j] = arr[mid + 1 + j];

        i = 0;
        j = 0;
        k = left;

        while (i < n1 && j < n2)
        {
            if (L[i] <= R[j])
            {
                arr[k] = L[i];
                i++;
            }
            else
            {
                arr[k] = R[j];
                j++;
            }

            k++;
        }

        while (i < n1)
        {
            arr[k] = L[i];
            i++;
            k++;
        }

        while (j < n2)
        {
            arr[k] = R[j];
            j++;
            k++;
        }
    }

    //*****************************************************************************************************

    static void mergeSort( vector <int> & arr, int left, int right )
    {
        if (left < right)
        {
            int mid = left + (right - left) / 2;
            mergeSort(arr, left, mid);
            mergeSort(arr, mid + 1, right);
            merge(arr, left, mid, right);
        }
    }

    //*****************************************************************************************************

    static int partition( vector <int> & arr, int low, int high )
    {
        int pivot = arr[high];
        int i = (low - 1);

        for (int j = low; j <= high - 1; j++)
        {
            if (arr[j] < pivot)
            {
                i++;
                swap(arr[i], arr[j]);
            }
        }
        swap(arr[i + 1], arr[high]);
        return (i + 1);
    }

    //*****************************************************************************************************

    static void quickSort( vector <int> & arr, int low, int high )
    {
        if (low < high)
        {
            int pivotIndex = partition(arr, low, high);
            quickSort(arr, low, pivotIndex - 1);
            quickSort(arr, pivotIndex + 1, high);
        }
    }

    //*****************************************************************************************************

    static void heapify(vector <int> & arr, int n, int i)
    {
        int largest = i;
        int left = 2 * i + 1;
        int right = 2 * i + 2;

        if (left < n && arr[left] > arr[largest])
        {
            largest = left;
        }

        if (right < n && arr[right] > arr[largest])
        {
            largest = right;
        }

        if (largest != i)
        {
            swap(arr[i], arr[largest]);
            heapify(arr, n, largest);
        }
    }

    //*****************************************************************************************************

    static void heapSort(vector <int> & arr)
    {
        int arrSize = arr.size();

        for (int i = arrSize / 2 - 1; i >= 0; i--)
        {
            heapify(arr, arrSize, i);
        }

        for (int i = arrSize - 1; i > 0; i--)
        {
            swap(arr[0], arr[i]);
            heapify(arr, i, 0);
        }
    }

    //*****************************************************************************************************

    static void shellSort(vector <int> & arr)
    {
        int arrSize = arr.size();
        int temp = 0,
            j = 0;

        for (int gap = arrSize / 2; gap > 0; gap /= 2)
        {
            for (int i = gap; i < arrSize; i += 1)
            {
                temp = arr[i];

                for (j = i; j >= gap && arr[j - gap] > temp; j -= gap)
                {
                    arr[j] = arr[j - gap];
                }

                arr[j] = temp;
            }
        }
    }

    //*****************************************************************************************************

    static int getMax(vector <int> & arr)
    {
        int max_val = arr[0];

        for (int i = 1; i < arr.size(); i++)
        {
            if (arr[i] > max_val)
            {
                max_val = arr[i];
            }
        }

        return max_val;
    }

    //*****************************************************************************************************

    static void countingSort(vector <int> & arr, int exponent)
    {
        vector <int> output(arr.size());
        vector <int> count(10, 0);

        for (int i : arr)
        {
            count[(i / exponent) % 10]++;
        }

        for (int i = 1; i < 10; i++)
        {
            count[i] += count[i - 1];
        }

        for (int i = arr.size() - 1; i >= 0; i--)
        {
            output[count[(arr[i] / exponent) % 10] - 1] = arr[i];
            count[(arr[i] / exponent) % 10]--;
        }

        for (int i = 0; i < arr.size(); i++)
        {
            arr[i] = output[i];
        }
    }

    //*****************************************************************************************************

    static void radixSort(vector <int> & arr)
    {
        int max_val = getMax(arr);

        for (int exp = 1; max_val / exp > 0; exp *= 10)
        {
            countingSort(arr, exp);
        }
    }

    //*****************************************************************************************************
/*
    static void bucketSort(vector <int> & arr)
    {
        int arrSize = arr.size();
        vector <list<int>> buckets(arrSize);
        int bucketIndex = 0;
        int max_val = getMax(arr);
        int index = 0;

        if (max_val == 0 || arrSize <= 0)
        {
            return; //cannot do this, you can use if, else but no empty return. -Professor
        }

        for (int i = 0; i < arrSize; i++)
        {
            bucketIndex = static_cast<int>((double)arr[i] / (max_val + 1) * arrSize);

            if (bucketIndex >= arrSize)
            {
                bucketIndex = arrSize - 1;
            }

            if (bucketIndex < 0)
            {
                bucketIndex = 0;
            }

            buckets[bucketIndex].push_back(arr[i]);
        }

        for (int i = 0; i < arrSize; i++)
        {
            buckets[i].sort();
        }

        for (int i = 0; i < arrSize; i++)
        {
            for (int val : buckets[i])
            {
                arr[index++] = val;
            }
        }
    }
*/
    static void bucketSort(vector <int> & arr)
    {
        int arrSize = arr.size();

       if (arrSize > 0)
        {
            vector<list<int>> buckets(arrSize);
            int bucketIndex = 0;
            int max_val = getMax(arr);
            int index = 0;

            if (max_val > 0)
            {
                for (int i = 0; i < arrSize; i++)
                {
                    bucketIndex = static_cast<int>( (static_cast<double>(arr[i]) / (max_val + 1)) * arrSize );
                    buckets[bucketIndex].push_back(arr[i]);
                }

                for (int i = 0; i < arrSize; i++)
                {
                    if (!buckets[i].empty())
                    {
                        buckets[i].sort();
                    }
                }

                for (int i = 0; i < arrSize; i++)
                {
                    for (int val : buckets[i])
                    {
                        arr[index++] = val;
                    }
                }
            }
        }
    }



    //*****************************************************************************************************

    static void printArray( const vector <int> & arr )
    {
        for (int x : arr)
        {
            cout << x << " ";
        }
        cout << endl;
    }
};

//*****************************************************************************************************

int main()
{
    vector <int> randomArr(10);
    vector <int> arrCopy;
    vector <int> fileNumbers;
    vector<int> numbersCopy;

    ifstream inputFile("numbers.txt");
    ofstream outputFile("sorted_numbers.txt");

    srand(time(nullptr));
    int number = 0;

    cout << "----------------------------------------" << endl;
    cout << "Part 1: Sorting a random array of 10 integers" << endl;
    cout << "----------------------------------------" << endl;

    for (int i = 0; i < 10; i++)
    {
        randomArr[i] = rand() % 100 + 1;
    }

    // Selection Sort
    arrCopy = randomArr;
    cout << "before: ";
    SortUtility :: printArray(arrCopy);
    auto start = high_resolution_clock :: now();
    SortUtility :: selectionSort(arrCopy, arrCopy.size());
    auto stop = high_resolution_clock :: now();
    auto duration = duration_cast <microseconds> (stop - start);
    cout << "after:  ";
    SortUtility :: printArray(arrCopy);
    cout << "Selection Sort time: " << duration.count() << " microseconds" << endl;
    cout << "----------------------------------------" << endl;

    // Insertion Sort
    arrCopy = randomArr;
    cout << "before: ";
    SortUtility :: printArray(arrCopy);
    start = high_resolution_clock :: now();
    SortUtility :: insertionSort(arrCopy, arrCopy.size());
    stop = high_resolution_clock :: now();
    duration = duration_cast <microseconds> (stop - start);
    cout << "after:  ";
    SortUtility :: printArray(arrCopy);
    cout << "Insertion Sort time: " << duration.count() << " microseconds" << endl;
    cout << "----------------------------------------" << endl;

    // Merge Sort
    arrCopy = randomArr;
    cout << "before: ";
    SortUtility :: printArray(arrCopy);
    start = high_resolution_clock :: now();
    SortUtility :: mergeSort(arrCopy, 0, arrCopy.size() - 1);
    stop = high_resolution_clock :: now();
    duration = duration_cast <microseconds> (stop - start);
    cout << "after:  ";
    SortUtility :: printArray(arrCopy);
    cout << "Merge Sort time: " << duration.count() << " microseconds" << endl;
    cout << "----------------------------------------" << endl;

    // Quick Sort
    arrCopy = randomArr;
    cout << "before: ";
    SortUtility :: printArray(arrCopy);
    start = high_resolution_clock :: now();
    SortUtility :: quickSort(arrCopy, 0, arrCopy.size() - 1);
    stop = high_resolution_clock :: now();
    duration = duration_cast <microseconds> (stop - start);
    cout << "after:  ";
    SortUtility :: printArray(arrCopy);
    cout << "Quick Sort time: " << duration.count() << " microseconds" << endl;
    cout << "----------------------------------------" << endl;

    // Heap Sort
    arrCopy = randomArr;
    cout << "before: ";
    SortUtility :: printArray(arrCopy);
    start = high_resolution_clock :: now();
    SortUtility :: heapSort(arrCopy);
    stop = high_resolution_clock :: now();
    duration = duration_cast <microseconds> (stop - start);
    cout << "after:  ";
    SortUtility :: printArray(arrCopy);
    cout << "Heap Sort time: " << duration.count() << " microseconds" << endl;
    cout << "----------------------------------------" << endl;

    // Shell Sort
    arrCopy = randomArr;
    cout << "before: ";
    SortUtility :: printArray(arrCopy);
    start = high_resolution_clock :: now();
    SortUtility :: shellSort(arrCopy);
    stop = high_resolution_clock :: now();
    duration = duration_cast <microseconds> (stop - start);
    cout << "after:  ";
    SortUtility :: printArray(arrCopy);
    cout << "Shell Sort time: " << duration.count() << " microseconds" << endl;
    cout << "----------------------------------------" << endl;

    // Radix Sort
    arrCopy = randomArr;
    cout << "before: ";
    SortUtility :: printArray(arrCopy);
    start = high_resolution_clock :: now();
    SortUtility :: radixSort(arrCopy);
    stop = high_resolution_clock :: now();
    duration = duration_cast <microseconds> (stop - start);
    cout << "after:  ";
    SortUtility :: printArray(arrCopy);
    cout << "Radix Sort time: " << duration.count() << " microseconds" << endl;
    cout << "----------------------------------------" << endl;

    // Bucket Sort
    arrCopy = randomArr;
    cout << "before: ";
    SortUtility :: printArray(arrCopy);
    start = high_resolution_clock :: now();
    SortUtility :: bucketSort(arrCopy);
    stop = high_resolution_clock :: now();
    duration = duration_cast <microseconds> (stop - start);
    cout << "after:  ";
    SortUtility :: printArray(arrCopy);
    cout << "Bucket Sort time: " << duration.count() << " microseconds" << endl;
    cout << "----------------------------------------" << endl;

    //*****************************************************************************************************

    cout << "\n----------------------------------------" << endl;
    cout << "Part 2: Sorting numbers from file" << endl;
    cout << "----------------------------------------" << endl;

    if (inputFile.is_open())
    {
        while (inputFile >> number)
        {
            fileNumbers.push_back(number);
        }

        inputFile.close();
    }
    else
    {
        cout << "Unable to open numbers.txt" << endl;
    }

    // Selection Sort
    numbersCopy = fileNumbers;
    start = high_resolution_clock :: now();
    SortUtility :: selectionSort(numbersCopy, numbersCopy.size());
    stop = high_resolution_clock :: now();
    duration = duration_cast <microseconds> (stop - start);
    cout << "Selection Sort time: " << duration.count() << " microseconds" << endl;
    cout << "----------------------------------------" << endl;

    // Insertion Sort
    numbersCopy = fileNumbers;
    start = high_resolution_clock :: now();
    SortUtility :: insertionSort(numbersCopy, numbersCopy.size());
    stop = high_resolution_clock :: now();
    duration = duration_cast <microseconds> (stop - start);
    cout << "Insertion Sort time: " << duration.count() << " microseconds" << endl;
    cout << "----------------------------------------" << endl;

    // Merge Sort
    numbersCopy = fileNumbers;
    start = high_resolution_clock :: now();
    SortUtility :: mergeSort(numbersCopy, 0, numbersCopy.size() - 1);
    stop = high_resolution_clock :: now();
    duration = duration_cast <microseconds> (stop - start);
    cout << "Merge Sort time: " << duration.count() << " microseconds" << endl;
    cout << "----------------------------------------" << endl;

    // Quick Sort
    numbersCopy = fileNumbers;
    start = high_resolution_clock :: now();
    SortUtility :: quickSort(numbersCopy, 0, numbersCopy.size() - 1);
    stop = high_resolution_clock :: now();
    duration = duration_cast <microseconds> (stop - start);
    cout << "Quick Sort time: " << duration.count() << " microseconds" << endl;
    cout << "----------------------------------------" << endl;

    // Heap Sort
    numbersCopy = fileNumbers;
    start = high_resolution_clock :: now();
    SortUtility :: heapSort(numbersCopy);
    stop = high_resolution_clock :: now();
    duration = duration_cast <microseconds> (stop - start);
    cout << "Heap Sort time: " << duration.count() << " microseconds" << endl;
    cout << "----------------------------------------" << endl;

    // Shell Sort
    numbersCopy = fileNumbers;
    start = high_resolution_clock :: now();
    SortUtility :: shellSort(numbersCopy);
    stop = high_resolution_clock :: now();
    duration = duration_cast <microseconds> (stop - start);
    cout << "Shell Sort time: " << duration.count() << " microseconds" << endl;
    cout << "----------------------------------------" << endl;

    // Radix Sort
    numbersCopy = fileNumbers;
    start = high_resolution_clock :: now();
    SortUtility :: radixSort(numbersCopy);
    stop = high_resolution_clock :: now();
    duration = duration_cast <microseconds> (stop - start);
    cout << "Radix Sort time: " << duration.count() << " microseconds" << endl;
    cout << "----------------------------------------" << endl;

    // Bucket Sort
    numbersCopy = fileNumbers;
    start = high_resolution_clock :: now();
    SortUtility :: bucketSort(numbersCopy);
    stop = high_resolution_clock :: now();
    duration = duration_cast <microseconds> (stop - start);
    cout << "Bucket Sort time: " << duration.count() << " microseconds" << endl;
    cout << "----------------------------------------" << endl;

    if (outputFile.is_open())
    {
        for (int x: numbersCopy)
        {
            outputFile << x << endl;
        }

        outputFile.close();
        cout << "Sorted numbers saved to sorted_numbers.txt" << endl;
    }
    else
    {
        cout << "Unable to open sorted_numbers.txt for writing" << endl;
    }

    return 0;
}

//*****************************************************************************************************

/*
----------------------------------------
Part 1: Sorting a random array of 10 integers
----------------------------------------
before: 82 88 64 38 67 55 65 64 1 63
after:  1 38 55 63 64 64 65 67 82 88
Selection Sort time: 0 microseconds
----------------------------------------
before: 82 88 64 38 67 55 65 64 1 63
after:  1 38 55 63 64 64 65 67 82 88
Insertion Sort time: 0 microseconds
----------------------------------------
before: 82 88 64 38 67 55 65 64 1 63
after:  1 38 55 63 64 64 65 67 82 88
Merge Sort time: 11 microseconds
----------------------------------------
before: 82 88 64 38 67 55 65 64 1 63
after:  1 38 55 63 64 64 65 67 82 88
Quick Sort time: 0 microseconds
----------------------------------------
before: 82 88 64 38 67 55 65 64 1 63
after:  1 38 55 63 64 64 65 67 82 88
Heap Sort time: 1 microseconds
----------------------------------------
before: 82 88 64 38 67 55 65 64 1 63
after:  1 38 55 63 64 64 65 67 82 88
Shell Sort time: 0 microseconds
----------------------------------------
before: 82 88 64 38 67 55 65 64 1 63
after:  1 38 55 63 64 64 65 67 82 88
Radix Sort time: 13 microseconds
----------------------------------------
before: 82 88 64 38 67 55 65 64 1 63
after:  1 38 55 63 64 64 65 67 82 88
Bucket Sort time: 19 microseconds
----------------------------------------

----------------------------------------
Part 2: Sorting numbers from file
----------------------------------------
Selection Sort time: 2540 microseconds
----------------------------------------
Insertion Sort time: 1766 microseconds
----------------------------------------
Merge Sort time: 833 microseconds
----------------------------------------
Quick Sort time: 125 microseconds
----------------------------------------
Heap Sort time: 239 microseconds
----------------------------------------
Shell Sort time: 217 microseconds
----------------------------------------
Radix Sort time: 815 microseconds
----------------------------------------
Bucket Sort time: 411 microseconds
----------------------------------------
Sorted numbers saved to sorted_numbers.txt

 */

void dijkstra ( const T & src, const T & dest)
{
    unordered_map <T, int> dist;
    unordered_map <T, T>;
    priority_queue <pair<int, T>, vector < pair<int, T>>,
        greater <pair<int, T>>> pq;
    for (auto node : adj)
        dist [node.first] = INT_MAX;
    pq.push({0,src}); //push distance 0 to pq

    while (!pq.empty())
    {
        T node = pq.top().first; // node contains both distance and node
        pq.pop();

        for ( auto n : adjList[node])
        {
            T next = n.first; //first is node, second is distance
            int weight = next.second;
            if (node + weight < dist[next])
            {

            }
        }
    }

}

/*


Heap Sort
Start from leaf node
Swap as u go

Shell Sort
initialize Gap = size/2 int division
 compare first vale and size/2
 swap
 divide gap again
 compare and then swap
 retrace steps going backwards by minusing gap

Counting Sort
 make an array of counts
 accumulate array that adds up cumuluative sum of counts
 make a sorting array

 Radix
 start sorting with one's place
 then ten's place
 then hundred's place

 bucket sort
 (num * n) / (max + 1)

 BFS
 use priority queue




  */