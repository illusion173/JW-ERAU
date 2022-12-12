/* -----------------------------------------------
  	 Submitted By: Jeremiah Webb
  	 Homework Number: #8
   	 Credit to:

   	 Ryan Lucas (Student in other CS223 section)

  	 Submitted On: 4/5/21

 	  By submitting this program with my name,
 	  I affirm that the creation and modification
 	  of this program is primarily my own work.
 ------------------------------------------------ */

 //Include libraries
 #include <stdio.h>
 #include <stdlib.h>
 #include <math.h>
 #include <time.h>
 #include <ctype.h>

 //Define constants
 #define MAXCHAR 1000
 #define INTCHAR 3


 //prototypes
double distCalc(int x, int y, int z);

 void main()
 {
     //open file and make a pointer
     FILE *pfile = fopen("location.txt", "r");
     FILE *ofile  = fopen("distance.txt", "w");
     /*
     char coords[MAXCHAR];
     */
     //initialize x, y, integer coordinates to be used for mathematics in distcalc function.
     int x_coordinate;
     int y_coordinate;
     int z_coordinate;
     //Initialize distance integer
     int distance;
     //initialize arrays to store array elements
     char line[MAXCHAR];
     //array to store name of row
     char name[MAXCHAR];
     //array to store x value
     int xcomp[INTCHAR];
     //array to store y value
     int ycomp[INTCHAR];
     //array to store z value
     int zcomp[INTCHAR];


     printf("\nThis program was made by Jeremiah Webb!\n\n");

     //create table headers
     printf("Name");
     printf("\t X");
     printf("\t Y");
     printf("\t Z");
     printf("\t Distance\n");
     //write headers for distance.txt
     fprintf(ofile, "Name\tDistance\n");

    //if statement to determine if the file chosen is able to be open, if so, continue with code, if not end program.
    if(pfile != NULL)
    {
        //while loop, fscanf condition input all string data into assigned arrays.
        while(fscanf(pfile, "%s %s %s %s", name, &xcomp, &ycomp, &zcomp)==4)
        {
            //Atoi was new to learn, but after learning what it could do, it converts the array's string character digits to mathematical integers we can use for math
            x_coordinate = atoi(xcomp);
            y_coordinate = atoi(ycomp);
            z_coordinate = atoi(zcomp);
            //calculate distance from distcalc function, input all the x, y, and z integers.
            distance = distCalc(x_coordinate, y_coordinate, z_coordinate);
            //print all the needed data from the arrays to create table.
            printf("%s\t %s\t %s\t %s\t %d miles\n", name, xcomp, ycomp, zcomp, distance);
            //input data from distance and name into distance.txt, begins to create visual table.
            fprintf(ofile, "\n%s\t%d Miles\n",name, distance);
        }
    }
    else
    {
        printf("File does not exist");
    }

    /* Program to print initial data
    while(!feof(pfile))
    {
         fgets(coords, MAXCHAR, pfile);
         printf("%s", coords);
    }
    */

    //close files
     fclose(pfile);
     fclose(ofile);
 return(0);
 }

 //calculate distance from origin using passed x, y, z coordinates
 double distCalc(int x, int y, int z)
 {
     //initialize distance variable
     int distance;
     //mathematical equation to find distance
     distance = sqrt((pow(x, 2)+(pow(y, 2)+(pow(z, 2)))));
     //returns distance variable to main function
     return(distance);
 }
