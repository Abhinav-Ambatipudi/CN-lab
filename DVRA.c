#include<stdio.h>
int destination[10], weight[10] , i, j, sum, no_of_routers, start_router, distance_matrix[10];

void main()
{
    //Taking the Input Data
    printf("\nEnter the Number of Routers : ");
    scanf("%d",&no_of_routers);
    for(i = 1 ; i  <= no_of_routers ; i++)
    {
        printf("\n\neEnter DESTINATION & WEIGHT of Router %d : ",i);
        scanf("%d%d",&destination[i], &weight[i]);
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