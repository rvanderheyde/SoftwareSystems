/* A function that takes a command and redirects it to a file
 * -a should append to the end of the file 
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>


int main(int argc, char *argv[]){
	char line[80];

	if (argc < 2) {
		puts("Too few arguments");
		return 1;
	}

	FILE *files[argc-1];
	int i, j;
	int use = 0;
	if (strstr(argv[1],"-a"))
		use = 1;
	for (i=1; i<argc; i++){
		if (!strstr(argv[i],"-a")) {
			if (use) {
				files[i-1] = fopen(argv[i], "a");
			} else {
				files[i-1] = fopen(argv[i], "w");
			}
		}
	}

	while (scanf("%79[^\n]\n", line) == 1) {
		printf("%s\n", line);
		for (j=1; j<argc; j++) {
			if (!strstr(argv[j],"-a"))
				fprintf(files[j-1], "%s\n", line);
		}
	}
	return 0;
} 