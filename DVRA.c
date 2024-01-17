#include<stdio.h>
int source[10], destination[10], weight[10] , i, j, sum, no_of_routers, start_router, distance_matrix[10];

int min_weight(int a)
{
    int min;
    for(int i = 1 ; i <= no_of_routers ; i++)
    {
        if(source[i] == a && weight[i] <= min)
        {
            min = weight[i];
        }
    }
    return min;
}
void main()
{
    //Taking the Input Data
    printf("\nEnter the Number of Routers : ");
    scanf("%d",&no_of_routers);
    for(i = 1 ; i  <= no_of_routers ; i++)
    {
        printf("\n\nEnter SOURCE , DESTINATION & WEIGHT : ");
        scanf("%d%d%d", &source[i], &destination[i], &weight[i]);
    }
    printf("\n\nEnter the Starting Router : ");
    scanf("%d",&start_router);

    //Calculating the Distance Matrix
    for(i = 1 ; i <= no_of_routers ; i++)
    {
        if(i == start_router)
        {
            distance_matrix[i] = 0;
        }
        else if(i == destination[start_router])
        {
            distance_matrix[i] = weight[start_router];
        }
        else
        {
            sum = 0;
            j = start_router;
            while(j != i)
            {
                sum += weight[j];
                j = destination[j];
            }
            distance_matrix[i] = sum;
        }
    }

    //Printing the Output
    printf("\n\nThe Distance Matrix for Router %d is :\n\n",start_router);
    printf("DESTINATION\tDISTANCE\n");
    for(i = 1 ; i <= no_of_routers ; i++)
    {
        printf("%d\t\t%d\n",i,distance_matrix[i]);
    }
}