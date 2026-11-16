//项目名称：简单的通讯录管理程序
//项目功能：添加、删除、修改、查询联系人信息
#include <iostream>
using namespace std;
//联系人结构体
struct Contact
{
	char name[50];//姓名
	char phone[12];//电话
	int year, month, day;//出生日期
	struct Birthday
	{
		int year;
		int month;
		int day;
	} birthday;
	int age;//年龄
};
//定义通讯录结点结构体
struct Node
{
	Contact data;//联系人信息
	Node* next;//指向下一个结点的指针
};

/*函数功能：初始化一个空的通讯录链表
*函数形参：无
*函数返回值：返回一个指向链表头结点的指针,Node*类型
*/
Node* InitAdressBook()
{
	Node* head = new Node;//创建一个头结点
	if (head == NULL)//判断内存是否分配成功
	{
		cout << "内存分配失败！" << endl;
		return NULL;
	}
	else
	{
		head->next = NULL;//将头节点的next指针置为空
	}
	return head;//返回头节点指针
}
/*函数功能：采用头插法创建一个通讯录链表
*函数形参：通讯录链表头指针Node*head，联系人信息Contact contact
*函数返回值：创建成功返回true，否则返回false，bool类型
*/
bool CreateAdressBookHead(Node* head, Contact contact)
{
	Node* node = new Node;//创建一个新结点
	if (node == NULL)//判断内存是否分配成功
	{
		cout << "内存分配失败！" << endl;
		return false;
	}
	node->data;//将联系人信息赋值给新结点的数据域
	node->next = head->next;//将新结点的next指针指向原来的第一个结点
	head->next = node;//将头结点的next指针指向新结点
	return true;//返回创建成功
}
/*函数功能：采用尾插法创建一个通讯录链表
*函数形参：通讯录链表头指针Node*head，联系人信息Contact contact
*函数返回值：创建成功返回true，否则返回false，bool类型
*/
bool CreateAdressBookTail(Node* head, Contact contact)
{
	static Node* tail = head;//定义一个尾指针，指向链表的最后一个结点
	Node* node = new Node;//创建一个新结点
	if (node == NULL)
	{
		cout << "内存分配失败！" << endl;
		return false;
	}
	while (tail->next != NULL)
	{
		tail = tail->next;//找到链表的最后一个结点
	}
	tail->next = node;//将新结点插入到链表的末尾
	node->next = NULL;//将新结点的next指针置为空
	return true;//返回创建成功
}

/*函数功能：输出单个联系人信息
* 函数形参：无
* 函数返回值：返回联系人信息，Contact类型
*/
Contact InputContact()
{
	Contact data;
	cout << "请输入联系人姓名：" << endl;
	cin >> data.name;
	cout << "请输入联系人电话：" << endl;
	cin >> data.phone;
	cout << "请输入联系人出生日期（年 月 日）：" << endl;
	cin >> data.birthday.year >> data.birthday.month >> data.birthday.day;
	data.age = 2026 - data.birthday.year;
	return data;
}

/*函数功能：输出通讯录中所有联系人信息
* 函数形参：通讯录链表头指针Node*head
* 函数返回值：无，void类型
*/
void OutputContact(Contact data)
{
	cout << "姓名：" << data.name << endl;
	cout << "电话：" << data.phone << endl;
	cout << "出生日期：" << data.birthday.year << "年" << data.birthday.month << "月" << data.birthday.day << "日" << endl;
	cout << "年龄：" << data.age << endl;
}
void OutputAdressBook(Node* head)
{
	Node* node = head->next;
	while (node)
	{
		OutputContact(node->data);
		node = node->next;

	}
}

/*函数功能：按姓名查找通讯录中指定联系人信息
* 函数形参：通讯录链表头指针Node*head，联系人姓名char name[]
* 函数返回值：查找成功，返回地址，否则返回空，Node*类型
*/
Node* SearchContactByName(Node* head, char* name)
{
	Node* node = head->next;
	while (node)
	{
		if (strcmp(node->data.name, name) == 0)
			return node;//查找成功，返回结点地址
		node = node->next;
	}
	return NULL;//查找失败，返回空
}

