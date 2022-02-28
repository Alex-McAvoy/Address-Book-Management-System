/*手机卡联系人类*/

#ifndef CARDCONTACT_H
#define CARDCONTACT_H

#include"phonecontact.h"  
class CardContact : public PhoneContact{
protected:
	string homeland;
	string QQ;
public:
	CardContact(string rname = "新联系人", string rtel_num = "无号码", string rhomeland = "无地址", string rQQ = "无QQ");	//有参构造函数
	void modify();																											//修改数据成员的值
	friend istream & operator >>(istream &input, CardContact &obj);															//重载>>运算符
	friend ostream & operator <<(ostream &output, CardContact &obj);														//重载<<运算符
	string get_homeland();																								    //获取籍贯
	string get_QQ();																									    //获取QQ
	void set(string rname, string rtel_num,string rhomeland,string rQQ);													//为数据成员赋值
};

#endif