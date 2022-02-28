#ifndef CARDMAILLIST_H
#define CARDMAILLIST_H

#include"cardcontact.h"
#include"maillist.h"
#include<vector>
class CardMaillist :public Maillist {
protected:
	int card_contact_num;						//�ֻ�����ϵ������
	vector <CardContact> card_contact;			//�ֻ�����ϵ�˶���̬����
public:
	CardMaillist();								//���캯������ȡ�ı��ļ��е�����,�������ļ����ݴ�����ϵ�˶�������
	~CardMaillist();							//���������������������е�����д�뵽�ı��ļ���
	void add() ;								//�½���ϵ��
	void Delete(string rtel_num) ;				//ɾ����ϵ��
	void change(string rtel_num) ;				//�޸���ϵ����Ϣ  
	void inquiry(string rname) ;				//��ѯ��ϵ����Ϣ  
	void display() ;							//��ʾ������ϵ����Ϣ
	int get_card_contact_num();					//��ȡ�ֻ���ͨѶ¼��ϵ������
	void copy(string rname, string rtel_num);	//������������ѹ�붯̬����
	string get_name(int i);						//��ȡ��̬�����i����ϵ�˵�����
	string get_tel_num(int i);					//��ȡ��̬�����i����ϵ�˵ĺ���
	void clear();								//����ֻ���ͨѶ¼
};

#endif