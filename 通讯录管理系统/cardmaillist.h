#ifndef CARDMAILLIST_H
#define CARDMAILLIST_H

#include"cardcontact.h"
#include"maillist.h"
#include<vector>
class CardMaillist :public Maillist {
protected:
	int card_contact_num;						//手机卡联系人数量
	vector <CardContact> card_contact;			//手机卡联系人对象动态数组
public:
	CardMaillist();								//构造函数，读取文本文件中的数据,并根据文件内容创建联系人对象数组
	~CardMaillist();							//析构函数，将对象数组中的内容写入到文本文件中
	void add() ;								//新建联系人
	void Delete(string rtel_num) ;				//删除联系人
	void change(string rtel_num) ;				//修改联系人信息  
	void inquiry(string rname) ;				//查询联系人信息  
	void display() ;							//显示所有联系人信息
	int get_card_contact_num();					//获取手机卡通讯录联系人数量
	void copy(string rname, string rtel_num);	//将姓名、号码压入动态数组
	string get_name(int i);						//获取动态数组第i个联系人的姓名
	string get_tel_num(int i);					//获取动态数组第i个联系人的号码
	void clear();								//清空手机卡通讯录
};

#endif