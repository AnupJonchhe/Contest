//const int NUM_SIG = 476251;

#include <cstdio>
#include <cassert>
#include <cstdlib>

int main(int argc, char **argv) {
  if (argc != 6) {
   fprintf(stderr, "Usage %s rowlen binaryfile csvfile xlen ylen\n", argv[0]);
    exit(1);
  }
  int xlen = atoi(argv[4]);
  FILE *fin = fopen(argv[2], "r");
  FILE *fout = fopen(argv[3], "w");
  int ylen = atoi(argv[5]);
  int rowlen = atoi(argv[1]);
  float truth[xlen];
  
  for (int i = 0; i < ylen; ++i) {
    int x = fread(truth, sizeof(float), xlen, fin);
    fseek(fin, sizeof(float)*(rowlen-xlen), SEEK_CUR);
    //    fprintf(stderr, "x=%d\n", x);
    assert(x == xlen);
    for (int j = 0; j < xlen; ++j) {
      if (j) fprintf(fout, "\t");
      fprintf(fout, "%.6lf", truth[j]);
//      printf("truth[%d]: %.6lf\n", j, truth[j]);
    }
    fprintf(fout, "\n");
  }
  return 0;
}
