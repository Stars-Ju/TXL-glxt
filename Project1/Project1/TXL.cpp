#define _CRT_SECURE_NO_WARNINGS	
#include <iostream>
using namespace std;
#include <string>
#define MAX 1000

struct person
{
	string name;
	int gender;
	int age;
	int number;
	string address;
};

struct  addressbooks {
	struct person personarr[MAX];
	int m_Size;
};


void showMenu() {
	cout << "************" << endl;
	cout << "1.添加联系人" << endl;
	cout << "2.显示联系人" << endl;
	cout << "3.删除联系人" << endl;
	cout << "4.查找联系人" << endl;
	cout << "5.修改联系人" << endl;
	cout << "6.清空联系人" << endl;
	cout << "0.退出通讯录" << endl;
	cout << "************" << endl;
}

void addperson(addressbooks *abs) {

	if (abs->m_Size == MAX) {
		cout << "通讯录已满，无法添加" << endl;
		return;
	}
	else {
		string name;
		cout << "请输入名字：" << endl;
		cin >> name;
		abs->personarr[abs->m_Size].name = name;

		cout << "请输入性别：" << endl;
		cout << "1 --- 男" << endl;
		cout << "2 --- 女" << endl;

		int sex = 0;
		while (true)
		{
			cin >> sex;
			if (sex == 1 || sex == 2)
			{
				abs->personarr[abs->m_Size].gender = sex;
				break;
			}
			cout << "输入有误，请重新输入";
		}
		
		cout << "请输入年龄:" << endl;
		int age = 0;
		cin >> age;
		abs->personarr[abs->m_Size].age = age;

		cout << "请输入电话:" << endl;
		int phone = 0;
		cin >> phone;
		abs->personarr[abs->m_Size].number = phone;

		cout << "请输入家庭住址：" << endl;
		string address;
		cin >> address;
		abs->personarr[abs->m_Size].address = address;

		abs->m_Size++;

		cout << "添加成功" << endl;
		system("pause");
		system("cls");
	}

}

void showperson(addressbooks* abs)
{
	if (abs->m_Size == 0)
	{
		cout << "当前记录为空" << endl;
	}
	else
	{
		for (int i = 0; i < abs->m_Size; i++)
		{
			cout << "姓名：" << abs->personarr[i].name << "\t";
			cout << "性别：" << (abs->personarr[i].gender == 1 ? "男" : "女") << "\t";
			cout << "年龄：" << abs->personarr[i].age << "\t";
			cout << "电话：" << abs->personarr[i].number << "\t";
			cout << "住址：" << abs->personarr[i].address << endl;
		}
	}

	system("pause");
	system("cls");

}

int isExist(addressbooks* abs, string name) {
	for (int i = 0; i < abs->m_Size; i++) {
		if (abs->personarr[i].name == name) {
			return i;
		}
	}
	return -1;
}

void deleteperson(addressbooks * abs) {

		cout << "请输入删除联系人姓名：" << endl;
		string name;
		cin >> name;

		int ret = isExist(abs, name);
		if (ret != -1) {
			for (int i = ret; i < abs->m_Size; i++) {
				abs->personarr[i] = abs->personarr[i + 1];
			}
			abs->m_Size--;
			cout << "删除成功" << endl;
		}
		else {
			cout << "查无此人" << endl;
		}

		system("pause");
		system("cls");
}

int main() {
	addressbooks abs;
	abs.m_Size = 0;

	int select = 0;

	while (1) {
		showMenu();

		cin >> select;
		switch (select)
		{
		case 1:
			addperson(&abs);
			break;
		case 2:
			showperson(&abs);
			break;
		case 3:
			deleteperson(&abs);
		//{
		//	cout << "请输入删除联系人姓名：" << endl;
		//	string name;
		//	cin >> name;

		//	int ret = isExist(&abs, name);
		//	if (ret != -1) {
		//		cout << "查无此人" << endl;
		//	}
		//	else {
		//		cout << "找到此人" << endl;
		//	}
		//}
			break;
		case 4:
			break;
		case 5:
			break;
		case 6:
			break;
		case 0:
			cout << "欢迎下次使用" << endl;
			system("pause");
			return 0;
			break;
		default:
			break;
		}
	}



	system("pause");
	return 0;
}