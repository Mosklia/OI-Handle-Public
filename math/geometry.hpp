#include <bits/stdc++.h>

#ifndef SPARKY14145_GEOMETRY
#define SPARKY14145_GEOMETRY

namespace planimetry {
    struct Point {
        double index[2];
        double &x = index[0], &y = index[1];

        // 构造函数
        Point(double __x = 0, double __y = 0) : x(__x), y(__y) {}
        Point(const Point &__p) : x(__p.x), y(__p.y) {}

        // 修改操作
        double get_x() const {return x;}
        double get_y() const {return y;}
        void set_x(double &__v) {x = __v;}
        void set_y(double &__v) {y = __v;}

        // 比较运算符
        inline bool operator== (const Point &__p) const {return x == __p.x && y == __p.y;}
        inline bool operator!= (const Point &__p) const {return ! (*this == __p);}

        // 两点间距离
        inline double dist(const Point &__p) const {
            double temp = x * __p.x + y * __p.y;
            return sqrt(temp);
        }
    };

    class Vector {
        public:
            // 构造函数
            Vector(double __mod = 0, double __deg = 0) {
                // 要求给定的角以弧度制表示
                endpos.x = __mod * sin(__deg);
                endpos.y = __mod * cos(__deg);
            }
            Vector(Point __s, Point __t) {
                endpos.x = __t.x - __s.x;
                endpos.y = __t.y - __s.y;
            }

            // 赋值操作
            inline void set(double __mod = 0, double __deg = 0) {
                // 要求给定的角以弧度制表示
                endpos.x = __mod * sin(__deg);
                endpos.y = __mod * cos(__deg);
            }
            inline void set(Point __s, Point __t) {
                endpos.x = __t.x - __s.x;
                endpos.y = __t.y - __s.y;
            }

            // 比较运算符
            inline bool operator== (const Vector &__v) const {return endpos == __v.endpos;}
            inline bool operator!= (const Vector &__v) const {return endpos != __v.endpos;}

            // 运算符
            inline const Vector& operator- () const {
                return Vector(-endpos.x, -endpos.y);
            }
            inline const Vector& operator+ (const Vector &__v) const {
                return Vector(endpos.x + __v.endpos.x, endpos.y + __v.endpos.y);
            }
            inline const Vector& operator- (const Vector &__v) const {
                return *this + -__v;
            }
            inline double operator* (const Vector &__v) const {
                return endpos.x * __v.endpos.x + endpos.y * __v.endpos.y;
            }
            inline const Vector& operator* (double __v) const {
                return Vector(endpos.x * __v, endpos.y * __v);
            }

            // 其他运算
            inline double get_modulus() {
                return endpos.dist(Point(0, 0));
            }
            inline double get_polar_angle() {
                return atan2(endpos.y, endpos.x);
                // 不知道为什么标准库的 atan2 是 y 在前，x 在后……
            }
            inline double inner_product(const Vector &__v) const {
            // 内积
                return *this * __v;
            }
            inline double outer_product_val(const Vector &__v) const {
            // 外积数值（以 x+->y+ 方向为正方向）
                return endpos.x * __v.endpos.y - endpos.y * __v.endpos.x;
            }
        private:
            Point endpos; // 采用坐标形式保存
    };
}
#endif