#include<stdio.h>
#include<string.h>
char text[10], cipher_text[10], result[10];
int key;
void main()
{
    int i;
    printf("------- MENU -------\n\n");
    printf("1. Encryption\n2. Decryption\n\n");
    printf("Enter your choice : ");
    scanf("%d",&i);
    if(i == 1)
    {
        printf("Enter the Plain Text : ");
        scanf("%s",text);
        printf("Enter your Encryption Key (in integer): ");
        scanf("%d",&key);
        for(int i = 0 ; text[i] != '\0' ; i++)
        {
            result[i] = text[i] ^ key;
        }
        printf("\nENCRYPTED KEY = %s\n\n",result);
    }
    else
    {
        printf("Enter the Encrypted Text : ");
        scanf("%s",text);
        printf("Enter your Decryption Key (in integer): ");
        scanf("%d",&key);
        for(int i = 0 ; text[i] != '\0' ; i++)
        {
            result[i] = text[i] ^ key;
        }
        printf("\nDECRYPTED KEY = %s\n\n",result);
    }
}