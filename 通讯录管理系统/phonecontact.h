/*手机联系人类*/

#ifndef PHONECONTACT_H
#define PHONECONTACT_H

#include<iostream>
#include<string>
using namespace std;
class PhoneContact {
protected:
	string name;
	string tel_num;
public:
	PhoneContact(string rname = "新联系人", string rtel_num = "无号码");   //有参构造函数
	void modify();														   //修改数据成员的值
	friend istream &operator >>(istream &input, PhoneContact &obj);		   //重载>>运算符
	friend ostream &operator <<(ostream &output, PhoneContact &obj);	   //重载<<运算符
	string get_name();													   //获取姓名
	string get_tel_num();												   //获取号码
	void set(string rname, string rtel_num);							   //为数据成员赋值
};

#endif