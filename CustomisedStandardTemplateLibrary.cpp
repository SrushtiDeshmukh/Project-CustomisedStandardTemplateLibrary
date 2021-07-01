#include<iostream>
using namespace std;

//declaration of generic Singly linked list
template <class T>
struct SinglyLLnode
{
	T data;
	struct SinglyLLnode* next;
};

///////////////////////////////////////////////////////////////////////////////////////////////
//
//  class name : SinglyLL
//  Description : This class represents generic singly linked list
//
/////////////////////////////////////////////////////////////////////////////////////////////

template <class T>
class SinglyLL
{
	private:
	  struct SinglyLLnode <T> *Head;		//Pointer points to the first node
	  struct SinglyLLnode <T> *Tail;		//Pointer points to the last node
	  int iSize;				//variable for counting nodes

	public:
	 SinglyLL();
	 ~SinglyLL();

	//Declaration of functions
	void InsertFirst(T);			
	void InsertLast(T);
	void InsertAtPos(T,int);
	void DeleteFirst();
	void DeleteLast();
	void DeleteAtPos(int);
	int Count();
	void Display();
	int SearchFirstOcc(T);
	int SearchLastOcc(T);
	void Empty();
	T FirstElement();
	T LastElement();
	void Remove(T);
	
};

/////////////////////////////////////////////////////////////////////////////////////////////////////////////
// 
//   Function name : SinglyLL()
//   Date : 25/05/2021
//   Author : Srushti Deshmukh
//   Parameters : NONE
//   Description : This is constructor of class SinglyLL
//
////////////////////////////////////////////////////////////////////////////////////////////////////////////

template <class T>
SinglyLL<T>::SinglyLL()
{
	cout<<"Inside Constructor\n";
	Head=NULL;
	Tail=NULL;
	iSize=0;
}

/////////////////////////////////////////////////////////////////////////////////////////////////////////////
// 
//   Function name : ~SinglyLL()
//   Date : 25/05/2021
//   Author : Srushti Deshmukh
//   Parameters : NONE
//   Description : This is destructor of class SinglyLL
//
////////////////////////////////////////////////////////////////////////////////////////////////////////////


template <class T>
SinglyLL<T>::~SinglyLL()
{
	struct SinglyLLnode<T>*temp=NULL;

	cout<<"Inside Destructor\n";
	while(Head!=NULL)
	{
		temp=Head;
		Head=Head->next;
		delete temp;
	}
}

/////////////////////////////////////////////////////////////////////////////////////////////////////////////
// 
//   Function name : InsertFirst()
//   Date : 25/05/2021
//   Author : Srushti Deshmukh
//   Parameters : One
//			T no-It is data of generic datatype
//   Description : This is fun use to insert node in Linked List at first position
//
////////////////////////////////////////////////////////////////////////////////////////////////////////////

template <class T>
void SinglyLL<T>::InsertFirst(T no)
{
	struct SinglyLLnode <T> *newn=NULL;
	newn=new struct SinglyLLnode<T>;

	newn->data=no;
	newn->next=NULL;

	if(Head==NULL)
	{
		Head=newn;
		Tail=newn;
	}
	else
	{
		newn->next=Head;
		Head=newn;
	}	
	iSize++;
}

/////////////////////////////////////////////////////////////////////////////////////////////////////////////
// 
//   Function name : InsertLast()
//   Date : 25/05/2021
//   Author : Srushti Deshmukh
//   Parameters : One
// 			T no-It is data of generic datatype
//   Description : This is fun use to insert node in Linked List at last
//
////////////////////////////////////////////////////////////////////////////////////////////////////////////


template <class T>
void SinglyLL<T>::InsertLast(T no)
{
	struct SinglyLLnode<T> *temp=Head;

	struct SinglyLLnode<T> *newn=NULL;
	newn=new struct SinglyLLnode<T>;

	newn->data=no;
	newn->next=NULL;
	
	if(Head==NULL)
	{
		Head=newn;
		Tail=newn;
	}
	else
	{
		/*while(temp->next!=NULL)
		{
			temp=temp->next;
		}	
		temp->next=newn;
		Tail=newn;*/
		
		Tail->next=newn;
		Tail=newn;
	}
	iSize++;
}