/*函数功能：按电话查找通讯录中指定联系人信息
* 函数形参：通讯录链表头指针Node*head，联系人电话char phone[]
* 函数返回值：查找成功，返回地址，否则返回空，Node*类型
*/
Node* SearchContactByPhone(Node* head, char* phone)
{
	Node* node = head->next;
	while (node)
	{
		if (strcmp(node->data.phone, phone) == 0)
			return node;//查找成功，返回结点地址
		node = node->next;
	}
	return NULL;//查找失败，返回空
}

/*函数功能：在指定联系人的后面插入一个新的联系人
* 函数形参：通讯录链表头指针Node*head，指定联系人地址Node* target,联系人信息Contact data
* 函数返回值：查找成功，返回true，否则返回false，bool类型
*/
bool InsertContactAfter(Node* head, Node* target, Contact data)
{
	Node* node = new Node;//创建一个新的结点
	if (node)
	{
		node->data = data;//数据域赋值
		node->next = target->next;//指针域赋值
		target->next = node;//将指定结点的next指针指向新结点
		return true;//插入成功，返回true
	}
	return false;
}

/*函数功能：查找指定联系人的前驱结点
* 函数形参：通讯录链表头指针Node*head，指定联系人地址Node* target,联系人信息Contact data
* 函数返回值：查找成功，返回前驱，否则返回空，Node*类型
*/
Node* SearchContactPrev(Node* head, Node* target)
{
	for (Node* pre = head;pre->next != NULL;pre = pre->next)
		if (pre->next == target)
			return pre;//查找成功，返回前驱结点
	return NULL;//查找失败，返回空
}

/*函数功能：在指定联系人的前面插入一个新的联系人
* 函数形参：通讯录链表头指针Node* head，指定联系人地址Node* target, 联系人信息Contact data
* 函数返回值：查找成功，返回true，否则返回false，bool类型
*/
bool InsertContactBefore(Node* head, Node* target, Contact data)
{
	Node* pre = SearchContactPrev(head, target);//查找指定联系人的前驱结点
	if (pre)
	{
		Node* node = new Node;//创建一个新的结点
		if (node)
		{
			node->data = data;//数据域赋值
			node->next = target;//指针域赋值
			pre->next = node;//将前驱结点的next指针指向新结点
			return true;//插入成功，返回true
		}
	}
	return false;//插入失败，返回false
}

/*函数功能：删除指定联系人
* 函数形参：通讯录链表头指针Node* head，指定联系人地址Node* target
* 函数返回值：查找成功，返回true，否则返回false，bool类型
*/
bool DeleteContact(Node* head, Node* target)
{
	Node* pre = SearchContactPrev(head, target);//查找指定联系人的前驱结点
	if (pre)
	{
		pre->next = target->next;//将前驱结点的next指针指向指定结点的下一个结点
		delete target;//释放指定结点的内存空间
		return true;//删除成功，返回true
	}
	return false;//删除失败，返回false
}

/*函数功能：删除指定联系人的后继
* 函数形参：通讯录链表头指针Node* head，指定联系人地址Node* target
* 函数返回值：查找成功，返回true，否则返回false，bool类型
*/
bool DeleteContactNext(Node* head, Node* target)
{
	if (target->next)
	{
		Node* next = target->next;//保存指定结点的下一个结点
		target->next = next->next;//将指定结点的next指针指向下一个结点的下一个结点
		delete next;//释放下一个结点的内存空间
		return true;//删除成功，返回true
	}
	return false;//删除失败，返回false
}

/*函数功能：删除指定联系人的前驱结点
* 函数形参：通讯录链表头指针Node* head，指定联系人地址Node* target
* 函数返回值：查找成功，返回true，否则返回false，bool类型
*/
bool DeleteContactPrev(Node* head, Node* target)
{
	Node* pre = SearchContactPrev(head, target);//查找指定联系人的前驱结点
	if (pre && pre != head)//判断前驱结点是否存在且不是头结点
	{
		Node* prepre = SearchContactPrev(head, pre);//查找前驱结点的前驱结点
		if (prepre)
		{
			prepre->next = target;//将前驱结点的前驱结点的next指针指向指定结点
			delete pre;//释放前驱结点的内存空间
			return true;//删除成功，返回true
		}
	}
	return false;//删除失败，返回false
}

int main()
{

	return 0;
}