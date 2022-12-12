/* -----------------------------------------------
  	 Submitted By: Jeremiah Webb
  	 Homework Number: #7
   	 Credit to:

   	 Ryan Lucas (Student in other CS223 section)

  	 Submitted On: 3/25/21

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
 double avgGen(int avgArray[],int);
    //Define size for two dimensional array, row 4, columns 4
    #define ROWS 4
    #define COLUMNS 4
    //Define size of single dimensional array
    #define ARRAYSZ 15
    //used for calculating diagonal values
    #define LIM 4
    //define minimum and maximum of the range of numbers for random number generator
    #define MIN 1
    #define MAX 20

 void main()
 {
    //Establish seed for srand
    srand(time(NULL));
    printf("\nThis program was made by Jeremiah Webb!\n");
    //initialize two dimensional array
    int randArray[ROWS][COLUMNS];
    //initialize one dimensional array
    int avgArray[ARRAYSZ];
    //initialize needed variables
    int i = 0 ;
    int j = 0;
    int k = 0;
    //initialize sum values
    int sum_lr = 0.0;
    int sum_rl = 0.0;
    double rowAvg = 0.0;
    //sum variable, add all the elements
    int sum = 0.0;

    //set table header
    printf("\n\t\t\t\tAvg.\n");

    //input random numbers into "randArray", find the sum of all elements, convert double array into a single dimensional array "avgArray".
    for(i = 0; i < ROWS; i++)
    {
        for(j = 0; j < COLUMNS; j++)
        {
            //input random numbers from randomNumberGen into randArray elements
            randArray[i][j] = randomNumberGen();
            //Find sum of all elements of randArray
            sum += randArray[i][j];
            //input element values of randArray to single dimensional avgArray
            avgArray[k]=randArray[i][j];
            k++;
        }
    }

    //print table
    for(i = 0; i < ROWS; i++)
    {
        for(j = 0; j < COLUMNS; j++)
        {   //print data of specific element
            printf("%d\t", randArray[i][j]);
        }
        //rowAvg equals function avgGen, input avgArray and i, to determine which row to calculate.
        rowAvg = avgGen(avgArray, i);
        //print rowAvg, start next line.
        printf("%.2f", rowAvg);
        printf("\n");
    }

    //reset variables
    i = i-i;
    j = j-j;
    k = k-k;

    //calculate diagonals
    for(i = 0; i < LIM; ++i)
    {
        //Calculate Top left to bottom Right diagonal
        sum_lr = sum_lr + randArray[i][i];
        //Calculate Top right to bottom Left diagonal
        sum_rl = sum_rl + randArray[i][LIM - i - 1];
    }

    /*used to display 1D array, used as a tool
    printf("1D-Array\n");
	for(i=0;i<16;i++)
    printf("%d ",avgArray[i]);
    printf("\n");
    printf("\n");
    */
    //display sum of all elements
    printf("\nSum of all elements of array = %d\n", sum);
    //display sum of Top left to bottom Right diagonal
    printf("\nSum of top left to bottom right diagonal = %d\n", sum_lr);
    //display sum of Top right to bottom Left diagonal
    printf("\nSum of top right to bottom left diagonal = %d\n", sum_rl);

    return 0;
 }

 //random number generator
 int randomNumberGen()
{
    //int randomNumber is the random number itself, use rand() to create random number and assign it to randomNumber variable.
    int randomNumber = (rand()% MAX + MIN);
    //return randomNumber integer from function.
    return (randomNumber);
}

//function to determine average of each row, input array and i, which is the variable to determine which row the program is on.
double avgGen(int avgArray[], int i)
{
    //variable to determine the sum of the elements in the row
    double rowSum = 0.0;

        //if statement determines which row the program is on, adds specific elements to row sum variable.
        if(i==0)
        {
            rowSum = (avgArray[0] + avgArray[1] + avgArray[2] + avgArray[3]);
        }
        if(i==1)
        {
            rowSum = (avgArray[4] + avgArray[5] + avgArray[6] + avgArray[7]);
        }
        if(i==2)
        {
            rowSum = (avgArray[8] + avgArray[9] + avgArray[10] + avgArray[11]);
        }
        if(i==3)
        {
            rowSum = (avgArray[12] + avgArray[13] + avgArray[14] + avgArray[15]);
        }

    //determine average divide sum of the row's elements, divide by size of row, 4.
    double rowAvg = rowSum / LIM;
    //reset sum value 0
    rowSum = rowSum - rowSum;
    //return average value
    return(rowAvg);
    //reset average value to 0
    rowAvg = rowAvg - rowAvg;
}