/////////////////////////////////////////////////////////////////////////////////////////////////////////////
// 
//   Function name : DeleteFirst()
//   Date : 25/05/2021
//   Author : Srushti Deshmukh
//   Parameters : None
//   Description : This is fun use to delete node in Linked List from first
//
////////////////////////////////////////////////////////////////////////////////////////////////////////////


template <class T>
void SinglyLL<T>::DeleteFirst()
{
	struct SinglyLLnode<T> *temp=Head;
	
	if(Head==NULL && Tail==NULL)
	{
		cout<<"Linked list is empty\n";
		return;
	}
	
	if(Head->next==NULL)
	{
		delete temp;
		Head=NULL;
		Tail=NULL;
		iSize--;
	}
	else
	{
		Head=Head->next;
		delete temp;
		iSize--;
	}
}

/////////////////////////////////////////////////////////////////////////////////////////////////////////////
// 
//   Function name : DeleteLast()
//   Date : 25/05/2021
//   Author : Srushti Deshmukh
//   Parameters : None
//   Description : This is fun use to delete node in Linked List from last
//
////////////////////////////////////////////////////////////////////////////////////////////////////////////

template <class T>
void SinglyLL<T>::DeleteLast()
{
	struct SinglyLLnode<T> *temp=Head;

	if(Head==NULL && Tail==NULL)
	{
		cout<<"Linked list is empty\n";
		return;
	}
	
	if(Head->next==NULL)
	{
		delete temp;
		Head=NULL;
		Tail=NULL;
		iSize--;
	}
	else
	{
		while(temp->next->next!=NULL)
		{
			temp=temp->next;
		}
		delete temp->next;
		temp->next=NULL;
		Tail=temp;
		iSize--;
	}
}

/////////////////////////////////////////////////////////////////////////////////////////////////////////////
// 
//   Function name : InsertAtPos()
//   Date : 25/05/2021
//   Author : Srushti Deshmukh
//   Parameters : Two
//			T no-It is data of generic datatype
//			int iPos-it is position of insertion 
//   Description : This is fun use to insert node in Linked List at given position
//
////////////////////////////////////////////////////////////////////////////////////////////////////////////


template <class T>
void SinglyLL<T>::InsertAtPos(T no,int iPos)
{
	struct SinglyLLnode<T> *temp=Head;
	
	struct SinglyLLnode<T> *newn=NULL;
	newn=new struct SinglyLLnode<T> ;
		
	newn->data=no;
	newn->next=NULL;

	if((iPos<1) || (iPos>iSize+1))
	{
		cout<<"Enter valid position\n";
		return;
	}	
	else if(iPos==1)
	{
		InsertFirst(no);
	}
	else if(iPos==iSize+1)
	{
		InsertLast(no);
	}
	else
	{
		for(int i=1;i<iPos-1;i++)
		{
			temp=temp->next;
		}
		newn->next=temp->next;
		temp->next=newn;
		iSize++;
	}
}

/////////////////////////////////////////////////////////////////////////////////////////////////////////////
// 
//   Function name : DeleteAtPos()
//   Date : 25/05/2021
//   Author : Srushti Deshmukh
//   Parameters : One
//			int iPos-It is position of deletion
//   Description : This is fun use to delete node in Linked List at given position
//
////////////////////////////////////////////////////////////////////////////////////////////////////////////

template <class T>
void SinglyLL<T>::DeleteAtPos(int iPos)
{
	struct SinglyLLnode<T> *temp=Head;
	struct SinglyLLnode<T> *target=NULL;
	
	if((iPos<1) || (iPos>iSize))
	{
		cout<<"Enter valid position\n";
		return;
	}	
	else if(iPos==1)
	{
		DeleteFirst();
	}
	else if(iPos==iSize)
	{
		DeleteLast();
	}
	else
	{
		for(int i=1;i<iPos-1;i++)
		{
			temp=temp->next;
		}
		target=temp->next;
		temp->next=target->next;
		delete target;
		iSize--;
	}
}

