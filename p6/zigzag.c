# include <stdio.h>
# include <string.h>
# include <stdlib.h>


char* convert(char* s, int numRows) {
    // first assume only full cols
    int col_size = (numRows*2)-2;
    int full_cols = strlen(s) / col_size;
    int half_cols = strlen(s) % col_size;
    printf("%d\n",col_size);
    printf("%d\n",full_cols);

    int* row_lens = malloc(sizeof(int)*numRows);

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
                printf("added extra full col for row %d\n", i);
                row_lens[i]++;
            }
        } else if (i==numRows-1) {
            row_lens[numRows-1] = full_cols;
            if (half_cols>i) row_lens[numRows-1]++;
        } else {
            fprintf(stderr, "ERROR: invalid row_lens state\n");
        }
    }
    printf("row_lens:\n");
    for (int i = 0; i < numRows; i++)
    {
        printf("row %d has %d\n",i ,row_lens[i]);
    }

    int s_len = strlen(s);
    char* res = malloc(s_len+1);
    res[s_len] = '\0';

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
            printf("i=%d; j=%d; r_idx=%d; s[%d]=%c\n",i,j,r_idx,s_idx,s[s_idx]);
            res[s_idx] = s[r_idx];
            // last:
            s_idx++;
        }
    }

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
}

// char = s[full_colls + (full_cols * 2 * j) + 2*i]

// P    I    N
// A  L S  I G  E
// Y A  H R  N N
// P    I    O

// 0      1     2
// 3   4  5  6  7   8
// 9 10  11 12 13 14
// 15    16    17

// 0      1     2
// 3   4  5   6 7
// 8 9   10 11
// 12    13

// 0      6      12
// 1   5  7   11 13
// 2 4    8 10
// 3      9

// rows[i]  = row_i_len
// full_cols
// last_col

// for i=range(len(rows)):
    // for j=range(rows[i]):
        // if row==0:
            // res[i+] = s[i*len(rows[])]





// i -> col
// j -> pos_in_col
    // if j==0:
        // p[i*n_rows+j] = i
    // else if (j>0&&j<n_rows-1):
        // p[i*n_rows+j] = s[n_cols + j*(2*n_cols) + i*2];      // count top row with single char + rows above with 2 chars + chars to left
    // else if (j=n_rows-1):
        // p[i*n_rows+j]= s[n_cols + j*(2*n_cols) + i];
    // else if (j>=n_rows&&j<col_size):
        // p[i*n_rows+j]= s[n_cols + 2*(j-(n_rows-1))*(2*n_cols) + i]
        // 






//  p -> idx = 0
//  I -> idx += r_len * i + (r_len-2)*i = 0+ 4*1 + 2*1 = 6
//  N -> 4*2 + 2*2 = 12
// idx = idx + 
//  A -> 

// col_size = r_len*2-2
// full_cols = len(s)/(col_size)
// for i=range(full_cols):
//  for j=range(col_size):
    // if j == 0:
        // idx = i * col_size 
    // else if j > 0: 
        // if (i>0):
            // idx = (full_cols + i*2)
        // idx = full_cols * j
    //  res_str[i*col_size+j] = 


