#include<iostream>
using namespace std;
#include<string>
//global error flag for dequeue
bool ERR_Flag = false;
template<class T>
class queue
{
	protected:
	int front;
	int rear;
	int capacity;
	T *ele;
	public:
	//constructor to allocate memory and initialize data members
	queue();
	bool isempty();
	bool isfull();
	//Check if queue is full before insertion
	//if queue is full return false
	// insert element and return true otherwise
	bool enqueue(T data);
	//funtion to remove an element and return
	T dequeue();
	~queue();
	void print();
};
template<class T>
class deque:public queue<T>
{
	public:
	bool push_Back(T data);
	bool push_Front(T data);
	T pop_Front();
	T pop_Back();
};

queue::queue()
{
    capacity = 30;
    ele = new T[capacity];
    front=-1;
    rear=-1;
}

bool queue::isempty()
{
    if((front>rear)||(front==-1 && rear==-1))
        return true;
    else
        return false;
}

bool queue::isfull()
{
    if(rear==capacity-1)
        return true;
    else
        return false;
}

bool queue::enqueue(T data)
{
    if(isfull())
    {
        return false;
    }
    else
    {
        rear++;
        if(front==-1)
            front++;
        ele[rear]=data;
        return true;
    }
}

T queue::dequeue()
{
    if(!isempty())
    {
        int del = front;
        front++;
        return ele[del];
    }
}

queue::~queue()
{

}

void queue::print()
{
    for(int i=front; i<=rear; i++)
        cout<<ele[i];
}

bool deque::push_Back(T data)
{
    return enqueue(data);
}

bool deque::push_Front(T data)
{

}

T deque::pop_Front()
{
    return dequeue();
}

T deque::pop_Back()
{
    if(!isempty)
    {
        int del = rear;
        rear--;
        return ele[del];
    }
}



int main()
{
	int d_Choice;
	int op_Choice;
	deque<string> d;
	queue<int> q;
	cin>>d_Choice;
	if(d_Choice==1)
	{
		while(1)
		{
			cin>>op_Choice;
			if(op_Choice==1)
			{
				if(q.isempty())
				cout<<"Queue is empty"<<endl;
				else
				cout<<"Queue is not empty"<<endl;
			}
			else if(op_Choice==2)
			{
				if(q.isfull())
				cout<<"Queue is full"<<endl;
				else
				cout<<"Queue is not full"<<endl;
			}
			else if(op_Choice==3)
			{
				int data;
				cin>>data;
				if(!q.enqueue(data))
				cout<<"Queue full insertion not possible";
			}
			else if(op_Choice==4)
			{
				q.dequeue();
				if(ERR_Flag)
				cout<<"Queue is empty";
			}
			else if(op_Choice==5)
			{
				q.print();
			}
			else if(op_Choice==6)
			{
			break;
			}
		}
	}
	else if(d_Choice==2)
	{
		string s_Data;
		while(1)
		{
			cin>>op_Choice;
			if(op_Choice==1)
			{
				if(d.isempty())
				cout<<"Queue is empty"<<endl;
				else
				cout<<"Queue is not empty"<<endl;
			}
			else if(op_Choice==2)
			{
				if(d.isfull())
				cout<<"Queue is full"<<endl;
				else
				cout<<"Queue is not full"<<endl;
			}
			else if(op_Choice==3)
			{
				cin>>s_Data;
				if(!d.push_Back(s_Data))
				cout<<"Queue full insertion not possible";
			}
			else if(op_Choice==4)
			{
				cin>>s_Data;
				if(!d.push_Front(s_Data))
				cout<<"Queue full insertion not possible";

			}
			else if(op_Choice==5)
			{
				d.pop_Back();
				if(ERR_Flag)
				cout<<"Queue is empty";
			}
			else if(op_Choice==6)
			{
				d.pop_Front();
				if(ERR_Flag)
				cout<<"Queue is empty";
			}
			else if(op_Choice==7)
			{
				d.print();
			}
			else if(op_Choice==8)
			{
				break;
			}
		}
	}
}
