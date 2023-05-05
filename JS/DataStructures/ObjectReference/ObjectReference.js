//Create objec Employee
let employee1 = {
    name: "John Doe",
    age: 30,
    salary: 1000
};
//Create array of employees and add Employee to the array
let employees = [employee1];
//Get a reference to the selected employee and change that employee's salary
let selectedEmployee = employees[0];
selectedEmployee.salary = 1500;
//Check the salary value of that employee
console.log(employee1.salary); // Output: 1500