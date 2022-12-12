/* -----------------------------------------------
  	 Submitted By: Jeremiah Webb
  	 Homework Number: #4
   	 Credit to:

  	 Submitted On: 2/24/21

 	  By submitting this program with my name,
 	  I affirm that the creation and modification
 	  of this program is primarily my own work.
 ------------------------------------------------ */
 //Include libraries

 #include <stdio.h>
 #include <stdlib.h>

 //Start Main Function
void main()
{
     printf("This program was made by Jeremiah Webb!");

     //declare variables & constants
     #define GRAVITY 9.81
     #define PI 3.14159265358979323846
     double initial_v =0.0;
     double degree =0.0;
     double radian =0.0;
     double horizontal_d =0.0;
     double vertical_d =0.0;
     double time =0.0;

    //Ask user to input degrees of launch
    printf("\nPlease input your initial angle of launch, in degrees\n");
    scanf("%lf", &degree);

     //While loop in case initial angle input is out of parameters
     while(degree >= 90 || degree <= 0)
     {
         printf("\nDegrees must between 0 and 90 degrees, not including 0 and 90.\n");
         printf("\nPlease re-input your initial angle of launch, in degrees\n");
         scanf("%lf", &degree);
     }
     //Convert degree into radians
     radian = (degree * PI)/180;

     //Confirm degree input is in proper parameters
     printf("\nYour degree input is in the proper parameters.\n");

     //Ask if it is raining and for input
     printf("\nPlease input your initial velocity \n");
     scanf("%lf", &initial_v);

     //Determine if initial velocity input is within parameters.
     while(initial_v <= 49 || initial_v >=301)
     {
         printf("\nDegrees must between 50 and 300 meters per second.\n");
         printf("\nPlease re-input your initial velocity \n");
         scanf("%lf", &initial_v);
     }

     //Velocity confirmation is in proper parameters
     printf("\nYour velocity input is in the proper parameters.\n");

     //Begin 1st Table
     printf("\nTime(sec)     Horizontal dist.(m)     Vertical dist.(m)\n");
     printf("\n%.2f           %.2f                  %.2f", time, horizontal_d, vertical_d);

     //Do .5 interval table with while loop
    while(time < 10)
    {
         //add .5 sec to original time
         time = time + .5;
         //reset distances
         double horizontal_d =0.0;
         double vertical_d =0.0;
         //calculate horizontal distance
         horizontal_d = (initial_v * cos(radian)) * (time);
         //calculate vertical distance
         vertical_d = ((initial_v * sin(radian)) * (time)) - (((GRAVITY * (time * time)))/ 2);
         //print data
         printf("\n%.2f           %.2f                  %.2f", time, horizontal_d, vertical_d);
     }

    //reset time
    time = time - time;
    //Begin 2nd Table
    printf("\nTime(sec)     Horizontal dist.(m)     Vertical dist.(m)\n");
    printf("\n%.2f           %.2f                  %.2f", time, horizontal_d, vertical_d);
    //Do While loop to do 2nd table if statement to ask if vertical distance is lower than 0.

    do
     {
        if (vertical_d < 0)
        {
            break;
        }
        //add .5 sec to original time
        time = time + .50;
        //calculate horizontal distance
        horizontal_d = (initial_v * cos(radian)) * (time);
        //calculate vertical distance
        vertical_d = ((initial_v * sin(radian)) * (time)) - (((GRAVITY * (time * time)))/ 2);
        //print data
        printf("\n%.2f           %.2f                  %.2f", time, horizontal_d, vertical_d);
     }
    while(vertical_d < -1 || vertical_d > -1 );

    //end program
return(0);
}
