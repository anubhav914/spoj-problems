#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <string.h>
typedef long long ll;

const int MOD = pow(10,9) + 7;

int modPow(int base, int exponent){
	if(exponent == 1) return base;
	if(exponent%2) return ((ll)base * (ll)modPow(base, exponent-1))%MOD;
	ll temp = modPow(base, exponent/2);
	return (temp*temp)%MOD;
}

int fact(int N){
	ll prod = 1;
	for (ll i = 1; i <= N; i++) prod = (prod*i)%MOD;
	return prod;
}

int inverse(int N){
	return modPow(N%MOD, MOD-2);
}

int countPalinAnagrams(int N, int* chCount, int size){
	ll num = fact(N); ll den = 1;
	for(int i = 0; i < size; i++)
		den = (den * (ll)fact(chCount[i]))%MOD;
	return (num * (ll)inverse(den))%MOD;
}

int *makeChCount(char *str){
	int *chCount = (int *)calloc(26, sizeof(int));
	for(int i = 0; str[i]; i++) chCount[str[i] - 'a']++;
	for (int i = 0; i < 26; ++i) chCount[i] = chCount[i]/2;
	return chCount;
}

int main(){
	char *str = (char *)calloc(100007, sizeof(char));
	scanf("%s", str);
	int *chCount = makeChCount(str);
	int palinAnagrams = countPalinAnagrams(strlen(str)/2, chCount, 26);
	printf("%d\n", palinAnagrams);
}