/////////////////////////////////////////////////////////////////////////////////////////////////////////////
// 
//   Function name : Count()
//   Date : 26/05/2021
//   Author : Srushti Deshmukh
//   Parameters : None
//   Description : This is fun use to count number of nodes in Linked List
//
////////////////////////////////////////////////////////////////////////////////////////////////////////////

template <class T>
int SinglyLL<T>::Count()
{
	return iSize;
}

/////////////////////////////////////////////////////////////////////////////////////////////////////////////
// 
//   Function name : Display()
//   Date : 26/05/2021
//   Author : Srushti Deshmukh
//   Parameters : One
//   Description : This is fun use to display all nodes in Linked List
//
////////////////////////////////////////////////////////////////////////////////////////////////////////////

template <class T>
void SinglyLL<T>::Display()
{
	struct SinglyLLnode<T> *temp=Head;

	while(temp!=NULL)
	{
		cout<<"|"<<temp->data<<"|->";		
		temp=temp->next;
	}
	cout<<"NULL\n";
}

/////////////////////////////////////////////////////////////////////////////////////////////////////////////
// 
//   Function name : SearchFirstOcc()
//   Date : 26/05/2021
//   Author : Srushti Deshmukh
//   Parameters : One
//			T no-It is data to search its first occurence
//   Description : This is fun use to return index of first occurence in Linked List
//
////////////////////////////////////////////////////////////////////////////////////////////////////////////


template <class T>
int SinglyLL<T>::SearchFirstOcc(T no)
{
	int iCnt=0,i=0;
	struct SinglyLLnode<T> *temp=Head;
	
	for(i=1;i<=iSize;i++)
	{
		if(temp->data==no)
		{	
			iCnt=i;
			break;			
		}
		temp=temp->next;
	}
	
	if(i>iSize)
		return -1;
	else
		return iCnt;
}

/////////////////////////////////////////////////////////////////////////////////////////////////////////////
// 
//   Function name : SearchFirstOcc()
//   Date : 26/05/2021
//   Author : Srushti Deshmukh
//   Parameters : One
//			T no-It is data to search its last occurence
//   Description : This is fun use to return index of last occurence in Linked List
//
////////////////////////////////////////////////////////////////////////////////////////////////////////////


template <class T>
int SinglyLL<T>::SearchLastOcc(T no)
{
	int iCnt=0,i=0;
	struct SinglyLLnode<T> *temp=Head;
	
	for(i=1;i<=iSize;i++)
	{
		if(temp->data==no)
		{	
			iCnt=i;
		}
		temp=temp->next;
	}
	if(iCnt==0)
		return -1;
	else
		return iCnt;
}

/////////////////////////////////////////////////////////////////////////////////////////////////////////////
// 
//   Function name : Empty()
//   Date : 26/05/2021
//   Author : Srushti Deshmukh
//   Parameters : None
//   Description : This is fun use to empty all linked list
//
////////////////////////////////////////////////////////////////////////////////////////////////////////////

template <class T>
void SinglyLL<T>::Empty()
{
	struct SinglyLLnode<T>*temp=NULL;

	while(Head!=NULL)
	{
		temp=Head;
		Head=Head->next;
		delete temp;
	}
	iSize=0;
}

/////////////////////////////////////////////////////////////////////////////////////////////////////////////
// 
//   Function name : FirstElement()
//   Date : 26/05/2021
//   Author : Srushti Deshmukh
//   Parameters : None
//   Description : This is fun use to return first element in Linked List
//
////////////////////////////////////////////////////////////////////////////////////////////////////////////

template <class T>
T SinglyLL<T>::FirstElement()
{
	if(Head==NULL && Tail==NULL)
	{
		return -1;		
	}
	else
		return Head->data;
}	

/////////////////////////////////////////////////////////////////////////////////////////////////////////////
// 
//   Function name : LastElement()
//   Date : 26/05/2021
//   Author : Srushti Deshmukh
//   Parameters : None
//   Description : This is fun use to return last element in Linked List
//
////////////////////////////////////////////////////////////////////////////////////////////////////////////

template <class T>
T SinglyLL<T>::LastElement()
{
	if(Head==NULL && Tail==NULL)
	{
		return -1;		
	}
	else
		return Tail->data;
}

