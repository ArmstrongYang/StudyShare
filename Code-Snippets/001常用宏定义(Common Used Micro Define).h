//常用参数判断宏
#define IF_INVALID_BREAK(condition) if(!(condition)) {break;}
#define IF_INVALID_RETURN(condition, returnValue) if(!(condition)) {return (returnValue);}
#define IF_INVALID_RETURN_NOVALUE(condition) if(!(condition)) {return ;}
#define IF_INVALID_SET_RETURN_VALUE(condition, returnValue, returenPara) if(!(condition)) {(returenPara) = (returnValue);}

//内存释放宏
#define FREE_PTR(ptr) if((ptr)) {free((ptr)); (ptr) = NULL;}
#define SIZE(arr) sizeof((arr))/sizeof((arr)[0])
