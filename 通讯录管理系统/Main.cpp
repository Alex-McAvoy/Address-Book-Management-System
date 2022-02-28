/*主函数*/

#include"uimenu.h"
#include"phonecontact.h"
#include"cardcontact.h"
#include"maillist.h"
#include"phonemaillist.h"
#include"cardmaillist.h"
#include"user.h"
int main()
{
	User user;		//创建用户对象
	Uimenu uimenu;	//创建菜单对象

	int m=1;
	while (m != 0) {
		change_begin: {
			
			/*显示控制，使界面更友好*/
			system("pause");
			system("cls");

			uimenu.MainUimenu();	//显示主菜单
			cin >> m;
			switch (m) {	//对主菜单操作选择
				case 1: {	//新建联系人
					user.add();
					goto change_begin;
				}
				case 2: {	//删除联系人
					user.Delete();
					goto change_begin;
				}
				case 3: {	//查询联系人
					user.inquiry();
					goto change_begin;
				}
				case 4: {	//修改联系人信息
					user.change();
					goto change_begin;
				}
				case 5: {	//浏览所有联系人信息
					user.display();
					goto change_begin;
				}
				case 6: {	//将联系人的信息从手机转存到手机卡上
					Transferred1: {
						uimenu.TransferredMethod();
						int n;
						cin >> n;
						switch (n)	{
							case 1: {
								user.copy_phone_to_card();
								goto change_begin;
							}
							case 2: {
								user.move_phone_to_card();
								goto change_begin;
							}
							case 0: {
								goto change_begin;
							}
							default: {
								cout << "选择错误，请重新选择！" << endl;
								goto Transferred1;
							}
						}
					}

				}
				case 7: {	//将联系人的信息从手机卡转存到手机上 
					Transferred2: {
						uimenu.TransferredMethod();
						int n;
						cin >> n;
						switch (n)	{
							case 1: {
								user.copy_card_to_phone();
								goto change_begin;
							}
							case 2: {
								user.move_card_to_phone();
								goto change_begin;
							}
							case 0: {
								goto change_begin;
							}
							default: {
								cout << "选择错误，请重新选择！" << endl;
								goto Transferred2;
							}
						}
					}
				}
				case 0: {	//退出
					/*显示控制，使界面更友好*/
					system("pause");
					system("cls");
					break;
				}
				default: {
					cout << "选择错误，请重新选择！" << endl;
					goto change_begin;
				}
			}
		}
	}
	getchar();
	return 0;
}