template <class T>
void SinglyLL<T>::Remove(T no)
{
	struct SinglyLLnode<T> *temp=Head;
	struct SinglyLLnode<T> *target=NULL;
	
	if(Head==NULL && Tail==NULL)
	{
		return ;		
	}
	if(Head->data==no)
	{
		Head=Head->next;
		delete temp;
		iSize--;
	}
	else
	{
		while(temp->next!=NULL)
		{
			if(temp->data==no)
			{
				target=temp->next;
				temp->next=target->next;
				delete target;
				iSize--;
			}	
			temp=temp->next;
		}
	}
}


//declaration of generic Singly circular linked list
template <class T>
struct SinglyCLnode
{
	T data;
	struct SinglyCLnode* next;
};

template <class T>
class SinglyCL
{
	private:
	  struct SinglyCLnode <T> *Head;		//Pointer points to the first node
	  struct SinglyCLnode <T> *Tail;		//Pointer points to the last node
	  int iSize;				//variable for counting nodes

	public:
	 SinglyCL();
	 ~SinglyCL();

	//Declaration of functions
	void InsertFirst(T);			
	void InsertLast(T);
	void InsertAtPos(T,int);
	void DeleteFirst();
	void DeleteLast();
	void DeleteAtPos(int);
	int Count();
	void Display();
	int SearchFirstOcc(T);
	int SearchLastOcc(T);
	bool isEmpty();
	T FirstElement();
	T LastElement();
	
};

template <class T>
SinglyCL<T>::SinglyCL()
{
	cout<<"Inside Constructor\n";
	Head=NULL;
	Tail=NULL;
	iSize=0;
}

template <class T>
SinglyCL<T>::~SinglyCL()
{
	struct SinglyCLnode<T>*temp=NULL;

	cout<<"Inside Destructor\n";
	while(iSize!=0)
	{
		temp=Head;
		Head=Head->next;
		delete temp;
		iSize--;
	}
}

template <class T>
void SinglyCL<T>::InsertFirst(T no)
{
	struct SinglyCLnode <T> *newn=NULL;
	newn=new struct SinglyCLnode<T>;

	newn->data=no;
	newn->next=NULL;

	if(Head==NULL)
	{
		Head=newn;
		Tail=newn;
		Tail->next=Head;
	}
	else
	{
		newn->next=Head;
		Head=newn;
		Tail->next=Head;
	}	
	iSize++;
}

template <class T>
void SinglyCL<T>::InsertLast(T no)
{
	struct SinglyCLnode<T> *newn=NULL;
	newn=new struct SinglyCLnode<T>;

	newn->data=no;
	newn->next=NULL;
	
	if(Head==NULL)
	{
		Head=newn;
		Tail=newn;
		Tail->next=Head;
	}
	else
	{	
		Tail->next=newn;
		Tail=newn;
		Tail->next=Head;
	}
	iSize++;
}

template <class T>
void SinglyCL<T>::DeleteFirst()
{
	struct SinglyCLnode<T> *temp=Head;
	
	if(Head==NULL && Tail==NULL)
	{
		cout<<"Linked list is empty\n";
		return;
	}
	
	if(Head->next==NULL)
	{
		delete temp;
		Head=NULL;
		Tail=NULL;
		iSize--;
	}
	else
	{
		Head=Head->next;
		delete temp;
		Tail->next=Head;
		iSize--;
	}
}

template <class T>
void SinglyCL<T>::DeleteLast()
{
	struct SinglyCLnode<T> *temp=Head;

	if(Head==NULL && Tail==NULL)
	{
		cout<<"Linked list is empty\n";
		return;
	}
	
	if(Head->next==NULL)
	{
		delete temp;
		Head=NULL;
		Tail=NULL;
		iSize--;
	}
	else
	{
		for(int i=1;i<iSize-1;i++)
		{
			temp=temp->next;
		}
		delete temp->next;
		Tail=temp;
		Tail->next=Head;
		iSize--;
	}
}

