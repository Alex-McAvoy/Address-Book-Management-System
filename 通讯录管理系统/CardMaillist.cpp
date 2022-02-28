/*手机卡通讯簿类的实现*/

#include"cardmaillist.h"
#include"uimenu.h"
#include<fstream>

CardMaillist::CardMaillist() {	//构造函数，读取文本文件中的数据,并根据文件内容创建联系人对象数组

	ifstream fin("手机卡.txt");//打开文件  

	/*吸收标题行*/
	char str[100];
	fin.getline(str, 100);
	fin.getline(str, 100);
	fin.getline(str, 100);
	fin.getline(str, 100);


	card_contact_num = -1;
	string rname, rtel_num,rhomeland,rQQ;
	while (fin >> rname >> rtel_num >> rhomeland >> rQQ)//读取文件中的联系人姓名、号码、籍贯与QQ
	{		
		CardContact temp;										//建立手机卡联系人临时对象
		temp.set(rname, rtel_num , rhomeland , rQQ);			//存储联系人姓名和号码
		card_contact.push_back(temp);							//压入vector容器
		card_contact_num++;										//联系人数量+1
	}
	
	fin.close();//关闭文件
}
CardMaillist::~CardMaillist() {	//析构函数，将对象数组中的内容写入到文本文件中

	ofstream fout("手机卡.txt");//打开文件 

	/*写入文件标题*/
	fout << " ----------------------------------------------------------------------- " << endl;
	fout << "|				手机卡联系人		   		|" << endl;
	fout << " ----------------------------------------------------------------------- " << endl;
	fout << " 姓名\t\t号码\t\t籍贯\t\tQQ\t\t" << endl;

	for (int i = card_contact_num; i >= 0; i--)
	{
		fout.setf(ios::left);							//设置左对齐
		fout.width(16);									//设置域宽，与上述2个/t对应
		fout << card_contact[i].get_name();				//写入姓名
		fout.width(16);									//设置域宽，与上述2个/t对应
		fout << card_contact[i].get_tel_num();			//写入号码
		fout.width(16);									//设置域宽，与上述2个/t对应
		fout << card_contact[i].get_homeland();			//写入籍贯
		fout.width(16);									//设置域宽，与上述2个/t对应
		fout << card_contact[i].get_QQ() << endl;		//写入QQ
	}

	card_contact_num = -1;		//待存储联系人数量清空
	card_contact.clear();		//vector容器清空
	fout.close();				//关闭文件
}
void CardMaillist::add() {		//新建联系人
	if (card_contact_num>1000) {	 //当达到容量上限时不再添加
		cout << "手机通讯录容量已满，无法新建联系人！" << endl;
		cout << "请尝试在手机卡通讯录新建联系人" << endl;
		return;
	}
	CardContact temp;				//建立临时对象
	cin >> temp;					//使用重载 >> 输入数据  
	card_contact.push_back(temp);	//压入vector容器
	card_contact_num++;				//手机联系人个数+1
	cout << "新建联系人成功！" << endl;
}
void CardMaillist::Delete(string rtel_num) {	//删除联系人
	if (card_contact_num<0) {	//手机通讯录没有联系人时
		cout << "手机通讯录无联系人！" << endl;
		return;
	}

	while (true) {
		bool flag = false;
		for (int i = 0; i <= card_contact_num; i++) {	//枚举所有联系人
			if (card_contact[i].get_tel_num() == rtel_num) {	//如果号码相同
				flag = true;
				cout << "该联系人信息为：" << endl;
				cout << card_contact[i];
				cout << "是否删除该联系人？" << endl;
				cout << "1.确定删除" << endl;
				cout << "2.取消删除" << endl;

				int t;
				cin >> t;
				if (t == 1)
				{
					card_contact.erase(card_contact.begin() + i);
					card_contact_num--;
					cout << "删除成功！" << endl;
				}
				else	//如果取消删除，继续向下枚举
					continue;
			}
		}
		if (flag == false) {	//如果未找到相应联系人
			cout << "在手机通讯录未找到相应联系人!" << endl;
			cout << "是否重新输入号码？" << endl;
			cout << "1.重新输入" << endl;
			cout << "2.不重新输入" << endl;

			int t;
			cin >> t;
			if (t == 1) {
				cout << "请重新输入号码 :";
				cin >> rtel_num;
				continue;
			}
			else {
				cout << "输入取消" << endl;
				return;
			}
		}
		else { //如果找到相应联系人
			cout << "搜索结束，删除完毕！" << endl;
			return;
		}
	}
}
void CardMaillist::change(string rtel_num) {	//修改联系人信息  
	if (card_contact_num<0) {	//手机通讯录没有联系人时
		cout << "手机通讯录无联系人！" << endl;
		return;
	}

	while (true)
	{
		bool flag = false;
		for (int i = 0; i <= card_contact_num; i++) {	//枚举所有联系人
			if (card_contact[i].get_tel_num() == rtel_num) {	//如果号码相同
				flag = true;
				cout << "该联系人信息为：" << endl;
				cout << card_contact[i];
				cout << "是否修改该联系人？" << endl;
				cout << "1.确定修改" << endl;
				cout << "2.取消修改" << endl;

				int t;
				cin >> t;
				if (t == 1) {
					card_contact[i].modify();
					cout << "修改成功！" << endl;
					cout << "是否寻找相同姓名联系人？" << endl;
					cout << "1.确定寻找" << endl;
					cout << "2.取消寻找" << endl;

					int t;
					cin >> t;
					if (t == 1)
						continue;
					else
						break;
				}
				else {	//如果取消修改，继续向下枚举

					cout << "是否寻找相同姓名联系人？" << endl;
					cout << "1.确定寻找" << endl;
					cout << "2.取消寻找" << endl;

					int t;
					cin >> t;
					if (t == 1)
						continue;
					else
						break;
				}
			}
		}
		if (flag == false) {	//如果未找到相应联系人
			cout << "在手机通讯录未找到相应联系人!" << endl;
			cout << "是否重新输入号码？" << endl;
			cout << "1.重新输入" << endl;
			cout << "2.不重新输入" << endl;

			int t;
			cin >> t;
			if (t == 1) {
				cout << "请重新输入号码 :";
				cin >> rtel_num;
				continue;
			}
			else {
				cout << "输入取消" << endl;
				return;
			}
		}
		else { //如果找到相应联系人
			cout << "搜索结束，修改完毕！" << endl;
			return;
		}
	}
}
void CardMaillist::inquiry(string rname) {		//查询联系人信息  
	if (card_contact_num<0) {	//手机通讯录没有联系人时
		cout << "手机通讯录无联系人！" << endl;
		return;
	}
	while (true)
	{
		bool flag = false;
		for (int i = 0; i <= card_contact_num; i++) {	//枚举所有联系人
			if (card_contact[i].get_name() == rname) {		//如果姓名相同
				flag = true;
				cout << "该联系人信息为：" << endl;
				cout << card_contact[i];

				cout << "是否寻找相同姓名联系人？" << endl;
				cout << "1.确定寻找" << endl;
				cout << "2.取消寻找" << endl;

				int t;
				cin >> t;
				if (t == 1)
					continue;
				else
					break;
			}
		}
		if (flag == false) {	//如果未找到相应联系人
			cout << "在手机通讯录未找到相应联系人!" << endl;
			cout << "是否重新输入姓名？" << endl;
			cout << "1.重新输入" << endl;
			cout << "2.不重新输入" << endl;

			int t;
			cin >> t;
			if (t == 1) {
				cout << "请重新输入姓名 :";
				cin >> rname;
				continue;
			}
			else {
				cout << "输入取消" << endl;
				return;
			}
		}
		else { //如果找到相应联系人
			cout << "搜索结束，查询完毕！" << endl;
			return;
		}
	}
}
void CardMaillist::display() {		//显示所有联系人信息
	if (card_contact_num<0) {	//手机通讯录没有联系人时
		cout << "手机通讯录无联系人！" << endl;
		return;
	}
	cout << "手机通讯录中共有" << card_contact_num + 1 << "个联系人." << endl;
	cout << "信息如下：" << endl;

	vector <CardContact>::iterator temp;									//vector迭代器
	for (temp = card_contact.begin(); temp != card_contact.end(); temp++)	//显示vector容器内的所有信息
		cout << (*temp);
}
int CardMaillist::get_card_contact_num() {	//获取手机卡通讯录联系人数量
	return card_contact_num;
}
void CardMaillist::copy(string rname, string rtel_num) {	//将姓名、号码压入动态数组
	for (int i = 0; i <= card_contact_num; i++)	{	//枚举所有联系人  
		if (card_contact[i].get_name() == rname && card_contact[i].get_tel_num() == rtel_num)	{	//避免存在相同的联系人
			cout << "姓名为：" << rname << "　电话为：" << rtel_num << " 的联系人已存在!" << endl;
			return;
		}
	}
	CardContact temp;								//建立手机卡联系人临时对象
	temp.set(rname, rtel_num, "无地址", "无QQ");	//将联系人信息赋给临时对象
	card_contact.push_back(temp);					//压入动态数组
	card_contact_num++;								//手机卡联系人数量+1
	cout << "已存入姓名为：" << rname << "　电话为：" << rtel_num << " 的联系人!" << endl;
}
string CardMaillist::get_name(int i) {	//获取动态数组第i个联系人的姓名
	return card_contact[i].get_name();
}
string CardMaillist::get_tel_num(int i) {	//获取动态数组第i个联系人的号码
	return card_contact[i].get_tel_num();
}
void CardMaillist::clear() {	//清空手机卡通讯录
	card_contact.clear();
	card_contact_num = -1;
}