use 图书管理信息系统;
drop view 计算机科学技术视图,计算机_王珊,读者_西建大

GO
create view 计算机科学技术视图 (书籍信息ID,书籍名称,作者名称,出版社,出版日期) as select 书籍编号,书籍名称,作者名称,出版社名称,出版日期 from book where 书籍类别 = (select 类别编号 from book_cate where 类别名称='计算机科学技术') WITH CHECK OPTION 
GO
create view 计算机_王珊 (书籍信息ID,书籍名称,作者名称,出版社,出版日期) as select 书籍编号,书籍名称,作者名称,出版社名称,出版日期 from book where 书籍类别 = (select 类别编号 from book_cate where 类别名称='计算机科学技术') and 作者名称 = '王珊' WITH CHECK OPTION 
Go
create view 读者_西建大 as select * from reader where 工作单位 = '西安建筑科技大学' WITH CHECK OPTION 



