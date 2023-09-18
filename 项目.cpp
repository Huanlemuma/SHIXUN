#include <iostream>
#include <string>
#include<fstream>
#include<istream>
#include<stdlib.h>
#define MAX 1000

using namespace std;

// ��ϵ�˽ṹ��
struct Person
{
	string personName; // ����
	int personSex = 0; // �Ա� 1�� 2Ů
	int personAge = 0; // ����
	double personPhone = 0; // �绰
	string personAddress; // סַ
};

// ͨѶ¼�ṹ��
struct Addressbooks
{
	struct Person personArray[MAX]; // ͨѶ¼�б������ϵ������
	int size = 0; // ��ǰͨѶ¼��ϵ�˸���
};

// ��ʾ�˵�����
void showMenu()
{
	cout << "***************************" << endl;
	cout << "*****  1�������ϵ��  *****" << endl;
	cout << "*****  2����ʾ��ϵ��  *****" << endl;
	cout << "*****  3��ɾ����ϵ��  *****" << endl;
	cout << "*****  4��������ϵ��  *****" << endl;
	cout << "*****  5���޸���ϵ��  *****" << endl;
	cout << "*****  6�������ϵ��  *****" << endl;
	cout << "*****  7������ͨѶ¼  *****" << endl;
	cout << "*****  8���ָ�ͨѶ¼  *****" << endl;
	cout << "*****  9�����ͨѶ¼  *****" << endl;
	cout << "*****  0���˳�ͨѶ¼  *****" << endl;
	cout << "***************************" << endl;
}

// �����ϵ���Ƿ���ڣ������򷵻���ϵ���������еľ���λ�ã������ڷ���-1
int isExist(Addressbooks* abs, string name)
{
	for (int i = 0; i < abs->size; i++)
	{
		if (abs->personArray[i].personName == name)
			return i;
	}
	return -1;
}

// 1�������ϵ��
void addPerson(Addressbooks* abs)
{
	if (abs->size == MAX)
	{
		cout << "ͨѶ¼�������޷���ӣ�" << endl;
		return;
	}
	// ��Ӿ�����ϵ��

	// ����
	string name;
	cout << "������������ " << endl;
	cin >> name;
	abs->personArray[abs->size].personName = name;

	// �Ա�
	int sex = 0;
	cout << "�������Ա� " << endl;
	cout << "1 --- ��" << endl;
	cout << "2 --- Ů" << endl;
	while (true)
	{
		cin >> sex;
		if (sex == 1 || sex == 2)
		{
			abs->personArray[abs->size].personSex = sex;
			break;
		}
		cout << "������������������" << endl;
	}

	// ����
	int age = 0;
	cout << "���������䣺 " << endl;
	while (true)
	{
		cin >> age;
		if (age > 0)
		{
			abs->personArray[abs->size].personAge = age;
			break;
		}
		cout << "������������������" << endl;
	}

	// �绰
	double phone;
	cout << "��������ϵ�绰�� " << endl;
	cin >> phone;
	abs->personArray[abs->size].personPhone = phone;

	// סַ
	string address;
	cout << "�������ͥסַ�� " << endl;
	cin >> address;
	abs->personArray[abs->size].personAddress = address;

	// ����ͨѶ¼����
	abs->size++;

	cout << "��ӳɹ�" << endl;
	system("pause"); // �밴���������
	system("cls"); // ��������
}

// 2����ʾ��ϵ��
void showPerson(Addressbooks* abs)
{
	// �ж�ͨѶ¼�������Ƿ�Ϊ0
	if (abs->size == 0)
	{
		cout << "��ǰ��¼Ϊ��" << endl;
	}
	else
	{
		for (int i = 0; i < abs->size; i++)
		{
			cout << "������" << abs->personArray[i].personName << '\t';
			cout << "�Ա�" << (abs->personArray[i].personSex == 1 ? "��" : "Ů") << '\t';
			cout << "���䣺" << abs->personArray[i].personAge << '\t';
			cout << "�绰��" << abs->personArray[i].personPhone << '\t';
			cout << "סַ��" << abs->personArray[i].personAddress << endl;
		}
	}
	system("pause"); // �밴���������
	system("cls"); // ��������
}

// 3��ɾ����ϵ��
void deletePerson(Addressbooks* abs)
{
	cout << "��������Ҫɾ������ϵ�ˣ� " << endl;

	string name;
	cin >> name;

	int ret = isExist(abs, name);
	if (ret != -1) // ��ѯ���ˣ�ɾ������ϵ��
	{
		// ����ǰ��
		for (int i = ret + 1; i < abs->size; i++)
		{
			abs->personArray[i - 1] = abs->personArray[i];
		}
		// ����ͨѶ¼��Ա��
		abs->size--;

		cout << "ɾ���ɹ���" << endl;
	}
	else
	{
		cout << "���޴��ˣ�" << endl;
	}

	system("pause");
	system("cls");
}

// 4��������ϵ��
void findPerson(Addressbooks* abs)
{
	cout << "��������Ҫ���ҵ���ϵ�ˣ� " << endl;

	string name;
	cin >> name;

	int ret = isExist(abs, name);
	if (ret != -1)
	{
		cout << "������" << abs->personArray[ret].personName << '\t';
		cout << "�Ա�" << abs->personArray[ret].personSex << '\t';
		cout << "���䣺" << abs->personArray[ret].personAge << '\t';
		cout << "�绰��" << abs->personArray[ret].personPhone << '\t';
		cout << "��ַ��" << abs->personArray[ret].personAddress << endl;
	}
	else
	{
		cout << "���޴��ˣ�" << endl;
	}

	system("pause");
	system("cls");
}

