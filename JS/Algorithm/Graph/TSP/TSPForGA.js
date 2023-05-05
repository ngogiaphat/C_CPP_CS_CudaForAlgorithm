//Declare a constant
const POPULATION_SIZE = 1000; //Population size
const MUTATION_RATE = 0.05; //Mutation rate
const NUM_OF_ELITE_ROUTES = 1; //The best number of routes is retained without participating in hybridization
const TOURNAMENT_SELECTION_SIZE = 5; //Tournament selection size
//Declare global variables
let currentGeneration = [];
//Generates a random place on the map
function createCity(){
  return {
    x: Math.floor(Math.random() * 200),
    y: Math.floor(Math.random() * 200)
  };
}
//Create a route from a list of cities
function createRoute(cityList){
  return {
    cityList,
    distance: 0
  };
}
//Calculate distance between two cities
function getDistance(cityA, cityB){
  const xDistance = Math.abs(cityA.x - cityB.x);
  const yDistance = Math.abs(cityA.y - cityB.y);
  return Math.sqrt(xDistance * xDistance + yDistance * yDistance);
}
//Calculate route length
function calculateRouteDistance(route){
  let totalDistance = 0;
  for (let i = 0; i < route.cityList.length - 1; i++){
    totalDistance += getDistance(route.cityList[i], route.cityList[i + 1]);
  }
  return totalDistance;
}
//Initial population initialization
function initializePopulation(numOfCities){
  const cityList = [];
  for (let i = 0; i < numOfCities; i++){
    cityList.push(createCity());
  }
  for (let i = 0; i < POPULATION_SIZE; i++){
    currentGeneration.push(createRoute(cityList.sort(() => 0.5 - Math.random())));
  }
}
//Sort routes in order of length to short
function sortRoutesByDistance(routeList){
  return routeList.sort((routeA, routeB) => {
    return routeB.distance - routeA.distance;
  });
}
//Perform a hybrid of 2 routes to create 1 new route
function breed(parent1, parent2){
    const offspringCityList = [];
    let startIndex = Math.floor(Math.random() * parent1.cityList.length);
    let endIndex = Math.floor(Math.random() * parent1.cityList.length);
    if (startIndex > endIndex){
        [startIndex, endIndex] = [endIndex, startIndex];
    }
    for (let i = startIndex; i < endIndex; i++){
        offspringCityList.push(parent1.cityList[i]); 
    }
    for (let i = 0; i < parent2.cityList.length; i++){
        const city = parent2.cityList[i]; 
        if (!offspringCityList.includes(city)){
            offspringCityList.push(city);   
        }
    }
    return createRoute(offspringCityList);
}
//Perform route hybridization in the population
function crossover(eliteRoutes){
    const offspringRouteList = [];
    for (let i = 0; i < POPULATION_SIZE - NUM_OF_ELITE_ROUTES; i++){
        const parent1 = eliteRoutes[Math.floor(Math.random() * NUM_OF_ELITE_ROUTES)];
        const parent2 = eliteRoutes[Math.floor(Math.random() * NUM_OF_ELITE_ROUTES)];
        offspringRouteList.push(breed(parent1, parent2));
    }
    return offspringRouteList;
}
//Implement a route mutation
function mutate(route) {
    for (let i = 0; i < route.cityList.length; i++){
      if (Math.random() < MUTATION_RATE){
        const j = Math.floor(Math.random() * route.cityList.length);
        [route.cityList[i], route.cityList[j]] = [route.cityList[j], route.cityList[i]];
      }
    }
}
//Perform mutation on the route in the population
function mutation(routeList){
    for (let i = NUM_OF_ELITE_ROUTES; i < POPULATION_SIZE; i++) {
      mutate(routeList[i]);
    }
}
//Make selections by league
function tournamentSelection(routeList){
    const selectedRouteList = [];
    for (let i = 0; i < TOURNAMENT_SELECTION_SIZE; i++){
      const randomIndex = Math.floor(Math.random() * POPULATION_SIZE);
      selectedRouteList.push(routeList[randomIndex]);
    }
    return sortRoutesByDistance(selectedRouteList)[0];
}
//Implement genetic algorithm
function geneticAlgorithm(numOfCities){
    initializePopulation(numOfCities);
    let generationCount = 1;
    while (generationCount < 100) {
      currentGeneration.forEach(route => {
        route.distance = calculateRouteDistance(route);
      });
      const eliteRoutes = currentGeneration.slice(0, NUM_OF_ELITE_ROUTES);
      const offspringRouteList = crossover(eliteRoutes);
      mutation(offspringRouteList);
      const nextGeneration = eliteRoutes.concat(offspringRouteList);
      currentGeneration = nextGeneration.map(() => tournamentSelection(nextGeneration));
      generationCount++;
    }
    return sortRoutesByDistance(currentGeneration)[0].distance;
}