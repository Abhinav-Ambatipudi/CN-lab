#include<stdio.h>
#include<string.h>
int i , j , k , n , len , size;
char sender[100], reciever[100], check_sum1[100] , check_sum2[100], c = '0', sub[2][100];

void div(char string[])
{
     //Division into parts
    k = 0;
    for(i = 0 ; i < n ; i++)
    {
        for(j = 0 ; j < size ; j++)
        {
            sub[i][j] = string[k++];
        }
    }

    // Display of all parts
    k = 0;
    for(i = 0 ; i < n ; i++)
    {
        printf("Part %d :",i+1);
        for(j = 0 ; j < size ; j++)
        {
            printf("%c",sub[i][j]);
        }
        printf("\n");
    }
}

//Binary addition
char binary_add(char a, char b)
{
    if(a == '0' && b == '0' && c == '0')
    {
        return '0';
    }
    else if( (a == '0' && b == '0' && c == '1') || (a == '0' && b == '1'  && c == '0') || (a == '1' && b == '0' && c == '0') )
    {
        return '1';
    }
    else if ( (a == '0' && b == '1'  && c == '1') || (a == '1' && b == '0'  && c == '1') || (a == '1' && b == '1'  && c == '0') )
    {
        c = '1';
        return '0';
    }
    else if (a == '1' && b == '1'  && c == '1')
    {
        c = '1';
        return '1';
    }
}

//Finding compliment 
void compliment()
{
    for(i = 0 ; i < size ; i++)
    {
        if(check_sum1[i] == '0')
        {
            check_sum1[i] = '1';
        }
        else if(check_sum1[i] == '1')
        {
            check_sum1[i] = '0';
        }
    }
}
//main method
void main()
{
    //Taking Sender Message
    //system("clear");
    printf("Enter the Sender String : ");
    scanf("%s",sender);
    printf("Enter the number of parts : ");
    scanf("%d",&n);
    len = strlen(sender);
    size = len / n;
    
     //Division into parts
     div(sender);

    //Binary Addition
    for(i = size-1 ; i >= 0 ; i--)
    {
        check_sum1[i] = binary_add(sub[0][i],sub[1][i]);
    }
    compliment();
    printf("\nCheck Sum1 = %s\n",check_sum1);

    //Taking Reciever Message
    c = 0;
    printf("\n\nEnter the Reciever String : ");
    scanf("%s",reciever);
    printf("Enter the number of parts : ");
    scanf("%d",&n);
    len = strlen(reciever);
    size = len / n;
    
     //Division into parts
     div(reciever);

    //Binary Addition
    for(i = size-1 ; i >= 0 ; i--)
    {
        check_sum2[i] = binary_add(sub[0][i],sub[1][i]);
    }
    printf("\nCheck Sum2 = %s\n",check_sum2);

    for(i = 0 ; i < size ; i++)
    {
        c = 0;
        char a = binary_add(check_sum1[i],check_sum2[i]);
        if(a == '0')
        {
            printf("\nERROR !!\n\n");
            exit(0);
        }
    }
    printf("\nNO ERROR !!\n\n");  
}