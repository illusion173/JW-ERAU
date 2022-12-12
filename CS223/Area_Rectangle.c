/* This program calculates the area of a rectangle */

 //Include libraries

 #include <stdio.h>
 #include <stdlib.h>

 //Start Main Function
 int main(void)
 {
 //Declare variables and initialize
 double wid_rectangle =0.0;
 double len_rectangle =0.0;
 double area_rectangle =0.0;
 //Get data from user
 printf("Input the width of your rectangle   ");
 scanf("%lf", &wid_rectangle);
 printf("Input the length of your rectangle   ");
 scanf("%lf", &len_rectangle);
 //Calculate area
 area_rectangle = wid_rectangle * len_rectangle;
 //Display area
 printf("The area of rectangle with width of %.2f and the length of %.2f is %.2f", wid_rectangle, len_rectangle, area_rectangle);
 return(0);

 }
