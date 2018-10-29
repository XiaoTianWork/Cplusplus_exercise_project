#include<iostream>
#include"List.h"
#include"People.h"
using namespace std;
int main()
{
	int input;
	List mybook;
	cout << "请输入功能序号：" << endl;
	cout << "1、添加" << endl;
	cout << "2、删除" << endl;
	cout << "3、查找" << endl;
	cout << "4、显示所有" << endl;
	cout << "5、退出程序" << endl;
	cin >> input;
	switch (input) {
	case 1:
		mybook.add();
		break;
	case 2:
		break;
	case 3:
		break;
	case 4:
		break;
	case 5:
		break;
	default:
		break;
	}
	return 0;
}