#ifndef __COM_STRUCT_H__
#define __COM_STRUCT_H__

/** 基本定义：结构体，通俗讲就像是打包封装，把一些有共同特征（比如同属于某一类事物的属性，往往是某种业务相关属性的聚合）的变量封装在内部，通过一定方法访问修改内部变量。
*/
/* 第一种：最常用结构体重定义 */
typedef struct	Stuff	//stuff可以省略
{
        char job[20];
        int age;
        float height;
}Stuff;
//Stuff stuff;

/* 第二种：只有结构体定义 */
struct stuff{
        char job[20];
        int age;
        float height;
};
//struct stuff yourname;

/* 第三种：附加该结构体类型的“结构体变量”的初始化的结构体定义 */
struct stuff{
        char job[20];
        int age;
        float height;
}Huqinwei;				//直接带变量名Huqinwei
//也许初期看不习惯容易困惑，其实这就相当于：
struct stuff{
        char job[20];
        int age;
        float height;
};
struct stuff Huqinwei;



#endif