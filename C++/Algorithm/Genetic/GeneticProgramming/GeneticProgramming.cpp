#include <iostream>
#include <cmath>
#include <vector>
#include <algorithm>
#include <ctime>
using namespace std;
const int POPULATION_SIZE = 1000;
const int CHROMOSOME_LENGTH = 50;
const int MAX_GENERATIONS = 100;
const double MUTATION_PROBABILITY = 0.1;
const double CROSSOVER_PROBABILITY = 0.8;
const double FITNESS_TARGET = 0.0;
double target_function(double x){
    return sin(x) + cos(2 * x);
}
double fitness_function(const vector<double>& chromosome){
    double sum = 0.0;
    for(int i = 0; i < CHROMOSOME_LENGTH; ++i){
        double x = (double)i / double(CHROMOSOME_LENGTH) * 10.0;
        sum += pow(chromosome[i] - target_function(x), 2.0);
    }
    return sqrt(sum / CHROMOSOME_LENGTH);
}
void initialize_population(vector<vector<double>>& population){
    for(int i = 0; i < POPULATION_SIZE; ++i){
        population.emplace_back(CHROMOSOME_LENGTH);
        for(int j = 0; j < CHROMOSOME_LENGTH; ++j){
            population.back()[j] = -0.5 + static_cast<double>(rand()) / (static_cast<double>(RAND_MAX / (1.0 - -0.5)));
        }
    }
}
bool sort_by_fitness(const vector<double>& a, const vector<double>& b){
    return fitness_function(a) < fitness_function(b);
}
vector<double> select_parent(const vector<vector<double>>& population){
    double total_fitness = 0.0;
    for(const auto& chromosome : population){
        total_fitness += fitness_function(chromosome);
    }
    double random_fitness = static_cast<double>(rand()) / static_cast<double>(RAND_MAX) * total_fitness;
    for(const auto& chromosome : population){
        random_fitness -= fitness_function(chromosome);
        if (random_fitness < 0.0){
            return chromosome;
        }
    }
    return population.back();
}
vector<double> reproduce(const vector<double>& parent1, const vector<double>& parent2){
    vector<double> offspring(CHROMOSOME_LENGTH);
    for(int i = 0; i < CHROMOSOME_LENGTH; ++i){
        if(static_cast<double>(rand()) / static_cast<double>(RAND_MAX) < CROSSOVER_PROBABILITY){
            offspring[i] = parent1[i];
        } 
        else {
            offspring[i] = parent2[i];
        }
        if (static_cast<double>(rand()) / static_cast<double>(RAND_MAX) < MUTATION_PROBABILITY){
            double mutation = -0.5 + static_cast<double>(rand()) / (static_cast<double>(RAND_MAX / (1.0 - -0.5)));
            offspring[i] += mutation;
            if(offspring[i] < -0.5){
                offspring[i] = -0.5;
            }
            if(offspring[i] > 0.5){
                offspring[i] = 0.5;
            }
        }
    }
    return offspring;
}
void evolve_population(vector<vector<double>>& population){
    sort(population.begin(), population.end(), sort_by_fitness);
    if(fitness_function(population.front()) <= FITNESS_TARGET){
        return;
    }
    vector<vector<double>> new_population;
    new_population.reserve(POPULATION_SIZE);
    new_population.push_back(population.front());
    while(new_population.size() < POPULATION_SIZE){
        vector<double> parent1 = select_parent(population);
        vector<double> parent2 = select_parent(population);
        vector offspring = reproduce(parent1, parent2);
        new_population.push_back(offspring);
    }
    population = new_population;
}
int main(){
    srand(static_cast(time(nullptr)));
    vector<vector<double>> population;
    initialize_population(population);
    for(int generation = 0; generation < MAX_GENERATIONS; ++generation){
        evolve_population(population);
        if(generation % 10 == 0){
            double best_fitness = fitness_function(population.front());
            cout << "Generation " << generation + 1 << ", Best Fitness: " << best_fitness << endl;
        }
        if(fitness_function(population.front()) <= FITNESS_TARGET){
            cout << "Solution Found!" << endl;
            break;
        }
    }
    double x = 0.0;
    double y = target_function(x);
    for(int i = 0; i < CHROMOSOME_LENGTH; ++i){
        x = (double)i / double(CHROMOSOME_LENGTH) * 10.0;
        y = population.front()[i];
        cout << "x: " << x << ", y: " << y << endl;
    }
    return 0;
}