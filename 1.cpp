#include<iostream>
using namespace std:
	
typedef int DataType;
struct Node
{
	DataType data;
	Node* next;
};

/*函数功能：初始化一个带头结点的单链表
*函数形参：无 
*函数返回值：返回单链表的头指针，Node*类型 
*/ 
Node* InitLinkList()
{
	//Node* head = (Node*)malloc(sizeof(Node));
	Node* head = new Node;
	if (head)
	{
		head->next = nullptr;
		return head;
	}
	return NULL;
}
/*函数功能：
* 函数形参：一个单链表的头指针Node* head
* 函数返回值：插入成功返回true，否则返回false，bool类型
*/ 
bool CreateLinkList_head(Node* head)
{
	int data;
	cin>>data;
	Node* p=new Node;  //申请结点空间 
	if(p)  //申请成功 
	{
		p->data=data;  //数据域赋值 
		p->next=head->next;   //指针域赋值
		head-> 
	}
	
}
/*函数功能：打印单链表结点的数据 
* 函数形参：一个单链表的头指针Node* head
* 函数返回值：无，void类型 
*/ 
void PrintLinkList(Node* head)
{
	Node*p=head->next;  //循环变量赋初值
	while(p)
	{
		count++;  //计数器加1 
		cout<<p->data<<"";
		p=p->next;
	} 
	//cout<<"共打印输出"<<p<<"个结点数据";
	cout<<endl<<count;
} 

int main() 
{
	Node* head = InitLinkList()
	CreateLinkList_head(head);
	CreateLinkList_head(head);
	
	PrintLinkList(head);
	
	return 0;
}
