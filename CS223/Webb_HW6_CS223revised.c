/* -----------------------------------------------
  	 Submitted By: Jeremiah Webb
  	 Homework Number: #6
   	 Credit to:

  	 Submitted On: 3/11/21

 	  By submitting this program with my name,
 	  I affirm that the creation and modification
 	  of this program is primarily my own work.
 ------------------------------------------------ */

 //Include libraries
 #include <stdio.h>
 #include <stdlib.h>
 #include <math.h>
 #include <time.h>

 //prototypes
 int randomNumberGen();
 void checkTri(int aSide, int bSide, int cSide);
 void calcTri(int aSide, int bSide, int cSide);

void main()
{
    //Establish seed for srand
    srand(time(NULL));
    printf("\nThis program was made by Jeremiah Webb!\n");

    //Establish size of array, initialize array and needed variables.
    //define ArraySize
    #define ARRSZ 18
    int randArray[ARRSZ];
    int i;
    //Use for loop and use randomNumberGen to create random numbers, assign random numbers to specific array elements.
    for(i=0;i<ARRSZ;i++)
    {
        randArray[i]= randomNumberGen();
    }

    //Run for loop to check each element in the checkTri function to see if each 3 elements can develop a triangle.
    for(i=0; i<ARRSZ;i = i + 3)
    {
        checkTri(randArray[i], randArray[i+1], randArray[i+2]);
    }

    return;
}

//Random number generator.
int randomNumberGen()
{
    //define minimum and maximum of the range of numbers.
    #define MIN 1
    #define MAX 99
    //int randomNumber is the random number itself, use rand() to create random number and assign it to randomNumber variable.
    int randomNumber = (rand()% MAX + MIN);
    //return randomNumber integer from function.
    return (randomNumber);
}

//Check whether sides can make a triangle,
void checkTri(int aSide, int bSide, int cSide)
{
    //If statement asks if sides can be made into a triangle based on less than.
    if ((aSide + bSide <= cSide) || (aSide + cSide <= bSide) || (bSide + cSide <= aSide))
    {
        //Cannot make a triangle, return nothing.
    }
    else
    {
        //Can make a triangle, call calc triangle function in order to calculate area.
        calcTri(aSide, bSide, cSide);
    }
    return;
}

//Calculate Triangle area using Heron's formula, then print sides and area.
void calcTri(int aSide, int bSide, int cSide)
{
    //initialize needed variables for calculation of area.
    double area =0.0;

    //Heron's formula to calculate area of triangle.
    //Variation of Heron's Formula
    area = (sqrt(((aSide+bSide+cSide)*(bSide+cSide-aSide)*(aSide+cSide-bSide)*(aSide+bSide-cSide))))/4;

    //Print data.
    printf("\nThe sides of the triangle are %d, %d and %d and the area is %.2f\n", aSide, bSide, cSide, area);

    return;
}
