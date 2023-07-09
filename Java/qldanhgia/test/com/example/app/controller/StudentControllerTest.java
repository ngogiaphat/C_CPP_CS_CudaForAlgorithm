package com.example.app.controller;
import org.junit.Test;
import org.junit.Assert; 
import com.example.app.model.Student; 
import com.example.app.service.StudentService; 
public class StudentControllerTest { 
    @Test 
    public void testHandleAddStudentRequest(){ 
        StudentDao studentDao = new StudentDao(); 
        StudentService studentService = new StudentService(studentDao); 
        StudentController studentController = new StudentController(studentService);
        String name = "John Doe";
        int age = 20;
        studentController.handleAddStudentRequest(name, age);
        // perform assertions or checks to validate the student addition
    }
}   