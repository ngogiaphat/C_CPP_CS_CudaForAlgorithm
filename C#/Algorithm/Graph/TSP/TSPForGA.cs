using System;
using System.Collections.Generic;
using System.Linq;
class TSP_GA {
    static void Main(){
        Console.WriteLine("Nhap so thanh pho: ");
        int n = Int32.Parse(Console.ReadLine());
        int[,] distanceMatrix = RandomMatrix(n);
        Console.WriteLine("Ma tran khoang cach giua cac thanh pho: ");
        PrintMatrix(distanceMatrix);
        GeneticAlgorithm ga = new GeneticAlgorithm(100, 0.01, 0.6, 2, 25);
        int[] solution = ga.FindShortestPath(distanceMatrix, n);
        Console.WriteLine("Duong di ngan nhat: ");
        foreach (int city in solution){
            Console.Write(city + " ");
        }
    }
    public static int[,] RandomMatrix(int n){
        int[,] matrix = new int[n, n];
        Random random = new Random();
        for(int row = 0; row < n; row++){
            for(int col = 0; col < n; col++){
                if(col == row){
                    matrix[row, col] = 0;
                }
                else {
                    matrix[row, col] = random.Next(1, 100);
                    matrix[col, row] = matrix[row, col];
                }
            }
        }
        return matrix;
    }
    public static void PrintMatrix(int[,] matrix){
        for(int row = 0; row < matrix.GetLength(0); row++){
            for(int col = 0; col < matrix.GetLength(1); col++){
                Console.Write(matrix[row, col] + "\t");
            }
            Console.WriteLine("\n");
        }
    }
}
class GeneticAlgorithm {
    private int populationSize;
    private double mutationRate;
    private double crossoverRate;
    private int elitismCount;
    private int tournamentSize;
    public GeneticAlgorithm(int populationSize, double mutationRate, double crossoverRate, int elitismCount, int tournamentSize){
        this.populationSize = populationSize;
        this.mutationRate = mutationRate;
        this.crossoverRate = crossoverRate;
        this.elitismCount = elitismCount;
        this.tournamentSize = tournamentSize;
    }
    public int[] FindShortestPath(int[,] distanceMatrix, int n){
        Population population = new Population(populationSize, n);
        int generationCount = 0;
        while(generationCount < 100){
            population = population.Crossover(crossoverRate, elitismCount, tournamentSize);
            population = population.Mutate(mutationRate);
            generationCount++;
        }
        return population.GetShortestPath(distanceMatrix);
    }
}
class Population {
    private List<Chromosome> chromosomes = new List<Chromosome>();
    private int fittestIndex;
    public Population(int populationSize, int chromosomeLength){
        for (int i = 0; i < populationSize; i++){
            chromosomes.Add(new Chromosome(chromosomeLength));
        }
    }
    public Chromosome GetFittest(){
        Chromosome fittest = chromosomes[0];
        for(int i = 1; i < chromosomes.Count; i++){
            if(fittest.GetFitness() <= chromosomes[i].GetFitness()){
                fittest = chromosomes[i];
                fittestIndex = i;
            }
        }
        return fittest;
    }
    public Chromosome GetSecondFittest(){
        Chromosome fittest = chromosomes[0];
        Chromosome secondFittest = chromosomes[0];
        for(int i = 1; i < chromosomes.Count; i++){
            if(fittest.GetFitness() <= chromosomes[i].GetFitness()){
                secondFittest = fittest;
                fittest = chromosomes[i];
            }
            else if(secondFittest.GetFitness() <= chromosomes[i].GetFitness()){
                secondFittest = chromosomes[i];
            }
        }
        return secondFittest;
    }
    public int GetLeastFittestIndex(){
        int leastFittestIndex = 0;
        for(int i = 1; i < chromosomes.Count; i++){
            if(chromosomes[i].GetFitness() < chromosomes[leastFittestIndex].GetFitness()){
                leastFittestIndex = i;
            }
        }
        return leastFittestIndex;
    }
    public void AddChromosome(Chromosome chromosome){
        chromosomes.Add(chromosome);
    }
    public void RemoveChromosome(int index){
        chromosomes.RemoveAt(index);
    }
    public Chromosome GetChromosome(int index){
        return chromosomes[index];
    }
    public void SetChromosome(int index, Chromosome chromosome){
        chromosomes[index] = chromosome;
    }
    public Population Crossover(double crossoverRate, int elitismCount, int tournamentSize){
        Population newPopulation = new Population(0, chromosomes[0].GetChromosomeLength());
        newPopulation.chromosomes.Clear();
        for(int i = 0; i < elitismCount; i++){
            newPopulation.AddChromosome(chromosomes[GetFittestIndex()]);
        }
        for(int i = elitismCount; i < chromosomes.Count; i++){
            Chromosome parent1 = SelectByTournament(tournamentSize);
            if(crossoverRate > new Random().NextDouble() && i < chromosomes.Count - elitismCount){
                Chromosome parent2 = SelectByTournament(tournamentSize);
                Chromosome child = parent1.Crossover(parent2);
                newPopulation.AddChromosome(child);
            }
            else {
                newPopulation.AddChromosome(parent1);
            }
        }
        return newPopulation;
    }
    public Population Mutate(double mutationRate){
        for(int i = 0; i < chromosomes.Count; i++){
            if(i >= elitismCount){
                for(int j = 0; j < chromosomes[i].GetChromosomeLength(); j++){
                    if(mutationRate > new Random().NextDouble()){
                        chromosomes[i].SetGene(j, new Random().Next(chromosomes[i].GetChromosomeLength()));
                    }
                }
            }
        }

        return this;
    }
    public int GetFittestIndex(){
        GetFittest();
        return fittestIndex;
    }
    public int[] GetShortestPath(int[,] distanceMatrix){
        int[] path = GetFittest().GetChromosome();
        int[] shortestPath = new int[path.Length + 1];
        for(int i = 0; i < path.Length; i++){
            shortestPath[i] = path[i] + 1;
        }
        shortestPath[shortestPath.Length - 1] = path[0] + 1;
        return shortestPath;
    }
    private Chromosome SelectByTournament(int tournamentSize){
        Population tournamentPopulation = new Population(tournamentSize, chromosomes[0].GetChromosomeLength());
        for(int i = 0; i < tournamentSize; i++){
            int randomIndex = new Random().Next(chromosomes.Count);
            tournamentPopulation.SetChromosome(i, chromosomes[randomIndex]);
        }
        return tournamentPopulation.GetFittest();
    }
    public int GetPopulationSize(){
        return chromosomes.Count;
    }
}
class Chromosome{
    private int[] genes;
    private int fitness = 0;
    public Chromosome(int length){
        genes = new int[length];
        Random = new Random();
        for(int i = 0; i < genes.Length; i++){
            genes[i] = i;
        }
        for (int i = 0; i < genes.Length; i++){
            int randomIndex = Random.Next(genes.Length);
            int temp = genes[randomIndex];
            genes[randomIndex] = genes[i];
            genes[i] = temp;
        }
    }
    public Chromosome(int[] genes){
        this.genes = genes;
    }
    public int[] GetChromosome(){
        return genes;
    }
    public int GetChromosomeLength(){
        return genes.Length;
    }
    public int GetFitness(){
        if(fitness == 0){
            fitness = FitnessCalculator.CalculateFitness(this);
        }

        return fitness;
    }
    public void SetGene(int index, int gene){
        genes[index] = gene;
        fitness = 0;
    }
    public int GetGene(int index){
        return genes[index];
    }
    public Chromosome Crossover(Chromosome parent2){
        int[] childGenes = new int[genes.Length];
        int startPos = new Random().Next(genes.Length);
        int endPos = new Random().Next(genes.Length);
        for(int i = 0; i < childGenes.Length; i++){
            if(startPos < endPos && i > startPos && i < endPos){
                childGenes[i] = genes[i];
            }
            else if(startPos > endPos){
                if(!(i < startPos && i > endPos)){
                    childGenes[i] = genes[i];
                }
            }
        }
        for(int i = 0; i < parent2.GetChromosomeLength(); i++){
            if(!childGenes.Contains(parent2.GetGene(i))){
                for(int j = 0; j < childGenes.Length; j++){
                    if(childGenes[j] == 0){
                        childGenes[j] = parent2.GetGene(i);
                        break;
                    }
                }
            }
        }
        return new Chromosome(childGenes);
    }
}