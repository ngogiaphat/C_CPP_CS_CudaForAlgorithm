using System;
public class Person {
    public string Name;
    public int Age;
    public void SayHello(){
        Console.WriteLine("Hello, my name is " + Name + " and I am " + Age + " years old.");
    }
}
class Program {
    static void Main(string[] args){
        Person person = new Person();
        person.Name = "John";
        person.Age = 30;
        person.SayHello();
    }
}