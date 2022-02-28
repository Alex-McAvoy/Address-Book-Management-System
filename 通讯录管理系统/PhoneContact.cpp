/*手机联系人类的实现*/

#include"PhoneContact.h"
#include"Uimenu.h"
PhoneContact::PhoneContact(string rname , string rtel_num ) {//有参构造函数
	name = rname;
	tel_num = rtel_num;
}
void PhoneContact::modify() {//修改数据成员的值
	int n;
	Uimenu obj;
	obj.ChangePhoneUimenu();
	change1:{
		cin >> n;
		switch (n)
		{
			case 1: {
				cout << "请重新输入联系人姓名：";
				cin >> name;
				cout << "请重新输入联系人号码：";
				cin >> tel_num;
				break;
			}
			case 2: {
				cout << "请重新输入联系人姓名：";
				cin >> name;
				break;
			}
			case 3: {
				cout << "请重新输入联系人号码：";
				cin >> tel_num;
				break;
			}
			case 0: {
				return;
			}
			default:{
				cout << "选择错误，请重新选择！" << endl;
				goto change1;
			}
		}
	}
}
istream &operator >>(istream &input, PhoneContact &obj) {//重载>>运算符
	cout << "请输入联系人姓名：";
	input >> obj.name;
	cout << "请输入联系人号码：";
	input >> obj.tel_num;
	return input;
}
ostream &operator <<(ostream &output, PhoneContact &obj) {//重载<<运算符
	output << "联系人姓名：" << obj.name<<"\t";
	output << "联系人号码：" << obj.tel_num<<endl;
	return output;
}
string PhoneContact::get_name() {	//获取姓名
	return name;
}
string PhoneContact::get_tel_num() {	//获取号码
	return tel_num;
}
void PhoneContact::set(string rname, string rtel_num) {//为数据成员赋值
	name = rname;
	tel_num = rtel_num;
}