template <class T>
void SinglyCL<T>::InsertAtPos(T no,int iPos)
{
	struct SinglyCLnode<T> *temp=Head;
	
	struct SinglyCLnode<T> *newn=NULL;
	newn=new struct SinglyCLnode<T> ;
		
	newn->data=no;
	newn->next=NULL;

	if((iPos<1) || (iPos>iSize+1))
	{
		cout<<"Enter valid position\n";
		return;
	}	
	else if(iPos==1)
	{
		InsertFirst(no);
	}
	else if(iPos==iSize+1)
	{
		InsertLast(no);
	}
	else
	{
		for(int i=1;i<iPos-1;i++)
		{
			temp=temp->next;
		}
		newn->next=temp->next;
		temp->next=newn;
		Tail->next=Head;
		iSize++;
	}
}

template <class T>
void SinglyCL<T>::DeleteAtPos(int iPos)
{
	struct SinglyCLnode<T> *temp=Head;
	struct SinglyCLnode<T> *target=NULL;
	
	if((iPos<1) || (iPos>iSize))
	{
		cout<<"Enter valid position\n";
		return;
	}	
	else if(iPos==1)
	{
		DeleteFirst();
	}
	else if(iPos==iSize)
	{
		DeleteLast();
	}
	else
	{
		for(int i=1;i<iPos-1;i++)
		{
			temp=temp->next;
		}
		target=temp->next;
		temp->next=target->next;
		delete target;
		Tail->next=Head;
		iSize--;
	}
}

template <class T>
int SinglyCL<T>::Count()
{
	return iSize;
}

template <class T>
void SinglyCL<T>::Display()
{
	struct SinglyCLnode<T> *temp=Head;

	for(int i=1;i<=iSize;i++)
	{
		cout<<"|"<<temp->data<<"|->";		
		temp=temp->next;
	}
	cout<<"NULL\n";
}

template <class T>
int SinglyCL<T>::SearchFirstOcc(T no)
{
	int iCnt=0,i=0;
	struct SinglyCLnode<T> *temp=Head;
	
	for(i=1;i<=iSize;i++)
	{
		if(temp->data==no)
		{	
			iCnt=i;
			break;			
		}
		temp=temp->next;
	}
	
	if(i>iSize)
		return -1;
	else
		return iCnt;
}

template <class T>
int SinglyCL<T>::SearchLastOcc(T no)
{
	int iCnt=0,i=0;
	struct SinglyCLnode<T> *temp=Head;
	
	for(i=1;i<=iSize;i++)
	{
		if(temp->data==no)
		{	
			iCnt=i;
		}
		temp=temp->next;
	}
	if(iCnt==0)
		return -1;
	else
		return iCnt;
}

template <class T>
bool SinglyCL<T>::isEmpty()
{
	if(Head==NULL && Tail==NULL)
	{
		return true;
	}
	else
		return false;
}


template <class T>
T SinglyCL<T>::FirstElement()
{
	if(Head==NULL && Tail==NULL)
	{
		return -1;		
	}
	else
		return Head->data;
}	

template <class T>
T SinglyCL<T>::LastElement()
{
	if(Head==NULL && Tail==NULL)
	{
		return -1;		
	}
	else
		return Tail->data;
}

//declaration of generic Doubly linked list
template <class T>
struct DoublyLLnode
{
	T data;
	struct DoublyLLnode* next;
	struct DoublyLLnode* prev;
};

template <class T>
class DoublyLL
{
	private:
	  struct DoublyLLnode <T> *Head;		//Pointer points to the first node
	  struct DoublyLLnode <T> *Tail;		//Pointer points to the last node
	  int iSize;				//variable for counting nodes

	public:
	 DoublyLL();
	 ~DoublyLL();

	//Declaration of functions
	void InsertFirst(T);			
	void InsertLast(T);
	void InsertAtPos(T,int);
	void DeleteFirst();
	void DeleteLast();
	void DeleteAtPos(int);
	int Count();
	void Display();
	int SearchFirstOcc(T);
	int SearchLastOcc(T);
	void Empty();
	T FirstElement();
	T LastElement();
	//void Remove(T);
	
};

template <class T>
DoublyLL<T>::DoublyLL()
{
	Head=NULL;
	Tail=NULL;
	iSize=0;
}

