package com.example.app.service;
import com.example.app.dao.StudentDao;
import com.example.app.model.Student;
import org.junit.Assert;
import org.junit.Test;
public class StudentServiceTest {
    @Test
    public void testSaveStudent(){
        StudentDao studentDao = new StudentDao();
        StudentService studentService = new StudentService(studentDao);
        Student student = new Student("John Doe", 20);
        studentService.saveStudent(student);
        // perform assertions or checks to validate the save operation
    }
}