#include<stdio.h>
#include<time.h>
int main()
{
    clock_t start_time = clock();
    int size;
    double execution_time;
    printf("enter the size of an array");
    scanf("%d",&size);
    int arr[size];
    printf("enter the elements\n");
    for(int i = 0; i < size; i++)
    {
        scanf("%d",&arr[i]);
    }
    int key;
    printf("enter the elements to be search");
    scanf("%d",&key);
    int found = 0;
    int low = 0;
    int high = size - 1;
    int mid;
    while(low<=high)
    {
        mid=(low + high)/2;
        if(arr[mid]==key)
        {
            found=1;
            break;
        }
        else if (arr[mid]<key)
        {
            low=mid+1;
        }
        else{
            high=mid-1;
        }
    }
    if(found)
    {
        printf("element %d found at %d index",key,mid);
    }
    clock_t end_time = clock();
    execution_time = (double)(end_time - start_time) / CLOCKS_PER_SEC;
    printf("\n execution time = %f",execution_time);
    return 0;

}
