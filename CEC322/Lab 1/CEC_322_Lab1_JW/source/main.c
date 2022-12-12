/* Code by Jeremiah Webb
Student ID: 2545328
Date: 9/10/21
Class: CEC 222
Section #2
*/
#include <stdio.h>
#include <stdint.h>
#include <math.h>

//Store euclidean norm value
uint32_t euclidean_norm = 0;

//Stores the max value of a uin32
uint32_t max_of_uint32_t = 0;

//Stores the 1-11th values of the fibonacci sequence
uint32_t fibonacci_array[10];


void generate_fibo_array(uint32_t N, uint32_t *ptrarray) {
	//Assign 1 to initial values
	ptrarray[0] = 1;
	ptrarray[1] = 1;
	for (uint32_t i = 2; i < N; i++) {
    //Compute values with the recursive formulia
    ptrarray[i] = ptrarray[i - 2] + ptrarray[i - 1];
	}
}

uint32_t calculate_eucl_norm(uint32_t N, uint32_t *ptrarray) {
  //n dimensional distance formulia
  uint32_t total = 0;
  for (uint32_t i = 0; i < N; i++) {
    total += ptrarray[i] * ptrarray[i];
  }
  //Calcuale the square root of the squared total
  float norm = sqrtf(total);
	
  return (uint32_t) norm;
}

uint32_t print_array(uint32_t N, uint32_t *ptrarray) {
	for(uint32_t i = 0; i < N; i++) {
		printf("%d ", ptrarray[i]);
	}
}

void main() {
	//Assign team names
	char my_team[] = "Jeremiah Webb";
	printf("\nResults of Lab 1 from %s. \n", my_team);
	
	//Print address for fibonacci array
	printf("\nThis is the address for fibonacci array: 0x%p\n", &fibonacci_array);
	
	
	//Print address for euclidean norm
	printf("\nThis is the address for the euclidean_norm in hex: 0x%p\n", &euclidean_norm);
	
	
	//Assign max and print it
  max_of_uint32_t = 0xFFFFFFFF;
	printf("\nmax_of_uint32_t: %u at 0x%p\n", max_of_uint32_t, &max_of_uint32_t);
	
	//Generate array for Fibonacci
	generate_fibo_array(10, fibonacci_array);
	
	//Calculate Euclidean Norm
	euclidean_norm = calculate_eucl_norm(10, fibonacci_array);
	
	//Print array
	print_array(12, fibonacci_array);
  

}