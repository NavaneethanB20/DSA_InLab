#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;
  
// function to heapify the tree
void heapify(int arr[], int n, int root) {
   int max = root;
   int left = 2*root + 1;
   int right = 2*root + 2;

   if(left < n and arr[left] > arr[max]) {
      max = left;
   } 
   
   if(right < n and arr[right] > arr[max]) {
      max = right;
   }

   if(max != root) {
      swap(arr[root], arr[max]);
      heapify(arr, n, max);
   }
}
  
// implementing heap sort
void heapSort(int arr[], int n) {
   int i = n/2-1;
   while(i >= 0) {
      heapify(arr, n, i);
      i--;
   }

   while(n > 1) {
      swap(arr[0], arr[n-1]);
      heapify(arr, n-1, 0);
      n--;
   }
}
  
/* print contents of array */
void displayArray(int arr[], int n)
{
   for (int i=0; i<n; ++i)
   cout << arr[i] << " ";
   cout << "\n";
}
  
// main program
int main() {
   srand(time(0));

   int n;
   cout << "Enter the preferred size of the array: ";
   cin >> n;

   int heap_arr[n];
   for(int i=0; i<n; i++)
      heap_arr[i] = rand() % 101 - 50;
   
   cout<<"Input array"<<endl;
   displayArray(heap_arr,n);
  
   heapSort(heap_arr, n);
  
   cout << "Sorted array"<<endl;
   displayArray(heap_arr, n);
}