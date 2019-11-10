#include<bits/stdc++.h>
using namespace std;

class Graph{
public:
	int size;
	vector<int> *adj;
	Graph(int sizeInp){
		size = sizeInp;
		//Remember to add elements starting from zero ! and not 1
		adj = new vector<int>[size];
	}

	void add_Undirected_Edge(int x,int y){
		adj[x].push_back(y);
		adj[y].push_back(x);
	}

	void add_Directed_Edge(int from,int to){
		adj[from].push_back(to);
		
	}

	void print_Adjacency_List(){
		for(int i = 0 ;i < size;i++){
			cout<<"Adjacency list for "<<i<<" is : ";
			for(auto j: adj[i]){
				cout<<j<<" -> ";
			}
			cout<<endl;
		}
	}

	void BFS(int startElement){
		int visited[size];
		for(int i =0 ;i < size;i++)visited[i] = 0;
		queue<int> q;
		q.push(startElement);

		int x;
		x = startElement;
		visited[x] = 1;
		cout<<"BFS from "<< startElement<<" is : ";
		while(!q.empty()){
			x = q.front();
			
			q.pop();
			cout<<x<<" ";
			for(auto i = adj[x].begin();i != adj[x].end();i++){
				if(!visited[*i]){
					visited[*i] = 1;
					q.push(*i);
				}
			}

		}
		cout<<endl;
	}

	void Recurtion_DFS(int startElement,int visited[]){
		if(!visited[startElement]){
			cout<<startElement<<" ";
			visited[startElement] = 1;
			for(auto i = adj[startElement].begin();i != adj[startElement].end();i++){
				Recurtion_DFS(*i,visited);
				visited[*i] = 1;
			}
		}
		
	}

	void DFS(int startElement){
		int visited[size];
		cout<<"The DFS for element "<<startElement<<" is : ";
		for(int i =0;i < size;i++)visited[i] = 0;
		Recurtion_DFS(startElement,visited);
		cout<<endl;
	}
};


int main(){
	Graph g(5);
	g.add_Undirected_Edge(0,1);
	g.add_Undirected_Edge(0,2);
	g.add_Undirected_Edge(1,2);
	g.add_Undirected_Edge(2,0);
	g.add_Undirected_Edge(2,3);
	g.add_Undirected_Edge(3,3);

	g.print_Adjacency_List();
	g.DFS(2);
	return 0;

}