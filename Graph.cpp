#include<bits/stdc++.h>
using namespace std;

class Graph{
public:
	int size;
	vector<int> *adj;

	int **transitiveClosureMat;

	Graph(int sizeInp){
		size = sizeInp;
		//Remember to add elements starting from zero ! and not 1
		adj = new vector<int>[size];


		transitiveClosureMat = new int* [size]; 
	    for (int i=0; i<size; i++) { 
	        transitiveClosureMat[i] = new int[size]; 
	        memset(transitiveClosureMat[i], 0, size*sizeof(int)); 
	    } 


	}

	int getSize(){
		return size;
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

	/*
	*A mother is a vertex from where we can got to any vertex in the graph
	*There can be more than one mother vertex we have to print any one of them.
	*This is only for Directed graph and not for undirected graph
	*also the trick here is that if the element that performs dfsUtil last
	*is the mother vertex (or one of them) because as it visits all vertices 
	*thus no other is searched more.
	*/

	int findMotherVertex(){
		vector <bool> visited(size, false); 

		int v;

		for(int i = 0;i < size;i++){
			if(!visited[i]){
				dfsUtilForMotherVertex(i,visited);
				v = i;
			}
		}

		//reset visited to false and do a dfs util to v that we got and 
		// if any element is remaining then it is not a mother vertex.
	    fill(visited.begin(), visited.end(), false); 
	    dfsUtilForMotherVertex(v,visited);


	    for(auto i = visited.begin();i != visited.end();i++){
	    	if(!visited[*i]){
	    		cout<<"No mother vertex found!"<<endl;
	    		return -1;
	    	}
	    }

	    cout<<"Mother vertex is at : "<<v<<endl;
	    return v;
	}
	void dfsUtilForMotherVertex(int v,vector<bool> &visited){
		visited[v] = true;
		for(auto i = adj[v].begin();i != adj[v].end();i++){
			if(!visited[*i]){
				dfsUtilForMotherVertex(*i,visited);
			}
		}
	}


	//https://www.geeksforgeeks.org/transitive-closure-of-a-graph-using-dfs/
	// it is basically of matrix of elements that we can reach
	//if mat[a][b] == 1 then there is a possible path from a to b
	//if mat[a][b] == 1 then there is no way to reach b from a
	void transitiveClosure(){
		

		for(int i = 0;i < size;i++){
			for(int j= 0;j < size;j++){
				transitiveClosureMat[i][j] = 0;
			}	
		}

		for(int i = 0;i < size;i++){
			dfsUtilTransitiveClosure(i,i);
		}

		cout<<"The transitive matrix is : ";

		for(int i = 0;i < size;i++){
			for(int j= 0;j < size;j++){
				cout<<transitiveClosureMat[i][j]<<" ";
			}
			cout<<endl;	
		}
		cout<<endl;
	}
	void dfsUtilTransitiveClosure(int from,int to){
		transitiveClosureMat[from][to] = 1;

		for(auto i = adj[to].begin(); i != adj[to].end();i++){
			if(transitiveClosureMat[from][*i] == 0)dfsUtilTransitiveClosure(from,*i);
		}
	}


	void printShortestPathMatrixForUnweightedDirected(int element){
		queue<int> q;
		int arr[size];
		int path[size];
		for(int i = 0;i < size;i++){
			arr[i] = 0;
			path[i] = -1;
		}
		q.push(element);
		int curr;
		int ct =  0;
		path[element] = ct;
		while(!q.empty()){

			curr = q.front();
			q.pop();
			arr[curr] = 1;

			for(auto i = adj[curr].begin();i != adj[curr].end();i++){
				if(arr[*i] == 0){
					q.push(*i);
					path[*i] = path[curr]+1;
				}
			}
			ct++;
		}
		cout<<"Shortest path for "<<element;
		for(int i = 0;i < size;i++){
			cout<<"shortest path to "<<i<<" from "<<element<<" is : "<<path[i]<<endl;
		}
		cout<<endl;
	}
};



int main(){

	//CHECk THE SIZE
	Graph g(5);
	//CHECk THE SIZE

	g.add_Directed_Edge(0,1);
	g.add_Directed_Edge(1,3);
	g.add_Directed_Edge(1,4);
	g.add_Directed_Edge(2,0);
	g.add_Directed_Edge(4,2);
	

	//CHECk THE SIZE

	// g.add_Directed_Edge(0,3);
	// g.add_Directed_Edge(0,3);
	// g.add_Directed_Edge(0,3);
	// g.transitiveClosure();
	g.printShortestPathMatrixForUnweightedDirected(2);


	return 0;

}