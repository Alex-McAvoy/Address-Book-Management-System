/*用户类的实现*/

#include"user.h"
#include<iostream>
using namespace std;
User::User() {	//构造函数
	cout << "****************************************" << endl;
	cout << "*        欢迎使用通讯录管理系统        *" << endl;
	cout << "*       手机通讯录目前有" << phonemaillist.get_phone_contact_num() + 1 << "个联系人      *" << endl;
	cout << "*      手机卡通讯录目前有" << cardmaillist.get_card_contact_num() + 1 << "个联系人     *" << endl;
	cout << "****************************************" << endl;
}
User::~User() {	//析构函数
	cout << "****************************************" << endl;
	cout << "*      感谢您使用本通讯录管理系统      *" << endl;
	cout << "*       手机通讯录目前有" << phonemaillist.get_phone_contact_num() + 1 << "个联系人      *" << endl;
	cout << "*      手机卡通讯录目前有" << cardmaillist.get_card_contact_num() + 1 << "个联系人     *" << endl;
	cout << "****************************************" << endl;

	/*显示控制，使界面更友好*/
	system("pause");
	system("cls");
}
void User::add() {	//新建联系人
	change3: {
		uimenu.AddUimenu();		//新建菜单
		Maillist *temp;			//通讯簿基类指针
		int t;
		cin >> t;
		switch (t)	{
			case 1: {	//新建联系人到手机
				temp = &phonemaillist;		//指针指向手机通讯簿对象  
				temp -> add();				//调用手机通讯簿对象函数  
				break;
			}
			case 2: {	//新建联系人到手机卡
				temp = &cardmaillist;		//指针指向手机卡通讯簿对象  
				temp -> add();				//调用手机卡通讯簿对象函数   
				break;
			}
			case 0: {	//返回上一级
				return;
			}
			default: {	//选择错误
				cout << "选择错误，请重新选择！" << endl;
				goto change3;
			}
		}
	}
}
void User::Delete() {	//删除联系人
	change4: {
		uimenu.DeleteUimenu();		//删除菜单
		Maillist *temp;				//通讯簿基类指针
		string rtel_num;
		int t;
		cin >> t;
		switch (t)
		{
			case 1: {	//在手机通讯录删除联系人
				cout << "请输入要删除的联系人的号码：";
				cin >> rtel_num;
				temp = &phonemaillist;		//指针指向手机通讯簿对象  
				temp -> Delete(rtel_num);   //调用手机通讯簿对象函数  
				break;
			}
			case 2: {	//在手机卡通讯录删除联系人
				cout << "请输入要删除的联系人的号码：";
				cin >> rtel_num;
				temp = &cardmaillist;		//指针指向手机通讯簿对象  
				temp -> Delete(rtel_num);   //调用手机卡通讯簿对象函数  
				break;
			}
			case 3: {	//在两个通讯录都进行删除
				cout << "请输入要删除的联系人的号码：";
				cin >> rtel_num;
				cout << "--------------手机通讯录----------------" << endl;
				temp = &phonemaillist;		//指针指向手机通讯簿对象  
				temp -> Delete(rtel_num);   //调用手机通讯簿对象函数  
				cout << "--------------手机卡通讯录----------------" << endl;
				temp = &cardmaillist;		//指针指向手机通讯簿对象  
				temp -> Delete(rtel_num);   //调用手机卡通讯簿对象函数    
				break;
			}
			case 0: {	//返回上一级
				return;
			}
			default: {	//选择错误
				cout << "选择错误，请重新选择！" << endl;
				goto change4;
			}
		}
	}

}
void User::change() {	//修改联系人信息  
	change5: {
		uimenu.ChangeUimenu();		//修改菜单
		Maillist *temp;				//通讯簿基类指针
		string rtel_num;
		int t;
		cin >> t;
		switch (t)
		{
			case 1: {	//在手机通讯录修改联系人
				cout << "请输入要修改的联系人的号码：";
				cin >> rtel_num;
				temp = &phonemaillist;		//指针指向手机通讯簿对象  
				temp -> change(rtel_num);   //调用手机通讯簿对象函数  
				break;
			}
			case 2: {	//在手机卡通讯录修改联系人
				cout << "请输入要修改的联系人的号码：";
				cin >> rtel_num;
				temp = &cardmaillist;		//指针指向手机通讯簿对象  
				temp -> change(rtel_num);   //调用手机卡通讯簿对象函数  
				break;
			}
			case 3: {	//在两个通讯录都进行修改
				cout << "请输入要修改的联系人的号码：";
				cin >> rtel_num;
				cout << "--------------手机通讯录----------------" << endl;
				temp = &phonemaillist;		//指针指向手机通讯簿对象  
				temp -> change(rtel_num);   //调用手机通讯簿对象函数  
				cout << "--------------手机卡通讯录----------------" << endl;
				temp = &cardmaillist;		//指针指向手机通讯簿对象  
				temp -> change(rtel_num);   //调用手机卡通讯簿对象函数    
				break;
			}
			case 0: {	//返回上一级
				return;
			}
			default: {	//选择错误
				cout << "选择错误，请重新选择！" << endl;
				goto change5;
			}
		}
	}
}
void User::inquiry() {	//查询联系人信息  
	change6: {
		uimenu.InquiryUimenu();		//查询菜单
		Maillist *temp;				//通讯簿基类指针
		string rname;
		int t;
		cin >> t;
		switch (t)
		{
			case 1: {	//在手机通讯录查询联系人
				cout << "请输入要查询的联系人的姓名：";
				cin >> rname;
				temp = &phonemaillist;		//指针指向手机通讯簿对象  
				temp -> inquiry(rname);		//调用手机通讯簿对象函数  
				break;
			}
			case 2: {	//在手机卡通讯录查询联系人
				cout << "请输入要查询的联系人的姓名：";
				cin >> rname;
				temp = &cardmaillist;		//指针指向手机通讯簿对象  
				temp ->inquiry(rname);		//调用手机卡通讯簿对象函数  
				break;
			}
			case 3: {	//在两个通讯录都进行修改
				cout << "请输入要查询的联系人的姓名：";
				cin >> rname;
				cout << "--------------手机通讯录----------------" << endl;
				temp = &phonemaillist;		//指针指向手机通讯簿对象  
				temp ->inquiry(rname);		//调用手机通讯簿对象函数  
				cout << "--------------手机卡通讯录----------------" << endl;
				temp = &cardmaillist;		//指针指向手机通讯簿对象  
				temp ->inquiry(rname);		//调用手机卡通讯簿对象函数    
				break;
			}
			case 0: {	//返回上一级
				return;
			}
			default: {	//选择错误
				cout << "选择错误，请重新选择！" << endl;
				goto change6;
			}
		}
	}
}
void User::display() {	//显示所有联系人信息
	change6: {
		uimenu.DisplayUimenu();		//显示菜单
		Maillist *temp;				//通讯簿基类指针
		int t;
		cin >> t;
		switch (t)
		{
			case 1: {	//显示手机通讯录所有联系人
				cout << "--------------手机通讯录----------------" << endl;
				temp = &phonemaillist;		//指针指向手机通讯簿对象  
				temp -> display();			//调用手机通讯簿对象函数  
				break;
			}
			case 2: {	//显示手机卡通讯录所有联系人
				cout << "--------------手机卡通讯录----------------" << endl;
				temp = &cardmaillist;		//指针指向手机通讯簿对象  
				temp -> display();			//调用手机卡通讯簿对象函数  
				break;
			}
			case 3: {	//显示两个通讯录的所有联系人
				cout << "--------------手机通讯录----------------" << endl;
				temp = &phonemaillist;		//指针指向手机通讯簿对象  
				temp -> display();			//调用手机通讯簿对象函数  
				cout << "--------------手机卡通讯录----------------" << endl;
				temp = &cardmaillist;		//指针指向手机通讯簿对象  
				temp -> display();			//调用手机卡通讯簿对象函数    
				break;
			}
			case 0: {	//返回上一级
				return;
			}
			default: {	//选择错误
				cout << "选择错误，请重新选择！" << endl;
				goto change6;
			}
		}
	}
}
void User::move_card_to_phone() {	//移动手机卡通讯录到手机通讯录
	if (cardmaillist.get_card_contact_num()<0) {	//手机卡通讯录无联系人时
		cout << "手机卡通讯录无联系人！" << endl;
		return;
	}
	for (int i = 0; i <= cardmaillist.get_card_contact_num(); i++) {	//枚举手机卡通讯录所有联系人
		if (phonemaillist.get_phone_contact_num() >= 1000) {	//当手机通讯录容量满时
			cout << "手机通讯录已满！无法增加新联系人！" << endl;
			return;
		}
		phonemaillist.copy(cardmaillist.get_name(i), cardmaillist.get_tel_num(i));	//将手机卡通讯录的第i个用户存入手机通讯录
	}
	cardmaillist.clear();	//清空手机卡通讯录
	cout << "移动成功！" << endl;
}
void User::move_phone_to_card() {	//移动手机通讯录到手机卡通讯录
	if (phonemaillist.get_phone_contact_num()<0) {	//手机通讯录无联系人时
		cout << "手机通讯录无联系人！" << endl;
		return;
	}
	for (int i = 0; i <= phonemaillist.get_phone_contact_num(); i++) {	//枚举手机通讯录所有联系人
		if (cardmaillist.get_card_contact_num() >= 1000) {	//当手机卡通讯录容量满时
			cout << "手机卡通讯录已满！无法增加新联系人！" << endl;
			return;
		}
		cardmaillist.copy(phonemaillist.get_name(i), phonemaillist.get_tel_num(i));	//将手机通讯录的第i个用户存入手机卡通讯录
	}
	phonemaillist.clear();	//清空手机通讯录
	cout << "移动成功！" << endl;
}
void User::copy_card_to_phone() {	//复制手机卡通讯录到手机通讯录
	if (cardmaillist.get_card_contact_num()<0) {	//手机卡通讯录无联系人时
		cout << "手机卡通讯录无联系人！" << endl;
		return;
	}
	for (int i = 0; i <= cardmaillist.get_card_contact_num(); i++) {	//枚举手机卡通讯录所有联系人
		if (phonemaillist.get_phone_contact_num() >= 1000) {	//当手机通讯录容量满时
			cout << "手机通讯录已满！无法增加新联系人！" << endl;
			return;
		}
		phonemaillist.copy(cardmaillist.get_name(i), cardmaillist.get_tel_num(i));	//将手机卡通讯录的第i个用户存入手机通讯录
	}
	cout << "复制成功！" << endl;
}
void User::copy_phone_to_card() {	//复制手机通讯录到手机卡通讯录
	if (phonemaillist.get_phone_contact_num()<0) {	//手机通讯录无联系人时
		cout << "手机通讯录无联系人！" << endl;
		return;
	}
	for (int i = 0; i <= phonemaillist.get_phone_contact_num(); i++) {	//枚举手机通讯录所有联系人
		if (cardmaillist.get_card_contact_num() >= 1000) {	//当手机卡通讯录容量满时
			cout << "手机卡通讯录已满！无法增加新联系人！" << endl;
			return;
		}
		cardmaillist.copy(phonemaillist.get_name(i), phonemaillist.get_tel_num(i));	//将手机通讯录的第i个用户存入手机卡通讯录
	}
	cout << "复制成功！" << endl;
}	