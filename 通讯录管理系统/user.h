#ifndef USER_H
#define	USER_H

#include"cardmaillist.h"
#include"phonemaillist.h"
#include"uimenu.h"
class User {
	PhoneMaillist phonemaillist;
	CardMaillist cardmaillist;
	Uimenu uimenu;
public:
	User();								//构造函数
	~User();							//析构函数
	void add();							//新建联系人
	void Delete();						//删除联系人
	void change();						//修改联系人信息  
	void inquiry();						//查询联系人信息  
	void display();						//显示所有联系人信息
	void move_card_to_phone();			//移动手机卡通讯录到手机通讯录
	void move_phone_to_card();			//移动手机通讯录到手机卡通讯录
	void copy_card_to_phone();			//复制手机卡通讯录到手机通讯录
	void copy_phone_to_card();			//复制手机通讯录到手机卡通讯录
};

#endif 