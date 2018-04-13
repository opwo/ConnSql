#include <winsock.h>
#include <iostream>
#include <mysql.h>
void main(int argc, char* args[])
{
	MYSQL *pConn;
	pConn = mysql_init(NULL);
	
	if (!mysql_real_connect(pConn, args[1], args[2], args[3], args[4], 0, NULL, 0))
	{
		printf("无法连接数据库：%s", mysql_error(pConn));
		return;
	}
	mysql_query(pConn, "set names utf8");
	char buf[256];
	const char* sql = "select * from %s";
	sprintf(buf, sql, args[5]);
	if (mysql_query(pConn, buf))
	{
		printf("查询失败：%s", mysql_error(pConn));
		return;
	}
	MYSQL_RES *result = mysql_store_result(pConn);
	MYSQL_FIELD *fiels;
	MYSQL_ROW row;
	while (fiels = mysql_fetch_field(result))
	{
		printf("%s,", fiels->name);
	}
	printf("\n");
	while (row = mysql_fetch_row(result))
	{
		int colm_size = result->field_count;
		for (int i=0; i < colm_size; i++)
		{
			printf("%s,", row[i]);
		}
		printf("\n");
		
	}
	mysql_free_result(result);
	mysql_close(pConn);
}