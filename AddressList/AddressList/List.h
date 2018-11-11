#pragma once
#include <iostream>
#include <vector>
#include <string>
#include "People.h"
class List {
public:
	List();
	~List();
	void add();
	void del();
	int search();
	int readfile();
	void showall();
	void flash();//刷新文件
	int removefile();

private:
	std::vector<Person> myfile;//定义一个myfile的容器，这块知识需要仔细看下
};

inline void setout();//输出格式控制