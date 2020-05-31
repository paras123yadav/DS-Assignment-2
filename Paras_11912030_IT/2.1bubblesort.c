#include<stdio.h>
int main()
{
    int i,n,j,temp;
    printf("enter the value of n=");
    scanf("%d",&n);
    int a[n];
    printf("\nenter the numbers\n");
    for(i=0;i<n;i++)
    {
        scanf("%d",&a[i]);
    }
    // bubble sort algorithm
        for(i=1;i<n;i++)                //if you start loop starts from i=0 to i < n-1
        {
            int flag=0;
            for ( j = 0; j < n-i; j++)          //we have to start this loop from j=0 to j < n-1-i
            {
                if (a[j]>a[j+1])
                {
                    temp=a[j];
                    a[j]=a[j+1];
                    a[j+1]=temp;
                    flag=1;     
                }
            }  
            if (flag==0)
            {
                break;
            }
             
        }   
    printf("the sorted elements are=");          //printing the sorted list
    for(i=0;i<n;i++)
    {
    printf("%d ",a[i]);
    }
    return 0;
}