#include <stdio.h>


int main()
{
	
	//We define the variables
	int balance = 0; 			//initial balance (to be read from user)
	int increase = 0;			//increase (to be read from user)
	int newbalance = 0;		//new balance (we will calculate this)

	printf("Enter starting balance in Swiss centimes\n");
	scanf("%d", &balance); //reading the initial balance from user
													//VERY IMPORTANT: Notice the & in front of the variable
													//read slides from 26.2.2019, slide 10 for explanation

	printf("Enter increased to be credited to account in swiss centimes\n");
	scanf("%d", &increase); //reading the increase

	newbalance = balance + increase; //calculating the nes balance
	
	printf("Account balance (cents): %d\n", newbalance); //printing the result



	return 0;
}
