#include <mysql.h>
#include <stdio.h>
#include <string.h>
// libmysqlclient.so libmysqlclient.a
// cc -o bookSql bookSql.c -I/usr/include/mysql -L/usr/lib/mysql -lmysqlclient

typedef struct
{
    int bookid;
    char bookname[40];
    char publisher[40];
    int price;
} Book;
void fetch_books(MYSQL *conn);
void add_books(MYSQL *conn);
int main(void)
{

    MYSQL *conn;
    // data inside
    char *host = "localhost";
    char *user = "myuser";
    char *pass = "0000";
    char *db = "mydb";
    int port = 3306;
    int choice = 1;

    // DB connect please
    conn = mysql_init(NULL);
    if (mysql_real_connect(conn, host, user, pass, db, port, NULL, 0))
    {
        printf("MYSQL 연결 성공\n");
    }
    else
    {
        printf("MySQL 연결 실패\n");
        return 1;
    }
    while (true)
    {
        printf("1번 2번 고르세요!\n");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            fetch_books(conn);
            break;
        case 2:
            add_books(conn);
            break;
        default:
            break;
        }
    }
    mysql_close(conn);

    return 0;
}
void add_books(MYSQL *conn)
{
    char query[255];
    printf("---도시 추가---\n");

    Book newbook;

    scanf("%d%s%s%d", &newbook.bookid, newbook.bookname, newbook.publisher, &newbook.price);
    printf("%d\n%s\n%s\n%d\n", newbook.bookid, newbook.bookname, newbook.publisher, newbook.price);
    sprintf(query, "INSERT INTO Book VALUES(%d , '%s', '%s' , %d);\n", newbook.bookid, newbook.bookname,
            newbook.publisher, newbook.price);
    printf("%s", query);
    if (mysql_query(conn, query))
    {
        printf("query 실패\n");
        return;
    }

    return;
}
void fetch_books(MYSQL *conn)
{
    MYSQL_RES *res;
    MYSQL_ROW row;
    // data inside

    char query[255];

    strcpy(query, "select * from Book");

    // DB connect please

    // query please
    if (mysql_query(conn, query))
    {
        printf("query 실패\n");
        return;
    }

    res = mysql_store_result(conn);
    if (!res)
    {
        printf("가져오기 실패\n");
        return;
    }
    Book book[100]; // 동적할당이 좋지만 일단.... 스택에 만들자.
    int i = 0;
    while (row = mysql_fetch_row(res))
    {

        book[i].bookid = atoi(row[0]);
        strcpy(book[i].bookname, row[1]);
        strcpy(book[i].publisher, row[2]);
        book[i].price = atoi(row[3]);
        ++i;
    }
    for (int j = 0; j < i; ++j)
    {
        printf("%d\t%s\t%s\t%d\n", book[j].bookid, book[j].bookname, book[j].publisher, book[j].price);
    }

    return;
}