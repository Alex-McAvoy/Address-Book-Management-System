/*������*/

#include"uimenu.h"
#include"phonecontact.h"
#include"cardcontact.h"
#include"maillist.h"
#include"phonemaillist.h"
#include"cardmaillist.h"
#include"user.h"
int main()
{
	User user;		//�����û�����
	Uimenu uimenu;	//�����˵�����

	int m=1;
	while (m != 0) {
		change_begin: {
			
			/*��ʾ���ƣ�ʹ������Ѻ�*/
			system("pause");
			system("cls");

			uimenu.MainUimenu();	//��ʾ���˵�
			cin >> m;
			switch (m) {	//�����˵�����ѡ��
				case 1: {	//�½���ϵ��
					user.add();
					goto change_begin;
				}
				case 2: {	//ɾ����ϵ��
					user.Delete();
					goto change_begin;
				}
				case 3: {	//��ѯ��ϵ��
					user.inquiry();
					goto change_begin;
				}
				case 4: {	//�޸���ϵ����Ϣ
					user.change();
					goto change_begin;
				}
				case 5: {	//���������ϵ����Ϣ
					user.display();
					goto change_begin;
				}
				case 6: {	//����ϵ�˵���Ϣ���ֻ�ת�浽�ֻ�����
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
								cout << "ѡ�����������ѡ��" << endl;
								goto Transferred1;
							}
						}
					}

				}
				case 7: {	//����ϵ�˵���Ϣ���ֻ���ת�浽�ֻ��� 
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
								cout << "ѡ�����������ѡ��" << endl;
								goto Transferred2;
							}
						}
					}
				}
				case 0: {	//�˳�
					/*��ʾ���ƣ�ʹ������Ѻ�*/
					system("pause");
					system("cls");
					break;
				}
				default: {
					cout << "ѡ�����������ѡ��" << endl;
					goto change_begin;
				}
			}
		}
	}
	getchar();
	return 0;
}