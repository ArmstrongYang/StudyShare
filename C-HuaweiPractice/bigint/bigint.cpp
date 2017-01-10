#include<stdio.h>
#include <iostream>  
#include <cstring>  
  
#define MAX 255


void add(char *s1, char* s2)
{
	int num1[MAX], num2[MAX], sum[MAX];
	int l1, l2;

	for (l1 = 0; s1[l1] != '\0'; l1++)
	{
		num1[l1] = s1[l1] - '0';
	}

	for (l2 = 0; s2[l2] != '\0'; l2++)
	{
		num2[l2] = s2[l2] - '0';
	}

	int carry = 0;
	int k = 0;
	int i = l1 - 1;
	int j = l2 - 1;
	for (; i >= 0 && j >= 0; i--, j--, k++)
	{
		sum[k] = (num1[i] + num2[j] + carry) % 10;
		carry = (num1[i] + num2[j] + carry) / 10;
	}
	if (l1 > l2) {
		while (i >= 0) {
			sum[k++] = (num1[i] + carry) % 10;
			carry = (num1[i--] + carry) / 10;
		}
	} 
	else if (l1 < l2) {
		while (j >= 0) {
			sum[k++] = (num2[j] + carry) % 10;
			carry = (num2[j--] + carry) / 10;
		}
	} 
	else {
		if (carry > 0)
		{
			sum[k++] = carry;
		}
	}
	
	printf("Result:");
	for (k--; k >= 0; k--)
	{
		printf("%d", sum[k]);
	}
	printf("\n");
}

int main() {

	char s1[MAX], s2[MAX];
	printf("Enter Number1:");
	scanf_s("%s", s1, sizeof(s1));
	printf("Enter Number2:");
	scanf_s("%s", s2, sizeof(s2));
	add (s1,s2);
	return 0;
}


