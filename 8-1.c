#include <stdio.h>
#include <stdlib.h>

int main(int argc, const char ** argv[]){
    int len = 11;
    printf("the length of the sequence: %d\n", len);

    int seq[11];
    seq[1] = 49; seq[2] = 38; seq[3] = 65; seq[4] = 97; seq[5] = 76; seq[6] = 13; seq[7] = 27; seq[8] = 49; seq[9] = 55; seq[10] = 4;

    printf("sequence elems: ");
    for(int i = 1;i < len; i++)
        printf("%d ", seq[i]);
    printf("\n");

    int d[3] = {5, 3, 1};

    //shell sort
    for(int i = 0; i < 3; i++){
        for(int j = d[i] + 1; j <= len; j++){
            seq[0] = seq[j];
            int k = j - d[i];
            while(k > 0 && seq[0] < seq[k]){
                seq[k + d[i]] = seq[k];
                k = k - d[i];
            }
            seq[k + d[i]] = seq[0];
        }

        printf("d = %d: ", d[i]);
        for(int i = 1; i <= len; i++)
            printf("%d ", seq[i]);
        printf("\n");
    }

    printf("sequence elems after sorting: ");
    for(int i = 1; i <= len; i++)
        printf("%d ", seq[i]);
    printf("\n");
}
