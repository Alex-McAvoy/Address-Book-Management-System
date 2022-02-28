/*通讯簿抽象类*/

#ifndef MAILLIST_H
#define MAILLIST_H

#include<iostream>
#include<string>
using namespace std;
class Maillist {
public:
	virtual void add() = 0;						//新建联系人
	virtual void Delete(string rtel_num) = 0;	//删除联系人
	virtual void change(string rtel_num) = 0;	//修改联系人信息  
	virtual void inquiry(string rname) = 0;		//查询联系人信息  
	virtual void display() = 0;					//显示所有联系人信息
};

#endif
