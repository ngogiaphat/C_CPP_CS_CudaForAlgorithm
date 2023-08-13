using System;
// Base class
class Person {
    public string name;
    public int aadhar_id;
    public int age;
    public Person(int aadhar_id, int age, string name){
        this.aadhar_id = aadhar_id;
        this.name = name;
        this.age = age;
    };
};
// Derived class
class Teacher : Person {
    public int teacher_salary;
    public Teacher(int addhar_id, int salary, string name, int age) : base(addhar_id, age, name){
        teacher_salary = salary;
    };
    public void TeacherDetails(){
        Console.WriteLine("teacher ID:      " + aadhar_id);
        Console.WriteLine("teacher Name:    " + name);
        Console.WriteLine("teacher Salary:  " + teacher_salary);`
        Console.WriteLine("teacher Age:     " + age);
    };
};
class Doctor : Person {
    public int doctor_fees;
    public Doctor(int addhar_id, int fees, string name, int age) : base(addhar_id. age, name){
        doctor_fees = fees;
    };
    public void DoctorDetails(){
        Console.WriteLine("Doctor ID:      " + aadhar_id);
        Console.WriteLine("Doctor Name:    " + name);
        Console.WriteLine("Doctor Fees:    " + doctor_fees);
        Console.WriteLine("Doctor Age:     " + age);
    };
};
class RETH {
    static public void Main(){
        // creating objects
        Teacher t = new Teacher(25054, 50000, "Sanjay", 28);
        Doctor d = new Doctor(25045, 750, "Rohit", 32);
        t.TeacherDetails();
        Console.WriteLine("-----------------------------------");
        d.DoctorDetails();
    };
};