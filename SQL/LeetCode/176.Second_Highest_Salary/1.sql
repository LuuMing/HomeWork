select MAX(Salary) as SecondHighestSalary from Employee where Salary not in (select MAX(Salary) from Employee);
