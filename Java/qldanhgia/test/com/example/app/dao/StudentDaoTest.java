package com.example.app.dao;
import com.example.app.model.Student;
import org.junit.Assert;
import org.junit.Test;
public class StudentDaoTest {
    @Test
    public void testSaveStudent(){
        StudentDao studentDao = new StudentDao();
        Student student = new Student("John Doe", 20);
        studentDao.saveStudent(student);
        // perform assertions or checks to validate the save operation
    }
}