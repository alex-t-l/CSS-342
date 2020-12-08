//
//  SortImpls.h
//  Program4
//
//  Created by Alex Lai on 11/16/20.
//

#ifndef SortImpls_h
#define SortImpls_h
#include <vector>
using namespace std;

//Merge sort and quicksort should be recursive
    void IterativeMergeSort(vector<int> &arr, int f, int l);
    void BubbleSort(vector<int> &arr, int f, int l);
    void InsertionSort(vector<int> &arr, int f, int l);
    void MergeSort(vector<int> &arr, int f, int l);
    void Merge(vector<int> &arr, int f, int m, int l);
    void QuickSort(vector<int> &arr, int f, int l);
    void ShellSort(vector<int> &arr, int f, int l);
    void ShellSort(vector<int> &arr, int n);
    void Swap(int &num1, int &num2);

#endif /* SortImpls_h */


void BubbleSort(vector<int> &arr, int f, int l){
    for(int i = f; i < l; i++){
        for(int j = 0; j < l - i; j++){
            if(arr[j] > arr[j+1])
            swap(arr[j], arr[j+1]);
        }
    }
}

void InsertionSort(vector<int> &arr, int f, int l){
    for(int i = f + 1; i <= l ; i++){
        int l = arr[i];
        int j = i - 1;
        while(j >= f && arr[j] > l){
            arr[j + 1] = arr[j];
            j = j - 1;
        }
        arr[j + 1] = l;
    }
}


 void MergeSort(vector<int> &arr, int f, int l){
    if(f < l){
    int m = (f + l) / 2;
    MergeSort(arr, f, m);
    MergeSort(arr, m + 1, l);
    Merge(arr, f, m, l);
 }
}

void Merge(vector<int> &arr, int f, int m, int l){
    int *tempArr;
    int size = l - f + 1;
    tempArr = new int[size];
    int f1 = f;
    int l1 = m;
    int f2 = m + 1;
    int l2 = l;
    int index = 0;
    while((f1 <= l1) && (f2 <= l2)){
        if(arr[f1] < arr[f2]){
            tempArr[index] = arr[f1];
            f1++;
        }
        else{
            tempArr[index] = arr[f2];
            f2++;
        }
        index++;
    }
    while(f1 <= l1){
        tempArr[index] = arr[f1];
        f1++;
        index++;
    }
    while(f2 <= l2){
        tempArr[index] = arr[f2];
        f2++;
        index++;
    }
    for(index = 0; index < size; index++){
        arr[f] = tempArr[index];
        f++;
    }
    delete[] tempArr;
    }


 void QuickSort(vector<int> &arr, int f, int l){
     if(l - f < 4){
         InsertionSort(arr, f, l);
     return;
     }
     int m = (f + l) / 2;
     if(arr[f] > arr[l])
         Swap(arr[f], arr[l]);
     if(arr[f] > arr[m])
         Swap(arr[f], arr[m]);
     else if(arr[m] > arr[l])
         Swap(arr[m],arr[l]);
     int pivot = arr[m];
     Swap(arr[m], arr[l - 1]);
     
     int left = f + 1;
     int right = l - 2;
     bool done = false;
     while(!done){
         while(arr[left] < pivot)
             left++;
         while(arr[right] > pivot)
             right--;
         if(right > left){
             swap(arr[left], arr[right]);
             right--;
             left++;
         }
         else{
             done = true;
         }
     }
     Swap(arr[left], arr[l - 1]);
     QuickSort(arr, f, left - 1);
     QuickSort(arr, left + 1, l);
 }

//Based off Carrano's book
void ShellSort(vector<int> &arr, int f, int l){
    if((f == 0) && (l == arr.size() - 1)){
        ShellSort(arr, arr.size());
        return;
    }
    vector<int> temp;
    for(int i = f; i <= l; i++)
        temp.push_back(arr[i]);
    ShellSort(temp, temp.size());
    int count = f;
    for(int sorted: temp){
        arr[count] = sorted;
        count++;
    }
        
}
   
void ShellSort(vector<int> &arr, int n) {
    int size = n;
    for (int gap = size / 2; gap > 0;
         gap = (gap == 2) ? 1 : int(gap / 2.2)){
        for (int i = gap; i < size; i++) {
            int tmp = arr[i];
            int j = i;
            for ( ; (j >= gap) && (tmp < arr[j - gap]); j -= gap){
                arr[j] = arr[j - gap];
            }
            arr[j] = tmp;
        }
    }
}


void IterativeMergeSort(vector<int>& arr, int f, int l)
{
    if (f < l)
    {
        int* temp = new int[l + 1];
        int arrLength = (l - f) + 1;
        int arrEnd = l + 1;
        int subSize = 1;
        int f1, f2, l1, l2;
        int index1, index2, tempIndex;

        for (tempIndex = 0; tempIndex < f; tempIndex++)
            temp[tempIndex] = arr[tempIndex];

        while (subSize < arrLength)
        {
            f1 = f;
            tempIndex = f;
            while ((f1 + subSize) < arrEnd)
            {
                f2 = f1 + subSize;
                l1 = f2 - 1;
                l2 = ((f2 + subSize - 1) < arrEnd) ? (f2 + subSize - 1) : (arrEnd - 1);

                for (index1 = f1, index2 = f2; index1 <= l1 && index2 <= l2; tempIndex++)
                {
                    if (arr[index1] <= arr[index2])
                        temp[tempIndex] = arr[index1++];
                    else
                        temp[tempIndex] = arr[index2++];
                }

                while (index1 <= l1)
                    temp[tempIndex++] = arr[index1++];

                while (index2 <= l2)
                    temp[tempIndex++] = arr[index2++];

                f1 = l2 + 1;
            }

            for (index1 = f1; tempIndex < arrEnd; index1++)
                temp[tempIndex++] = arr[index1];
            
            for (int i = f; i < arrEnd; i++)
                arr[i] = temp[i];

            subSize *= 2;
        }
    }
}

void Swap(int &num1, int &num2){
    int temp = num1;
    num1 =  num2;
    num2 = temp;
}

