# 一个数据库数据导出工具
## 使用方法
```dos
set tb_name=char_character
connsql 172.31.100.224 admin 123456 db_game %tb_name% >%tb_name%.csv
```
> 记事本打开start.bat  修改需要导出的表的名字 tb_name=xxxx 不要有空格
> 172.31.100.24 要链接的数据库IP， admin 123456 分别为数据库用户名密码
