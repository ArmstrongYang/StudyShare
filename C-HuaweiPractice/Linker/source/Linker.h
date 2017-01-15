#ifndef _LINKER_H_
#define _LINKER_H_

//常用参数判断宏和内存释放宏
#define IF_INVALID_BREAK(condition) if(!(condition)) {break;}
#define IF_INVALID_RETURN(condition, returnValue) if(!(condition)) {return (returnValue);}
#define IF_INVALID_RETURN_NOVALUE(condition) if(!(condition)) {return ;}
#define IF_INVALID_SET_RETURN_VALUE(condition, returnValue, returenPara) if(!(condition)) {(returenPara) = (returnValue);}
#define FREE_PTR(ptr) if((ptr)) {free((ptr)); (ptr) = NULL;}
#define SIZE(arr) sizeof((arr))/sizeof((arr)[0])

#define FILE_NUM_MAX	100
#define FILE_ID_MAX		5000
#define FILE_FUN_MAX	50
#define FUN_ID_MAX		5000

int AddFile(unsigned int file_id, unsigned int func_id_array[],unsigned int func_num);
int AddCallList(unsigned int caller_id, unsigned int callee_id_array[], unsigned int callee_num);
int IsFileLinked(unsigned int file_id);

#endif
