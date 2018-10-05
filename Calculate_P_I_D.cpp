#include<iostream>
#include<cmath>
#include<list>
using namespace std;
class Calculate_P_I_D{
	//z=x*cos(theta)+y*sin(theta)    小车默认位置（0，0）？
public:
	double get_P(double z1,double z2){   //CTE（Cross Track Error） 作为偏差度量 ，CTE就是我们到参考线的距离。  z1  z2分别为左右两条线的距离 目标尽可能保持一致
		return fabs(fabs(z1)-fabs(z2));
	}
	double get_I(double v,double theta){         //CTE的变化率描述了我们的无人车向着参考线方向移动的有多快，如果我们的无人车一直都完美的在参考线上运动的话，那么我们的CTE变化率就为0。那么这一项（描述误差的变化率）就可以用导数来表示
		return v*sin(theta);
	}
	double get_D(list<double> v1, list<double> v2, list<double> z1, list<double> z2){   //每隔1s？记录速度、距离   都为postive
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