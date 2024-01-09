#include<stdio.h>
int matrix[10][10], n, start_node;
void main()
{
    // Taking the Input
    printf("Enter the number of nodes : ");
    scanf("%d",&n);
    printf("\nEnter the Adjacency Matrix :\n");
    for(int i = 0 ; i < n ; i++)
    {
        for(int j = 0 ; j < n ; j++)
        {
            scanf("%d",&matrix[i][j]);
        }
    }
    
    // Calculating the Shortest Path
    printf("\nEnter the starting node : ");
    scanf("%d",&start_node);
    

}