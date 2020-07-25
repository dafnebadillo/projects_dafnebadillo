/*
Dafne Linette Badillo Campuzano A01275298
Andrea Munoz Gris A01733058
*/

class Stack{
	int Stack[];
	int top=0;
	int maxSize;

	Stack(int num_stack){
		maxSize = num_stack;
		Stack = new int[maxSize];
		top = 0;
	}

	void push(int n){
		if(top < maxSize){
			Stack[top] = n;
			top ++;
		}
	}

	void print(){
		for(int i=top-1; i>=0; i--)
			System.out.println(i+ "|"+ Stack[i]+"|");
	}
	
}