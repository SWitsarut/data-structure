#include<iostream>
#include<vector>
using namespace std;

class Graph{
public:
	int edges[100][100];
	int s_v;
	Graph(int n){
		s_v=n;
		for(int i =0 ;i<s_v;i++){
			for(int j =0;j<s_v;j++){
				edges[i][j] = 0;
			}
		}	
	}
		
	void add_edge(int src,int des,int wieght){
		edges[src][des]=wieght;
	}
	void print(){
		for(int i=0;i<s_v;i++){
			cout<<i<<":";
			for(int j =0;j<s_v;j++){
				if(edges[i][j]>0){
					cout<<j<<","<<edges[i][j]<<" ";
				}
			}
			cout<<endl;
		}
	}
	
	void bft(int start){
		bool visited_bft[100];
		//reset visited
		for(int i = 0;i<100;i++){
			visited_bft[i]=0;
		}
		visited_bft[start] = 1;
		vector<int> q;
		q.push_back(start);
		while(q.empty()==0){
			start= q.front();
			cout<<start<<" ";
			q.erase(q.begin());
			for(int y=0;y<s_v;y++){
				if(visited_bft[y]==0&&edges[start][y]>0){
					visited_bft[y] =1;
					q.push_back(y);
				}
			}
		}
	}
	
	bool visited_dft[100];
	void sub_dft(int start){
		cout<<start<<" ";
		visited_dft[start]=true;
		for(int y =0;y<s_v;y++){
			if(!visited_dft[y] && edges[start][y]>0){
				sub_dft(y);
			}
		}
	}
	
	void dft(int start){
		for(int i = 0;i<100;i++){
			visited_dft[i] =0;
		}
		sub_dft(start);
		cout<<endl;
	}
		
};

int main(){
	int size;
	cin >> size;
	Graph g(size);
	while (true) {
		char choice = getchar();
		if (choice == 's') {
			break;
		}
		
		if (choice == 'e') {
			int start, dest, weight;
			cin >> start;
			cin >> dest;
			cin >> weight;
			g.add_edge(start, dest, weight);
		}
		
	}
	
	while (true) {
		char choice = getchar();
		if (choice == 'q') {
			break;
		}
		
		if (choice == 'b') {
			int start;
			cin >> start;
			g.bft(start);
			cout<<endl;
		}
		
		if (choice == 'd') {
			int start;
			cin >> start;
			g.dft(start);
		}
		
	}
	return 0;
}
