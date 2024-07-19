#include"iostream"
#include"string"
#define max 1000
using namespace std;
struct person {
	string name;//姓名
	int xb;//性别
	int age;//年龄
	string phonenum;//电话号码
	string address;//地址
};
struct addressbooks
{
	struct person parr[max];
	int size;
};


//菜单界面
void menu()
{
	cout << "***********************" << endl;
	cout << "*****1、添加联系人*****" << endl;
	cout << "*****2、显示联系人*****" << endl;
	cout << "*****3、删除联系人*****" << endl;
	cout << "*****4、查找联系人*****" << endl;
	cout << "*****5、修改联系人*****" << endl;
	cout << "*****6、清空联系人*****" << endl;
	cout << "*****0、退出通讯录*****" << endl;
	cout << "***********************" << endl;

}
void add(addressbooks* abs)
{
	if (abs->size >= max) {
		cout << "通讯录已满，无法再添加" << endl;
		return;
	}
	else
	{
		//输入姓名
		string name;
		cout << "请输入一个姓名" << endl;
		cin >> name;
		abs->parr[abs->size].name = name;
		//输入性别
		int xb;
		cout << "请输入它的性别" << endl;
		cout << "1---男" << endl;
		cout << "2---女" << endl;
		
		while (1) {
			cin >> xb;
			if (xb == 1 || xb == 2) {
				abs->parr[abs->size].xb = xb;
				break;
			}
			else {
				cout << "输入错误，请输入1或2" << endl;

			}
		}
			
	}
	//输入年龄
	int age;
	cout << "请输入它的年龄" << endl;
	cin >> age;
	abs->parr[abs->size].age = age;
	//输入联系电话
	string phonenum;
	cout << "请输入它的联系电话" << endl;
	cin >> phonenum;
	abs->parr[abs->size].phonenum = phonenum;
	//输入地址
	string address;
	cout << "请输入它的地址" << endl;
	cin >> address;
	abs->parr[abs->size].address = address;

	//更新通讯录人数
	abs->size++;
	cout << "添加成功" << endl;
	system("pause");
	system("cls");

	
}
//2.显示所有联系人函数
void showperson(addressbooks* abs)
{
	//判断通讯录中人数是否为0；如果为0，提示记录为空；如果不为0，显示记录的联系人信息
	if (abs->size == 0)
	{
		cout << "当前的记录为空" << endl;
	}
	else
	{
		for (int i = 0; i < abs->size; i++)
		{
			cout << "姓名：" << abs->parr[i].name << "\t"
				<< "性别：" << (abs->parr[i].xb == 1 ? "男" : "女") << "\t"
				<< "年龄：" << abs->parr[i].age << "\t"
				<< "电话：" << abs->parr[i].phonenum << "\t"
				<< "地址：" << abs->parr[i].address << endl;
		}
	}
	system("pause");
	system("cls");
}
int search(addressbooks* abs, string name) {
	for (int i = 0; i < abs->size; i++) {
		if (abs->parr[i].name == name) {
			return i;
		}
		else {
			i = -1;
		}
		return i;
	}
}
void delperseon(addressbooks* abs)
{
	string name;
	cin >> name;
	int i = search(abs, name);
	if (i != -1) {
		for (int j = i; j < abs->size; j++) {
			abs->parr[i] = abs->parr[i + 1];
		}
		abs->size--;
		cout << "删除成功" << endl;

	}
	else {
		cout << "空" << endl;
	}
}
void searchpeo(addressbooks* abs) {
	string name_1;
	cin >> name_1;
	for (int i = 0; i < abs->size; i++) {
		if (abs->parr[i].name == name_1) {
			cout << "姓名：" << abs->parr[i].name << "\t" << "性别：" << abs->parr[i].xb << "\t"
				<< "年龄：" << abs->parr[i].age << "\t" << "电话：" << abs->parr[i].phonenum << "\t"
				<< "地址：" << abs->parr[i].address << "\t" << endl;
		}
		else {
			cout << "查无此人" << endl;
		}
	}
}
void revise(addressbooks* abs)
{
	string name;
	cin >> name;
	for (int i = 0; i < abs->size; i++)
	{
		if (abs->parr[i].name == name) {
			cout << "第" << i << "位联系人" << endl;
			cout << "姓名：" << abs->parr[i].name << "\t" << "性别：" << abs->parr[i].xb << "\t"
				<< "年龄：" << abs->parr[i].age << "\t" << "电话：" << abs->parr[i].phonenum << "\t"
				<< "地址：" << abs->parr[i].address << "\t" << endl;
			cout << "请输入你想修改的信息" << endl;
			cout << "1->姓名" << endl;
			cout << "2->性别" << endl;
			cout << "3->年龄" << endl;
			cout << "4->电话" << endl;
			cout << "5->地址" << endl;
			int r_choose;
			cin >> r_choose;
			string r_name;//姓名
			int r_xb;//性别
			int r_age;//年龄
			string r_phonenum;//电话号码
			string r_address;//地址
			switch (r_choose)
			{
			case 1:
				cin >> r_name;
				abs->parr[i].name = r_name;
				break;
			case 2:
				cin >> r_xb;
				abs->parr[i].xb = r_xb;
				break;
			case 3:
				cin >> r_age;
				abs->parr[i].age = r_age;
				break;
			case 4:
				cin >> r_phonenum;
				abs->parr[i].phonenum = r_phonenum;
				break;
			case 5:
				cin >> r_address;
				abs->parr[i].address = r_address;
				break;
			default:
				cout << "输入错误" << endl;
				return;

			}
			cout << "修改成功" << endl;


		}

	}
	cout << "查无此人，请重新输入" << endl;


}
void clean(addressbooks* abs) {
	abs->size = 0;
	cout << "清理成功" << endl;
	system("pause");
	system("cls");
	
}


int main()
{
	//菜单调用
	
	int choose = 0;
	addressbooks abs;
	abs.size = 0;

	while (1) {
		menu();
		cin >> choose;
		switch (choose) {
		case 1://添加联系人
			add(&abs);
		case 2://显示联系人
			showperson(&abs);
			break;
		case 3://删除联系人
			delperseon(&abs);
			break;
		case 4://查找联系人
			searchpeo(&abs);
			break;
		case 5://修改联系人
			revise(&abs);
			break;
		case 6://清空通讯录
			clean(&abs);
			break;
		case 0://退出通讯录
			cout << "欢迎下次使用" << endl;
			system("pause");
			return 0;
			break;


		}

	}
	
	
	return 0;
}