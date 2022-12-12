/* -----------------------------------------------
  	 Submitted By: Jeremiah Webb
  	 Homework Number: #5
   	 Credit to:

  	 Submitted On: 3/2/21

 	  By submitting this program with my name,
 	  I affirm that the creation and modification
 	  of this program is primarily my own work.
 ------------------------------------------------ */

 //Include libraries
 #include <stdio.h>
 #include <stdlib.h>
 #include <math.h>

 /* prototypes */
 double velocityCheck();
 double degreeCheck();
 double timeFunc();
 double maxHFunc();
 double maxRFunc();

//Main function to display data
void main()
{
    printf("This program was made by Jeremiah Webb!");

    //declare variables & constants
    const double GRAVITY =9.81;
    const double PI =3.14159265358979323846;
    double initial_v = velocityCheck();
    double radian = degreeCheck(PI);
    double time = timeFunc(GRAVITY, PI, initial_v, radian);
    double maxHeight = maxHFunc(GRAVITY, PI, initial_v, radian);
    double maxRange = maxRFunc(GRAVITY, PI, initial_v, radian);
    char selection ='x';

    //Begin selection part of program ask what user wants to calculate.
    printf("\nWhat would you like to calculate?\n");
    printf("\nT for total time traveled\n");
    printf("\nH for max height\n");
    printf("\nR for horizontal range\n");

    //input selection
    printf("\nPlease make your selection now:\n");
    scanf("%s",&selection);

    //switch function to display what the user wants.
    switch(selection)
    {
        case 'T' :
            printf("The total time traveled is %2f seconds.", time);
            break;
        case 'H' :
            printf("The total height reached is %2f meters.", maxHeight);
            break;
        case 'R' :
            printf("The total distanced travel is %2f meters.", maxRange);
            break;
        default :
            printf("Invalid input");
    }
    //Display what time to reach maximum height
    time = time / 2;
    printf("\nThe time to reach maximum height is %2f seconds.\n", time);
    return(0);
}

//validates velocity
double velocityCheck ()
{
    double initial_v =0.0;
    //Ask if it is raining and for input
    printf("\nPlease input your initial velocity, in meters per second.\n");
    scanf("%lf", &initial_v);

    //Determine if initial velocity input is within parameters.
    while(initial_v <= 19 || initial_v >=801)
    {
        printf("\nVelocity must between 20 and 800 meters per second.\n");
        printf("\nPlease re-input your initial velocity \n");
        scanf("%lf", &initial_v);
    }
    //Velocity confirmation is in proper parameters
    printf("\nYour velocity input is in the proper parameters.\n");
    return(initial_v);
}

//validates degree input
double degreeCheck (double PI)
{
    double degree =0.0;
    double radian =0.0;
    //Ask user to input degrees of launch
    printf("\nPlease input your initial angle of launch, in degrees\n");
    scanf("%lf", &degree);

    //While loop in case initial angle input is out of parameters
    while(degree <= 4 || degree >= 81)
    {
        printf("\nDegrees must between 5 and 80 degrees.\n");
        printf("\nPlease re-input your initial angle of launch, in degrees\n");
        scanf("%lf", &degree);
    }
    //Convert degree into radians
    radian = (degree * PI)/180;
    //Velocity confirmation is in proper parameters
    printf("\nYour degree input is in the proper parameters.\n");
    return(radian);
}

//Calculate maximum height, return maximum height of inputted data
double maxHFunc(double GRAVITY, double PI, double initial_v, double radian)
{
    double maxHeight =0.0;
    maxHeight = ((pow(initial_v, 2))*(pow(sin(radian), 2)))/(2*GRAVITY);
    return(maxHeight);
}

//Calculate max range, return maximum range of inputted data
double maxRFunc(double GRAVITY, double PI, double initial_v, double radian)
{
    double maxRange =0.0;
    maxRange = ((pow(initial_v, 2))*(sin(2*radian)))/(GRAVITY);
    return(maxRange);
}

//Calculate total time traveled, return total time traveled of inputted data
double timeFunc(double GRAVITY, double PI, double initial_v, double radian)
{
    double time =0.0;
    time = ((2)*(initial_v) * (sin(radian)))/(GRAVITY);
    return(time);
}
