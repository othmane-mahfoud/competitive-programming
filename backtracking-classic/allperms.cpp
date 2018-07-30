#include <stdio.h>
#include <string.h>

using namespace std;

void swap(char* x, char* y){
	char temp;
	temp = *x;
	*x = *y;
	*y = temp;
}

void permutate(char* a, int l, int r){
	if(l==r){
		printf("%s\n", a);
	}
	else{
		for (int i = l; i < r; ++i)
		{
			swap((a+l), (a+i));
			permutate(a, l+1, r);
			swap((a+l), (a+i));
		}
	}
}

int main (){
	char* a;
	scanf("%s", a);
	int r = strlen(a);
	permutate(a, 0, r-1);
}
