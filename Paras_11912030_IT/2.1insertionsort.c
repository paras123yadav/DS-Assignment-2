#include<stdio.h>
int main()
{
    int i,j,temp,n;
     printf("enter the value of n=");
    scanf("%d",&n);
    int a[n];
    printf("enter the values\n");
    for ( i = 0; i < n; i++)
    {
        scanf("%d",&a[i]);
    }
    //insertion sort algorithm
        for ( i = 1; i < n; i++)
    {
        temp=a[i];
        j=i-1;
        while (j>=0&&a[j]>temp)
        {
            a[j+1]=a[j];
            j--;
        }
        a[j+1]=temp;
    }
    printf("the sorted array is=");               //printing the sorted list
    for ( i = 0; i < n; i++)
    {
        printf("%d ",a[i]);
    }
    
    return 0;
}