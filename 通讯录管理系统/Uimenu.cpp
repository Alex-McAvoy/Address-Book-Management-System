/*菜单类的实现*/

#include"uimenu.h"
void Uimenu::MainUimenu() {        //主菜单
	cout << "***********************************************" << endl;
	cout << "*                1.新建联系人                 *" << endl;
	cout << "*                2.删除联系人                 *" << endl;
	cout << "*                3.查询联系人                 *" << endl;
	cout << "*               4.修改联系人信息              *" << endl;
	cout << "*            5.浏览所有联系人信息             *" << endl;
	cout << "*     6.将联系人的信息从手机转存到手机卡上    *" << endl;
	cout << "*     7.将联系人的信息从手机卡转存到手机上    *" << endl;
	cout << "*                   0.退出                    *" << endl;
	cout << "***********************************************" << endl;
	cout << "请选择要进行的操作：";
}
void Uimenu::AddUimenu() {         //添加联系人菜单
	cout << "***********************************" << endl;
	cout << "*        1.新建联系人到手机       *" << endl;
	cout << "*       2.新建联系人到手机卡      *" << endl;
	cout << "*           0.返回上一级          *" << endl;
	cout << "***********************************" << endl;
	cout << "请选择要进行的操作：";
}
void Uimenu::DeleteUimenu() {	//删除菜单
	cout << "************************************" << endl;
	cout << "*     1.在手机通讯录删除联系人     *" << endl;
	cout << "*    2.在手机卡通讯录删除联系人    *" << endl;
	cout << "*     3.在两个通讯录都进行删除     *" << endl;
	cout << "*           0.返回上一级           *" << endl;
	cout << "************************************" << endl;
	cout << "请选择要进行的操作：";
}
void Uimenu::ChangeUimenu() {	//修改菜单
	cout << "************************************" << endl;
	cout << "*     1.在手机通讯录修改联系人     *" << endl;
	cout << "*    2.在手机卡通讯录修改联系人    *" << endl;
	cout << "*     3.在两个通讯录都进行修改     *" << endl;
	cout << "*           0.返回上一级           *" << endl;
	cout << "************************************" << endl;
	cout << "请选择要进行的操作：";
}
void Uimenu::ChangePhoneUimenu() {      //修改手机联系人菜单
	cout << "**********************************" << endl;
	cout << "*     1.修改联系人姓名和号码     *" << endl;
	cout << "*        2.修改联系人姓名        *" << endl;
	cout << "*        3.修改联系人号码        *" << endl;
	cout << "*          0.返回上一级          *" << endl;
	cout << "**********************************" << endl;
	cout << "请选择要进行的操作：";
}
void Uimenu::ChangeCardUimenu() {      //修改手机卡联系人菜单
	cout << "**********************************" << endl;
	cout << "*      1.修改联系人全部信息      *" << endl;
	cout << "*        2.修改联系人姓名        *" << endl;
	cout << "*        3.修改联系人号码        *" << endl;
	cout << "*        4.修改联系人籍贯        *" << endl;
	cout << "*         5.修改联系人QQ         *" << endl;
	cout << "*          0.返回上一级          *" << endl;
	cout << "**********************************" << endl;
	cout << "请选择要进行的操作：";
}
void Uimenu::InquiryUimenu() {	//查询菜单
	cout << "************************************" << endl;
	cout << "*     1.在手机通讯录查询联系人     *" << endl;
	cout << "*    2.在手机卡通讯录查询联系人    *" << endl;
	cout << "*     3.在两个通讯录都进行查询     *" << endl;
	cout << "*           0.返回上一级           *" << endl;
	cout << "************************************" << endl;
	cout << "请选择要进行的操作：";
}
void Uimenu::DisplayUimenu() {	//显示菜单
	cout << "************************************" << endl;
	cout << "*    1.显示手机通讯录所有联系人    *" << endl;
	cout << "*   2.显示手机卡通讯录所有联系人   *" << endl;
	cout << "*   3.显示两个通讯录的所有联系人   *" << endl;
	cout << "*           0.返回上一级           *" << endl;
	cout << "************************************" << endl;
	cout << "请选择要进行的操作：";
}
void Uimenu::TransferredMethod() {	//转存菜单
	cout << "************************************" << endl;
	cout << "*              1.复制              *" << endl;
	cout << "*              2.移动              *" << endl;
	cout << "*           0.返回上一级           *" << endl;
	cout << "************************************" << endl;
	cout << "请选择要进行的操作：";
}
