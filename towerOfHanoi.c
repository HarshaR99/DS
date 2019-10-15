#include<stdio.h>
void tower_hanoi(int n,char scr,char temp,char dest){
	if(n==1){
		printf("\nMove %d disc from %c to %c",n,scr,dest);
		return;
	}
	tower_hanoi(n-1,scr,dest,temp);
	printf("\nMove %d disc from %c to %c",n,scr,dest);
	tower_hanoi(n-1,temp,scr,dest);
}
void main(){
	tower_hanoi(3,'A','B','C');
}