template <class T>
DoublyLL<T>::~DoublyLL()
{
	struct DoublyLLnode<T>*temp=NULL;

	while(Head!=NULL)
	{
		temp=Head;
		Head=Head->next;
		delete temp;
	}
}

template <class T>
void DoublyLL<T>::InsertFirst(T no)
{
	struct DoublyLLnode <T> *newn=NULL;
	newn=new struct DoublyLLnode<T>;

	newn->data=no;
	newn->next=NULL;
	newn->prev=NULL;

	if(Head==NULL)
	{
		Head=newn;
		Tail=newn;
	}
	else
	{
		newn->next=Head;
		Head->prev=newn;
		Head=newn;
	}	
	iSize++;
}

template <class T>
void DoublyLL<T>::InsertLast(T no)
{
	struct DoublyLLnode<T> *temp=Head;

	struct DoublyLLnode<T> *newn=NULL;
	newn=new struct DoublyLLnode<T>;

	newn->data=no;
	newn->next=NULL;
	newn->prev=NULL;
	
	if(Head==NULL)
	{
		Head=newn;
		Tail=newn;
	}
	else
	{	
		Tail->next=newn;
		newn->prev=Tail;
		Tail=newn;
	}
	iSize++;
}

template <class T>
void DoublyLL<T>::DeleteFirst()
{
	struct DoublyLLnode<T> *temp=Head;
	
	if(Head==NULL && Tail==NULL)
	{
		cout<<"Linked list is empty\n";
		return;
	}
	
	if(Head->next==NULL)
	{
		delete temp;
		Head=NULL;
		Tail=NULL;
		iSize--;
	}
	else
	{
		Head=Head->next;
		Head->prev=NULL;
		delete temp;
		iSize--;
	}
}

template <class T>
void DoublyLL<T>::DeleteLast()
{
	struct DoublyLLnode<T> *temp=Head;

	if(Head==NULL && Tail==NULL)
	{
		cout<<"Linked list is empty\n";
		return;
	}
	
	if(Head->next==NULL)
	{
		delete temp;
		Head=NULL;
		Tail=NULL;
		iSize--;
	}
	else
	{
		while(temp->next->next!=NULL)
		{
			temp=temp->next;
		}
		delete temp->next;
		temp->next=NULL;
		Tail=temp;
		iSize--;
	}
}

template <class T>
void DoublyLL<T>::InsertAtPos(T no,int iPos)
{
	struct DoublyLLnode<T> *temp=Head;
	
	struct DoublyLLnode<T> *newn=NULL;
	newn=new struct DoublyLLnode<T> ;
		
	newn->data=no;
	newn->next=NULL;
	newn->prev=NULL;

	if((iPos<1) || (iPos>iSize+1))
	{
		cout<<"Enter valid position\n";
		return;
	}	
	else if(iPos==1)
	{
		InsertFirst(no);
	}
	else if(iPos==iSize+1)
	{
		InsertLast(no);
	}
	else
	{
		for(int i=1;i<iPos-1;i++)
		{
			temp=temp->next;
		}
		newn->next=temp->next;
		temp->next->prev=newn;
		temp->next=newn;
		newn->prev=temp;
		iSize++;
	}
}

template <class T>
void DoublyLL<T>::DeleteAtPos(int iPos)
{
	struct DoublyLLnode<T> *temp=Head;
	struct DoublyLLnode<T> *target=NULL;
	
	if((iPos<1) || (iPos>iSize))
	{
		cout<<"Enter valid position\n";
		return;
	}	
	else if(iPos==1)
	{
		DeleteFirst();
	}
	else if(iPos==iSize)
	{
		DeleteLast();
	}
	else
	{
		for(int i=1;i<iPos-1;i++)
		{
			temp=temp->next;
		}
		target=temp->next;
		temp->next=target->next;
		target->next->prev=temp;
		delete target;
		iSize--;
	}
}

template <class T>
int DoublyLL<T>::Count()
{
	return iSize;
}

template <class T>
void DoublyLL<T>::Display()
{
	struct DoublyLLnode<T> *temp=Head;

	while(temp!=NULL)
	{
		cout<<"|"<<temp->data<<"|->";		
		temp=temp->next;
	}
	cout<<"NULL\n";
}

