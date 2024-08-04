#include <iostream>
using namespace std;

class Rectangle {
private:
    double x1, y1; // 左上角坐标
    double x2, y2; // 右下角坐标

public:
    Rectangle() : x1(0), y1(0), x2(0), y2(0) {}

    double calculatC() const {
        double l = x2 - x1;
        double w = y1 - y2;
        return 2 * (l + w);
    }

    double calculatS() const {
        return (x2 - x1) * (y1 - y2);
    }

    void setTopLeft(double x, double y) {
        x1 = x;
        y1 = y;
    }

    void setBottomRight(double x, double y) {
        x2 = x;
        y2 = y;
    }
};

int main() {
    Rectangle rect;
    double x1, y1, x2, y2;

    cout << "请输入左上角坐标 (x y):" << endl;
    cin >> x1 >> y1;
    rect.setTopLeft(x1, y1);

    cout << "请输入右下角坐标 (x y):" << endl;
    cin >> x2 >> y2;
    rect.setBottomRight(x2, y2);

    cout << "矩形的周长为：" << rect.calculatC() << endl;
    cout << "矩形的面积为：" << rect.calculatS() << endl;

    system("pause");
    return 0;
}