package com.example.app.model;
import org.junit.Assert;
import org.junit.Test;
public class StudentTest {
    @Test
    public void testStudentCreation(){
        Student student = new Student("John Doe", 20);
        Assert.assertEquals("John Doe", student.getName());
        Assert.assertEquals(20, student.getAge());
    }
}