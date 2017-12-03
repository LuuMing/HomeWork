use LMS;
insert book_cate values('1','数学','考研 数学','无');
insert book_cate values('2','语文','考研 语文','无');
insert book_cate values('3','计算机科学技术','考研 计算机','无');
insert book_cate values('4','机械制造及其自动化','机械制造','无');

insert reader_cate values('1','老师',30,30,'老师每次最多可借阅30本，期限30天');
insert reader_cate values('2','本科生',10,10,'学生每次最多可借阅10本，期限10天');
insert reader_cate values('3','博士生',15,15,'学生每次最多可借阅15本，期限15天');
insert reader_cate(num,name,total) values('4','外来人员',1);

insert reader(num,name,cate,sex,company) values('1','卢明',2,'男','西安建筑科技大学');
insert reader(num,name,cate,sex,company) values('2','张勇强老师',1,'男','西安电子科技大学');
insert reader(num,name,cate,sex,company) values('3','杨佳佳','3','男','北京大学');
insert reader(num,name,cate,sex,company) values('4','张三','4','男','青龙帮');
insert reader(num,name,cate) values('5','徐雨雨','2');
insert reader(num,name,cate) values('r001','郭靖','4');



insert book(num,name,cate,author_name,pub_name) values('1','考研高数100练','1','张勇强','西安建筑科技大学出版社');
insert book(num,name,cate,author_name,pub_name) values('2','考研计算机100练','3','卢明','西安建筑科技大学出版社');
insert book(num,name,cate,author_name,pub_name) values('3','考研计算机精讲','3','卢明','西安建筑科技大学出版社');
insert book(num,name,cate,author_name,pub_name) values('4','计算机与玄学','3','王珊','西安建筑科技大学出版社');
insert book(num,name,cate,author_name,pub_name) values('5','理论力学','4','王四','机械工业出版社');
insert book(num,name,cate,author_name,pub_name) values('B00101','论语','2','孔子','西建大文学出版社');
insert book(num,name,cate) values('6','数据库系统概论','3');

insert borrow_relation(num,reader_num,book_num,out_time) values ('1','1','1','2017-11-27');
insert borrow_relation(num,reader_num,book_num,out_time,in_time) values ('2','1','B00101','2017-11-27','2017-12-01');
insert borrow_relation(num,reader_num,book_num,out_time,in_time) values ('3','2','B00101','2017-12-1','2017-12-02');
insert borrow_relation(num,reader_num,book_num,out_time) values ('4','1','B00101','2017-12-1');
insert borrow_relation(num,reader_num,book_num,out_time) values ('5','3','6','2017-12-3');
insert borrow_relation(num,reader_num,book_num,out_time) values ('6','1','6','2017-12-3');
insert borrow_relation(num,reader_num,book_num,out_time) values ('7','r001','B00101','2017-12-4');

