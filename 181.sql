select e.Name as Employee from Employee as e, Employee as m where e.ManagerId = m.Id and e.Salary > m.Salary
