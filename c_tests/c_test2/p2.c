#include<stdio.h>
int main(){
	int curr,prev=0,sum;
	for(curr=0;curr<=5;curr++){
			sum=curr+prev;
			printf("Curr= %d ,Prev = %d, Sum = %d\n",
               curr, prev, sum);
        prev = curr;
    }
    return 0;
}
