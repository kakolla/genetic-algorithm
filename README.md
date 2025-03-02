<h1>Genetic Optimization Algorithm</h1>
A Genetic algorithm that uses the concept of Chromosome Crossover to generate new, higher-fitness solutions. Solutions are generated until a generation that contains an individual matching the target is produced.

<br></br>
**Limitations of genetic algorithms:** Solutions may converge to local maxima driven by the fitness function that don't represent the target solution. This requires editing some of the hyperparameters including population size, and mutation & survival rate.

## Usage
Run `make` to compile the C++ genetic algorithm <br />
Navigate to /server and run `node server.js` to run the server <br />
Run `npx vite` in /frontend to run the web app

<br></br>
Sources:
https://www.cs.cmu.edu/Groups/AI/util/html/faqs/ai/genetic/part2/faq-doc-2.html
