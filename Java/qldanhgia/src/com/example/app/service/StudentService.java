package com.example.app.service;
import com.example.app.model.Student;
import com.example.app.dao.Studentdao;
public class StudentService {
    private StudentDao studentDao;
    public StudentService(StudentDao studentDao){
        this.studentDao = studentDao;
    }
    public void saveStudent(Student student){
        studentDao.saveStudent(student);
    }
}