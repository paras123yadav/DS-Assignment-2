#include <stdio.h>
#include<stdlib.h>

// Function to swap the elements
void swap(int *a, int *b) {
  int t = *a;
  *a = *b;
  *b = t;
}

// Function to partition the array on the basis of pivot element
int partition(int array[], int l, int h) {
  
  // Select the pivot element
  int pivot,i;
  pivot= array[h];
  i = (l - 1);

  // Put the elements smaller than pivot on the left and greater than pivot on the right of pivot
  for (int j = l; j < h; j++) {
    if (array[j] <= pivot) {
      i++;
      swap(&array[i], &array[j]);
    }
  }

  swap(&array[i + 1], &array[h]);
  return (i + 1);
}

void quickSort(int array[], int l, int h) {
  if (l < h) {
    
    // Select pivot position and put all the elements smaller than pivot on left and greater than pivot on right
    int pi = partition(array, l, h);
    
    // Sort the elements on the left of pivot
    quickSort(array, l, pi - 1);
    
    // Sort the elements on the right of pivot
    quickSort(array, pi + 1, h);
  }
}

int main() {
  int i,n;
  printf("enter the value of n:");
  scanf("%d",&n);
  int data[n];
  printf("enter the data:\n");
  for ( i = 0; i < n; i++)
  {
    scanf("%d",&data[i]);
  }
  quickSort(data, 0, n - 1);
  printf("Sorted array:");
  for(i=0;i<n;i++)
    {
    printf("%d ",data[i]);
    }   
}