#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <cstring>
using namespace std;
typedef struct Node
{
	int data;
	struct Node *next;
}NODE;

class Graph
{
	int G[10][10];
	NODE Header[10];
	const char city[5][20]={"Pune","Mumbai","Delhi","Jaipur","Chakan"};
	int visited[10];
	int mNodes;
	int lNodes;
	public:
	Graph()
	{
		for (int i=0;i<10;i++)
			for(int j=0;j<10;j++)
				G[i][j]=0;
		for (int i=0;i<10;i++)
		{
			Header[i].data=i+1;
			Header[i].next=NULL;
			visited[i]=0;
		}
		mNodes=0;
		lNodes=0;
	}
	
	void init_Matrix()
	{
		mNodes=5;
		for (int i=0;i<10;i++)
			for(int j=0;j<10;j++)
				G[i][j]=0;
	}
	
	void init_List()
	{
		for (int i=0;i<10;i++)
		{
			Header[i].data=i+1;
			Header[i].next=NULL;
			visited[i]=0;
		}
	}
	
	void init_visited()
	{
		for (int i=0;i<10;i++)
			visited[i]=0;
	}
	
	void readGAM()
	{
		int i,j;
		int flag=1;
		init_Matrix();
		mNodes=5;
		while(flag==1)
		{
			cout<<"\nEnter source node:";
			cin>>i;
			cout<<"\nEnter destination node:";
			cin>>j;
			G[i][j]=1;
			cout<<"\nDo you want to add more edge yes=1 or no=0:";
			cin>>flag;
		}
	}
	
	void printGAM()
	{
		int i,j,k=0;
		cout<<"\n\t";
		for (i=0;i<mNodes;i++)
			cout<<city[i]<<"\t";
		cout<<"\n";
		for (i=1;i<=mNodes;i++)
		{
			cout<<city[i-1]<<"\t";
			for(j=1;j<=mNodes;j++)
				cout<<G[i][j]<<"\t";
			cout<<"\n";
		}
	}

	void DFS_RECURSIVE(int i)
	{
		int j;
		cout<<" "<<i;
		visited[i]=1;
		for(j=1;j<=mNodes;j++)
			if(!visited[j] && G[i][j]==1)
				DFS_RECURSIVE(j);
	}
	
	bool isConnected()
	{
		int i;
		init_visited();
		DFS_RECURSIVE(1);
		for(i=1;i<=mNodes;i++)
			if(visited[i]==0)
				return false;
		return true;
	}
};

int main()
{
    Graph g1;
	int n;
	int cho=0;
	while(cho != 4)
	{
     cout<<"\n********CONNECTED GRAPH*********";
     cout<<"\n1-Read Graph Adjacency Matrix";
     cout<<"\n2-Print Graph Adjacency Matrix";
	 cout<<"\n3-Check Graph Connected or Not Connected";
     cout<<"\n4-EXIT";
     cout<<"\nEnter ur choice:";
     cin>>cho;
     switch(cho)
     {
       case 1:
		g1.readGAM();
		break;
       case 2:
		g1.printGAM();
		break;
	   case 3:
		if (g1.isConnected())
			cout<<"\nGraph is connected!";
		else
			cout<<"\nGraph is not connected!";
		break;
	   case 4:
		cout<<"\nProgram Exits!!";
		break;
       default:
		cout<<"\nWrong choice!";
     }
    }
	
    return 0;
}
/*
  Theory Explanation:

  1. What the Program Does:
     This C++ program represents a **directed graph using an adjacency matrix** and allows the user to:
     - Input the graph.
     - Display the adjacency matrix.
     - Check whether the graph is **connected** using **DFS traversal**.

  2. What Data Structures Are Used and Why:
     - **Adjacency Matrix (G[10][10])**: Used for representing the graph. It is suitable for dense graphs and easy to implement.
     - **Visited Array**: Used to track which nodes have been visited during the DFS traversal.
     - **Header Array (NODE)**: Declared but not used in this version—could be for future use with adjacency lists.
     - **City Array**: Maps numeric node indices to human-readable city names (e.g., Pune, Mumbai, etc.).

  3. Key Functionalities:
     - `readGAM()`: Inputs edges into the adjacency matrix.
     - `printGAM()`: Displays the graph in tabular adjacency matrix format.
     - `DFS_RECURSIVE()`: Performs a depth-first traversal starting from node 1.
     - `isConnected()`: Determines if all nodes are reachable from the starting node (node 1), indicating graph connectivity.

  4. Real-Life Applications:
     - **Road Networks**: Ensuring all cities (nodes) are reachable.
     - **Computer Networks**: Verifying full connectivity in a LAN/WAN topology.
     - **Utility Grids**: Checking that electricity or water can reach every point.
     - **Social Graphs**: Confirming mutual reachability in communication networks.

  5. Sample Use Case:
     - The user inputs edges between cities.
     - Chooses to check connectivity.
     - The program uses DFS to verify whether every node is reachable from the starting city (Pune = node 1).
     - It prints whether the graph is connected or not.

  Notes:
     - Node indexing starts from 1.
     - The graph is assumed to have 5 nodes (fixed).
     - Only adjacency matrix and DFS are used—no list-based representation or BFS.
*/
