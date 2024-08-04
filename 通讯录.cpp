/*  系统中需要实现的功能如下:
    添加联系人:向通讯录中添加新人，信息包括(姓名、性别、年龄、联系电话、家庭住址)最多记录1000人
    显示联系人:显示通讯录中所有联系人信息
    删除联系人:按照姓名进行删除指定联系人
    查找联系人:按照姓名查看指定联系人信息
    修改联系人:按照姓名重新修改指定联系人
    清空联系人:清空通讯录中所有信息
    退出通讯录:退出当前使用的通讯录
  */

#include "iostream"
using namespace std;
#define MAX 1000


//定义结构体
struct Person{
    string m_Name;
    int m_Gender;//1-male 2 female
    int m_Age;
    string m_Phone;
    string m_Address;

};

struct Book{
    Person pArray[MAX]; //联系人数组
    int m_Size; // 联系人数量

};

//函数声明区
void showMenu();
void Add(Book * book);
void Display(Book * book);
void Delete(Book * book);
void Search(Book * book);
void Revise(Book * book);
void Clean(Book * book);

int main()
{
    Book book;
    book.m_Size = 0;
    int select = 0;
    showMenu();

    while(true){
        cout << "请选择功能" << endl;
        cin >> select;
        switch(select){
            case 1://添加联系人
                Add(&book);
                break;
            case 2://显示联系人
                Display(&book);
                break;
            case 3://删除联系人
                Delete(&book);
                break;
            case 4://查找联系人
                Search(&book);
                break;
            case 5://修改联系人
                Revise(&book);
                break;
            case 6:// 清空联系人
                Clean(&book);
                break;
            case 0:
                cout << "成功退出！" << endl;
                return 0;
            default:
                cout << "无效输入" << endl;
                break;

        }
    }

    return 0;
}

void showMenu()
{
    cout << "******************" << endl;
    cout << "*** 1、添加联系人 ***" << endl;
    cout << "*** 2、显示联系人 ***" << endl;
    cout << "*** 3、删除联系人 ***" << endl;
    cout << "*** 4、查找联系人 ***" << endl;
    cout << "*** 5、修改联系人 ***" << endl;
    cout << "*** 6、清空联系人 ***" << endl;
    cout << "*** 0、退出通讯录 ***" << endl;
    cout << "******************" << endl;
    cout << endl;
}

void Add(Book * book)
{

    cout << "请输入联系人姓名" << endl;
    cin >> book -> pArray[book -> m_Size].m_Name;
    cout << "请输入联系人性别\n1-男\n2-女" << endl;
    cin >> book -> pArray[book -> m_Size].m_Gender;
    cout << "请输入联系人年龄" << endl;
    cin >> book -> pArray[book -> m_Size].m_Age;
    cout << "请输入联系人电话" << endl;
    cin >> book -> pArray[book -> m_Size].m_Phone;
    cout << "请输入联系人家庭住址" << endl;
    cin >> book -> pArray[book -> m_Size].m_Address;
    book -> m_Size ++;
    cout << endl;


}

void Display(Book * book)
{
    int len = book -> m_Size;
    for(int i = 0;i < len;i ++){
        cout << "联系人" << i + 1 << ": " << endl;
        cout << "姓名：" << book ->pArray[i].m_Name << " ";
        cout << "性别：";
        if(book -> pArray[i].m_Gender == 1){
            cout << "男" << " ";
        }else if(book -> pArray[i].m_Gender == 2){
            cout << "女" << " ";
        }
        cout << "年龄：" << book ->pArray[i].m_Age << " ";
        cout << "联系电话：" << book ->pArray[i].m_Phone << " ";
        cout << "家庭地址：" << book ->pArray[i].m_Address << endl;
        cout << endl;
    }
}

void Delete(Book * book)
{
    int ret;
    string deleteName;
    cout << "请输入要删除的联系人姓名：" << endl;
    cin >> deleteName;
    int len = book -> m_Size;
    for(int i = 0;i < len ;i ++){
        if(book-> pArray[i].m_Name == deleteName){
            ret = i;
        }
    }
    book->m_Size --;

    len = book ->m_Size;
    for(int i = ret;i < len ;i ++){
        book -> pArray[i] = book->pArray[i + 1];
    }



    cout << endl;
    cout << "删除成功" << endl << endl;


}

void Search(Book * book)
{
    string searchName;
    cout << "请输入要查找联系人的姓名：" << endl;
    cin >> searchName;

    int len = book -> m_Size ;

    for(int i = 0;i < len;i ++){
        if(book -> pArray[i].m_Name == searchName){
            cout << "姓名：" << book ->pArray[i].m_Name << " ";
            cout << "性别：";
            if(book -> pArray[i].m_Gender == 1){
                cout << "男" << " ";
            }else if(book -> pArray[i].m_Gender == 2){
                cout << "女" << " ";
            }
            cout << "年龄：" << book ->pArray[i].m_Age << " ";
            cout << "联系电话：" << book ->pArray[i].m_Phone << " ";
            cout << "家庭地址：" << book ->pArray[i].m_Address << endl;
            cout << endl;
        }
    }
}

void Revise(Book * book)
{
    string reviseName;
    int reviseNum;
    cout << "请输入要修改的联系人姓名：" << endl;
    cin >> reviseName;
    int len = book -> m_Size;

    for(int i = 0;i < len;i ++){
        if(book -> pArray[i].m_Name == reviseName){
            cout << "请输入要修改的内容:\n1-姓名\n2-性别\n3-年龄\n4-联系电话\n5-家庭地址\n0-修改完成" << endl;
            while(1) {
                cin >> reviseNum;
                switch (reviseNum) {
                    case 1:
                        cout << "请输入修改后的姓名：" << endl;
                        cin >> book->pArray[i].m_Name;
                        cout << "姓名修改成功，请选择下一步操作" << endl;
                        break;
                    case 2:
                        cout << "请输入修改后的性别(1-男,2-女)：" << endl;
                        cin >> book->pArray[i].m_Gender;
                        cout << "性别修改成功，请选择下一步操作" << endl;
                        break;
                    case 3:
                        cout << "请输入修改后的年龄：" << endl;
                        cin >> book->pArray[i].m_Age;
                        cout << "年龄修改成功，请选择下一步操作" << endl;
                        break;
                    case 4:
                        cout << "请输入修改后的联系电话：" << endl;
                        cin >> book->pArray[i].m_Phone;
                        cout << "联系电话修改成功，请选择下一步操作" << endl;
                        break;
                    case 5:
                        cout << "请输入修改后的家庭住址：" << endl;
                        cin >> book->pArray[i].m_Address;
                        cout << "家庭住址修改成功，请选择下一步操作" << endl;
                        break;
                    case 0:
                        cout << "修改完成！" << endl << endl;

                        return;

                }
            }
        }
    }
}

void Clean(Book * book)
{
    book -> m_Size = 0;
    cout << "清除成功！" << endl;
}