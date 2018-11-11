#include <fstream>
#include "List.h"
List::List()
{
}

List::~List()
{
}
void setout()//输出格式控制，即左对齐
{
	std::cout.setf(std::ios_base::left, std::ios_base::adjustfield);
}
int List::readfile()//读取文件
{
	std::ifstream readfile("book.txt");
	if (readfile)
	{
		Person p;
		std::cout << "***********电话簿***********" << std::endl;
		std::cout << "姓名" << "\t\t" << "电话" << std::endl;
		if (readfile >> p.name >> p.telnumber)//读取第一行若为空。
		{
			std::cout << "\tNULL\n" << std::endl;
		}
		myfile.push_back(p);
		while (readfile >> p.name >> p.telnumber)
		{
			myfile.push_back(p);
		}
		readfile.close();
	}
	else
	{
		std::ofstream file;
		file.open("book.txt");//如果不存在则创建文件
		if (!file.is_open())
		{
			std::cout << "文件创建失败！" << std::endl;
		}
	}
	return 0;
}
void List::showall()//显示文件  [测试通过]
{
	std::vector<Person>::iterator iter;
	setout();//输出格式控制
	for (iter = this->myfile.begin(); iter != this->myfile.end(); iter++)
	{
		std::cout.width(15);//字域宽度为15
		std::cout << iter->name;
		std::cout.width(15);
		std::cout << iter->telnumber << "\n";
	}
}
void List::add()//添加  [测试通过]
{
	Person p;
	std::cout << "请输入姓名：\n" << std::endl;
	std::cin >> p.name;
	std::cout << "请输入号码：\n" << std::endl;
	std::cin >> p.telnumber;
	myfile.push_back(p);//把输入的号码添加到myfile当中
	this->flash();
}
void List::flash()//刷新文件内容
{
	std::ofstream outfile("book.txt");
	std::vector<Person>::iterator iter;
	setout();
	for (iter = this->myfile.begin(); iter != this->myfile.end(); iter++)
	{
		outfile << iter->name;
		outfile << iter->telnumber << "\n";
	}
	outfile.close(); //关闭文件
}
void List::del()
{
	if (myfile.empty())
	{
		std::cout << "通讯录中没有记录！"<< std::endl;
		//return;
	}
	std::string name;
	std::cout << "请输入要删除的姓名" << std::endl;
	std::cin >> name;
	std::vector<Person>::iterator iter;
	for (iter = myfile.begin(); iter != myfile.end(); )
	{
		if (iter->name == name)
		{
			myfile.erase(iter);//删除对应项目，iter是索引
			std::cout << "删除成功！" << std::endl;
			this->flash();
			return;
		}
		else
			iter++;
	}
	std::cout << "未找到要删除的姓名！" << std::endl;
}

int List::search()
{
	std::string name;
	std::cout << "请输入要查找的联系人姓名：" << std::endl;
	std::cin >> name;
	std::vector<Person>::iterator iter;
	for (iter = this->myfile.begin(); iter != this->myfile.end(); iter++)
	{
		if (name == iter->name)
		{
			std::cout<< iter->name << "\t\t" << iter->telnumber << "\n";
		}
		std::cout << "未找到所需要的结果！";
	}
	
	return 0;
}
