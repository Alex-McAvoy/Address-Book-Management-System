/*�û����ʵ��*/

#include"user.h"
#include<iostream>
using namespace std;
User::User() {	//���캯��
	cout << "****************************************" << endl;
	cout << "*        ��ӭʹ��ͨѶ¼����ϵͳ        *" << endl;
	cout << "*       �ֻ�ͨѶ¼Ŀǰ��" << phonemaillist.get_phone_contact_num() + 1 << "����ϵ��      *" << endl;
	cout << "*      �ֻ���ͨѶ¼Ŀǰ��" << cardmaillist.get_card_contact_num() + 1 << "����ϵ��     *" << endl;
	cout << "****************************************" << endl;
}
User::~User() {	//��������
	cout << "****************************************" << endl;
	cout << "*      ��л��ʹ�ñ�ͨѶ¼����ϵͳ      *" << endl;
	cout << "*       �ֻ�ͨѶ¼Ŀǰ��" << phonemaillist.get_phone_contact_num() + 1 << "����ϵ��      *" << endl;
	cout << "*      �ֻ���ͨѶ¼Ŀǰ��" << cardmaillist.get_card_contact_num() + 1 << "����ϵ��     *" << endl;
	cout << "****************************************" << endl;

	/*��ʾ���ƣ�ʹ������Ѻ�*/
	system("pause");
	system("cls");
}
void User::add() {	//�½���ϵ��
	change3: {
		uimenu.AddUimenu();		//�½��˵�
		Maillist *temp;			//ͨѶ������ָ��
		int t;
		cin >> t;
		switch (t)	{
			case 1: {	//�½���ϵ�˵��ֻ�
				temp = &phonemaillist;		//ָ��ָ���ֻ�ͨѶ������  
				temp -> add();				//�����ֻ�ͨѶ��������  
				break;
			}
			case 2: {	//�½���ϵ�˵��ֻ���
				temp = &cardmaillist;		//ָ��ָ���ֻ���ͨѶ������  
				temp -> add();				//�����ֻ���ͨѶ��������   
				break;
			}
			case 0: {	//������һ��
				return;
			}
			default: {	//ѡ�����
				cout << "ѡ�����������ѡ��" << endl;
				goto change3;
			}
		}
	}
}
void User::Delete() {	//ɾ����ϵ��
	change4: {
		uimenu.DeleteUimenu();		//ɾ���˵�
		Maillist *temp;				//ͨѶ������ָ��
		string rtel_num;
		int t;
		cin >> t;
		switch (t)
		{
			case 1: {	//���ֻ�ͨѶ¼ɾ����ϵ��
				cout << "������Ҫɾ������ϵ�˵ĺ��룺";
				cin >> rtel_num;
				temp = &phonemaillist;		//ָ��ָ���ֻ�ͨѶ������  
				temp -> Delete(rtel_num);   //�����ֻ�ͨѶ��������  
				break;
			}
			case 2: {	//���ֻ���ͨѶ¼ɾ����ϵ��
				cout << "������Ҫɾ������ϵ�˵ĺ��룺";
				cin >> rtel_num;
				temp = &cardmaillist;		//ָ��ָ���ֻ�ͨѶ������  
				temp -> Delete(rtel_num);   //�����ֻ���ͨѶ��������  
				break;
			}
			case 3: {	//������ͨѶ¼������ɾ��
				cout << "������Ҫɾ������ϵ�˵ĺ��룺";
				cin >> rtel_num;
				cout << "--------------�ֻ�ͨѶ¼----------------" << endl;
				temp = &phonemaillist;		//ָ��ָ���ֻ�ͨѶ������  
				temp -> Delete(rtel_num);   //�����ֻ�ͨѶ��������  
				cout << "--------------�ֻ���ͨѶ¼----------------" << endl;
				temp = &cardmaillist;		//ָ��ָ���ֻ�ͨѶ������  
				temp -> Delete(rtel_num);   //�����ֻ���ͨѶ��������    
				break;
			}
			case 0: {	//������һ��
				return;
			}
			default: {	//ѡ�����
				cout << "ѡ�����������ѡ��" << endl;
				goto change4;
			}
		}
	}

}
void User::change() {	//�޸���ϵ����Ϣ  
	change5: {
		uimenu.ChangeUimenu();		//�޸Ĳ˵�
		Maillist *temp;				//ͨѶ������ָ��
		string rtel_num;
		int t;
		cin >> t;
		switch (t)
		{
			case 1: {	//���ֻ�ͨѶ¼�޸���ϵ��
				cout << "������Ҫ�޸ĵ���ϵ�˵ĺ��룺";
				cin >> rtel_num;
				temp = &phonemaillist;		//ָ��ָ���ֻ�ͨѶ������  
				temp -> change(rtel_num);   //�����ֻ�ͨѶ��������  
				break;
			}
			case 2: {	//���ֻ���ͨѶ¼�޸���ϵ��
				cout << "������Ҫ�޸ĵ���ϵ�˵ĺ��룺";
				cin >> rtel_num;
				temp = &cardmaillist;		//ָ��ָ���ֻ�ͨѶ������  
				temp -> change(rtel_num);   //�����ֻ���ͨѶ��������  
				break;
			}
			case 3: {	//������ͨѶ¼�������޸�
				cout << "������Ҫ�޸ĵ���ϵ�˵ĺ��룺";
				cin >> rtel_num;
				cout << "--------------�ֻ�ͨѶ¼----------------" << endl;
				temp = &phonemaillist;		//ָ��ָ���ֻ�ͨѶ������  
				temp -> change(rtel_num);   //�����ֻ�ͨѶ��������  
				cout << "--------------�ֻ���ͨѶ¼----------------" << endl;
				temp = &cardmaillist;		//ָ��ָ���ֻ�ͨѶ������  
				temp -> change(rtel_num);   //�����ֻ���ͨѶ��������    
				break;
			}
			case 0: {	//������һ��
				return;
			}
			default: {	//ѡ�����
				cout << "ѡ�����������ѡ��" << endl;
				goto change5;
			}
		}
	}
}
void User::inquiry() {	//��ѯ��ϵ����Ϣ  
	change6: {
		uimenu.InquiryUimenu();		//��ѯ�˵�
		Maillist *temp;				//ͨѶ������ָ��
		string rname;
		int t;
		cin >> t;
		switch (t)
		{
			case 1: {	//���ֻ�ͨѶ¼��ѯ��ϵ��
				cout << "������Ҫ��ѯ����ϵ�˵�������";
				cin >> rname;
				temp = &phonemaillist;		//ָ��ָ���ֻ�ͨѶ������  
				temp -> inquiry(rname);		//�����ֻ�ͨѶ��������  
				break;
			}
			case 2: {	//���ֻ���ͨѶ¼��ѯ��ϵ��
				cout << "������Ҫ��ѯ����ϵ�˵�������";
				cin >> rname;
				temp = &cardmaillist;		//ָ��ָ���ֻ�ͨѶ������  
				temp ->inquiry(rname);		//�����ֻ���ͨѶ��������  
				break;
			}
			case 3: {	//������ͨѶ¼�������޸�
				cout << "������Ҫ��ѯ����ϵ�˵�������";
				cin >> rname;
				cout << "--------------�ֻ�ͨѶ¼----------------" << endl;
				temp = &phonemaillist;		//ָ��ָ���ֻ�ͨѶ������  
				temp ->inquiry(rname);		//�����ֻ�ͨѶ��������  
				cout << "--------------�ֻ���ͨѶ¼----------------" << endl;
				temp = &cardmaillist;		//ָ��ָ���ֻ�ͨѶ������  
				temp ->inquiry(rname);		//�����ֻ���ͨѶ��������    
				break;
			}
			case 0: {	//������һ��
				return;
			}
			default: {	//ѡ�����
				cout << "ѡ�����������ѡ��" << endl;
				goto change6;
			}
		}
	}
}
void User::display() {	//��ʾ������ϵ����Ϣ
	change6: {
		uimenu.DisplayUimenu();		//��ʾ�˵�
		Maillist *temp;				//ͨѶ������ָ��
		int t;
		cin >> t;
		switch (t)
		{
			case 1: {	//��ʾ�ֻ�ͨѶ¼������ϵ��
				cout << "--------------�ֻ�ͨѶ¼----------------" << endl;
				temp = &phonemaillist;		//ָ��ָ���ֻ�ͨѶ������  
				temp -> display();			//�����ֻ�ͨѶ��������  
				break;
			}
			case 2: {	//��ʾ�ֻ���ͨѶ¼������ϵ��
				cout << "--------------�ֻ���ͨѶ¼----------------" << endl;
				temp = &cardmaillist;		//ָ��ָ���ֻ�ͨѶ������  
				temp -> display();			//�����ֻ���ͨѶ��������  
				break;
			}
			case 3: {	//��ʾ����ͨѶ¼��������ϵ��
				cout << "--------------�ֻ�ͨѶ¼----------------" << endl;
				temp = &phonemaillist;		//ָ��ָ���ֻ�ͨѶ������  
				temp -> display();			//�����ֻ�ͨѶ��������  
				cout << "--------------�ֻ���ͨѶ¼----------------" << endl;
				temp = &cardmaillist;		//ָ��ָ���ֻ�ͨѶ������  
				temp -> display();			//�����ֻ���ͨѶ��������    
				break;
			}
			case 0: {	//������һ��
				return;
			}
			default: {	//ѡ�����
				cout << "ѡ�����������ѡ��" << endl;
				goto change6;
			}
		}
	}
}
void User::move_card_to_phone() {	//�ƶ��ֻ���ͨѶ¼���ֻ�ͨѶ¼
	if (cardmaillist.get_card_contact_num()<0) {	//�ֻ���ͨѶ¼����ϵ��ʱ
		cout << "�ֻ���ͨѶ¼����ϵ�ˣ�" << endl;
		return;
	}
	for (int i = 0; i <= cardmaillist.get_card_contact_num(); i++) {	//ö���ֻ���ͨѶ¼������ϵ��
		if (phonemaillist.get_phone_contact_num() >= 1000) {	//���ֻ�ͨѶ¼������ʱ
			cout << "�ֻ�ͨѶ¼�������޷���������ϵ�ˣ�" << endl;
			return;
		}
		phonemaillist.copy(cardmaillist.get_name(i), cardmaillist.get_tel_num(i));	//���ֻ���ͨѶ¼�ĵ�i���û������ֻ�ͨѶ¼
	}
	cardmaillist.clear();	//����ֻ���ͨѶ¼
	cout << "�ƶ��ɹ���" << endl;
}
void User::move_phone_to_card() {	//�ƶ��ֻ�ͨѶ¼���ֻ���ͨѶ¼
	if (phonemaillist.get_phone_contact_num()<0) {	//�ֻ�ͨѶ¼����ϵ��ʱ
		cout << "�ֻ�ͨѶ¼����ϵ�ˣ�" << endl;
		return;
	}
	for (int i = 0; i <= phonemaillist.get_phone_contact_num(); i++) {	//ö���ֻ�ͨѶ¼������ϵ��
		if (cardmaillist.get_card_contact_num() >= 1000) {	//���ֻ���ͨѶ¼������ʱ
			cout << "�ֻ���ͨѶ¼�������޷���������ϵ�ˣ�" << endl;
			return;
		}
		cardmaillist.copy(phonemaillist.get_name(i), phonemaillist.get_tel_num(i));	//���ֻ�ͨѶ¼�ĵ�i���û������ֻ���ͨѶ¼
	}
	phonemaillist.clear();	//����ֻ�ͨѶ¼
	cout << "�ƶ��ɹ���" << endl;
}
void User::copy_card_to_phone() {	//�����ֻ���ͨѶ¼���ֻ�ͨѶ¼
	if (cardmaillist.get_card_contact_num()<0) {	//�ֻ���ͨѶ¼����ϵ��ʱ
		cout << "�ֻ���ͨѶ¼����ϵ�ˣ�" << endl;
		return;
	}
	for (int i = 0; i <= cardmaillist.get_card_contact_num(); i++) {	//ö���ֻ���ͨѶ¼������ϵ��
		if (phonemaillist.get_phone_contact_num() >= 1000) {	//���ֻ�ͨѶ¼������ʱ
			cout << "�ֻ�ͨѶ¼�������޷���������ϵ�ˣ�" << endl;
			return;
		}
		phonemaillist.copy(cardmaillist.get_name(i), cardmaillist.get_tel_num(i));	//���ֻ���ͨѶ¼�ĵ�i���û������ֻ�ͨѶ¼
	}
	cout << "���Ƴɹ���" << endl;
}
void User::copy_phone_to_card() {	//�����ֻ�ͨѶ¼���ֻ���ͨѶ¼
	if (phonemaillist.get_phone_contact_num()<0) {	//�ֻ�ͨѶ¼����ϵ��ʱ
		cout << "�ֻ�ͨѶ¼����ϵ�ˣ�" << endl;
		return;
	}
	for (int i = 0; i <= phonemaillist.get_phone_contact_num(); i++) {	//ö���ֻ�ͨѶ¼������ϵ��
		if (cardmaillist.get_card_contact_num() >= 1000) {	//���ֻ���ͨѶ¼������ʱ
			cout << "�ֻ���ͨѶ¼�������޷���������ϵ�ˣ�" << endl;
			return;
		}
		cardmaillist.copy(phonemaillist.get_name(i), phonemaillist.get_tel_num(i));	//���ֻ�ͨѶ¼�ĵ�i���û������ֻ���ͨѶ¼
	}
	cout << "���Ƴɹ���" << endl;
}	