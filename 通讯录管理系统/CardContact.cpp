/*�ֻ�����ϵ�����ʵ��*/

#include"cardcontact.h"  
#include"Uimenu.h"
CardContact::CardContact(string rname, string rtel_num, string rhomeland, string rQQ) :PhoneContact(rname, rtel_num){//�вι��캯��
	homeland = rhomeland; 
	QQ = rQQ;
}
void CardContact::modify() {//�޸����ݳ�Ա��ֵ
	int n;
	Uimenu obj;
	change2: {
		obj.ChangeCardUimenu();
		cin >> n;
		switch (n)
		{
			case 1: {
				cout << "������������ϵ��������";
				cin >> name;
				cout << "������������ϵ�˺��룺";
				cin >> tel_num;
				cout << "������������ϵ�˼��᣺";
				cin >> homeland;
				cout << "������������ϵ��QQ��";
				cin >> QQ;
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
			case 4: {
				cout << "������������ϵ�˼��᣺";
				cin >> homeland;
				break;
			}
			case 5: {
				cout << "������������ϵ��QQ��";
				cin >> QQ;
				break;
			}
			case 0: {
				return;
			}
			default: {
				cout << "ѡ�����������ѡ��" << endl;
				goto change2;
			}
		}
	}
}
istream & operator >> (istream & input, CardContact & obj){//����>>�����
	cout << "��������ϵ��������";
	input >> obj.name;
	cout << "��������ϵ�˺��룺";
	input >> obj.tel_num;
	cout << "�����뼮�᣺";
	input >> obj.homeland;
	cout << "������QQ��";
	input >> obj.QQ;
	return input;
}
ostream & operator << (ostream &output, CardContact &obj){//����<<�����
	output << "��ϵ��������" << obj.name << "\t";
	output << "��ϵ�˺��룺" << obj.tel_num << "\t";
	output << "��ϵ�˼��᣺" << obj.homeland << "\t";
	output << "��ϵ��QQ��" << obj.QQ << endl;
	return output;
}
string CardContact::get_homeland() {		//��ȡ����
	return homeland;
}
string CardContact::get_QQ() {	//��ȡQQ
	return QQ;
}
void CardContact::set(string rname, string rtel_num, string rhomeland, string rQQ) {		//Ϊ���ݳ�Ա��ֵ
	PhoneContact::set(rname,rtel_num);//���û���set����
	homeland = rhomeland;
	QQ = rQQ;
}