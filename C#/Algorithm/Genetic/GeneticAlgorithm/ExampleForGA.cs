using System;
class Program {
    static int populationSize = 10;
    static int chromosomeLength = 8;
    static double mutationRate = 0.1;
    static Random random = new Random();
    static void Main(string[] args)
    int[][] population = InitializePopulation();
    for(int generation = 0; generation < 100; generation++){
        double[] fitnessScores = EvaluateFitness(population);
        int[][] selectedParents = SelectedParents(population, fitnessScores);
        int[][] offspring = Reproduce(selectedParents);
        Mutate(offspring);
        population = offspring;
        int bestFitnessIndex = GetBestFitnessIndex(fitnessScores);
        Console.WriteLine("Generation {0}: Best fitness = {1}" , generation, fitnessScores[bestFitnessIndex]);
    }
    Console.ReadLine();
}
static int[][] InitializePopulation(){
    int[][] population = new int[populationSize][];
    for(int i = 0; i < populationSize; i++){
        population[i] = new int[chromosomeLength];
        for(int j = 0; j < chromosomeLength; j++){
            population[i][j] = random.Next(2);
        }
    }
    return population;
}
static double[] EvaluateFitness(int[][] population){
    double[] fitnessScores = new double[populationSize];
    for(int i = 0; i < populationSize; i++){
        int[] chromosome = population[i];
        double fitness = 0;
        for(int j = 0; j < chromosomeLength; j++){
            fitness += chromosome[j];
        }
        fitnessScores[i] = fitness;
    }
    return fitnessScores;
}
static int[][] SelectParents(int[][] population, double[] fitnessScores){
    int[][] selectedParents = new int[populationSize][];
    for(int i = 0; i < populationSize; i++){
        int parentIndex = RouletteWheelSelection(fitnessScores);
        selectedParents[i] = (int[])population[parentIndex].Clone();
    }
    return selectedParents;
}
static int RouletteWheelSelection(double[] fitnessScores){
    double totalFitness = 0;
    for(int i = 0; i < populationSize; i++){
        totalFitness += fitnessScores[i];
    }
    cumulativeFitness[0] = fitnessScores[0];
    for(int i = 1; i < populationSize; i++){
        cumulativeFitness[i] = cumulativeFitness[i-1] + fitnessScores[i];
    }
    while(randomValue > cumulativeFitness[parentIndex]){ 
        parentIndex++; 
    }
    return parentIndex;
}
static int[][] Reproduce(int[][] parents){ 
    int[][] offspring = new int[populationSize][];
    for(int i = 0; i < populationSize; i += 2){
        int[] parent1 = parents[i];
        int[] parent2 = parents[i + 1];
        int crossoverPoint = random.Next(1, chromosomeLength - 1);
        int[] child1 = new int[chromosomeLength];
        int[] child2 = new int[chromosomeLength];
        for(int j = 0; j < chromosomeLength; j++){
            if(j < crossoverPoint){
                child1[j] = parent1[j];
                child2[j] = parent2[j];
            }
            else {
                child1[j] = parent2[j];
                child2[j] = parent1[j];
            }
        }
        offspring[i] = child1;
        offspring[i + 1] = child2;
    }
    return offspring;
}
static void Mutate(int[][] population){ 
    for(int i = 0; i < populationSize; i++){ 
        for(int j = 0; j < chromosomeLength; j++){ 
            if(random.NextDouble() < mutationRate){ 
                population[i][j] = 1 - population[i][j]; 
            } 
        } 
    } 
}
static int GetBestFitnessIndex(double[] fitnessScores){ 
    int bestFitnessIndex = 0; double bestFitness = fitnessScores[bestFitnessIndex];
    for(int i = 1; i < populationSize; i++){
        if(fitnessScores[i] > bestFitness){
            bestFitnessIndex = i;
            bestFitness = fitnessScores[bestFitnessIndex];
        }
    }
    return bestFitnessIndex;
}