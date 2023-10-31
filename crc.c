#include<stdio.h>
#include<string.h>
char message[100] , g[100], result[100], buffer[100];
int i , l , n , p;

//XOR division 
char xor(char a, char b)
{
	if(a == b)
	{
		return '0';
	}
	else
	{
		return '1';
	}
}

//Finding Number of 0's
int no_zero()
{
	int i = 0;
	while(result[i] == '0')
	{
		i++;
	}
	return i;
}

//Calculation
void calc()
{
	p = n-1;
	
	for(i = 0 ; i < n ; i++)
	{
		buffer[i] = message[i];
	}
	printf("\nMessage after Appending = %s\n",message);
	
	while(message[p] != '\0')
	{
		for(i = 0 ; i < n ; i++)
		{
			result[i] = xor(buffer[i],g[i]);
		}
		int z = no_zero() , a = 0, b = p+1;
		
		
		for(i = z ; i < n ; i++)
		{
			buffer[a++] = result[i];
		}
		
		for(i = 0 ; i < z ; i++)
		{
			buffer[a++] = message[b++];
		}
		
		if(z == n)
		{
			printf("\nNO ERROR !!\n\n");
			exit(0);
		}		
		p += z;
	}
}

//Main Method
void main()
{
	system("clear");
	//Taking both inputs
	printf("\nEnter Your Sender Message : ");
	scanf("%s",message);
	printf("Enter your String : ");
	scanf("%s",g);
	
	//Length of the Message
	l = strlen(message);
	
	//Length of the g-string
	n = strlen(g);
	
	//Message pointer
	p = n-1;
	
	//Adding Required 0's
	for(int i = 0 ; i < n-1 ; i++)
	{
		message[i+l] = '0';
	}
	
	//SENDING
	calc();

	//Adding the Remainder
	for(int i = 0 ; i < n-1 ; i++)
	{
		message[i+l] = buffer[i];
	}
	printf("Remainder = %s\n\n",buffer);
	
	printf("\nEnter Your Reciever Message : ");
	scanf("%s",message);
	
	//RECIEVING
	calc();	

	printf("\nERROR !!\n\n");
}

