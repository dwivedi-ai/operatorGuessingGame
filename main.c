#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define MIN_EXPRESSIONS 3
#define MAX_EXPRESSIONS 5

int fetchRandom(int min, int max)
{
	return (int)(rand() % (max - min + 1) + min);
}

void displayHeader()
{
	printf("Welcome to Operator Guessing Game\n");
	printf("====Developed by Ankit Dwivedi====\n");
	printf("Note: This game does not work on BODMAS concept. Instead the expression is solved linearly\n\n");
}

char fetchOperator(float *result, int number)
{
	switch (fetchRandom(1, 4))
		{
		case 1: *result += number;
				return '+';
				break;
		case 2: *result -= number;
				return '-';
				break;
		case 3: *result *= number;
				return '*';
				break;
		case 4: *result /= (float)number;
				return '/';
				break;
		}
}

void displayExpression(int numberOfExpressions, int numbers[], char operators[], float result)
{
	printf("Here is your expression: ");
	for(int i = 0; i < numberOfExpressions; i++)
	{
		printf("%d ", numbers[i]);
		if (i < numberOfExpressions - 1)
			printf("[ ] ");
	}
	printf("= %.2f\n\n", result);
}

int checkResult(int numberOfExpressions, int numbers[], char answers[], float result)
{
	float testResult = numbers[0];
	for(int i = 0; i < numberOfExpressions - 1; i++)
	{
		switch (answers[i])
		{
		case '+': testResult += numbers[i + 1];
				break;
		case '-': testResult -= numbers[i + 1];
				break;
		case '*': testResult *= numbers[i + 1];
				break;
		case '/': testResult /= (float)numbers[i + 1]; 
				break;
		}
	}
	if (testResult == result)
		return 1;
	else
		return 0;
}

int displayResult(int flag)
{
	if (flag)
	{
		printf("You got it right!\n");
		return 1;
	}
	else
	{
		printf("Oops! that is wrong...\n");
		return 0;
	}
}

void displayAnswer(int numberOfExpressions, int numbers[], char operators[], float result)
{
	printf("\nCorrect answer: ");
	for(int i = 0; i < numberOfExpressions; i++)
	{
		printf("%d ", numbers[i]);
		if (i < numberOfExpressions - 1)
			printf("%c ", operators[i]);
	}
	printf("= %.2f\n\n", result);
}

int main()
{
	srand(time(NULL));
	int numberOfExpressions = fetchRandom(MIN_EXPRESSIONS, MAX_EXPRESSIONS);
	int numbers[numberOfExpressions];
	char operators[numberOfExpressions - 1], answers[numberOfExpressions - 1];

	for(int i = 0; i < numberOfExpressions; i++)
		numbers[i] = fetchRandom(1, 10);
	
	float result = numbers[0];
	for(int i = 0; i < numberOfExpressions - 1; i++)
	{
		operators[i] = fetchOperator(&result, numbers[i + 1]);
	}

	displayHeader();
	displayExpression(numberOfExpressions, numbers, operators, result);

	printf("Input your answer separated by spaces: ");
	for(int i = 0; i < numberOfExpressions - 1; i++)
	{
		scanf("%c", &answers[i]);
		char garbage;
		scanf("%c", &garbage);
	}
	int flag = checkResult(numberOfExpressions, numbers, answers, result);
	if (!displayResult(flag))
		displayAnswer(numberOfExpressions, numbers, operators, result);
	return 0;
}