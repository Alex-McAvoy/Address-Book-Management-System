/*�ֻ�����ϵ����*/

#ifndef CARDCONTACT_H
#define CARDCONTACT_H

#include"phonecontact.h"  
class CardContact : public PhoneContact{
protected:
	string homeland;
	string QQ;
public:
	CardContact(string rname = "����ϵ��", string rtel_num = "�޺���", string rhomeland = "�޵�ַ", string rQQ = "��QQ");	//�вι��캯��
	void modify();																											//�޸����ݳ�Ա��ֵ
	friend istream & operator >>(istream &input, CardContact &obj);															//����>>�����
	friend ostream & operator <<(ostream &output, CardContact &obj);														//����<<�����
	string get_homeland();																								    //��ȡ����
	string get_QQ();																									    //��ȡQQ
	void set(string rname, string rtel_num,string rhomeland,string rQQ);													//Ϊ���ݳ�Ա��ֵ
};

#endif