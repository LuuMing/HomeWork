use 图书管理信息系统;

select 读者姓名,读者性别,工作单位,电话号码 from reader where 读者种类 = (select 种类编号 from reader_cate where 种类名称 = '博士生')

select 书籍编号,书籍名称,作者名称,出版日期,(select 类别名称 from book_cate where 类别编号=book.书籍类别)as 书籍类别名称 from book where 出版社名称 = '机械工业出版社'

select 读者编号,读者姓名,工作单位,电话号码,邮件地址,借书日期,还书日期 from reader,borrow_relatio
