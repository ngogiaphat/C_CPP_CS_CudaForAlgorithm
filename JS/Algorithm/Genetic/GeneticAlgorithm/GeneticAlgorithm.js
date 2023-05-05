//Function to be optimized
function fitness(x) {
    return Math.sin(x) * x + 2;
}
//Genetic Algorithm Configuration
const config = {
    populationSize: 50, //Population size
    maxGenerations: 100, //Max generations
    mutationRate: 0.1, //Mutation rate
    crossoverRate: 0.8, //Cross over rate
    elitismCount: 2 //The most valuable individuals will be kept in each generation
};
//Create initial population
function createInitialPopulation() {
    const population = [];
    for (let i = 0; i < config.populationSize; i++) {
        population.push(Math.random() * 20 - 10);
    }
    return population;
}
//Selection parents
function selection(population) {
    //Select any 2 individuals in the population
    const a = population[Math.floor(Math.random() * population.length)];
    const b = population[Math.floor(Math.random() * population.length)];
    //Choose the better individual
    return fitness(a) > fitness(b) ? a : b;
}
//Crossing 2 individuals
    function crossover(a, b) {
    //Hybridization at the average score of 2 individuals
    const child = (a + b) / 2;
    return child;
}
//Mutation
function mutate(a) {
    //Increase or decrease the value of the mutant instance slightly
    return Math.random() < 0.5 ? a + Math.random() : a - Math.random();
}
//Calculate the mean of the population
function getAverageFitness(population) {
    const totalFitness = population.reduce((sum, x) => sum + fitness(x), 0);
    return totalFitness / population.length;
}
//Run Genetic Algorithm
function geneticAlgorithm() {
    let population = createInitialPopulation();
    for (let i = 0; i < config.maxGenerations; i++) {
        //Sort the population in descending order of optimal value
        population.sort((a, b) => fitness(b) - fitness(a));
        //Print results at current generation
        console.log(`Generation ${i}: Best fitness = ${fitness(population[0])}`);
        //Retain the most valuable individuals in the current generation
        const elitism = population.slice(0, config.elitismCount);
        //Create new populations from hybridization and mutation
        const newPopulation = [];
        while (newPopulation.length < config.populationSize - config.elitismCount) {
            const a = selection(population);
            const b = selection(population);
            const child = crossover(a, b, config.crossoverRate);
            mutate(child, config.mutationRate);
            newPopulation.push(child);
        }
        //Add elitism
        const elitePopulation = getFittest(population, config.elitismCount);
        newPopulation = newPopulation.concat(elitePopulation);
        //Sort population by fitness
        newPopulation = sortByFitness(newPopulation);
        //Replace old population with new population
        population = newPopulation;
        //Log best fitness of the generation
        const bestFitness = population[0].fitness;
        console.log(`Generation ${generation}: Best fitness: ${bestFitness}`);
        //Check if target has been reached
        if (bestFitness === target.length) {
        console.log(`Target reached in generation ${generation}!`);
        return population[0].genes.join('');
        }
    }
}