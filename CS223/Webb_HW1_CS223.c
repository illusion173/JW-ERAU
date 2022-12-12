/* -----------------------------------------------
  	 Submitted By: Jeremiah Webb
  	 Homework Number: #2
   	 Credit to:

  	 Submitted On: 2/4/21

 	  By submitting this program with my name,
 	  I affirm that the creation and modification
 	  of this program is primarily my own work.
 ------------------------------------------------ */

/* This program determines if a homeowner is able to mow their lawn in the rain */

 //Include libraries

 #include <stdio.h>
 #include <stdlib.h>

 //Start Main Function
 void main()
 {
 //Declare variables and initialize
 double wid_yard =0.0;
 double len_yard =0.0;
 double area_yard =0.0;
 double speed_lawn_sec =2.0;
 double speed_lawn_min =0.0;
 double time_lawn =0.0;
 double wid_house =0.0;
 double len_house =0.0;
 double area_house =0.0;
 double answer_rain =0;

 //Ask if it is raining and for input
 printf("\nIs it raining? Enter 1 for Yes, 0 for No.\n");
 scanf("%lf", &answer_rain);
//If else function to determine if owner can mow and if so, calculate if house is bigger than yard.
 if (answer_rain == 1)
 {

    printf("Sorry, it is raining, you cannot mow now.");
 }

 else{
    //Get data from user for yard calculation
    printf("Input the width of your yard in feet   ");
    scanf("%lf", &wid_yard);
    printf("Input the length of your yard in feet  ");
    scanf("%lf", &len_yard);
    //Calculate area of yard
    area_yard = wid_yard * len_yard;
    //Convert 2 square feet per second to minute
    speed_lawn_min = speed_lawn_sec * 60 ;
        //Divide area of yard and rate of cutting to find time
    time_lawn = area_yard / speed_lawn_min;

    //Get data from user for house calculation
    printf("Input the width of your house in feet   ");
    scanf("%lf", &wid_house);
    printf("Input the length of your house in feet  ");
    scanf("%lf", &len_house);
    //Calculate area of house
    area_house = wid_house * len_house;
    //Calculate if area of house is bigger than the area of the yard.
    if (area_house > area_yard)
        {
            printf ("That cannot be, your house is bigger than your yard!");
        }

        else
        {
            //Display area and time of cutting to mow it
            printf("\nThe area of the house with a width of %.2f feet and the length of %.2f feet is %.2f square feet.\nThe area of the yard with a width of %.2f feet and the length of %.2f feet is %.2f square feet. It takes %.2f minutes to mow it.",wid_house, len_house, area_house, wid_yard, len_yard, area_yard, time_lawn);
        }
    }
 return(0);
}
