# include <stdio.h>
# include <string.h>
# include <stdlib.h>


char* convert(char* s, int numRows) {
    int s_len = strlen(s);
    if (s_len==1 || numRows==1) return s;
    int* row_lens = malloc(sizeof(int)*numRows);
    char* res = malloc(s_len+1);
    res[s_len] = '\0';

    // first assume only full cols
    int col_size = (numRows*2)-2;
    int full_cols = strlen(s) / col_size;
    int half_cols = strlen(s) % col_size;
    // printf("%d\n",col_size);
    // printf("%d\n",full_cols);

    for (int i = 0; i < numRows; i++) {
        if (i==0) {
            row_lens[0] = full_cols;
            if (half_cols>0) row_lens[0]++;
        } else if (i<numRows-1) {
            row_lens[i] = 2*full_cols;
            if (half_cols>i) {
                row_lens[i]++;
            }
            if (half_cols>(col_size-i)) {
                // printf("added extra full col for row %d\n", i);
                row_lens[i]++;
            }
        } else if (i==numRows-1) {
            row_lens[numRows-1] = full_cols;
            if (half_cols>i) row_lens[numRows-1]++;
        } else {
            // fprintf(stderr, "ERROR: invalid row_lens state\n");
        }
    }
    // printf("row_lens:\n");
    // for (int i = 0; i < numRows; i++)
    // {
    //     printf("row %d has %d\n",i ,row_lens[i]);
    // }

    int s_idx=0;
    int r_idx=0;
    for (int i = 0; i < numRows; i++) {
        for (int j = 0; j < row_lens[i]; j++) {
            if (i==0) {
                r_idx = col_size * j;
            } else if (i>0&&i<numRows-1) {
                if (j%2==1) {
                    r_idx = (i + col_size * (j/2)) + (((numRows-1)-i)*2);
                } else {
                    r_idx = i + col_size * (j/2);
                }
            } else if (i==numRows-1) {
                r_idx = i + col_size*j;
            }
            // printf("i=%d; j=%d; r_idx=%d; s[%d]=%c\n",i,j,r_idx,s_idx,s[s_idx]);
            res[s_idx] = s[r_idx];
            s_idx++;
        }
    }
    free(row_lens);
    // for (int i = 0; i < full_cols+1; i++) {
    //     for (int j = 0; j < col_size; j++) {
    //         int out_s_idx = i*numRows+j;
    //         if (s[out_s_idx]=='\0') {
    //             printf("Got to end of input string");
    //             return NULL;
    //         }
    //         if (j==0) {
    //             printf("->first char in col %d:\n", i);
    //             if (half_rows) {
    //                 printf("    char %d, is %c\n\n", out_s_idx, s[i]);
    //             } else {
    //                 printf("    char %d, is %c\n\n", out_s_idx, s[i]);
    //             }
    //         } else if (j>0&&j<(numRows-1)) {
    //             printf("->mid char (%d) in col %d:\n",j,i);
    //             printf("    char %d, is %c\n\n", out_s_idx, s[full_cols + (2*full_cols)*(j-1) + 2*i]);
    //         } else if (j==numRows-1) {
    //             printf("->bottom char (%d) in col %d:\n",j,i);
    //             printf("    char %d, is %c\n\n", out_s_idx, s[full_cols + (2*full_cols)*(j-1) + i]);
    //         } else if (j>numRows-1&&j<col_size) {
    //             printf("->right wing char (%d) in col %d:\n",j,i);
    //             printf("    char %d, is %c\n\n", out_s_idx, s[full_cols + (2*full_cols)*(abs(col_size-j)-1) + 2*i+1]);
    //             if (j==col_size-1) {
    //                 printf("done col %d\n\n", i);
    //             }
    //         } else {
    //             fprintf(stderr, "ERROR: invalid col position bound state\n");
    //         }
    //     }
    // }
    return res;
}

int main () {
    // char* s = "PINALSIGEYAHRNNPIO"; // PAYPALISHIRINGNONE
    // char *s = "PINALSIGYAH";
    // char *s = "PINALSIGYAHRPI";
    char *s = "PAYPALISHIRINGNO";
    char *r = convert(s, 5);
    printf("res = %s\n", r);
    free(r);
}