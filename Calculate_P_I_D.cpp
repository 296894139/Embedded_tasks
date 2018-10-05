#include<iostream>
#include<cmath>
#include<list>
using namespace std;
class Calculate_P_I_D{
	//z=x*cos(theta)+y*sin(theta)    С��Ĭ��λ�ã�0��0����
public:
	double get_P(double z1,double z2){   //CTE��Cross Track Error�� ��Ϊƫ����� ��CTE�������ǵ��ο��ߵľ��롣  z1  z2�ֱ�Ϊ���������ߵľ��� Ŀ�꾡���ܱ���һ��
		return fabs(fabs(z1)-fabs(z2));
	}
	double get_I(double v,double theta){         //CTE�ı仯�����������ǵ����˳����Ųο��߷����ƶ����ж�죬������ǵ����˳�һֱ���������ڲο������˶��Ļ�����ô���ǵ�CTE�仯�ʾ�Ϊ0����ô��һ��������ı仯�ʣ��Ϳ����õ�������ʾ
		return v*sin(theta);
	}
	double get_D(list<double> v1, list<double> v2, list<double> z1, list<double> z2){   //ÿ��1s����¼�ٶȡ�����   ��Ϊpostive
		double s1 = 0;
		double s2 = 0;
		list<double>::iterator iter_v1 = v1.begin();
		list<double>::iterator iter_l1 = z1.begin();
		list<double>::iterator iter_v2 = v2.begin();
		list<double>::iterator iter_l2 = z2.begin();
		while (iter_v1 != v1.end()){
			s1 += (*iter_v1)*(*iter_l1);
			iter_v1++;
			iter_l1++;
		}
		while (iter_v2 != v2.end()){
			s2 += (*iter_v2)*(*iter_l2);
			iter_v2++;
			iter_l2++;
		}
		return fabs(s1 - s2);

	}


};