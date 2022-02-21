#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <string.h>

void sort(char arr[][50], int n)
{
	char cuv[100]{};

	for (int i = 0; i < n - 1; i++)
		for (int j = 0; j < n - i - 1; j++)
		{
			if (strlen(arr[j]) < strlen(arr[j + 1]))
			{
				strcpy(cuv, arr[j]);
				strcpy(arr[j], arr[j + 1]);
				strcpy(arr[j + 1], cuv);
			}
			else if (strlen(arr[j]) == strlen(arr[j + 1]))
			{
				if (strcmp(arr[j], arr[j + 1]) > 0)
				{
					strcpy(cuv, arr[j]);
					strcpy(arr[j], arr[j + 1]);
					strcpy(arr[j + 1], cuv);
				}
			}
		}
}


int main()
{
	char str[50]{};

	char cuv[50][50];

	scanf("%[^\n]", str);

	char sep[]{" "};
	char* p = strtok(str, sep);

	int len{ 0 };
	while (p != NULL)
	{
		strcpy(cuv[len], p);
		p = strtok(NULL, sep);
		++len;
	}

	sort(cuv, len);

	for (int i{ 0 }; i < len; ++i)
	{
		printf("%s\n", cuv[i]);
	}

	return 0;
}
