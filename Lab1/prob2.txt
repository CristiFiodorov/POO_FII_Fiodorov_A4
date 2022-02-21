##include <stdio.h>
#include <string.h>

int convert(char* str)
{
	int number{ 0 };

	for (int i{0}; str[i]; ++i)
	{
		number *= 10;
		number += (int)str[i] - 48;
	}

	return number;
}

int main()
{
	FILE* file{};

	if (fopen_s(&file, "input.txt", "r") != 0)
	{
		printf("Eroare\n");
	}
	else 
	{
		char str[200]{};
		int suma{ 0 };

		while (fgets(str, 200, file))
		{
			str[strlen(str) - 1] = '\0';
			suma += convert(str);
		}
		printf("%d\n", suma);
	}

	return 0;
}