// pratice1.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include<cstdio>
#include<vector>
#include<stdio.h>
#include<stdlib.h>
//using namespace std;
//bubble sort arr
//void Sort(int arr[],int n) {
//    int i, j;
//    bool swapped;
//    for (i = 0; i < n - 1; i++) {
//        swapped = false;
//        for (j = 0; j < n - i - 1; j++) {
//            if (arr[j] > arr[j + 1]) {
//                std::swap(arr[j], arr[j + 1]);
//                swapped = true;
//            }
//        }
//
//        if (swapped == false)
//            break;
//    }
//}
//void swap(int *a, int *b) {
//    int t = *a;
//    *a = *b;
//    *b = t;
//}
//
////using last element as the pivot
//int partition(int arr[], int low, int high) {
//
//    // choosing pivot
//    int pivot = arr[high];
//
//    int i = (low - 1);
//    for (int j = low; j <= high - 1; j++) {
//
//        if (arr[j] < pivot) {
//            i++;
//            swap(&arr[i], &arr[j]);
//        }
//    }
//    swap(&arr[i + 1], &arr[high]);
//    return (i + 1);
//}
//// quick sort
//void quickSort(int arr[], int low, int high){
//
//    if (low < high) {
//        int index = partition(arr, low, high);
//
//        quickSort(arr, low, index - 1);
//        quickSort(arr, index + 1, high);
//    }
//}
int cmpfnc(const void *a, const void *b) {
    //return(*(int*)a - *(int*)b);
    int
        n1 = *(int*)a,
        n2 = *(int*)b;


    return
        n1 > n2             // if
        ? 1                 // then
        : n1 == n2          // else if
        ? 0                 // then
        : -1                // else
        ;
}
// enter value of array
void inputArray(int *arr,int n) {
    for (int i = 0; i < n; i++) {
        printf("Nhap phan tu thu %d\n",i);
        scanf_s("%d",(arr+i));
    }
}
// print array to screen
void printArray(int arr[],int n) {
    for (int i = 0; i < n; i++) 
        printf("%d ",arr[i]);    
   
}

//Delete value any location
void Delete(int a[], int& n, int vitri) {
    for (int i = vitri + 1; i < n; i++) {
        a[i - 1] = a[i];
    }
    n--;
}
// delete repeat value
void deleteRepeat(int a[], int& n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            if (a[i] == a[j]) {
                Delete(a, n, j);
                i--;
            }
        }
    }
}

//void Swap(int* number_1, int* number_2)
//{
//    int temp = *number_1;
//    *number_1 = *number_2;
//    *number_2 = temp;
//}
//
//void ShuffleArray(int* arr, int n)
//{
//    srand(time(NULL));
//
//    int minPosition;
//    int maxPosition = n - 1;
//    int swapPosition;
//
//    int i = 0;
//    while (i < n - 1)
//    {
//        minPosition = i + 1;
//        swapPosition = rand() % (maxPosition - minPosition + 1) + minPosition;
//
//        Swap(&arr[i], &arr[swapPosition]);
//        i++;
//    }
//}
void shuffle(int* arr, size_t n) { 
        srand(time(NULL));
        size_t i;
        for (i = n-1; i > 0; i--)
        {
            int swap_index = rand() % n;
            int t = arr[i];
            arr[i] = arr[swap_index];
            arr[swap_index] = t;
        }   
}


int main()
{
    int value;
    printf( "nhap so luong phan tu cua mang :");
    scanf_s("%d", &value);
    int* arr = new int[value];
    printf("Value : %d", value);
    inputArray(arr, value);
    /*quickSort(arr,0,value-1);*/
    printf("array sorted : ");
    qsort(arr,value,sizeof(int),cmpfnc);
    printArray(arr, value);
    printf("\n");
   /* std::cout << "\n";
    std::cout << "array deleted\n";
    deleteRepeat(arr, value);
    printArray(arr, value);
    std::cout << "\n";*/
   /* ShuffleArray(arr, value);*/
  /*  std::cout << "shuffle array\n";
    printArray(arr, value);*/
    /*deleteRepeat(arr, value);
    printArray(arr, value);*/
    printf("\n");
    shuffle(arr,value);
    printf("shuffle array: ");
    printArray(arr, value);
    delete[] arr;
    return 0;
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
