#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include "palindrome2.h"
// #include palindrome.h

// char* strrev(char* str) {
//     size_t str_len = strlen(str);
//     char* rev_str = malloc(str_len+1);
//     for (size_t i = 0; i < str_len; i++) {
//         rev_str[i] = str[str_len-(i+1)];
//     }
//     rev_str[str_len] = '\0';
//     return rev_str;
// }

int main() {
    // char* rev_str = strrev("baobab");
    // char* rev_str = strrev("mwwfjysbkebpdjyabcfkgprtxpwvhglddhmvaprcvrnuxifcrjpdgnktvmggmguiiquibmtviwjsqwtchkqgxqwljouunurcdtoeygdqmijdympcamawnlzsxucbpqtuwkjfqnzvvvigifyvymfhtppqamlgjozvebygkxawcbwtouaankxsjrteeijpuzbsfsjwxejtfrancoekxgfyangvzjkdskhssdjvkvdskjtiybqgsmpxmghvvicmjxqtxdowkjhmlnfcpbtwvtmjhnzntxyfxyinmqzivxkwigkondghzmbioelmepgfttczskvqfejfiibxjcuyevvpawybcvvxtxycrfbcnpvkzryrqujqaqhoagdmofgdcbhvlwgwmsmhomknbanvntspvvhvccedzzngdywuccxrnzbtchisdwsrfdqpcwknwqvalczznilujdrlevncdsyuhnpmheukottewtkuzhookcsvctsqwwdvfjxifpfsqxpmpwospndozcdbfhselfdltmpujlnhfzjcgnbgprvopxklmlgrlbldzpnkhvhkybpgtzipzotrgzkdrqntnuaqyaplcybqyvidwcfcuxinchretgvfaepmgilbrtxgqoddzyjmmupkjqcypdpfhpkhitfegickfszermqhkwmffdizeoprmnlzbjcwfnqyvmhtdekmfhqwaftlyydirjnojbrieutjhymfpflsfemkqsoewbojwluqdckmzixwxufrdpqnwvwpbavosnvjqxqbosctttxvsbmqpnolfmapywtpfaotzmyjwnd");
    // if (!rev_str) return 1;
    // printf("%s\n", rev_str);
    // free(rev_str);

    // char* copied_s = malloc(4);
    // strncpy(copied_s, rev_str, 3);
    // printf("%s, %zu\n",copied_s, strlen(copied_s));

    char* s = "baobab";

    char* lp = longestPalindrome(s);
    printf("%s\n",lp);
    return 0;
}