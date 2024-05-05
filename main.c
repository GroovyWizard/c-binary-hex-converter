#include <stdio.h>
#include <math.h>
#include <string.h>
#include <stdlib.h>

#define DEFAULT_BINARY_DIVISOR  2.0;
#define DEFAULT_HEX_DIVISOR  16.0;
#define BINARY_ONE_STRING "1"
#define BINARY_ZERO_STRING "0"


int getDecimalInput()
{
	int decimalNumber = 0;
	scanf("%d", &decimalNumber);
	return decimalNumber;
}

int transformIntoHex(int decimal) 
{



}

void transformIntoBinary(int number, char *resultArray) 
{
	//Divide the number by 2, if the result is a fractional number
	//then append 1, if its a whole number, append 0
	//repeats until the rest is equal to 0 
	//NOTE: for the next division, use always a whole number
	
	double lastResult = (double) number;

	while(lastResult > 0) {
		printf("Before: %f \n", lastResult);
		int remainder = 0;
		remainder = (int) lastResult % (int) DEFAULT_BINARY_DIVISOR;
		printf("Remainder before: %d \n", remainder);

		if(lastResult == 1) {  
			lastResult = 0;
			strcat(resultArray, BINARY_ONE_STRING);
			break;
		}
									   

		if(remainder == 0) {
			strcat(resultArray, BINARY_ZERO_STRING);
		} else {
			strcat(resultArray, BINARY_ONE_STRING);
		}

		lastResult = lastResult / 2;
		printf("After:  %f \n", lastResult);
		lastResult = floor(lastResult);
	}

	return;

}

void invertBinaryNumberString(char *resultArray) {
	int i, j;
	char temp;
	int length = strlen(resultArray);

        for (i = 0, j = length - 1; i < j; i++, j--) {
		temp = resultArray[i];
		resultArray[i] = resultArray[j];
		resultArray[j] = temp;
	}
}

void showBinaryNumber(char *resultArray) {
	int binaryNumber = atoi(resultArray);
	printf("Binary number:");
	printf("%d", binaryNumber);
}


int main()
{
	char binaryResult[200];
	int inputNumber = 0;
	inputNumber = getDecimalInput();
	transformIntoBinary(inputNumber, binaryResult);
	invertBinaryNumberString(binaryResult);
	showBinaryNumber(binaryResult);
	return 0;
}


