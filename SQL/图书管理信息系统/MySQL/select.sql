use LMS;

select name,sex,company,phone from reader where cate = (select num from reader_cate where name = '博士生');

select num,name,author_name,pub_date,(select name from book_cate where num=book.cate)as 书籍类别名称 from book where pub_name = '机械工业出版社';

select reader.num,reader.name,company,phone,email,out_time,in_time from reader,borrow_relation
where reader.num = borrow_relation.reader_num and book_num = 'B00101';
/*嵌套查询*/
select name,phone from reader where num in (select reader_num from borrow_relation where book_num =(select num from book where name = '数据库系统概论'));
/*连接查询*/
select reader.name,phone from book,reader,borrow_relation where
(
borrow_relation.reader_num = reader.num and 
borrow_relation.book_num = book.num and
book.name = '数据库系统概论'
);

select * from reader_cate order by total asc;

select distinct reader_num from borrow_relation;

select book_cate.num,book_cate.name,count(*) as 总数量 from book,book_cate where book.cate = book_cate.num group by book_cate.num;

select * from reader,borrow_relation where (borrow_relation.reader_num = reader.num and reader.num = 'r001');

/*select reader_num,count(*) as 借书总数 from borrow_relation where reader_num='r001' group by reader_num*/
