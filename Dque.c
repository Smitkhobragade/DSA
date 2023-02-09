#include <stdio.h>
#define CAPACITY 20
int limit = 6;

typedef struct Dque{
	char a[CAPACITY];
	int front;
	int rear;
}Dque;

void create(Dque * d1){
	d1->front = -1;
	d1->rear = -1;
}
int isEmpty(Dque d1){
	if(d1.front == -1){
		return 1;
	}
	else
		return 0;
}
int isFull(Dque d1){
	if(d1.front == (((d1.rear) + 1) % CAPACITY))
		return 1;
	else
		return 0;
}
void insertfromrear(Dque * d1,char key){
	if(isFull(*d1))
		printf("Cannot Insert\n");
	else{
		d1->rear = (d1->rear + 1) % CAPACITY;
		d1->a[d1->rear] = key;
		if(isEmpty(*d1))
			d1->front = 0;
	}
}
char peekfront(Dque d1){
	if(isEmpty(d1))
		printf("Cannot Peek(Queue is Empty)\n");
	else{
		printf("%c \n",d1.a[d1.front]);
		return d1.a[d1.front];
	}
}
void insertfromfront(Dque * d1,char key){
	if(isFull(*d1))
		printf("Cannot Insert \n");
	else{
		if(d1->front == 0)
			d1->front = CAPACITY - 1;
		else if(isEmpty(*d1)){
			d1->front = 0;
			d1->rear = 0;
		}
		else
			(d1->front)--;
		
		d1->a[d1->front] = key;
	}
}
char deletefromrear(Dque * d1){
	if(isEmpty(*d1)){
		printf("Cannot Delete\n");
		return '\0';
	}
	else{
		char key = d1->a[d1->rear];
		//printf("%c \n",key);
		if((d1->rear) == (d1->front)){
		//printf("Hello\n");
			d1->rear = -1;
			d1->front = -1;
		}
		else if(d1->rear == 0)
			d1->rear = CAPACITY - 1;
		else
			(d1->rear)--;
			
		return key;
	}
}
char deletefromfront(Dque * d1){
	if(isEmpty(*d1)){
		printf("Cannot Delete\n");
		return '\0';
	}
	else{
		char key = d1->a[d1->front];
		//printf("%c \n",key);
		if((d1->rear) == (d1->front)){
			//printf("Hello\n");
			d1->rear = -1;
			d1->front = -1;
		}
		else
			d1->front = ((d1->front)+1)%CAPACITY;
			
		return key;
	}
}
void peekrear(Dque d1){
	if(isEmpty(d1))
		printf("Cannot Peek(Queue is Empty)\n");
	else{
		printf("%c \n",d1.a[d1.rear]);
		//return d1.a[d1.rear];
	}
}
int checkstr(char s[]){
	int i=0;
	while(s[i]!='\0'){
		if((s[i]>='a' && s[i]<='z')||(s[i]>='A' && s[i]<='Z'))
			i++;
		else
			return 1;
	}
	return 0;
}
int upper(char str[]){
	//printf("%s\n",str);
	//str[1]='Q';
	if(checkstr(str)){
		printf("Invalid Alphabet String\n");
		return 1;
	}
	else{
		
		int i = 0;
		while(str[i]!='\0'){
			//printf("%c\n",str[i]);
			if(str[i]>='a' && str[i]<='z')
				str[i] -= 32;
			i++;
		}
	}
}
int length(Dque dq1){
	int size;
	if(isEmpty(dq1)){
	//printf("00\n");
		return 0;
		
	}
	else{
		size = dq1.front > dq1.rear ? (CAPACITY - dq1.front + dq1.rear + 1) : (dq1.rear - dq1.front + 1);
		//printf("%d\n",size);
		return size;
	}
}
int palindrome(char s[],Dque * dq1){
	if(upper(s))
		return 0;
	else{
		for(int i=0;s[i]!='\0';i++)
			insertfromrear(dq1,s[i]);
		
		int flag = 1;
		while(length(*dq1)>1 && flag==1){
			char l,f;
			l = deletefromfront(dq1);
			f = deletefromrear(dq1);
			if(f != l)
				flag = 0;
		}
		
		if(flag == 1)
			printf("YES Its A Palindrome\n");
		else
			printf("Not a palindrome\n");
			
		return flag;
	}
}
void visit_tab(char key,Dque * dq){
	if(isFull(*dq) || limit <= 0){
		deletefromfront(dq);
	}
	insertfromrear(dq,key);
	limit--;
}
char delete_tab_recent(Dque * dq){
	char c = deletefromrear(dq);
	limit++;
	return c;
}
void display(Dque dq){
	if(isEmpty(dq))
		printf("(Queue is Empty)\n");
	else{
		//printf("%c \n",d1.a[d1.rear]);
		//return d1.a[d1.rear];
		//printf("HELLO\n");
		while(!(dq.front == (((dq.rear) + 1) % CAPACITY))){
			printf("%c\t",dq.a[dq.front]);
			//printf("H\n");
			dq.front = (dq.front + 1) % CAPACITY;
		}
   		printf("\n");
	}
	
}
int main(){
	Dque dq;
	create(&dq);
	//printf("%d\n",isEmpty(dq));
	//printf("%d\n",dq.front);
	//insertfromrear(&dq,'s');
	//insertfromrear(&dq,'t');
	/*peekfront(dq);
	insertfromfront(&dq,'a');
	peekfront(dq);
	deletefromfront(&dq);
	deletefromrear(&dq);
	peekfront(dq);
	peekrear(dq);*/
	
	// AIM 1
	printf("\n-----------Part 1-----------\n");
	
	char s[15] = "MADAM";
	palindrome(s,&dq);
	create(&dq);
	char s1[15] = "madAM";
	palindrome(s1,&dq);
	create(&dq);
	char s2[15] = "abccba";
	palindrome(s2,&dq);
	create(&dq);
	char s3[15] = "abcdba";
	palindrome(s3,&dq);
	create(&dq);
	char s4[15] = "programming";
	palindrome(s4,&dq);
	create(&dq);
	//AIM 2
	printf("\n-----------Part 2-----------\n");
	visit_tab('1',&dq);
	visit_tab('2',&dq);
	visit_tab('3',&dq);
	display(dq);
	delete_tab_recent(&dq);
	display(dq);
	visit_tab('4',&dq);
	visit_tab('5',&dq);
	visit_tab('6',&dq);
	visit_tab('7',&dq);
	display(dq);
	visit_tab('8',&dq);
	display(dq);
}








