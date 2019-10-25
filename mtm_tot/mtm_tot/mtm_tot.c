#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>

void printEnterInputSizeMessage();
void printEnterNumbersMessage();
void printInvalidSizeMessage();
void printInvalidNumberMessage();
void printFoundExponentMessage(int n, int exponent);
void printTotalExponentSum(int n);
int getExponentInBaseTwo(int x);

int main()
{
	
	int input_size = 0;
	int exponent_sum = 0;
	printEnterInputSizeMessage();
	if (scanf("%d", &input_size) == 0 || input_size <= 0)
	{
		// Size is illegal.
		printInvalidSizeMessage();
	}
	else
	{
		int* numbers_array = (int*)malloc(input_size * sizeof(int));
		int count = 0;
		// Initialize array to store the input numbers.
		if (numbers_array == NULL)
		{
			return 0;
		}
		for (int i = 0; i < input_size; i++)
		{
			numbers_array[i] = 0;
		}
		printEnterNumbersMessage();
		for (int i = 0; i < input_size; i++)
		{
			int temp = 0;
			if (scanf("%d", &temp) == 0)
			{
				// Number is illegal.
				printInvalidNumberMessage();
				free(numbers_array);
				return 0;
			}
			numbers_array[i] = temp;
			count++;
			
		}
		for (int i = 0; i <= count; i++)
		{
			// Calculating the base2 exponent of each input number and adding to sum.
			int exponent = getExponentInBaseTwo(numbers_array[i]);
			if (exponent != -1)
			{
				printFoundExponentMessage(numbers_array[i], exponent);
				exponent_sum += exponent;
			}
		}
		printTotalExponentSum(exponent_sum);
		free(numbers_array);
	}
	return 0;
}

void printEnterInputSizeMessage()
{
	printf("Enter size of input:\n");
}

void printEnterNumbersMessage()
{
	printf("Enter numbers:\n");
}

void printInvalidSizeMessage()
{
	printf("Invalid size\n");
}

void printInvalidNumberMessage()
{
	printf("Invalid number\n");
}

void printFoundExponentMessage(int n, int exponent)
{
	printf("The number %d is a power of 2: %d = 2^%d\n", n, n, exponent);
}

void printTotalExponentSum(int n)
{
	printf("Total exponent sum is %d\n", n);
}

int getExponentInBaseTwo(int n)
{
	int count = 0;
	if (n == 0)
	{
		return -1;
	}

	// Divide number until the result is 1.
	while (n != 1)
	{
		// Check if the number is divisable by 2.
		if (n % 2 != 0)
			return -1;
		n /= 2;
		// Count each division to calculate the exponent.
		count++;
	}
	return count;
}