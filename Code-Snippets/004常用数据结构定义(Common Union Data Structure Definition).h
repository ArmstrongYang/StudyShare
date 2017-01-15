#ifndef __COM_UNION_H__
#define __COM_UNION_H__

/**
1.联合体union的基本特性——和struct的同与不同
union，中文名“联合体、共用体”，在某种程度上类似结构体struct的一种数据结构，共用体(union)和结构体(struct)同样可以包含很多种数据类型和变量。
结构体(struct)中所有变量是“共存”的——优点是“有容乃大”，全面；缺点是struct内存空间的分配是粗放的，不管用不用，全分配。
而联合体(union)中是各变量是“互斥”的——缺点就是不够“包容”；但优点是内存使用更为精细灵活，也节省了内存空间。
*/
//联合类型
/* 方法一：最常用的，用typedef关键字将枚举类型定义成别名，并利用该别名进行变量声明：*/
typedef union Value //Value可以省略
{
    char c[4];  
    uint i; 
} Value;
//Value var;	//直接用Value进行定义


#endif