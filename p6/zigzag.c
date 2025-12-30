# include <stdio.h>
# include <string.h>
# include <stdlib.h>


char* convert(char* s, int numRows) {
    // first assume only full cols
    int col_size = (numRows*2)-2;
    int full_cols = strlen(s)/col_size;
    printf("%d\n",col_size);
    printf("%d\n",full_cols);

    for (int i = 0; i < full_cols; i++) {
        for (int j = 0; j < col_size; j++) {
            int out_s_idx = i*numRows+j;
            if (j==0) {
                printf("->first char in col %d:\n", i);
                // p[i*numRows+j] = i
                printf("    char %d, is %c\n\n", out_s_idx, s[i]);
            } else if (j>0&&j<(numRows-1)) {
                printf("->mid char (%d) in col %d:\n",j,i);
                printf("    char %d, is %c\n\n", out_s_idx, s[full_cols + (2*full_cols)*(j-1) + 2*i]);
            } else if (j==numRows-1) {
                printf("->bottom char (%d) in col %d:\n",j,i);
                printf("    char %d, is %c\n\n", out_s_idx, s[full_cols + (2*full_cols)*(j-1) + i]);
            } else if (j>numRows-1&&j<col_size) {
                printf("->right wing char (%d) in col %d:\n",j,i);
                printf("    char %d, is %c\n\n", out_s_idx, s[full_cols + (2*full_cols)*(abs(col_size-j)-1) + 2*i+1]);
                if (j==col_size-1) {
                    printf("done col %d\n\n", i);
                }
            } else {
                fprintf(stderr, "ERROR: invalid col position bound state\n");
            }
        }
    }
    return NULL;
}

int main () {
    char* s = "PINALSIGEYAHRNNPIO";
    convert(s, 4);
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


