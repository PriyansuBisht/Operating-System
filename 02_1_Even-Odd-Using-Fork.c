#include <stdio.h>
#include <process.h>
#include <unistd.h>

int main()
{
    int n, e_sum = 0, o_sum = 0;
    printf("\n Enter Size of Array : ");
    scanf("%d", &n);
    int arr[n];
    printf("\n Enter Array : ");
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
        //if(arr[i]%2 == 0)   e_sum+=arr[i];
        //else    o_sum+=arr[i];
    }

    for (int i = 0; i < n; i++)
    {
        if (arr[i] % 2 == 0)
            e_sum += arr[i];
        else
            o_sum += arr[i];
    }

    int r = fork();

    if (r > 0)  // PARENT
    {
        wait(NULL); 
        printf("\n Sum of EVEN Elements off Array is : %d", e_sum);
    }
    else if (r == 0)    // CHILD
    {
        printf("\n Sum of ODD Elements off Array is : %d", o_sum);
    }
    else             // fork smaller than 0, FORK FAIL
        exit(1);
    
    return 0;
}