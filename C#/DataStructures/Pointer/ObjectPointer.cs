class Person {
    public string Name;
    public int Age;
    public void Display(){
        Console.WriteLine(Name + ", " + Age + " tuoi.");
    }
}
class Program {
    static void Main(){
        Person person1 = new Person();
        person1.Name = "John";
        person1.Age = 30;
        Person person2 = person1; //Declare the pointer person2 pointing to the address of person1
        person2.Name = "Jane";
        person2.Age = 25;
        person1.Display(); // output: Jane, 25 tuoi.
    }
}