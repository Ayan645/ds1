#include<iostream>
#include<cstring>
#include<ios>
#include<limits>

using namespace std;
typedef struct keyword{
    char key[20];
    char meaning[100];
}WORD;
typedef struct node
{
   struct node *LC;
   WORD data;
   int height;
   struct node *RC;
}NODE;
 
class AVL
{
    NODE *root;
    int count;
    public:
    AVL()
    {
        root=NULL;
        count=0;
    }
    NODE* getroot()
    {
        return root;
    }

    int height(NODE *T)
    {
        int lh,rh;
        if(T==NULL)
            return 0;
        if(T->LC ==NULL && T->RC==NULL)
            return 0;
        lh=height(T->LC);
        rh=height(T->RC);
        if(lh>rh)
            return lh+1;
        else
            return rh+1;
    }

    int difference(NODE* T)
    {
        int l_height = height(T->LC);
        int r_height = height(T->RC);
        int b_factor = l_height - r_height;
        return b_factor;
    }

    NODE *rr_rotate(NODE* Pptr)
    {
        NODE *Aptr;
        Aptr = Pptr->RC;
        Pptr->RC = Aptr->LC;
        Aptr->LC = Pptr;
        return Aptr;
    }

    NODE *ll_rotate(NODE* Pptr)
    {
        NODE *Aptr;
        Aptr = Pptr->LC;
        Pptr->LC = Aptr->RC;
        Aptr->RC = Pptr;
        return Aptr;
    }

    NODE *lr_rotate(NODE* Pptr)
    {
        NODE *Aptr;
        Aptr = Pptr->LC;
        Pptr->LC = rr_rotate(Pptr);
        return ll_rotate(Pptr);
    }

    NODE *rl_rotate(NODE * Pptr)
    {
        NODE *Aptr;
        Aptr = Pptr->RC;
        Pptr->RC = ll_rotate(Pptr);
        return rr_rotate(Pptr);
    }

    NODE* balance(NODE* T)
    {
        int bal_factor = difference(T);
        if (bal_factor > 1) {
            if (difference(T->LC) > 0)
                T = ll_rotate(T);
            else
                T = lr_rotate(T);
        } else if (bal_factor < -1) {
            if (difference(T->RC) > 0)
                T = rl_rotate(T);
            else
                T = rr_rotate(T);
        }
        return T;  
    }

    NODE* insert(NODE* T,WORD w)
    {
        if (T == NULL) {
            T = new NODE;
            T->data = w;
            T->LC = NULL;
            T->RC = NULL;
            root=T;
            return T;
        } else if(strcmp(w.key,T->data.key)<0) {
                T->LC = insert(T->LC, w);
                T = balance(T);
        } else if (strcmp(w.key,T->data.key)>0) {
                T->RC = insert(T->RC, w);
                T = balance(T);
        } 
        root=T;
        return T;
    }

    void displayIN(NODE *T)
    {
        if(T)
        {
            displayIN(T->LC);
            cout<<T->data.key<<":"<<T->data.meaning<<endl;
            displayIN(T->RC);
        }
    }

};

int main(void)
{
   AVL B;
   int val,cho,n,cho1;
   WORD w;
   NODE* r;
   char key[30];
   cho=0;
   while(cho != 3)
   {
     cout<<"\n********DICTIONARY STORAGE using AVL*********";
     cout<<"\n1-ADD WORD";
     cout<<"\n2-DISPLAY DICTIONARY";
     cout<<"\n3-EXIT";
     cout<<"\nEnter ur choice:";
     cin>>cho;
     cin.ignore(numeric_limits<streamsize>::max(), '\n');
     switch(cho)
     {
       case 1:
        cout<<"\nEnter keyword:";
        cin.clear();
        fflush(stdin);
        cin.getline(w.key,20);
        cout<<"\nEnter meaning of the word:";
        cin.clear();
        fflush(stdin);
        cin.getline(w.meaning,100);
        r=B.insert(B.getroot(),w);
        break;
       case 2:
        B.displayIN(B.getroot());
        break;
       case 3:
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
     This program implements a **dictionary** using an **AVL Tree** data structure.
     - It allows users to insert a new word with its meaning.
     - It displays the dictionary in lexicographical (sorted) order using in-order traversal.
     - AVL balancing ensures that all operations remain efficient even after multiple insertions.

  2. What Data Structures Are Used and Why:
     - **Struct WORD**: Holds each keyword and its meaning.
     - **Struct NODE**: Represents a node in the AVL Tree with left/right child pointers, height, and a `WORD` object.
     - **AVL Tree**: A self-balancing Binary Search Tree (BST) used to keep dictionary words sorted and balanced, ensuring O(log n) time for insertions and lookups.

  3. Key Functionalities:
     - `insert()`: Inserts a new word while maintaining AVL balance using rotations (`LL`, `RR`, `LR`, `RL`).
     - `height()` and `difference()`: Help in maintaining balance by calculating height difference (balance factor).
     - `displayIN()`: In-order traversal to print the dictionary in alphabetical order.
     - Rotations (`ll_rotate`, `rr_rotate`, `lr_rotate`, `rl_rotate`): Maintain the height-balanced property of AVL Trees.

  4. Real-Life Applications:
     - **Auto-complete Systems**: Quickly search for words and their definitions.
     - **Mobile Dictionaries or Glossaries**: Efficient insert and search operations with real-time balancing.
     - **Search Engines**: Maintain sorted keyword indexes for fast retrieval.

  5. Sample Use Case:
     - The user adds multiple words and meanings through the console.
     - The AVL Tree automatically balances after each insertion.
     - Displaying the dictionary shows the words in alphabetical order, demonstrating proper BST property.

  Notes:
     - AVL Trees ensure balanced height, so search and insertion stay efficient.
     - In-order traversal of an AVL Tree yields words in sorted order, which is ideal for a dictionary.
     - The use of character arrays for string storage is based on basic C-style string handling.
*/
