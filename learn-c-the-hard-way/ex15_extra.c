#include <stdio.h>

void print_by_array_index(int *ages, char *names[], int count)
{
	for (int i = 0; i < count; i++) {
		printf("%s has %d years alive. \n", names[i], ages[i]);
	}
}

void print_by_array_pointer(int *ages, char *names[], int count)
{
	for (int i = 0; i < count; i++) {
		printf("%s is %d years old. \n", *(names + i), *(ages + i));
	}
}

void print_by_moving_pointers(int *ages, char *names[], int count)
{
	int *cur_age = ages;
	char **cur_name = names;
	for (; (cur_age - ages) < count; cur_name++, cur_age++) 
	{
		printf("%s lived %d years so far.\n", *cur_name, *cur_age);
	}
}

int main(int argc, char *argv[])
{
	char **cur_arg = argv;
	for (int i = 1; i < argc; i++) {
		printf("arg %d is %s\n", i, *(cur_arg + i));
	}
	printf("---\n");

	// create two arrays we care about
	int ages[] = { 23, 43, 12, 89, 2 };
	char *names[] = {
		"Alan", "Frank",
		"Mary", "John", "Lisa"
	};

	// safely get the size of ages
	int count = sizeof(ages) / sizeof(int);
	print_by_array_index(ages, names, count);
	printf("---\n");

	print_by_array_pointer(ages, names, count);
	printf("---\n");

	print_by_moving_pointers(ages, names, count);
	printf("---\n");

	int *cur_age = ages;
	char **cur_name = names;
	for (int i = 0; i < count; i++) {
		printf("address of \tname %s is \t%p.\n", *(cur_name + i), cur_name + i);
		printf("address of \tage %d is \t%p.\n", *(cur_age + i), cur_age + i);
	}

	return 0;
}
