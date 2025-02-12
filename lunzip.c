#include <stdio.h>
#include <stdlib.h>

void usage(void);
int decompress_file(FILE *, FILE *);

int main(int argc, char *argv[]) {
  if (argc != 2) {
    usage();
  }

  char *output_file = argv[1];

  // Open file
  FILE *fptr = fopen(output_file, "r+");
  if (fptr == NULL) {
    fprintf(stderr, "Not able to open file: %s", output_file);
    exit(1);
  }

  if (decompress_file(fptr, stdout) != 0) {
    fprintf(stderr, "An error has ocurred");
    exit(1);
  }
  
  // Close file
  fclose(fptr);
  return 0;
}

void usage(void) {
  fprintf(stderr, "Usage: ./lunzip destination_file\n");
  exit(1);
}

int decompress_file(FILE *fptr, FILE *out) {
  int num_chars, character;

  while (fread(&num_chars, sizeof(int), 1, fptr) != 0) {
    // Stop if EOF founded
    if (feof(fptr)) break;

    // Read character
    if (fread(&character, sizeof(char), 1, fptr) != 1) {
      return 1;
    }

    // Write characters
    for (int i = 0; i < num_chars; ++i) {
      if (fwrite(&character, sizeof(char), 1, out) != 1) {
        return 1;
      }
    }
  }

  return 0;
}
