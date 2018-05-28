#include<bits/stdc++.h>//super header file
namespace quank;
#ifndef QUANK_MATH
#define QUANK_MATH
class Point
{
	public:
		class 2d
		{
			private:
				double x,y;
			public:
				inline 2d(void) {}
				inline 2d(double p,double q)
				{
					x=p;
					y=q;
				}
				inline double get_x(void)
				{
					return x;
				}
				inline double get_y(void)
				{
					return y;
				}
				inline void edit_x(double origin)
				{
					x=origin;
					return;
				}
				inline void edit_y(double origin)
				{
					y=origin;
					return;
				}
				inline double dist(2d ano)
				{
					return std::sqrt((x-ano.x)*(x-ano.x)+(y-ano.y)*(y-ano.y));
				}
				friend 2d operator+(const 2d& a,const 2d& b)
				{
					return 2d(a.x+b.x,a.y+b.y);
				}
				friend 2d operator-(const 2d& a,const 2d& b)
				{
					return 2d(a.x-b.x,a.y-b.y);
				}
				friend 2d operator*(const int& a,const 2d& b)
				{
					return 2d(a*b.x,a+b.y);
				}
				friend 2d operator*(const 2d& a,const int& b)
				{
					return 2d(a.x*b,a.y*b);
				}
				inline double norm(void){
					return std::sqrt(x*x+y*y);
				}
				inline double module(void){
					return norm();
				}
		};
};
typedef Point Vector;
#endif
