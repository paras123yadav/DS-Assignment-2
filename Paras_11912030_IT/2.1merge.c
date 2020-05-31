#include <stdio.h>
#include<stdlib.h>

// Merge two subarrays L and M into arr
void merge(int arr[], int p, int q, int r) {

  int n1 = q - p + 1;
  int n2 = r - q;

  int L[n1], M[n2];

  for (int i = 0; i < n1; i++)
  {
    L[i] = arr[p + i];
  }
  for (int j = 0; j < n2; j++)
  {
    M[j] = arr[q + 1 + j];
  }

  // Maintain current index of sub-arrays and main array
  int i, j, k;
  i = 0;
  j = 0;
  k = p;

  // Until we reach either end of either L or M, pick larger among elements L and M and place them in the correct position
  while (i < n1 && j < n2) {
    if (L[i] <= M[j]) {
      arr[k] = L[i];
      i++;
    } else {
      arr[k] = M[j];
      j++;
    }
    k++;
  }

  while (i < n1) {
    arr[k] = L[i];
    i++;
    k++;
  }

  while (j < n2) {
    arr[k] = M[j];
    j++;
    k++;
  }
}

// Divide the array into two subarrays, sort them and merge them
void mergeSort(int arr[], int l, int r) {
  if (l < r) {

    // At 'm'  the array is divided into two subarrays
    int m = l + (r - l) / 2;

    mergeSort(arr, l, m);
    mergeSort(arr, m + 1, r);

    // Merge the sorted subarrays
    merge(arr, l, m, r);
  }
}
//main function
int main() {
    int i,n;
    printf("enter the value of n=");
    scanf("%d",&n);
    int arr[n];
     printf("\nenter the numbers\n");
    for(i=0;i<n;i++)
    {
        scanf("%d",&arr[i]);
    }
    mergeSort(arr, 0, n - 1); 
    printf("the sorted array is:");
    for(i=0;i<n;i++)
    {
    printf("%d ",arr[i]);
    }   
}