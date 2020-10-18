# Database

#### [175. 组合两个表](https://leetcode-cn.com/problems/combine-two-tables/)

表1: Person

```
+-------------+---------+
| 列名         | 类型    |
+-------------+---------+
| PersonId    | int     |
| FirstName   | varchar |
| LastName    | varchar |
+-------------+---------+
PersonId 是上表主键
```


表2: Address

```
+-------------+---------+
| 列名         | 类型    |
+-------------+---------+
| AddressId   | int     |
| PersonId    | int     |
| City        | varchar |
| State       | varchar |
+-------------+---------+
AddressId 是上表主键
```


编写一个 SQL 查询，满足条件：无论 person 是否有地址信息，都需要基于上述两表提供 person 的以下信息：

```
FirstName, LastName, City, State
```

MySQL query statement below:

```mysql
select FirstName, LastName, City, State 

from Person left join Address 

on Person.PersonId = Address.PersonId

;
```

![](./images/multiTabel.png)

```mysql
select ... from 表1 as a full outer join 表2 as b on a.列名=b.列名
select ... from 表1 as a full outer join 表2 as b on a.列名=b.列名 where a.列名 is null or b.列名 is null
```