// 5���޸���ϵ��
void modifyPerson(Addressbooks* abs)
{
	cout << "��������Ҫ�޸ĵ���ϵ�ˣ� " << endl;

	string name;
	cin >> name;

	int ret = isExist(abs, name);
	if (ret != -1) // �ҵ�ָ����ϵ��
	{
		// ����
		string name;
		cout << "������������ " << endl;
		cin >> name;
		abs->personArray[ret].personName = name;

		// �Ա�
		int sex = 0;
		cout << "�������Ա� " << endl;
		cout << "1 --- ��" << endl;
		cout << "2 --- Ů" << endl;
		while (true)
		{
			cin >> sex;
			if (sex == 1 || sex == 2)
			{
				abs->personArray[ret].personSex = sex;
				break;
			}
			cout << "������������������" << endl;
		}

		// ����
		int age = 0;
		cout << "���������䣺 " << endl;
		while (true)
		{
			cin >> age;
			if (age > 0)
			{
				abs->personArray[ret].personAge = age;
				break;
			}
			cout << "������������������" << endl;
		}

		// �绰
		double phone;
		cout << "��������ϵ�绰�� " << endl;
		cin >> phone;
		abs->personArray[ret].personPhone = phone;

		// סַ
		string address;
		cout << "�������ͥסַ�� " << endl;
		cin >> address;
		abs->personArray[ret].personAddress = address;

		cout << "�޸ĳɹ���" << endl;
	}
	else
	{
		cout << "���޴��ˣ�" << endl;
	}

	system("pause");
	system("cls");
}

// 6�������ϵ��
void cleanPerson(Addressbooks* abs)
{
	char ret;
	cout << "�Ƿ�ȷ�����ͨѶ¼��" << endl;
	cout << "y��ȷ��    n��ȡ��" << endl;
	cin >> ret;
	if (ret == 'y')
	{
		abs->size = 0; // �߼����
		cout << "ͨѶ¼����գ�" << endl;
	}
	system("pause");
	system("cls");
}
//7������ͨѶ¼
void ofaddressbook(const Addressbooks* abs)
{
	ofstream ofs;
	ofs.open("addressbook.txt", ios::out); //���ļ�
	ofs << "����\t�Ա�\t����\t�绰����\tסַ" << endl;
	for (int i = 0; i < abs->size; i++)
	{
		ofs << abs->personArray[i].personName
			<< "\t\t" << abs->personArray[i].personSex
			<< "\t\t" << abs->personArray[i].personAge
			<< "\t\t" << abs->personArray[i].personPhone
			<< "\t\t" << abs->personArray[i].personAddress
			<< endl;
	}
	ofs.close(); //�ر��ļ�
	cout << "���ݳɹ�" << endl;
}
//8���ָ�ͨѶ¼
void ifaddressbook(Addressbooks* abs)
{
	string temp;
	ifstream ifs;
	ifs.open("addressbook.txt", ios::in); //���ļ�
	if (ifs.is_open())
	{
		getline(ifs, temp); //���ļ��Ϸ��ı�ǩ���뵽��ʱ�ַ���
		while (ifs >> abs->personArray[abs->size].personName >> abs->personArray[abs->size].personSex >> abs->personArray[abs->size].personAge >> abs->personArray[abs->size].personPhone >> abs->personArray[abs->size].personAddress)
		{
			abs->size++; //����+1
		}
		ifs.close(); //�ر��ļ�
		cout << "�ָ��ɹ�" << endl;
	}
	else
	{
		cout << "�ļ���ʧ��" << endl;
	}
}
//9�����ͨѶ¼
void clearPerson(Addressbooks* abs)
{
	abs->size = 0;// ��ͨѶ¼���
		cout << "ͨѶ¼�����" << endl;
}
int main()
{
	// ����ͨѶ¼
	Addressbooks abs;
	abs.size = 0;

	int select = 0;
	while (true)
	{
		// �˵�����
		showMenu();

		// ��ȡ�û���ѡ��
		cin >> select;
		switch (select)
		{
		case 1: // �����ϵ��
			addPerson(&abs); // �������ò����޸�ͨѶ¼
			break;
		case 2: // ��ʾ��ϵ��
			showPerson(&abs);
			break;
		case 3: // ɾ����ϵ��
			deletePerson(&abs);
			break;
		case 4: // ������ϵ��
			findPerson(&abs);
			break;
		case 5: // �޸���ϵ��
			modifyPerson(&abs);
			break;
		case 6: // �����ϵ��
			cleanPerson(&abs);
			break;
		case 7://����ͨѶ¼
			ofaddressbook(&abs);
			break;
		case 8://�ָ�ͨѶ¼
			ifaddressbook(&abs);
			break;
		case 9://���ͨѶ¼
			clearPerson(&abs);
			break;
		case 0: // �˳�ͨѶ¼
			cout << "��ӭ�´�ʹ��" << endl;
			system("pause");
			return 0;
			break;
		default:
		{
			cout << "�����������������룺" << endl;
			system("pause");
			system("cls");
		}
		break;
		}
	}
	system("pause");

	return 0;
}