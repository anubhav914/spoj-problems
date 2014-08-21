#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int compare(const void *x, const void *y){
    return (*(char *)x) - (*(char *)y) ;
}


void sortStrInParts(char *str, int a, int b){
    qsort(str, a, sizeof(char), compare);
    qsort(str+a, b, sizeof(char), compare);
}

void printStr(char *str, int size){
    for (int i = 0; i < size; ++i)
    {
        printf("%c", str[i]);
    }
    printf("\n");
}

//returns the intersection count between 
//2 strings
int intersecArrays(char *str1, int s1, char *str2, int s2){
    int count = 0, i = 0, j = 0;
    while(i < s1 && j < s2){
        if(str1[i] == str2[j]){
            i++; j++; count++;
        }
        else if(str1[i] > str2[j]) j++;
        else i++;
    }
    return count;
}



int minChange(char *str){
    int len = strlen(str);
    int a = len/2, b = len - len/2;
    if(a != b) return -1;
    sortStrInParts(str, a, b);
    // printStr(str, a);
    // printStr(str+a, b);
    // printf("%d\n", intersecArrays(str, a, str+a, b));
    return len/2 - intersecArrays(str, a, str + a, b);
}


int main(){
    int T;
    scanf("%d", &T);
    while(T--){
        char *str = (char *)calloc(10002, sizeof(char));
        scanf("%s", str);
        //printf("%s\n", str);
        printf("%d\n", minChange(str));
        free(str);
    }
}