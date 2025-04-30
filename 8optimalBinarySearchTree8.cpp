#include<iostream>
using namespace std;
#define SIZE 10
class OBST
{
	private:
		int p[SIZE];
		int q[SIZE];
		int a[SIZE];
		int w[SIZE][SIZE];
		int c[SIZE][SIZE];
		int r[SIZE][SIZE];
		int n;
	public:
		void get_data()
		{
			int i;
			cout<<"\n Optimal Binary Search Tree \n";
			cout<<"\n Enter the number of nodes=>";
			cin>>n;
			cout<<"\n Enter the data as…\n";
			for(i=1;i<=n;i++)
			{
				cout<<"\n a["<<i<<"]=>";
				cin>>a[i];
			}
			for(i=1;i<=n;i++)
			{
				cout<<"\n p["<<i<<"]=>";
				cin>>p[i];
			}
			for(i=0;i<=n;i++)
			{
				cout<<"\n q["<<i<<"]=>";
				cin>>q[i];
			}
		}

		int Min_Value(int i,int j)
		{
			int m,k;
			int minimum=32000;
			for(m=r[i][j-1];m<=r[i+1][j];m++)
			{
				if((c[i][m-1]+c[m][j])<minimum)
				{
					minimum=c[i][m-1]+c[m][j];
					k=m;
				}
			}
			return k;
		}

		void build_OBST()
		{
			int i,j,k,l,m;
			for(i=0;i<n;i++)
			{
				w[i][i]=q[i];
				r[i][i]=c[i][i]=0;
				w[i][i+1]=q[i]+q[i+1]+p[i+1];
				r[i][i+1]=i+1;
				c[i][i+1]=q[i]+q[i+1]+p[i+1];
			}
			w[n][n]=q[n];
			r[n][n]=c[n][n]=0;
			for(m=2;m<=n;m++)
			{
				for(i=0;i<=n-m;i++)
				{
					j=i+m;
					w[i][j]=w[i][j-1]+p[j]+q[j];
					k=Min_Value(i,j);
					c[i][j]=w[i][j]+c[i][k-1]+c[k][j];
					r[i][j]=k;
				}
			}
		}

		void build_tree()
		{
			int i,j,k;
			int queue[20],front=-1,rear=-1;
			cout<<"The Optimal Binary Search Tree For the Given Node Is…\n";
			cout<<"\n The Root of this OBST is ::"<<r[0][n]<<"\n";
			cout<<"\nThe Cost of this OBST is::"<<c[0][n];
			cout<<"\n\n\t NODE \t LEFT CHILD \t RIGHT CHILD ";
			cout<<"\n";
			queue[++rear]=0;
			queue[++rear]=n;
			while(front!=rear)
			{
				i=queue[++front];
				j=queue[++front];
				k=r[i][j];
				cout<<"\n\t\t"<<k;
				if(r[i][k-1]!=0)
				{
					cout<<"\t\t\t"<<r[i][k-1];
					queue[++rear]=i;
					queue[++rear]=k-1;
				}
				else
					cout<<"\t\t\t";
				
				if(r[k][j]!=0)
				{
					cout<<"\t\t\t"<<r[k][j];
					queue[++rear]=k;
					queue[++rear]=j;
				}
				else
					cout<<"\t";
			}
			cout<<"\n";
		}
};

int main()
{
	OBST obj;
	obj.get_data();
	obj.build_OBST();
	obj.build_tree();
	return 0;
}
/*
  Theory Explanation:

  1. What the Program Does:
     This C++ program constructs an **Optimal Binary Search Tree (OBST)** from a given set of keys and their associated probabilities.
     - It calculates the cost of searching and builds the tree such that the total search cost is minimized.
     - Then, it displays the OBST structure including the root and left/right children of each node.

  2. What Data Structures Are Used and Why:
     - **Arrays (p[], q[], a[])**: 
       - `p[i]`: Probability of searching for actual keys.
       - `q[i]`: Probability of searching for dummy (unsuccessful) keys.
       - `a[i]`: The keys themselves.
     - **2D Arrays (w[][], c[][], r[][])**:
       - `w[i][j]`: Sum of probabilities from i to j (weights).
       - `c[i][j]`: Minimum cost of searching subtree from i to j.
       - `r[i][j]`: Root index for subtree from i to j.
     - **Queue (simple int array)**: Used for level-order traversal to print the OBST structure.

  3. Key Functionalities:
     - `get_data()`: Accepts keys and their probabilities.
     - `build_OBST()`: Computes cost and root matrices using dynamic programming.
     - `build_tree()`: Traverses the root matrix to print OBST node relations.

  4. Real-Life Applications:
     - **Compiler Design**: Used in symbol tables where certain symbols are accessed more frequently than others.
     - **Databases**: Efficient indexing using OBST can reduce the number of comparisons.
     - **Information Retrieval Systems**: To speed up search in static dictionaries with non-uniform access patterns.

  5. Sample Use Case:
     - The user enters 𝑛 keys, followed by probabilities of successful (`p[i]`) and unsuccessful (`q[i]`) searches.
     - The OBST is built with the lowest expected search cost using dynamic programming.
     - The final OBST structure is printed, showing each node's left and right children.

  Notes:
     - The OBST algorithm minimizes the **expected search cost** in a binary search tree.
     - It is particularly useful when the frequency of access to keys is known in advance.
     - The implementation assumes `p[1...n]` and `q[0...n]` as per standard OBST formulation.
*/
