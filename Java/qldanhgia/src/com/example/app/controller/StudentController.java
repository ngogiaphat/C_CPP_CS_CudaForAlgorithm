package com.example.app.controller;
import com.example.app.model.Student;
import com.example.app.service.StudentService;
public class StudentController {
    private StudentService studentService;
    public StudentController(StudentService studentService){
        this.studentService = studentService;
    }
    public void handleAddStudentRequest(String name, int age){
        // create a new student object
        Student student = new Student(name, age);
        // pass the student object to the service layer for saving
        studentService.saveStudent(student);
        // handle the response or perform any additional actions
    }
    // other methods related to student controller
}