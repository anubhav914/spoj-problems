#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int max(int a, int b){
	return a > b ? a :b;
}


//takes a difference of start positions of both strings, and K, and returns 
//the length of string with mismatch less than or equal to K
int maxLengthWithNoDiff(char *str1, char *str2, int K){
	int len = strlen(str2);
	if(K > len) return len;
	//mismatch[i+1] is the number of mismatches ending at str2[i]
	int *mismatch = (int *)calloc(len+1, sizeof(int));
	for (int i = 0; str2[i]; ++i){
		mismatch[i+1] = (str1[i] != str2[i] ? 1 : 0) + mismatch[i];
	}
	int i = 0, j = K, maxLen = 0;
	while(i <= j && j <= len){
		if(mismatch[j] - mismatch[i] > K){
			maxLen = max(maxLen, j-i-1); i++;
		}
		else j++;
	}	
	return maxLen != 0 ? maxLen : j-i-1;
}


//
int maxLength(char *str1, char *str2, int K){
	int len = strlen(str1); //length of str1 is equal to str2
	int maxLen = 0, temp;
	for(int diff = 0; diff < len; diff++){
		temp = max( maxLengthWithNoDiff(str1, str2+diff, K), 
			   		maxLengthWithNoDiff(str2, str1+diff, K));
		maxLen = max(temp, maxLen);
	}
	return maxLen;
}

int main(){
	int T, K;
	char *str1 = (char *)calloc(1505, sizeof(char));
	char *str2 = (char *)calloc(1505, sizeof(char));
	scanf("%d", &T);
	while(T--){
		scanf("%d %s %s", &K, str1, str2);
		printf("%d\n", maxLength(str1, str2, K));
	}

}