#include<iostream>
#include"List.h"
#include"People.h"
using namespace std;
int main()
{
	int input;
	List mybook;
	mybook.readfile();
	cout << "请输入功能序号：" << endl;
	cout << "1、添加" << endl;
	cout << "2、删除" << endl;
	cout << "3、查找" << endl;
	cout << "4、显示所有" << endl;
	cout << "5、退出程序" << endl;
	cin >> input;
	bool state = true;
	while (state)
	{
		switch (input) {
		case 1:
			std::cerr << "添加" << std::endl;
			mybook.add();
			break;
		case 2:
			std::cerr << "删除" << std::endl;
			mybook.del();
			break;
		case 3:
			std::cerr << "查找" << std::endl;
			break;
		case 4:
			std::cerr << "显示所有" << std::endl;
			mybook.showall();
			break;
		case 5:
			std::cerr << "退出程序" << std::endl;
			break;
		default:
			std::cerr << "输入错误" << std::endl;
			break;
		}
		cout << "请输入功能序号：" << endl;
		cin >> input;
	}
	
	return 0;
}