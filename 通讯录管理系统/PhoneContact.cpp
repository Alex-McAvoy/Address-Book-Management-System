/*�ֻ���ϵ�����ʵ��*/

#include"PhoneContact.h"
#include"Uimenu.h"
PhoneContact::PhoneContact(string rname , string rtel_num ) {//�вι��캯��
	name = rname;
	tel_num = rtel_num;
}
void PhoneContact::modify() {//�޸����ݳ�Ա��ֵ
	int n;
	Uimenu obj;
	obj.ChangePhoneUimenu();
	change1:{
		cin >> n;
		switch (n)
		{
			case 1: {
				cout << "������������ϵ��������";
				cin >> name;
				cout << "������������ϵ�˺��룺";
				cin >> tel_num;
				break;
			}
			case 2: {
				cout << "������������ϵ��������";
				cin >> name;
				break;
			}
			case 3: {
				cout << "������������ϵ�˺��룺";
				cin >> tel_num;
				break;
			}
			case 0: {
				return;
			}
			default:{
				cout << "ѡ�����������ѡ��" << endl;
				goto change1;
			}
		}
	}
}
istream &operator >>(istream &input, PhoneContact &obj) {//����>>�����
	cout << "��������ϵ��������";
	input >> obj.name;
	cout << "��������ϵ�˺��룺";
	input >> obj.tel_num;
	return input;
}
ostream &operator <<(ostream &output, PhoneContact &obj) {//����<<�����
	output << "��ϵ��������" << obj.name<<"\t";
	output << "��ϵ�˺��룺" << obj.tel_num<<endl;
	return output;
}
string PhoneContact::get_name() {	//��ȡ����
	return name;
}
string PhoneContact::get_tel_num() {	//��ȡ����
	return tel_num;
}
void PhoneContact::set(string rname, string rtel_num) {//Ϊ���ݳ�Ա��ֵ
	name = rname;
	tel_num = rtel_num;
}

