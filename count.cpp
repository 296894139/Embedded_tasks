#include<iostream>
#include<cmath>
#include<list>
using namespace std;
class tem{
public:
	double count_distance(double z1, double theta1, double z2, double theta2, double z3, double theta3){
		double x0 = (cos(theta1) / sin(theta1) - z1 / sin(theta1) + cos(theta2) / sin(theta2) - z2 / sin(theta2)) / 2;//���ĵ�x����
		double x3 = cos(theta3) / sin(theta3) - z3 / sin(theta3);//�����������x�ύ��
		double distance = abs(x0*cos(theta3) - z3);
		if (x3 > x0){//�������ұ�  ��ƫ
			return -distance;
		}
		else{
			return distance;
		}
	}
};