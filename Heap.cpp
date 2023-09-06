#include<iostream>;
using namespace std;

class Heap{
	public:
	int tail=-1;
	int *arr = new int[100];
	
	void insert(int num){
		arr[++tail] = num;
		int at = tail;
		while(at>0 && arr[at]>arr[(at-1)/2]){
			int temp =arr[at];
			arr[at] = arr[(at-1)/2];
			arr[(at-1)/2] = temp;
			at= (at-1)/2;
		}
	}
	
	int pop(){
		int temp = arr[0];
		arr[0] = arr[tail--];
		int at = 0;
		while(true){
			int biggest = at;
			int Lidx = at*2+1;
			int Ridx = at*2+2;
			
			if(Lidx<tail+1 && arr[Lidx]>arr[biggest]){
				biggest=Lidx;
			}
			
			if (Ridx<tail+1 && arr[Ridx]>arr[biggest]){
				biggest=Ridx;
			}
			if(biggest == at){
				break;
			}
			else{
				int temp = arr[at];
				arr[at] = arr[biggest];
				arr[biggest] = temp;
				at = biggest;
			}
			
		}
		return temp;
	}
	
	void print(){
		for(int i =0; i<tail+1;i++){
			cout<<arr[i]<<" ";
		}
		cout<<endl;
	}
};

int main(){
	char operation;
	Heap* heap = new Heap();
	int num;
	do{
		cin>>operation;
		switch(operation){
			case 'a':
				cin>>num;
				heap->insert(num);
				break;
			case 'd':
				cout<<heap->pop()<<endl;
				break;
			case 'p':
				heap->print();
				break;
		}
			
	} while ( operation != 'e' );
	return 0;
}
