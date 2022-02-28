/*�ֻ�ͨѶ�����ʵ��*/

#include"phonemaillist.h"
#include"uimenu.h"
#include<fstream>
PhoneMaillist::PhoneMaillist() {	//���캯������ȡ�ı��ļ��е�����,�������ļ����ݴ�����ϵ�˶�������
	
	ifstream fin("�ֻ�.txt");//���ļ�  
	
	/*���ձ�����*/
	char str[100];
	fin.getline(str, 100);
	fin.getline(str, 100);
	fin.getline(str, 100);
	fin.getline(str, 100);

	phone_contact_num = -1;
	string rname, rtel_num;
	while (fin >> rname >> rtel_num )//��ȡ�ļ��е���ϵ����������룬����������Ϊ������ϵ�ˡ�����ϵ��
	{

		PhoneContact temp;					//�����ֻ���ϵ����ʱ����
		temp.set(rname, rtel_num);			//�洢��ϵ�������ͺ���
		phone_contact.push_back(temp);		//ѹ��vector����
		phone_contact_num++;				//��ϵ������+1
	}
	fin.close();//�ر��ļ�
}
PhoneMaillist::~PhoneMaillist() {	//���������������������е�����д�뵽�ı��ļ���
	
	ofstream fout("�ֻ�.txt");//���ļ� 

	/*д���ļ�����*/
	fout << " ----------------------------------------------- " << endl;
	fout << "|		   �ֻ���ϵ��   		|" << endl;
	fout << " ----------------------------------------------- " << endl;
	fout << " ����\t\t\t����\t\t\t" << endl;

	for (int i = phone_contact_num; i >= 0; i--)
	{
		fout.setf(ios::left);							//���������
		fout.width(24);									//�����������������/t��Ӧ
		fout << phone_contact[i].get_name();			//д������
		fout.width(24);									//�����������������/t��Ӧ
		fout << phone_contact[i].get_tel_num() << endl;	//д�����
	}

	phone_contact_num = -1;		//���洢��ϵ���������
	phone_contact.clear();	//vector�������
	fout.close();			//�ر��ļ�
}
void PhoneMaillist::add() {		//�½���ϵ��
	if (phone_contact_num>1000) {	 //���ﵽ��������ʱ�������
		cout << "�ֻ�ͨѶ¼�����������޷��½���ϵ�ˣ�" << endl; 
		cout << "�볢�����ֻ���ͨѶ¼�½���ϵ��" << endl;
		return; 
	}                  
	PhoneContact temp;				//������ʱ����
	cin >> temp;					//ʹ������ >> ��������  
	phone_contact.push_back(temp);	//ѹ��vector����
	phone_contact_num++;			//�ֻ���ϵ�˸���+1
	cout << "�½���ϵ�˳ɹ���" << endl;
}
void PhoneMaillist::Delete(string rtel_num) {	//ɾ����ϵ��
	if (phone_contact_num<0) {	//�ֻ�ͨѶ¼û����ϵ��ʱ
		cout << "�ֻ�ͨѶ¼����ϵ�ˣ�" << endl;
		return;
	}

	while (true) {
		bool flag = false;
		for (int i = 0; i <= phone_contact_num; i++)	{	//ö��������ϵ��
			if (phone_contact[i].get_tel_num() == rtel_num) {	//���������ͬ
				flag = true;
				cout << "����ϵ����ϢΪ��" << endl;
				cout << phone_contact[i];
				cout << "�Ƿ�ɾ������ϵ�ˣ�" << endl;
				cout << "1.ȷ��ɾ��" << endl;
				cout << "2.ȡ��ɾ��" << endl;

				int t;
				cin >> t;
				if (t == 1)
				{
					phone_contact.erase(phone_contact.begin() + i);
					phone_contact_num--;
					cout << "ɾ���ɹ���" << endl;
				}
				else	//���ȡ��ɾ������������ö��
					continue;
			}
		}
		if (flag == false)	{	//���δ�ҵ���Ӧ��ϵ��
			cout << "���ֻ�ͨѶ¼δ�ҵ���Ӧ��ϵ��!" << endl;
			cout << "�Ƿ�����������룿" << endl;
			cout << "1.��������" << endl;
			cout << "2.����������" << endl;

			int t; 
			cin >> t;
			if (t == 1)	{
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
void PhoneMaillist::change(string rtel_num) {	//�޸���ϵ����Ϣ  
	if (phone_contact_num<0) {	//�ֻ�ͨѶ¼û����ϵ��ʱ
		cout << "�ֻ�ͨѶ¼����ϵ�ˣ�" << endl;
		return;
	}

	while (true)
	{
		bool flag = false;
		for (int i = 0; i <= phone_contact_num; i++)	{	//ö��������ϵ��
			if (phone_contact[i].get_tel_num() == rtel_num)	{	//���������ͬ
				flag = true;
				cout << "����ϵ����ϢΪ��" << endl;
				cout << phone_contact[i];
				cout << "�Ƿ��޸ĸ���ϵ�ˣ�" << endl;
				cout << "1.ȷ���޸�" << endl;
				cout << "2.ȡ���޸�" << endl;

				int t;
				cin >> t;
				if (t == 1)	{
					phone_contact[i].modify();     
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
		if (flag == false)	{	//���δ�ҵ���Ӧ��ϵ��
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
void PhoneMaillist::inquiry(string rname) {		//��ѯ��ϵ����Ϣ  
	if (phone_contact_num<0) {	//�ֻ�ͨѶ¼û����ϵ��ʱ
		cout << "�ֻ�ͨѶ¼����ϵ�ˣ�" << endl;
		return;
	}
	while (true)
	{
		bool flag = false;
		for (int i = 0; i <= phone_contact_num; i++)	{	//ö��������ϵ��
			if (phone_contact[i].get_name() == rname) {		//���������ͬ
				flag = true;
				cout << "����ϵ����ϢΪ��" << endl;
				cout << phone_contact[i];

				cout << "�Ƿ�Ѱ����ͬ������ϵ�ˣ�" << endl;
				cout << "1.ȷ��Ѱ��" << endl;
				cout << "2.ȡ��Ѱ��" << endl;

				int t;
				cin >> t;
				if (t==1) 
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
void PhoneMaillist::display() {		//��ʾ������ϵ����Ϣ
	if (phone_contact_num<0) 	{	//�ֻ�ͨѶ¼û����ϵ��ʱ
		cout << "�ֻ�ͨѶ¼����ϵ�ˣ�" << endl;
		return; 
	}
	cout << "�ֻ�ͨѶ¼�й���" << phone_contact_num + 1 << "����ϵ��." << endl;
	cout << "��Ϣ���£�" << endl;

	vector <PhoneContact>::iterator temp;									//vector������
	for (temp = phone_contact.begin(); temp != phone_contact.end(); temp++)	//��ʾvector�����ڵ�������Ϣ
		cout << (*temp);
}
int PhoneMaillist::get_phone_contact_num() {	//��ȡ�ֻ�ͨѶ¼��ϵ������
	return phone_contact_num;
}
void PhoneMaillist::copy(string rname, string rtel_num) {	//������������ѹ�붯̬����
	for (int i = 0; i <= phone_contact_num; i++) {	//ö��������ϵ��  
		if (phone_contact[i].get_name() == rname && phone_contact[i].get_tel_num() == rtel_num) {	//���������ͬ����ϵ��
			cout << "����Ϊ��" << rname << "���绰Ϊ��" << rtel_num << " ����ϵ���Ѵ���!" << endl;
			return;
		}
	}
	PhoneContact temp;								//�����ֻ���ϵ����ʱ����
	temp.set(rname, rtel_num);						//����ϵ����Ϣ������ʱ����
	phone_contact.push_back(temp);					//ѹ�붯̬����
	phone_contact_num++;							//�ֻ���ϵ������+1
	cout << "�Ѵ�������Ϊ��" << rname << "���绰Ϊ��" << rtel_num << " ����ϵ��!" << endl;
}
string PhoneMaillist::get_name(int i) {	//��ȡ��̬�����i����ϵ�˵�����
	return phone_contact[i].get_name();
}
string PhoneMaillist::get_tel_num(int i) {	//��ȡ��̬�����i����ϵ�˵ĺ���
	return phone_contact[i].get_tel_num();
}
void PhoneMaillist::clear() {	//����ֻ�ͨѶ¼
	phone_contact.clear();
	phone_contact_num = -1;
}