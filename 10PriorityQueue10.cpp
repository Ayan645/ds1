#include<iostream>
#include<cstring>
#include<ios>
#include<limits>

using namespace std;

typedef struct patient{
	int patientID;
	int severity;
}PATIENT;

class priorityQ
{
	private:
		int nop;
		PATIENT P[50];
		const char priority[3][10]={"Least","Medium","Top"};
	public:
	priorityQ()
    {
		for (int i=0;i<50;i++)
		{
			P[i].patientID=0;
			P[i].severity=0;
		}
		nop=0;
    }
	
	void displayQueue()
	{
		for (int i=1;i<=nop;i++)
			cout<<"\n"<<P[i].patientID<<"  "<<priority[P[i].severity];
	}
	
	void addPatient(PATIENT p)
	{
		int i;
		PATIENT t;
		i=nop;
		if(i==0)
		{
			P[++i]=p;
			nop=i;
		}
		else
		{
			P[++i]=p;
			nop=i;
			while(i>1 && P[i].severity > P[i/2].severity)
			{
				t=P[i];
				P[i]=P[i/2];
				P[i/2]=t;
				i=i/2;
			}
		}
	}
	
	void deletePatient()
	{		
		PATIENT t;
		int i,j;
		t=P[1];
		P[1]= P[nop];
		P[nop]=t;
		nop--;
		i=1;
		
		while(2*i<=nop)
		{
			j=2*i;
			if(j+1<=nop && P[j+1].severity>P[j].severity)
				j++;

			if(P[i].severity<P[j].severity)
			{
				t=P[i];
				P[i]=P[j];
				P[j]=t;
				i=j;
			}
			else
				break;
		}
	}
};

int main(void)
{
   priorityQ B;
   int cho,n;
   PATIENT p;
   cho=0;
   while(cho != 4)
   {
     cout<<"\n************PATIENT QUEUE*************";
     cout<<"\n1-ADD PATIENT TO QUEUE";
     cout<<"\n2-DISPLAY QUEUE";
	 cout<<"\n3-DELETE PATIENT FROM QUEUE";
     cout<<"\n4-EXIT";
     cout<<"\nEnter ur choice:";
     cin>>cho;
	 cin.ignore(numeric_limits<streamsize>::max(), '\n');
     switch(cho)
     {
       case 1:
		cout<<"\nEnter patient ID:";
		cin>>p.patientID;
		cout<<"\nEnter severity\n\t2. Top \n\t1. Medium \n\t0. Least\n\t::";
		cin>>n;
		p.severity=n;	
		B.addPatient(p);
		break;
       case 2:
		B.displayQueue();
		break;
	   case 3:
		B.deletePatient();
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
     This program simulates a priority queue for managing patients based on their severity levels. 
     - It allows the user to add a patient to the queue, display the current queue, and delete the highest-priority patient (the one with the highest severity).
     - The queue is implemented as a **Max-Heap** where the patient with the highest severity always has the highest priority.

  2. What Data Structures Are Used and Why:
     - **Struct PATIENT**: Represents a patient with a unique `patientID` and a `severity` level (Top, Medium, or Least).
     - **Array-based Max-Heap**: The array `P[50]` stores patients, and the heap property ensures that the patient with the highest severity is always at the root (position 1). 
       - The Max-Heap structure ensures efficient addition and removal of patients based on severity.
  
  3. Key Functionalities:
     - **addPatient(PATIENT p)**: Adds a patient to the priority queue and ensures that the heap property is maintained. After insertion, the new patient is "bubbled up" to its correct position based on severity.
     - **deletePatient()**: Removes the patient with the highest priority (root of the heap), and then re-adjusts the heap by "bubbling down" the patient at the root to restore the heap property.
     - **displayQueue()**: Displays the current queue of patients with their severity.

  4. Real-Life Applications:
     - **Hospital Emergency Rooms**: Prioritize patients based on the severity of their conditions, ensuring that the most critical patients are treated first.
     - **Customer Support Systems**: Prioritize customers or clients based on the urgency of their requests.
     - **Scheduling Systems**: Efficiently manage tasks or jobs that need to be completed based on priority or deadlines.

  5. Sample Use Case:
     - The user can add a patient by specifying the `patientID` and `severity` (Top, Medium, or Least).
     - The patient is inserted into the queue according to their severity, ensuring that the highest severity patient is always at the front.
     - The user can delete the highest-priority patient, and the system will reorganize the queue.
     - The system also allows for viewing the current status of the queue.

  Notes:
     - The severity is mapped to integers where `2` represents **Top**, `1` represents **Medium**, and `0` represents **Least**.
     - The heap ensures that both insertion and deletion operations are efficient, operating in O(log n) time complexity.
*/
