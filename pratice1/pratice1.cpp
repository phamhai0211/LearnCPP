// pratice1.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include<cstdio>
#include<vector>
//using namespace std;
//bubble sort arr
void Sort(int arr[],int n) {
    int i, j;
    bool swapped;
    for (i = 0; i < n - 1; i++) {
        swapped = false;
        for (j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                std::swap(arr[j], arr[j + 1]);
                swapped = true;
            }
        }

        if (swapped == false)
            break;
    }
}

// quick sort
void Quick_Sort(){

}
// enter value of array
void inputArray(int *arr,int n) {
    for (int i = 0; i <= n - 1; i++) {
        std::cout << "nhap gia tri thu " << i << "\n";
        std::cin >> *(arr+i);
    }
}
// print array to screen
void printArray(int arr[],int n) {
    for (int i = 0; i < n; i++) {
        std::cout << " " << arr[i];
    }
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

void Swap(int* number_1, int* number_2)
{
    int temp = *number_1;
    *number_1 = *number_2;
    *number_2 = temp;
}

void ShuffleArray(int* arr, int n)
{
    srand(time(NULL));

    int minPosition;
    int maxPosition = n - 1;
    int swapPosition;

    int i = 0;
    while (i < n - 1)
    {
        minPosition = i + 1;
        swapPosition = rand() % (maxPosition - minPosition + 1) + minPosition;

        Swap(&arr[i], &arr[swapPosition]);
        i++;
    }
}
int main()
{
    int value;
    std::cout << "nhap so luong phan tu cua mang\n";
    std::cin >> value;
    int* arr = new int[value];
    
    inputArray(arr, value);
    Sort(arr, value);
    std::cout << "array sorted\n";
    printArray(arr, value);
    std::cout << "\n";
    std::cout << "array deleted\n";
    deleteRepeat(arr, value);
    printArray(arr, value);
    std::cout << "\n";
    ShuffleArray(arr, value);
    std::cout << "shuffle array\n";
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
