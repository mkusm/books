#include <stdio.h>
#include <ctype.h>
#include <string.h>

// forward declarations
int can_print_it(char ch);
void print_letters(char arg[], int);
void print_digits(char arg[], int);

void print_arguments(int argc, char *argv[])
{
	int i = 0;

	for (i = 0; i < argc; i++) {
		int len = strlen(argv[i]);
		print_letters(argv[i], len);
		print_digits(argv[i], len);
	}
	printf("\n");
}

void print_letters(char arg[], int len)
{
	int i = 0;

	for (i = 0; i < len; i++) {
		char ch = arg[i];

		if (isalpha(ch) || isblank(ch)) {
			printf("letters and blanks: '%c' == %d \n", ch, ch);
		}
	}
}

void print_digits(char arg[], int len)
{
	int i = 0;

	for (i = 0; i < len; i++) {
		char ch = arg[i];

		if (isdigit(ch) || ispunct(ch)) {
			printf("digits and other:   '%c' == %d \n", ch, ch);
		}
	}
}

int main(int argc, char *argv[])
{
	print_arguments(argc, argv);
	return 0;
}