template <class T>
int DoublyLL<T>::SearchFirstOcc(T no)
{
	int iCnt=0,i=0;
	struct DoublyLLnode<T> *temp=Head;
	
	for(i=1;i<=iSize;i++)
	{
		if(temp->data==no)
		{	
			iCnt=i;
			break;			
		}
		temp=temp->next;
	}
	
	if(i>iSize)
		return -1;
	else
		return iCnt;
}

template <class T>
int DoublyLL<T>::SearchLastOcc(T no)
{
	int iCnt=0,i=0;
	struct DoublyLLnode<T> *temp=Head;
	
	for(i=1;i<=iSize;i++)
	{
		if(temp->data==no)
		{	
			iCnt=i;
		}
		temp=temp->next;
	}
	if(iCnt==0)
		return -1;
	else
		return iCnt;
}

template <class T>
void DoublyLL<T>::Empty()
{
	struct DoublyLLnode<T>*temp=NULL;

	while(Head!=NULL)
	{
		temp=Head;
		Head=Head->next;
		delete temp;
		iSize--;
	}
}

template <class T>
T DoublyLL<T>::FirstElement()
{
	if(Head==NULL && Tail==NULL)
	{
		return -1;		
	}
	else
		return Head->data;
}

template <class T>
T DoublyLL<T>::LastElement()
{
	if(Head==NULL && Tail==NULL)
	{
		return -1;		
	}
	else
		return Tail->data;
}


//declaration of generic Doubly Circular linked list
template <class T>
struct DoublyCLnode
{
	T data;
	struct DoublyCLnode* next;
	struct DoublyCLnode* prev;
};

template <class T>
class DoublyCL
{
	private:
	  struct DoublyCLnode <T> *Head;		//Pointer points to the first node
	  struct DoublyCLnode <T> *Tail;		//Pointer points to the last node
	  int iSize;				//variable for counting nodes

	public:
	 DoublyCL();
	 ~DoublyCL();

	//Declaration of functions
	void InsertFirst(T);			
	void InsertLast(T);
	void InsertAtPos(T,int);
	void DeleteFirst();
	void DeleteLast();
	void DeleteAtPos(int);
	int Count();
	void Display();
	int SearchFirstOcc(T);
	int SearchLastOcc(T);
	void Empty();
	T FirstElement();
	T LastElement();
	//void Remove(T);
	
};

template <class T>
DoublyCL<T>::DoublyCL()
{
	Head=NULL;
	Tail=NULL;
	iSize=0;
}

template <class T>
DoublyCL<T>::~DoublyCL()
{
	struct DoublyCLnode<T>*temp=NULL;

	for(int i=1;i<=iSize;i++)
	{
		temp=Head;
		Head=Head->next;
		delete temp;
	}
}


template <class T>
void DoublyCL<T>::InsertFirst(T no)
{
	struct DoublyCLnode <T> *newn=NULL;
	newn=new struct DoublyCLnode<T>;

	newn->data=no;
	newn->next=NULL;
	newn->prev=NULL;

	if((Head==NULL) && (Tail==NULL))
	{
		Head=newn;
		Tail=newn;
	}
	else
	{
		newn->next=Head;
		Head->prev=newn;
		Head=newn;
	}	
	Tail->next=Head;
	Head->prev=Tail;
	iSize++;
}

template <class T>
void DoublyCL<T>::InsertLast(T no)
{
	struct DoublyCLnode<T> *newn=NULL;
	newn=new struct DoublyCLnode<T>;

	newn->data=no;
	newn->next=NULL;
	newn->prev=NULL;
	
	if((Head==NULL) && (Tail==NULL))
	{
		Head=newn;
		Tail=newn;
	}
	else
	{	
		Tail->next=newn;
		newn->prev=Tail;
		Tail=newn;
	}
	Tail->next=Head;
	Head->prev=Tail;
	iSize++;
}

