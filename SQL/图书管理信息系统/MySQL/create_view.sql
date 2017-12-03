use LMS;
drop view if exists 计算机科学技术视图,计算机_王珊,读者_西建大;
create view 计算机科学技术视图 (书籍信息ID,书籍名称,作者名称,出版社,出版日期) as select num,name,author_name,pub_name,reg_date from book where cate = (select num from book_cate where name='计算机科学技术') WITH CHECK OPTION;
create view 计算机_王珊 (书籍信息ID,书籍名称,作者名称,出版社,出版日期) as select num,name,author_name,pub_name,reg_date from book where cate = (select num from book_cate where name='计算机科学技术') and author_name = '王珊' WITH CHECK OPTION;

create view 读者_西建大 as select * from reader where company = '西安建筑科技大学' WITH CHECK OPTION;
