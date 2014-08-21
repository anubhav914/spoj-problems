#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MOD 1000000007 

//count of pairs of subsequence in the string
//that are same.
//S[i][j] is the number pair of subsequences such that
//first subsequence ends at i and the second subsequence
//ends at j. To remove repition we will take j > i




int **SSC; //similar subsequence count

int sim(int i, int j, char *str){
    if(i == j) return 0;
    return str[i-1] == str[j-1];
}

int squareSubCount(char *str, int len){
    int sum = 0;
    if(str[i] == str[j]){
    
    }
}

int main(){
    int T;
    scanf("%d", &T);
    while(T--){
        char *str = (char *)calloc(202, sizeof(char));
        scanf("%s", str);
        int len = strlen(str);
        SSC = (int ***)calloc(len/2+2, sizeof(int **));
        for(int i = 0; i < len/2 + 2; i++){
            SSC[i] = (int **)calloc(len+1, sizeof(int *));
            for(int j = 0; j <= len; j++)
            SSC[i][j] = (int *)calloc(len+1, sizeof(int));
        }
        printf("%d\n", squareSubCount(str, len));
    }
}