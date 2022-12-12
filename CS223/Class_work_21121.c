#include <stdio.h>
#include <conio.h>


int main(void)
{
	int number;

	system("cls");

	printf("Please enter a number between 1-1000 \n");
	scanf("%d",&number);


	if ((number < 200 && number > 100))
    {
    printf("Your number was %d", number);
	}
	else
	{
    printf("Your number is out of range");
	}
return 0;
}

