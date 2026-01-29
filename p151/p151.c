#include <stdlib.h>
#include <stdio.h>
#include <string.h>

// " fuck you  \0" -> "\0\0fuck\0you\0" -> {*->you, *->fuck} -> ["you","fuck"]
// "fuck you\0" -> "fuck\0you" -> {*->you, *->fuck} -> ["you","fuck"]
// "\0" -> [\0]

int countWords(char* s) {
    int count = 0;
    for (size_t i = 0; i < strlen(s); i++) {
        if ((i==strlen(s)-1) && s[i]!=' ') {
            count++;
            break;
        } else if (s[i]!=' ' && s[i+1]==' ') {
            count++;
        }
    }
    return count;
}

char* reverseWords(char* s) {
    if (strlen(s)==0) return s;
    int word_count = countWords(s);
    printf("%d\n",word_count);
    char** reversedStrings = malloc(word_count * sizeof(char*)); // * -> {*->str1, *->str2,...}
    if (reversedStrings != NULL) {
        printf("allocated reversedStrings\n");
    }
    int word_idx = 0;
    for (int i = strlen(s)-2; i >= 0; i--) {
        printf("i=%d; Looking at char=%c\n",i,s[i]);
        if (i == 0) {
            if (s[i]!=' ') {
                printf("Adding last (first) string=%s\n",s);
                reversedStrings[word_idx++] = s;
            }
            break;
        } else if (s[i]==' ' && s[i+1]!='\0') {
            printf("Adding string=%s\n",s+i+1);
            reversedStrings[word_idx] = s+i+1;
            word_idx++;
        }
        if (s[i]==' ') s[i]='\0';
    }
    int idx = 0;
    for (size_t i = 0; i < word_count; i++)
    {
        printf("%s; ", reversedStrings[i]);
        // strcpy(s + idx, reversedStrings[i]);
        memmove(s + idx, reversedStrings[i], strlen(reversedStrings[i]) + 1);
        if (i<word_count-1) {
            idx += strlen(reversedStrings[i]);
            s[idx] = ' ';
            idx++;
        } else if (i==word_count-1) {
            idx += strlen(reversedStrings[i]);
            s[idx] = '\0';
        } else {
            printf("error");
        }
    }
    printf("to return s=%s\n",s);
    free(reversedStrings);
    return s;
}

int main(int argc, char const *argv[])
{
    // printf("%lu",sizeof(char*));
    // char* stuff = "  fuck you   asdj s w2";
    char* stuff = strdup("  fuck you   asdj s w2   ");
    // int count = countWords(stuff);
    // printf("%d",count);
    reverseWords(stuff);
    return 0;
}
