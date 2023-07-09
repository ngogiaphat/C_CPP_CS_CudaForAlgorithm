package com.example.app;
import com.example.app.dao.StudentDao;
import com.example.app.service.StudentService;
import com.example.app.controller.StudentController;
public class Main {
    public static void main(String[] args){
        // initialize the dependencies
        StudentDao studentDao = new StudentDao();
        StudentService studentService = new StudentService(studentDao);
        StudentController studentController = new StudentController(studentService);
        // perform the desired application logic using the controller
        studentController.handleAddStudentRequest("John Doe", 20);
    }
}