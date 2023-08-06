using System;
class Student{
    public string Name;
    public int StudentNumber;
    public Student NextStudent;
    public Student(string name, int studentNumber){
        Name = name;
        StudentNumber = studentNumber;
        NextStudent = null;
    }
}
class ClassList {
    private Student head;
    public ClassList(){
        head = null;
    }
    public void AddStudent(string name, int studentNumber){
        Student newStudent = new Student(name, studentNumber);
        if(head == null){
            head = newStudent;
        }
        else {
            Student currentStudent = head;
            while(currentStudent.NextStudent != null){
                currentStudent = currentStudent.NextStudent;
            }
            currentStudent.NextStudent = newStudent;
        }
    }
    public void RemoveStudent(int studentNumber){
        if(head == null){
            return;
        }
        if(head.StudentNumber == studentNumber){
            head = head.NextStudent;
        }
        else {
            Student previousStudent = head;
            Student currentStudent = head.NextStudent;
            while(currentStudent != null){
                if(currentStudent.StudentNumber == studentNumber){
                    previousStudent.NextStudent = currentStudent.NextStudent;
                    return;
                }
                previousStudent = currentStudent;
                currentStudent = currentStudent.NextStudent;
            }
        }
    }
    public void PrintClassList(){
        if(head == null){
            Console.WriteLine("Class list is empty");
            return;
        }
        Console.WriteLine("Class List:");
        Student currentStudent = head;
        while(currentStudent != null){
            Console.WriteLine("Name: " + currentStudent.Name + ", Student Number: " + currentStudent.StudentNumber);
            currentStudent = currentStudent.NextStudent;
        }
    }
}
class Program {
    static void Main(){
        ClassList myClassList = new ClassList();
        myClassList.AddStudent("John Doe", 123456);
        myClassList.AddStudent("Jane Doe", 789012);
        myClassList.AddStudent("Bob Smith", 345678);
        myClassList.PrintClassList(); // output: Class List: Name: John Doe, Student Number: 123456, Name: Jane Doe, Student Number: 789012, Name: Bob Smith, Student Number: 345678
        myClassList.RemoveStudent(789012);
        myClassList.PrintClassList(); // output: Class List: Name: John Doe, Student Number: 123456, Name: Bob Smith, Student Number: 345678
    }
}