template <class T>
void DoublyCL<T>::DeleteFirst()
{
	if(Head==NULL && Tail==NULL)
	{
		cout<<"Linked list is empty\n";
		return;
	}
	
	if(Head==Tail)
	{
		delete Head;
		Head=NULL;
		Tail=NULL;
		iSize--;
	}
	else
	{
		Head=Head->next;
		delete (Tail->next);
		Tail->next=Head;
		Head->prev=Tail;
		iSize--;
	}
}

template <class T>
void DoublyCL<T>::DeleteLast()
{
	struct DoublyCLnode<T> *temp=Head;

	if(Head==NULL && Tail==NULL)
	{
		cout<<"Linked list is empty\n";
		return;
	}
	
	if(Head==Tail)
	{
		delete temp;
		Head=NULL;
		Tail=NULL;
		iSize--;
	}
	else
	{
		Tail=Tail->prev;
		Tail->next=Head;
		Head->prev=Tail;
		iSize--;
	}
}

template <class T>
void DoublyCL<T>::InsertAtPos(T no,int iPos)
{
	struct DoublyCLnode<T> *temp=Head;
	
	struct DoublyCLnode<T> *newn=NULL;
	newn=new struct DoublyCLnode<T> ;
		
	newn->data=no;
	newn->next=NULL;
	newn->prev=NULL;

	if((iPos<1) || (iPos>iSize+1))
	{
		cout<<"Enter valid position\n";
		return;
	}	
	else if(iPos==1)
	{
		InsertFirst(no);
	}
	else if(iPos==iSize+1)
	{
		InsertLast(no);
	}
	else
	{
		for(int i=1;i<iPos-1;i++)
		{
			temp=temp->next;
		}
		newn->next=temp->next;
		temp->next->prev=newn;
		temp->next=newn;
		newn->prev=temp;
		iSize++;
	}
}

template <class T>
void DoublyCL<T>::DeleteAtPos(int iPos)
{
	struct DoublyCLnode<T> *temp=Head;
	struct DoublyCLnode<T> *target=NULL;
	
	if((iPos<1) || (iPos>iSize))
	{
		cout<<"Enter valid position\n";
		return;
	}	
	else if(iPos==1)
	{
		DeleteFirst();
	}
	else if(iPos==iSize)
	{
		DeleteLast();
	}
	else
	{
		for(int i=1;i<iPos-1;i++)
		{
			temp=temp->next;
		}
		target=temp->next;
		temp->next=target->next;
		target->next->prev=temp;
		delete target;
		iSize--;
	}
}

template <class T>
int DoublyCL<T>::Count()
{
	return iSize;
}

template <class T>
void DoublyCL<T>::Display()
{
	struct DoublyCLnode<T> *temp=Head;

	for(int i=1;i<=iSize;i++)
	{
		cout<<"|"<<temp->data<<"|->";		
		temp=temp->next;
	}
	cout<<"NULL\n";
}

template <class T>
int DoublyCL<T>::SearchFirstOcc(T no)
{
	int iCnt=0,i=0;
	struct DoublyCLnode<T> *temp=Head;
	
	for(i=1;i<=iSize;i++)
	{
		if(temp->data==no)
		{	
			iCnt=i;
			break;			
		}
		temp=temp->next;
	}
	
	if(i>iSize)
		return -1;
	else
		return iCnt;
}

template <class T>
int DoublyCL<T>::SearchLastOcc(T no)
{
	int iCnt=0,i=0;
	struct DoublyCLnode<T> *temp=Head;
	
	for(i=1;i<=iSize;i++)
	{
		if(temp->data==no)
		{	
			iCnt=i;
		}
		temp=temp->next;
	}
	if(iCnt==0)
		return -1;
	else
		return iCnt;
}

template <class T>
void DoublyCL<T>::Empty()
{
	struct DoublyCLnode<T>*temp=NULL;

	for(int i=1;i<=iSize;i++)
	{
		temp=Head;
		Head=Head->next;
		delete temp;
	}
	iSize=0;
}

template <class T>
T DoublyCL<T>::FirstElement()
{
	if(Head==NULL && Tail==NULL)
	{
		return -1;		
	}
	else
		return Head->data;
}

template <class T>
T DoublyCL<T>::LastElement()
{
	if(Head==NULL && Tail==NULL)
	{
		return -1;		
	}
	else
		return Tail->data;
}

