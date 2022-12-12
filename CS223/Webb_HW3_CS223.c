/* -----------------------------------------------
  	 Submitted By: Jeremiah Webb
  	 Homework Number: #3
   	 Credit to:

  	 Submitted On: 2/17/21

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
    double time_lawn =0.0;
    double wid_house =0.0;
    double len_house =0.0;
    double area_house =0.0;
    double answer_rain =0.0;
    const double speed_lawn_user_sec =0.0;
    double speed_lawn_user_min =0.0;

    printf("This program was made by Jeremiah Webb!");
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
        printf("\nInput the width of your yard in feet\n   ");
        scanf("%lf", &wid_yard);
        printf("\nInput the length of your yard in feet\n  ");
        scanf("%lf", &len_yard);

            //Begin program major determine if width and length of yard are in proper sizes.
            if (((wid_yard >= 100 && wid_yard <= 1000) || (len_yard >= 100 && len_yard <= 1000)))
                {
                    //Tell user yard is in correct parameters.
                    printf("\nThe yard is in the correct parameters!\n");
                    //Input data for the size of house
                    printf("\nInput the width of your house in feet\n  ");
                    scanf("%lf", &wid_house);
                    printf("\nInput the length of your house in feet\n  ");
                    scanf("%lf", &len_house);

                    //Determines whether size of house is in correct size.
                    if (((wid_house >= 100 && wid_house <= 1000) || (len_house >= 100 && len_house <= 1000)))
                    {
                         //Tells user is in proper housing parameters, asks for the speed of the lawn mower.
                         printf("\nThe house is in the correct parameters!\n");
                         printf("\nInput the speed of your lawn mower in square feet per second, up to 1 decimal place\n");
                         scanf("%lf", &speed_lawn_user_sec);

                         //Determine if lawn mower speed is in proper parameters.
                         if ((speed_lawn_user_sec >= 1.5 && speed_lawn_user_sec <= 3.0 ))
                         {
                                 //Tell user lawn mower is correct format and speed.
                                 printf("\nThe lawn mower is the correct speed!");
                                 //Calculate area of yard & house
                                 area_yard = wid_yard * len_yard;
                                 area_house = wid_house * len_house;
                                 //Divide area of yard and rate of cutting to find time
                                 speed_lawn_user_min = speed_lawn_user_sec * 60;
                                 time_lawn = (area_yard) * (1/speed_lawn_user_min);

                                  //Calculate if area of house is bigger than the area of the yard.
                                  if (area_house > area_yard)
                                    {   //If area of house bigger than yard, print text, stop program.
                                        printf ("\nThat cannot be, your house is bigger than your yard!\n");
                                    }
                                    else
                                        {
                                            //Display area and time of cutting to mow it
                                            printf("\nThe area of the house with a width of %.2f feet and the length of %.2f feet is %.2f square feet.\nThe area of the yard with a width of %.2f feet and the length of %.2f feet is %.2f square feet. It takes %.2f minutes to mow it.",wid_house, len_house, area_house, wid_yard, len_yard, area_yard, time_lawn);
                                        }

                         }
                         else{
                                //Print lawn mower is out of range, close program.
                                printf("\n The lawn mower is out of range, ensure that the lawn mower is between 1.5 square feet per second and 3 square feet per second.");
                            }
                    }
                    else{
                         //Print that the house is not in the correct parameters, and end program.
                         printf("\nYour house is not in the correct parameters! The house's width and length must be between 100 and 1000 feet.\n");
                        }
                }
            else{
                    //If length and width of yard do not much parameters, print, and close program.
                    printf("Your yard is not in the correct parameters! The yard's width and length must be between 100 and 1000 feet.");

                }
        }
 //End Program
 return(0);
}
