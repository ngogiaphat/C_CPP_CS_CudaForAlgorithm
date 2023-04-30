#include <iostream>
#include <vector>
#include <algorithm>
#include <random>
struct Individual{
    std::vector<int> genes;
    int fitness;
};
//Evaluation function for each individual
int evaluateFitness(std::vector<int> genes){
    int fitness = 0;
    for(int i = 0; i < genes.size(); i++){
        fitness += genes[i];
    }
    return fitness;
}
//Random individual generation function
Individual generateInvidual(int geneLength){
    std::vector<int> genes(geneLength);
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> dis(0, 1);
    for(int i = 0; i < geneLength; i++){
        genes[i] = distribution(generator);
    }
    Individual individual = {genes, evaluateFitness(genes)};
    return individual;
}
//Select function parents
std::vector<Individual> selection(std::vector<Individual> population){
    std::vector<Individual> parents(2);
    std::random_device rd;
    std::mt19937 generator(rd());
    std::uniform_int_distribution<int> distribution(0, population.size() - 1);
    int parentIndex1 = distribution(generator);
    int parentIndex2 = distribution(generator);
    while (parentIndex2 == parentIndex1){
        parentIndex2 = distribution(generator);
    }
    parents[0] = population[parentIndex1];
    parents[1] = population[parentIndex2];
    return parents;
}
//Hybridization between 2 individuals
Individual crossover(Individual parent1, Individual parent2){
    std::random_device rd;
    std::mt19937 generator(rd());
    std::uniform_int_distribution<int> distribution(0, parent1.genes.size() - 1);
    int crossoverPoint = distribution(generator);
    std::vector<int> childGenes(parent1.genes.size());
    for (int i = 0; i < crossoverPoint; i++){
        childGenes[i] = parent1.genes[i];
    }
    for (int i = crossoverPoint; i < parent1.genes.size(); i++){
        childGenes[i] = parent2.genes[i];
    }
    Individual child = {childGenes, evaluateFitness(childGenes)};
    return child;
}
//Mutation function for an individual
Individual mutation(Individual individual, double mutationRate){
    std::random_device rd;
    std::mt19937 generator(rd());
    std::uniform_real_distribution<double> distribution(0.0, 1.0);
    for (int i = 0; i < individual.genes.size(); i++) {
        double randomValue = distribution(generator);
        if (randomValue < mutationRate) {
            individual.genes[i] = 1 - individual.genes[i];
        }
    }
    individual.fitness = evaluateFitness(individual.genes);
    return individual;
}
//Function that runs the Genetic Algorithm
std::vector<Individual> geneticAlgorithm(int geneLength, int populationSize, double mutationRate, int numGenerations){
    //Initial population initialization
    std::vector<Individual> population(population_size);
}
//Perform crossbreeding operations between individuals to create new generations 
void GeneticAlgorithm::crossover(){
    for (int i = 0; i < POPULATION_SIZE; i++){
        int p1_idx = tournamentSelection();
        int p2_idx = tournamentSelection();
        PopulationMember p1 = population[p1_idx];
        PopulationMember p2 = population[p2_idx];
        PopulationMember child = crossover(p1, p2);
        new_population[i] = child;
    }
}
//Perform a hybrid operation between 2 individuals to create offspring
PopulationMember GeneticAlgorithm::crossover(const PopulationMember& p1, const PopulationMember& p2){
    PopulationMember child;
    //Random cut point selection 
    int cut_point = rand() % (GENOME_LENGTH - 1) + 1;
    //Duplication of genes from p1 up to the cut point 
    for (int i = 0; i < cut_point; i++){
        child.genome[i] = p1.genome[i];
    }
    //Copy genes from p2 from cut to end
    for (int i = cut_point; i < GENOME_LENGTH; i++){
        child.genome[i] = p2.genome[i];
    }
    return child;
}
//Perform mutation operation for some individuals in the new generation 
void GeneticAlgorithm::mutate(){
    for (int i = 0; i < POPULATION_SIZE; i++){
        if (rand() % 100 < MUTATION_RATE){
            new_population[i] = mutate(new_population[i]);
        }
    }
}
//Perform mutation operation for an instance 
PopulationMember GeneticAlgorithm::mutate(const PopulationMember& member){
    PopulationMember mutated_member = member;
    //Selection of gene locations to mutate 
    int mutation_point = rand() % GENOME_LENGTH;
    //Change the value of the gene at the mutation site
    mutated_member.genome[mutation_point] = rand() % (GENE_RANGE * 2) - GENE_RANGE;
    return mutated_member;
}