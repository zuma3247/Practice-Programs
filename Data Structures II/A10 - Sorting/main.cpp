//*****************************************************************************************************
//
//		File:			    AVLDriver.cpp
//
//		Student:			Muazuddin Mohammed
//
//		Assignment:	 	    Program  #10
//
//		Course Name:		Data Structures II
//
//		Course Number:		COSC 3100 - Z1
//
//		Due:			    April 18, 2025
//
//
//		This file defines and implements an AVL Tree.
//
//
//*****************************************************************************************************
/*
 * Assignment #10: Sorting #1
 * Author: Muazuddin Mohammed
 * Date: April 22, 2025
 * Description: Implements selection sort, insertion sort, merge sort, and quick sort
 *              with performance measurement and file I/O.


#include <iostream>
#include <vector>
#include <fstream>
#include <chrono>
#include <random>

using namespace std;
using namespace std :: chrono;

class SortUtility
{
public:
    static void selectionSort(vector<int> & arr);
    static void insertionSort(vector<int> & arr);
    static void mergeSort(vector<int> & arr, int left, int right);
    static void quickSort(vector<int> & arr, int low, int high);

private:
    static void merge(vector<int> & arr, int left, int mid, int right);
    static int partition(vector<int> & arr, int low, int high);
};

void SortUtility::selectionSort(vector<int> & arr)
{
    int n = static_cast<int>(arr.size());
    for (int i = 0; i < n - 1; ++i)
    {
        int minIndex = i;
        for (int j = i + 1; j < n; ++j)
        {
            if (arr[j] < arr[minIndex])
                minIndex = j;
        }
        if (minIndex != i)
            swap(arr[i], arr[minIndex]);
    }
}

void SortUtility::insertionSort(vector<int> & arr)
{
    int n = static_cast<int>(arr.size());
    for (int i = 1; i < n; ++i)
    {
        int key = arr[i];
        int j = i - 1;
        while (j >= 0 && arr[j] > key)
        {
            arr[j + 1] = arr[j];
            --j;
        }
        arr[j + 1] = key;
    }
}

void SortUtility::merge(vector<int> & arr, int left, int mid, int right)
{
    int n1 = mid - left + 1;
    int n2 = right - mid;
    vector<int> L(n1);
    vector<int> R(n2);

    for (int i = 0; i < n1; ++i)
        L[i] = arr[left + i];
    for (int j = 0; j < n2; ++j)
        R[j] = arr[mid + 1 + j];

    int i = 0, j = 0, k = left;
    while (i < n1 && j < n2)
    {
        if (L[i] <= R[j])
            arr[k++] = L[i++];
        else
            arr[k++] = R[j++];
    }
    while (i < n1)
        arr[k++] = L[i++];
    while (j < n2)
        arr[k++] = R[j++];
}

void SortUtility::mergeSort(vector<int> & arr, int left, int right)
{
    if (left < right)
    {
        int mid = left + (right - left) / 2;
        mergeSort(arr, left, mid);
        mergeSort(arr, mid + 1, right);
        merge(arr, left, mid, right);
    }
}

int SortUtility::partition(vector<int> & arr, int low, int high)
{
    int pivot = arr[high];
    int i = low - 1;
    for (int j = low; j <= high - 1; ++j)
    {
        if (arr[j] < pivot)
            swap(arr[++i], arr[j]);
    }
    swap(arr[i + 1], arr[high]);
    return i + 1;
}

void SortUtility::quickSort(vector<int> & arr, int low, int high)
{
    if (low < high)
    {
        int pi = partition(arr, low, high);
        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}

int main()
{
    // Part 1: Random array sorting and timing
    cout << "=== Part 1: Random Array Sorting ===" << endl;
    vector<int> original(10);
    mt19937 rng(static_cast<unsigned int>(steady_clock :: now().time_since_epoch().count()));
    uniform_int_distribution<int> dist(1, 100);

    for (int & v : original)
        v = dist(rng);

    cout << "Original array: ";
    for (int v : original)
        cout << v << " ";
    cout << "\n\n";

    auto runAndTime = [&](const string & name, auto sortFunc, vector<int> data)
    {
        cout << name << " :\n";
        auto start = high_resolution_clock :: now();
        sortFunc(data);
        auto stop = high_resolution_clock :: now();
        auto duration = duration_cast<microseconds>(stop - start);
        for (int v : data)
            cout << v << " ";
        cout << "\n";
        cout << "Time: " << duration.count() << " microseconds" << endl << endl;
    };

    runAndTime("Selection Sort", [](vector<int> & a) { SortUtility::selectionSort(a); }, original);
    runAndTime("Insertion Sort", [](vector<int> & a) { SortUtility::insertionSort(a); }, original);
    runAndTime("Merge Sort", [](vector<int> & a) { SortUtility::mergeSort(a, 0, static_cast<int>(a.size()) - 1); }, original);
    runAndTime("Quick Sort", [](vector<int> & a) { SortUtility::quickSort(a, 0, static_cast<int>(a.size()) - 1); }, original);

    // Part 2: File input/output sorting
    cout << "=== Part 2: File I/O Sorting ===" << endl;
    ifstream inFile("numbers.txt");
    if (!inFile)
    {
        cerr << "Error: could not open numbers.txt for reading." << endl;
        return 1;
    }

    vector<int> numbers;
    int value;
    while (inFile >> value)
        numbers.push_back(value);
    inFile.close();

    cout << "Original numbers from file: ";
    for (int v : numbers)
        cout << v << " ";
    cout << "\n\n";

    ofstream outFile("sorted_numbers.txt");
    if (!outFile)
    {
        cerr << "Error: could not open sorted_numbers.txt for writing." << endl;
        return 1;
    }

    auto sortAndRecord = [&](const string & name, auto sortFunc)
    {
        vector<int> copy = numbers;
        sortFunc(copy);
        cout << name << " result: ";
        outFile << name << " result: ";
        for (int v : copy)
        {
            cout << v << " ";
            outFile << v << " ";
        }
        cout << endl;
        outFile << "\n";
    };

    sortAndRecord("Selection Sort", [&](vector<int> & a) { SortUtility::selectionSort(a); });
    sortAndRecord("Insertion Sort", [&](vector<int> & a) { SortUtility::insertionSort(a); });
    sortAndRecord("Merge Sort", [&](vector<int> & a) { SortUtility::mergeSort(a, 0, static_cast<int>(a.size()) - 1); });
    sortAndRecord("Quick Sort", [&](vector<int> & a) { SortUtility::quickSort(a, 0, static_cast<int>(a.size()) - 1); });

    outFile.close();
    cout << "Sorted results have also been saved to sorted_numbers.txt" << endl;

    return 0;
}
*/