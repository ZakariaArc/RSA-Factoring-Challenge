#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <string.h>

void factorize_numbers(char *file_name)
{
	FILE *file_stream;
	char *line = NULL;
	size_t line_length = 0;
	long long is_factorizable = 1, divisor, remainder, number, counter;
	ssize_t read_bytes;

	file_stream = fopen(file_name, "r");
	if (file_stream == NULL)
	{
		perror("fopen");
		exit(EXIT_FAILURE);
	}

	while ((read_bytes = getline(&line, &line_length, file_stream)) != -1)
	{
		is_factorizable = 1;
		divisor = 2;
		number = atoll(line);
		while (is_factorizable)
		{
			remainder = number % divisor;
			if (!remainder)
			{
				counter = number / divisor;
				printf("%lld=%lld*%lld\n", number, counter, divisor);
				is_factorizable = 0;
			}
			divisor++;
		}
	}

	free(line);
	fclose(file_stream);
}

int main(int argc, char *argv[])
{
	if (argc != 2)
	{
		fprintf(stderr, "Usage: %s <file>\n", argv[0]);
		exit(EXIT_FAILURE);
	}
	factorize_numbers(argv[1]);
	exit(EXIT_SUCCESS);
}
