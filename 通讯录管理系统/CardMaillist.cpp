/*�ֻ���ͨѶ�����ʵ��*/

#include"cardmaillist.h"
#include"uimenu.h"
#include<fstream>

CardMaillist::CardMaillist() {	//���캯������ȡ�ı��ļ��е�����,�������ļ����ݴ�����ϵ�˶�������

	ifstream fin("�ֻ���.txt");//���ļ�  

	/*���ձ�����*/
	char str[100];
	fin.getline(str, 100);
	fin.getline(str, 100);
	fin.getline(str, 100);
	fin.getline(str, 100);


	card_contact_num = -1;
	string rname, rtel_num,rhomeland,rQQ;
	while (fin >> rname >> rtel_num >> rhomeland >> rQQ)//��ȡ�ļ��е���ϵ�����������롢������QQ
	{		
		CardContact temp;										//�����ֻ�����ϵ����ʱ����
		temp.set(rname, rtel_num , rhomeland , rQQ);			//�洢��ϵ�������ͺ���
		card_contact.push_back(temp);							//ѹ��vector����
		card_contact_num++;										//��ϵ������+1
	}
	
	fin.close();//�ر��ļ�
}
CardMaillist::~CardMaillist() {	//���������������������е�����д�뵽�ı��ļ���

	ofstream fout("�ֻ���.txt");//���ļ� 

	/*д���ļ�����*/
	fout << " ----------------------------------------------------------------------- " << endl;
	fout << "|				�ֻ�����ϵ��		   		|" << endl;
	fout << " ----------------------------------------------------------------------- " << endl;
	fout << " ����\t\t����\t\t����\t\tQQ\t\t" << endl;

	for (int i = card_contact_num; i >= 0; i--)
	{
		fout.setf(ios::left);							//���������
		fout.width(16);									//�������������2��/t��Ӧ
		fout << card_contact[i].get_name();				//д������
		fout.width(16);									//�������������2��/t��Ӧ
		fout << card_contact[i].get_tel_num();			//д�����
		fout.width(16);									//�������������2��/t��Ӧ
		fout << card_contact[i].get_homeland();			//д�뼮��
		fout.width(16);									//�������������2��/t��Ӧ
		fout << card_contact[i].get_QQ() << endl;		//д��QQ
	}

	card_contact_num = -1;		//���洢��ϵ���������
	card_contact.clear();		//vector�������
	fout.close();				//�ر��ļ�
}
void CardMaillist::add() {		//�½���ϵ��
	if (card_contact_num>1000) {	 //���ﵽ��������ʱ�������
		cout << "�ֻ�ͨѶ¼�����������޷��½���ϵ�ˣ�" << endl;
		cout << "�볢�����ֻ���ͨѶ¼�½���ϵ��" << endl;
		return;
	}
	CardContact temp;				//������ʱ����
	cin >> temp;					//ʹ������ >> ��������  
	card_contact.push_back(temp);	//ѹ��vector����
	card_contact_num++;				//�ֻ���ϵ�˸���+1
	cout << "�½���ϵ�˳ɹ���" << endl;
}
void CardMaillist::Delete(string rtel_num) {	//ɾ����ϵ��
	if (card_contact_num<0) {	//�ֻ�ͨѶ¼û����ϵ��ʱ
		cout << "�ֻ�ͨѶ¼����ϵ�ˣ�" << endl;
		return;
	}

	while (true) {
		bool flag = false;
		for (int i = 0; i <= card_contact_num; i++) {	//ö��������ϵ��
			if (card_contact[i].get_tel_num() == rtel_num) {	//���������ͬ
				flag = true;
				cout << "����ϵ����ϢΪ��" << endl;
				cout << card_contact[i];
				cout << "�Ƿ�ɾ������ϵ�ˣ�" << endl;
				cout << "1.ȷ��ɾ��" << endl;
				cout << "2.ȡ��ɾ��" << endl;

				int t;
				cin >> t;
				if (t == 1)
				{
					card_contact.erase(card_contact.begin() + i);
					card_contact_num--;
					cout << "ɾ���ɹ���" << endl;
				}
				else	//���ȡ��ɾ������������ö��
					continue;
			}
		}
		if (flag == false) {	//���δ�ҵ���Ӧ��ϵ��
			cout << "���ֻ�ͨѶ¼δ�ҵ���Ӧ��ϵ��!" << endl;
			cout << "�Ƿ�����������룿" << endl;
			cout << "1.��������" << endl;
			cout << "2.����������" << endl;

			int t;
			cin >> t;
			if (t == 1) {
				cout << "������������� :";
				cin >> rtel_num;
				continue;
			}
			else {
				cout << "����ȡ��" << endl;
				return;
			}
		}
		else { //����ҵ���Ӧ��ϵ��
			cout << "����������ɾ����ϣ�" << endl;
			return;
		}
	}
}
void CardMaillist::change(string rtel_num) {	//�޸���ϵ����Ϣ  
	if (card_contact_num<0) {	//�ֻ�ͨѶ¼û����ϵ��ʱ
		cout << "�ֻ�ͨѶ¼����ϵ�ˣ�" << endl;
		return;
	}

	while (true)
	{
		bool flag = false;
		for (int i = 0; i <= card_contact_num; i++) {	//ö��������ϵ��
			if (card_contact[i].get_tel_num() == rtel_num) {	//���������ͬ
				flag = true;
				cout << "����ϵ����ϢΪ��" << endl;
				cout << card_contact[i];
				cout << "�Ƿ��޸ĸ���ϵ�ˣ�" << endl;
				cout << "1.ȷ���޸�" << endl;
				cout << "2.ȡ���޸�" << endl;

				int t;
				cin >> t;
				if (t == 1) {
					card_contact[i].modify();
					cout << "�޸ĳɹ���" << endl;
					cout << "�Ƿ�Ѱ����ͬ������ϵ�ˣ�" << endl;
					cout << "1.ȷ��Ѱ��" << endl;
					cout << "2.ȡ��Ѱ��" << endl;

					int t;
					cin >> t;
					if (t == 1)
						continue;
					else
						break;
				}
				else {	//���ȡ���޸ģ���������ö��

					cout << "�Ƿ�Ѱ����ͬ������ϵ�ˣ�" << endl;
					cout << "1.ȷ��Ѱ��" << endl;
					cout << "2.ȡ��Ѱ��" << endl;

					int t;
					cin >> t;
					if (t == 1)
						continue;
					else
						break;
				}
			}
		}
		if (flag == false) {	//���δ�ҵ���Ӧ��ϵ��
			cout << "���ֻ�ͨѶ¼δ�ҵ���Ӧ��ϵ��!" << endl;
			cout << "�Ƿ�����������룿" << endl;
			cout << "1.��������" << endl;
			cout << "2.����������" << endl;

			int t;
			cin >> t;
			if (t == 1) {
				cout << "������������� :";
				cin >> rtel_num;
				continue;
			}
			else {
				cout << "����ȡ��" << endl;
				return;
			}
		}
		else { //����ҵ���Ӧ��ϵ��
			cout << "�����������޸���ϣ�" << endl;
			return;
		}
	}
}
void CardMaillist::inquiry(string rname) {		//��ѯ��ϵ����Ϣ  
	if (card_contact_num<0) {	//�ֻ�ͨѶ¼û����ϵ��ʱ
		cout << "�ֻ�ͨѶ¼����ϵ�ˣ�" << endl;
		return;
	}
	while (true)
	{
		bool flag = false;
		for (int i = 0; i <= card_contact_num; i++) {	//ö��������ϵ��
			if (card_contact[i].get_name() == rname) {		//���������ͬ
				flag = true;
				cout << "����ϵ����ϢΪ��" << endl;
				cout << card_contact[i];

				cout << "�Ƿ�Ѱ����ͬ������ϵ�ˣ�" << endl;
				cout << "1.ȷ��Ѱ��" << endl;
				cout << "2.ȡ��Ѱ��" << endl;

				int t;
				cin >> t;
				if (t == 1)
					continue;
				else
					break;
			}
		}
		if (flag == false) {	//���δ�ҵ���Ӧ��ϵ��
			cout << "���ֻ�ͨѶ¼δ�ҵ���Ӧ��ϵ��!" << endl;
			cout << "�Ƿ���������������" << endl;
			cout << "1.��������" << endl;
			cout << "2.����������" << endl;

			int t;
			cin >> t;
			if (t == 1) {
				cout << "�������������� :";
				cin >> rname;
				continue;
			}
			else {
				cout << "����ȡ��" << endl;
				return;
			}
		}
		else { //����ҵ���Ӧ��ϵ��
			cout << "������������ѯ��ϣ�" << endl;
			return;
		}
	}
}
void CardMaillist::display() {		//��ʾ������ϵ����Ϣ
	if (card_contact_num<0) {	//�ֻ�ͨѶ¼û����ϵ��ʱ
		cout << "�ֻ�ͨѶ¼����ϵ�ˣ�" << endl;
		return;
	}
	cout << "�ֻ�ͨѶ¼�й���" << card_contact_num + 1 << "����ϵ��." << endl;
	cout << "��Ϣ���£�" << endl;

	vector <CardContact>::iterator temp;									//vector������
	for (temp = card_contact.begin(); temp != card_contact.end(); temp++)	//��ʾvector�����ڵ�������Ϣ
		cout << (*temp);
}
int CardMaillist::get_card_contact_num() {	//��ȡ�ֻ���ͨѶ¼��ϵ������
	return card_contact_num;
}
void CardMaillist::copy(string rname, string rtel_num) {	//������������ѹ�붯̬����
	for (int i = 0; i <= card_contact_num; i++)	{	//ö��������ϵ��  
		if (card_contact[i].get_name() == rname && card_contact[i].get_tel_num() == rtel_num)	{	//���������ͬ����ϵ��
			cout << "����Ϊ��" << rname << "���绰Ϊ��" << rtel_num << " ����ϵ���Ѵ���!" << endl;
			return;
		}
	}
	CardContact temp;								//�����ֻ�����ϵ����ʱ����
	temp.set(rname, rtel_num, "�޵�ַ", "��QQ");	//����ϵ����Ϣ������ʱ����
	card_contact.push_back(temp);					//ѹ�붯̬����
	card_contact_num++;								//�ֻ�����ϵ������+1
	cout << "�Ѵ�������Ϊ��" << rname << "���绰Ϊ��" << rtel_num << " ����ϵ��!" << endl;
}
string CardMaillist::get_name(int i) {	//��ȡ��̬�����i����ϵ�˵�����
	return card_contact[i].get_name();
}
string CardMaillist::get_tel_num(int i) {	//��ȡ��̬�����i����ϵ�˵ĺ���
	return card_contact[i].get_tel_num();
}
void CardMaillist::clear() {	//����ֻ���ͨѶ¼
	card_contact.clear();
	card_contact_num = -1;
}