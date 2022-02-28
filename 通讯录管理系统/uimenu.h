/*菜单类*/

#ifndef UIMENU_H
#define UIMENU_H

#include<iostream>
using namespace std;
class Uimenu {
public:
	void MainUimenu();			//主菜单
	void AddUimenu();			//添加菜单
	void DeleteUimenu();		//删除菜单
	void ChangeUimenu();		//修改菜单
	void ChangePhoneUimenu();	//修改手机联系人菜单
	void ChangeCardUimenu();    //修改手机卡联系人菜单
	void InquiryUimenu();		//查询菜单
	void DisplayUimenu();		//显示菜单
	void TransferredMethod();	//转存菜单
}; 

#endif