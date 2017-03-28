#!/usr/bin/python3

#! /usr/bin/python
# coding=utf-8

import calendar


"""
返回的某个月的日历
返回类型是字符串型
"""
cal = calendar.month(2011, 11)

"""
返回一年的日历
"""
cal = calendar.calendar(2011)

cal = calendar.HTMLCalendar(calendar.MONDAY)
"""
打印出一个月日历
"""
cal.formatmonth(2011, 11)
"""
打印出一年的日历
formatyearpage将生成完整的页面代码
"""
print (cal.formatyear(2017))
cal.formatyearpage(2017)

"""
默认每周的第一天是星期一，这里修改成星期天
"""
calendar.setfirstweekday(calendar.SUNDAY)

if __name__=='__main__':
    print(__file__)

    exit(0)