#include <stdio.h>
#include <stdlib.h>
#include <vector>
#include <map>

struct Customer{
		int arrTime;
		int departTime;
		int compartment;
};


int compareMytype(const void *a, const void *b){
	if( (*(Customer *)a).arrTime > (*(Customer *)b).arrTime ) return -1;
	if( (*(Customer *)a).arrTime == (*(Customer *)b).arrTime ) return 0;
	else return 1;
}


void initCustomerArrTime(std::map<int, int>& NCAT, Customer * C, int N){
	for(int i = 0; i < N; i++)
		if( NCAT.find(C[i].compartment) == NCAT.end() ||
		    NCAT[C[i].compartment] < C[i].departTime
		  )
			NCAT[C[i].compartment] = C[i].departTime;
}

/**
Stratergy is we sort the customers based on their arrival times 
in decreasing order. NCAT[compartment] contains the time
when the next customer could arrive in the compartment. 
We initalize NCAT with the last departure time of the person 
for compartment K. 
Now for a ith customer(in decreasing order of arrival times)
they can occupy that compartment if their departure time is less than
or equal to the arrival time of next person.
*/
int maxCustomerCount(Customer* C, int N){
	std::map<int, int> NCAT; //NCAT stands for nextCustomerArrTime
	initCustomerArrTime(NCAT, C, N);
	qsort(C, N, sizeof(Customer), compareMytype);
	int customerCount = 0;
	for(int i = 0; i < N; i++){
		if(C[i].departTime <= NCAT[C[i].compartment]){
			NCAT[C[i].compartment] = C[i].arrTime;
			customerCount++;
		}
	}
	return customerCount;
}

int main(){
	int T,  N, K;
	scanf("%d", &T);
	while(T--){
		scanf("%d %d", &N, &K);
		Customer *C = (Customer *)calloc(N, sizeof(Customer));
		for (int i = 0; i < N; ++i)
			scanf("%d %d %d", &C[i].arrTime, &C[i].departTime, &C[i].compartment);
		printf("%d\n", maxCustomerCount(C, N));
	}

}