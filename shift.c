#include<stdio.h>
#include <string.h>
#include <math.h>
#define SIZE 8

int change_byte(int s, int i){
	int total;
	if (s / (int)pow( 2, SIZE-i) == 1){
		total = 1;
		
	}else{
		total = 0;
	}
	return total;
		
}

int left_shift(int s[]){
	int i;
	for(i=0;i<=SIZE-2;i++){
		s[i] = s[i+1];
	}
	s[SIZE - 1] = 0;
}

int right_shift(int s[]){
	int i;
	for(i=SIZE-1;i>=1;i--){
		s[i] = s[i-1];
	}
	s[0] = 0;
	
}

	

int main(void){
	int byte[SIZE];
	int ten;
	
	printf("숫자 입력(0~ 255): ");
	scanf("%d",&ten);
	if(ten <= 255){
		int byte[SIZE];
		int j,i,a;
		for(i=0;i<SIZE;i++){
			byte[i] = change_byte(ten,i);
			ten = ten % (int)pow( 2, SIZE -i);
		}
		for(i=0;i<SIZE;i++){
			printf("%d",byte[i]);
		}
		printf("\n");
		printf("1.left_shift 2.right_shift 3.exit");
		scanf("%d",&a);
		while(a!=3){
			if(a==1){
				left_shift(byte);
				for(i=0;i<SIZE;i++){
					printf("%d",byte[i]);
				}
				printf("\n");
			}
			if(a==2){
				right_shift(byte);
				for(i=0;i<SIZE;i++){
					printf("%d",byte[i]);
				}
				printf("\n");
			}
			if(a==3){
				printf("안녕히계세요");
				break;
			}
			a = 0;
			printf("1.left_shift 2.right_shift 3.exit");
			scanf("%d",&a);
		}
		
	}else{
		printf("프로그램에 오류가 났어요. 다시 실행한 후 올바르게 입력하세요.");
	}
	
	return 0;
}
