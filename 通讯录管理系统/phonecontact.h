/*�ֻ���ϵ����*/

#ifndef PHONECONTACT_H
#define PHONECONTACT_H

#include<iostream>
#include<string>
using namespace std;
class PhoneContact {
protected:
	string name;
	string tel_num;
public:
	PhoneContact(string rname = "����ϵ��", string rtel_num = "�޺���");   //�вι��캯��
	void modify();														   //�޸����ݳ�Ա��ֵ
	friend istream &operator >>(istream &input, PhoneContact &obj);		   //����>>�����
	friend ostream &operator <<(ostream &output, PhoneContact &obj);	   //����<<�����
	string get_name();													   //��ȡ����
	string get_tel_num();												   //��ȡ����
	void set(string rname, string rtel_num);							   //Ϊ���ݳ�Ա��ֵ
};

#endif