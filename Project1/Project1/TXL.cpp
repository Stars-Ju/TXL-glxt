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
	cout << "1.�����ϵ��" << endl;
	cout << "2.��ʾ��ϵ��" << endl;
	cout << "3.ɾ����ϵ��" << endl;
	cout << "4.������ϵ��" << endl;
	cout << "5.�޸���ϵ��" << endl;
	cout << "6.�����ϵ��" << endl;
	cout << "0.�˳�ͨѶ¼" << endl;
	cout << "************" << endl;
}

void addperson(addressbooks *abs) {

	if (abs->m_Size == MAX) {
		cout << "ͨѶ¼�������޷����" << endl;
		return;
	}
	else {
		string name;
		cout << "���������֣�" << endl;
		cin >> name;
		abs->personarr[abs->m_Size].name = name;

		cout << "�������Ա�" << endl;
		cout << "1 --- ��" << endl;
		cout << "2 --- Ů" << endl;

		int sex = 0;
		while (true)
		{
			cin >> sex;
			if (sex == 1 || sex == 2)
			{
				abs->personarr[abs->m_Size].gender = sex;
				break;
			}
			cout << "������������������";
		}
		
		cout << "����������:" << endl;
		int age = 0;
		cin >> age;
		abs->personarr[abs->m_Size].age = age;

		cout << "������绰:" << endl;
		int phone = 0;
		cin >> phone;
		abs->personarr[abs->m_Size].number = phone;

		cout << "�������ͥסַ��" << endl;
		string address;
		cin >> address;
		abs->personarr[abs->m_Size].address = address;

		abs->m_Size++;

		cout << "��ӳɹ�" << endl;
		system("pause");
		system("cls");
	}

}

void showperson(addressbooks* abs)
{
	if (abs->m_Size == 0)
	{
		cout << "��ǰ��¼Ϊ��" << endl;
	}
	else
	{
		for (int i = 0; i < abs->m_Size; i++)
		{
			cout << "������" << abs->personarr[i].name << "\t";
			cout << "�Ա�" << (abs->personarr[i].gender == 1 ? "��" : "Ů") << "\t";
			cout << "���䣺" << abs->personarr[i].age << "\t";
			cout << "�绰��" << abs->personarr[i].number << "\t";
			cout << "סַ��" << abs->personarr[i].address << endl;
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

		cout << "������ɾ����ϵ��������" << endl;
		string name;
		cin >> name;

		int ret = isExist(abs, name);
		if (ret != -1) {
			for (int i = ret; i < abs->m_Size; i++) {
				abs->personarr[i] = abs->personarr[i + 1];
			}
			abs->m_Size--;
			cout << "ɾ���ɹ�" << endl;
		}
		else {
			cout << "���޴���" << endl;
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
		//	cout << "������ɾ����ϵ��������" << endl;
		//	string name;
		//	cin >> name;

		//	int ret = isExist(&abs, name);
		//	if (ret != -1) {
		//		cout << "���޴���" << endl;
		//	}
		//	else {
		//		cout << "�ҵ�����" << endl;
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
			cout << "��ӭ�´�ʹ��" << endl;
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