#include <stdio.h>
#include <stdbool.h>
#include <math.h>

#pragma warning(disable : 4996)
void printEnterInputSizeMessage();
void printEnterNumbersMessage();
void printInvalidSizeMessage();
void printInvalidNumberMessage();
void printFoundExponentMessage(int n, int exponent);
void printTotalExponentSum(int n);
bool isPowerOfTwo(int n);
int getExponentOfTwo(int n);

int main()
{
	int input_number = 0;
	int exponent_sum = 0;
	printEnterInputSizeMessage();
	if (scanf("%d", &input_number) == 0 || input_number <= 0)
	{
		printInvalidNumberMessage();
	}
	else
	{
		for (int i = 0; i < input_number; i++)
		{
			int temp = 0;
			printEnterNumbersMessage();
			if (scanf("%d", &temp) == 0 || input_number <= 0)
			{
				printInvalidNumberMessage();
				return 0;
			}
			if (isPowerOfTwo(temp))
			{
				int exponent = getExponentOfTwo(temp);
				printFoundExponentMessage(temp, exponent);
				exponent_sum += exponent;
			}
		}
		printTotalExponentSum(exponent_sum);
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

bool isPowerOfTwo(int n)
{
	if (n == 0)
	{
		return false;
	}

	return (ceil(log2(n)) == floor(log2(n)));
}

int getExponentOfTwo(int n)
{
	return log2(n);
}