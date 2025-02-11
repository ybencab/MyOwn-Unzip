#include <stdio.h>
#include <stdlib.h>

void usage(void);

int main(int argc, char *argv[]) {
  if (argc != 2) {
    usage();
  }
  
  return 0;
}

void usage(void) {
  fprintf(stderr, "Usage: ./lunzip destination_file\n");
  exit(1);
}