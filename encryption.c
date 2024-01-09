#include<stdio.h>
#include<string.h>
char plain[10], cipher[10], result[10];
int p, c, k, key;
void main()
{
    int i;
    printf("------- MENU -------\n\n");
    printf("1. Encryption\n2. Decryption\n\n");
    printf("Enter your choice : ");
    scanf("%d",&i);
    if(i == 1)
    {
        printf("Enter the plain text : ");
        scanf("%s",plain);
        printf("Enter your Encryption Key (in integer): ");
        scanf("%d",&key);
        for(int i = 0 ; plain[i] != '/0' ; i++)
        {
            result[i] = 
        }
        printf("\nENCRYPTED KEY = %d",)
    }
}