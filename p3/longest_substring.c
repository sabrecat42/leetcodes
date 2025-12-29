# include <stdio.h>
# include <string.h>
# include <stdlib.h>

void append_char(char* s, char c) {
    int len = strlen(s);
    s[len] = c;
    s[len+1] = '\0';
}

int char_in_string(const char*s, char c) {
    int len = strlen(s);
    for (size_t i = 0; i < len; i++) { if (s[i] == c) return i; }
    return -1; 
}

int lengthOfLongestSubstring(const char* s) {
    int longest_substr_len = 0;
    int stringLen = strlen(s);
    char* subStrStart = malloc(stringLen+1);
    char* subStr = subStrStart;
    subStr[0] = '\0';
    // printf("working with string: %s\n\n", s);
    for (int i = 0; i < stringLen; i++) {
        // printf("looking at char %c\n", s[i]);
        int char_in_str_idx = char_in_string(subStr, s[i]);
        if (char_in_str_idx > -1) {
            // printf("l43: for -> if => detected char %c in substr: %s\n", s[i], subStr);
            int current_substr_len = strlen(subStr);
            if (current_substr_len > longest_substr_len) {
                longest_substr_len = current_substr_len;
                // printf("l47: for -> if -> if => new longest substr_len: %d\n", longest_substr_len);
            }
            append_char(subStr, s[i]);
            subStr = subStr + char_in_str_idx + 1;
            // printf("l51: for -> if => new substr: %s\n", subStr);
        } else {
            append_char(subStr, s[i]);
            // printf("l50: new unique char '%c' added to substr: %s\n\n",s[i],subStr);
            int current_substr_len = strlen(subStr);
            if (i==(stringLen-1) && (current_substr_len > longest_substr_len)) {
                longest_substr_len = current_substr_len;
                // printf("l56: for -> if -> else => (last char in s) new longest substr_len: %d\n", longest_substr_len);
            }
        }
    }
    free(subStrStart);
    return longest_substr_len;
}

int main() {

    char buff[90000];
    if (fgets(buff, sizeof buff, stdin)!=NULL) {
        buff[strcspn(buff,"\n")] = '\0';
        printf("%d\n", lengthOfLongestSubstring(buff));
    } 

    // char* s1 = "bbaobab"; 
    // char* s2 = "fargoazxvm"; 
    // char* s3 = "faaargoaxzmt"; 
    // char* s4 = "pwwkew"; 

    // char* rm = rm_incl_first(s1, 'b');
    // printf("rm from %s until first %c -> %s\n", s1, 'b', rm);
    // int in_str = char_in_string(s3, 't');
    // printf("%c in %s -> %d\n", 't', s3, in_str);

    // printf("%s",s1);
    // printf("%d\n", lengthOfLongestSubstring(s1));
    // printf("%s -> ",s2);
    // printf("%d\n", lengthOfLongestSubstring(s1));
    // printf("%s -> ",s3);
    // printf("%d\n", lengthOfLongestSubstring(s3));
    // printf("%s",s4);
    // printf("%d\n", lengthOfLongestSubstring(s4));

}

// for each char in string:
    //  add to substring
    //  if already in current substring ->
        // if (substring len > prev substr_len) -> sub_str_len = len(current_substr)-1 ;
        // set head of longest substring to next char after first occurance of repeated char;

// baobab -> bao
// fargoazxvm -> rgoazxvm
// fargoaazxvm -> azxvm
// faaargoaxzmt -> rgoaxzmt

// // remove char from head until first occurance of given char
// char* rm_incl_first(char* s, char c) {
//     printf("rm_until_char: %s, %c\n",s,c);
//     char current_char;
//     do { 
//         current_char = s[0];
//         s++;
//         if (current_char == '\0') { fprintf(stderr, "ERROR: rm_incl_first didn't find char in str\n"); exit(EXIT_FAILURE); return NULL; }
//     } while (current_char != c);
//     printf("rm_until_char will return: %s \n\n", s);
//     return s;
// }