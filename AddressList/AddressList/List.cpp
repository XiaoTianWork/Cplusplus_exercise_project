#include <fstream>
#include "List.h"
List::List()
{
}

List::~List()
{
}
void List::add()
{
	Person p;
	std::cout << "请输入姓名：\n" << std::endl;
	std::cin >> p.name;
	std::cout << "请输入号码：\n" << std::endl;
	std::cin >> p.telnumber;
	myfile.push_back(p);//把输入的号码添加到myfile当中
	this->flash();
}
void List::flash()
{
	std::ofstream outfile("book.txt");
	std::vector<Person>::iterator iter;
	for (iter = this->myfile.begin(); iter != this->myfile.end(); iter++)
	{
		outfile << iter->name;
		outfile << iter->telnumber;
	}
	outfile.close(); //关闭文件
}
void List::del()
{
	if (myfile.empty())
	{
		std::cout << "通讯录中没有记录！"<< std::endl;
		return;
	}
	std::string name;
	std::cout << "请输入要删除的姓名" << std::endl;
	std::cin >> name;
	std::vector<Person>::iterator iter;
	for (iter = myfile.begin(); iter != myfile.end(); iter++)
	{
		if (iter->name == name)
		{
			myfile.erase(iter);//删除对应项目，iter是索引
			std::cout << "删除成功！" << std::endl;
		}
	}

}