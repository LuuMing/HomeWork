use LMS;
insert book_cate values('1','数学','考研 数学','无');
insert book_cate values('2','语文','考研 语文','无');
insert book_cate values('3','计算机科学技术','考研 计算机','无');

insert reader_cate values('1','老师',30,30,'老师每次最多可借阅30本，期限30天');
insert reader_cate values('2','本科生',10,10,'学生每次最多可借阅10本，期限10天');
insert reader_cate values('3','博士生',10,10,'学生每次最多可借阅10本，期限10天');
insert reader_cate(num,name) values('4','外来人员');

insert reader(num,name,cate,sex,company) values('1','卢明',2,'男','西安建筑科技大学');
insert reader(num,name,cate,sex,company) values('2','张勇强老师',1,'男','西安电子科技大学');

insert book(num,name,cate,author_name,pub_name) values('1','考研高数100练',1,'张勇强','西安建筑科技大学出版社');
insert book(num,name,cate,author_name,pub_name) values('2','考研计算机100练',3,'卢明','西安建筑科技大学出版社');
insert book(num,name,cate,author_name,pub_name) values('3','考研计算机精讲',3,'卢明','西安建筑科技大学出版社');
insert book(num,name,cate,author_name,pub_name) values('4','计算机与玄学',3,'王珊','西安建筑科技大学出版社');

insert borrow_relation(num,reader_num,book_num,out_time) values ('1','1','1','2017-11-27');

