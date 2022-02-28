/*手机卡联系人类的实现*/

#include"cardcontact.h"  
#include"Uimenu.h"
CardContact::CardContact(string rname, string rtel_num, string rhomeland, string rQQ) :PhoneContact(rname, rtel_num){//有参构造函数
	homeland = rhomeland; 
	QQ = rQQ;
}
void CardContact::modify() {//修改数据成员的值
	int n;
	Uimenu obj;
	change2: {
		obj.ChangeCardUimenu();
		cin >> n;
		switch (n)
		{
			case 1: {
				cout << "请重新输入联系人姓名：";
				cin >> name;
				cout << "请重新输入联系人号码：";
				cin >> tel_num;
				cout << "请重新输入联系人籍贯：";
				cin >> homeland;
				cout << "请重新输入联系人QQ：";
				cin >> QQ;
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
			case 4: {
				cout << "请重新输入联系人籍贯：";
				cin >> homeland;
				break;
			}
			case 5: {
				cout << "请重新输入联系人QQ：";
				cin >> QQ;
				break;
			}
			case 0: {
				return;
			}
			default: {
				cout << "选择错误，请重新选择！" << endl;
				goto change2;
			}
		}
	}
}
istream & operator >> (istream & input, CardContact & obj){//重载>>运算符
	cout << "请输入联系人姓名：";
	input >> obj.name;
	cout << "请输入联系人号码：";
	input >> obj.tel_num;
	cout << "请输入籍贯：";
	input >> obj.homeland;
	cout << "请输入QQ：";
	input >> obj.QQ;
	return input;
}
ostream & operator << (ostream &output, CardContact &obj){//重载<<运算符
	output << "联系人姓名：" << obj.name << "\t";
	output << "联系人号码：" << obj.tel_num << "\t";
	output << "联系人籍贯：" << obj.homeland << "\t";
	output << "联系人QQ：" << obj.QQ << endl;
	return output;
}
string CardContact::get_homeland() {		//获取籍贯
	return homeland;
}
string CardContact::get_QQ() {	//获取QQ
	return QQ;
}
void CardContact::set(string rname, string rtel_num, string rhomeland, string rQQ) {		//为数据成员赋值
	PhoneContact::set(rname,rtel_num);//调用基类set函数
	homeland = rhomeland;
	QQ = rQQ;
}