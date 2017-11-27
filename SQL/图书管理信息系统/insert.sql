use 图书管理信息系统
insert book_cate values(1,'数学','考研 数学','无')
insert book_cate values(2,'语文','考研 语文','无')

insert reader_cate values(1,'老师',30,30,'老师每次最多可借阅30本，期限30天')
insert reader_cate values(2,'学生',10,10,'学生每次最多可借阅10本，期限10天')

insert reader_cate(种类编号,种类名称) values(3,'外来人员')
insert reader(读者编号,读者姓名,读者种类,读者性别,工作单位) values(1,'卢明',2,'男','西安建筑科技大学')
insert book(书籍编号,书籍名称,书籍类别,作者名称,出版社名称) values(1,'考研高数100练',1,'张勇强','西安建筑科技大学出版社')

insert borrow_relation(借阅编号,读者编号,书籍编号,借书日期) values (1,1,1,'2017-11-27')


select * from borrow_relation