/*ͨѶ��������*/

#ifndef MAILLIST_H
#define MAILLIST_H

#include<iostream>
#include<string>
using namespace std;
class Maillist {
public:
	virtual void add() = 0;						//�½���ϵ��
	virtual void Delete(string rtel_num) = 0;	//ɾ����ϵ��
	virtual void change(string rtel_num) = 0;	//�޸���ϵ����Ϣ  
	virtual void inquiry(string rname) = 0;		//��ѯ��ϵ����Ϣ  
	virtual void display() = 0;					//��ʾ������ϵ����Ϣ
};

#endif
