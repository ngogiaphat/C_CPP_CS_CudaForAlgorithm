using System;
using System.Collections.Generic;
class Program {
    static int POPULATION_SIZE = 50;
    static int NUMBER_OF_GENERATIONS = 100;
    static double MUTATION_RATE = 0.01;
    static Random random = new Random();
    static void Main(string[] args){
        //Initialize the population
        List<Duck> population = new List<Duck>();
        for(int i = 0; i < POPULATION_SIZE; i++){
            population.Add(new Duck());
        }
        //Evolve the population across generations
        for(int i = 0; i < NUMBER_OF_GENERATIONS; i++){
            // Evaluate the fitness of each individual in the population
            foreach (Duck duck in population){
                duck.Fitness = duck.CalculateFitness();
            }
            // Create a new population through selection and crossover
            List<Duck> newPopulation = new List<Duck>();
            for(int j = 0; j < POPULATION_SIZE; j++){
                Duck parent1 = SelectParent(population);
                Duck parent2 = SelectParent(population);
                Duck child = parent1.Crossover(parent2);
                newPopulation.Add(child);
            }
            //Mutate the new population
            foreach(Duck duck in newPopulation){
                duck.Mutate(MUTATION_RATE);
            }

            //Replace the old population with the new population
            population = newPopulation;
        }
        //Find the best individual in the final population
        double bestFitness = double.MinValue;
        Duck bestDuck = null;
        foreach(Duck duck in population){
            double fitness = duck.CalculateFitness();
            if(fitness > bestFitness){
                bestFitness = fitness;
                bestDuck = duck;
            }
        }
        Console.WriteLine("Best duck found:");
        Console.WriteLine(bestDuck.ToString());
    }
    static Duck SelectParent(List<Duck> population){
        //Tournament selection: choose two individuals at random and return the fitter one
        int index1 = random.Next(POPULATION_SIZE);
        int index2 = random.Next(POPULATION_SIZE);
        if(population[index1].Fitness > population[index2].Fitness){
            return population[index1];
        }
        else {
            return population[index2];
        }
    }
}
class Duck {
    static int GENOME_SIZE = 20;
    static Random random = new Random();
    private bool[] genome;
    public double Fitness { get; set; }
    public Duck(){
        genome = new bool[GENOME_SIZE];
        for(int i = 0; i < GENOME_SIZE; i++){
            genome[i] = random.NextDouble() < 0.5;
        }
    }
    public double CalculateFitness(){
        //Fitness function: the number of 'true' values in the genome
        int count = 0;
        foreach(bool gene in genome){
            if(gene){
                count++;
            }
        }
        return count;
    }
    public Duck Crossover(Duck otherParent){
        //Single-point crossover: choose a random point and exchange genes after that point
        int crossoverPoint = random.Next(GENOME_SIZE);
        Duck child = new Duck();
        for(int i = 0; i < GENOME_SIZE; i++){
            if(i < crossoverPoint){
                child.genome[i] = genome[i];
            }
            else {
                child.genome[i] = otherParent.genome[i];
            }
        }
        return child;
    }
}