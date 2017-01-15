#ifndef __COM_ENUM_H__
#define __COM_ENUM_H__

/*******************************通用类型************************************************************/
//枚举类型
/* 方法一：最常用的，用typedef关键字将枚举类型定义成别名，并利用该别名进行变量声明：*/
typedef enum WEEKDAY //WEEKDAY可以省略
{
    MON = 1,
	TUE, 
	WED, 
	THU, 
	FRI, 
	SAT, 
	SUN
} WEEKDAY；
//WEEKDAY today;	//直接用WEEKDAY进行定义

/* 方法二：枚举类型的定义和变量的声明分开 */
enum _WEEKDAY
{
    MON = 1,
	TUE, 
	WED, 
	THU, 
	FRI, 
	SAT, 
	SUN
};
//enum _WEEKDAY today;

/* 方法三：类型定义与变量声明同时进行 */
enum WeekDay		//此处的标号weekday可以省略
{
    monday = 1,
    tuesday,
    wednesday,
    thursday,
    friday，
	saturday,
    sunday    
} tomorrow; 			//变量weekday的类型为枚举型enum WeekDay

#endif