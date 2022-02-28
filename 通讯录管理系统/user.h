#ifndef USER_H
#define	USER_H

#include"cardmaillist.h"
#include"phonemaillist.h"
#include"uimenu.h"
class User {
	PhoneMaillist phonemaillist;
	CardMaillist cardmaillist;
	Uimenu uimenu;
public:
	User();								//���캯��
	~User();							//��������
	void add();							//�½���ϵ��
	void Delete();						//ɾ����ϵ��
	void change();						//�޸���ϵ����Ϣ  
	void inquiry();						//��ѯ��ϵ����Ϣ  
	void display();						//��ʾ������ϵ����Ϣ
	void move_card_to_phone();			//�ƶ��ֻ���ͨѶ¼���ֻ�ͨѶ¼
	void move_phone_to_card();			//�ƶ��ֻ�ͨѶ¼���ֻ���ͨѶ¼
	void copy_card_to_phone();			//�����ֻ���ͨѶ¼���ֻ�ͨѶ¼
	void copy_phone_to_card();			//�����ֻ�ͨѶ¼���ֻ���ͨѶ¼
};

#endif 