import java.lang.Math;
import java.util.ArrayList;
import java.util.stream.IntStream;

// Not the best example, but if you are looking for bare bones, this is it
class geneticAlgorithm {
    private static ArrayList<int[]> population;

    // These values can be modified 
    private static int tournSize = 15;
    private static int length = 15;
    private static double chanceOfMutation = .25;
    private static int numParents = 3;
    private static int popSize = 50;


    public static void main(String[] args) {
        int[] result = geneticAlgorithmRun();
        for (int value: result){
            System.out.println(value);
        }
    }

    public static int[] geneticAlgorithmRun(, int iterations) {
        initializePop(popSize);

        ArrayList<int[]> best;
        for (int i=0; i<iterations; i++) {
            best = selection(popSize);
            population = crossover(best, popSize);
            mutate(popSize);
        }
        return population.get(0);
    }

    private static ArrayList<int[]> crossover(ArrayList<int[]> parents, int popSize) {
        ArrayList<int[]> newPop = new ArrayList<int[]>();
        newPop.addAll(parents);
        for (int i: IntStream.range(0, popSize-parents.size()).toArray()) {
            int[] temp = new int[length];
            for (int j: IntStream.range(0, length).toArray()) {
                temp[j]=parents.get((int) (Math.random() * parents.size()))[j];
            }
            newPop.add(temp);
        }
        return newPop;
    }

    private static void mutate(int popSize) {
        for (int i: IntStream.range(0, popSize).toArray()) {
            for (int j: IntStream.range(0, length).toArray()) {
                if (Math.random()<=chanceOfMutation) {
                    population.get(i)[j] += Math.round(population.get(i)[j]*(Math.random()-.5));
                }
            }
        }
    }

    private static ArrayList<int[]> selection(int popSize) {
        ArrayList<int[]> parents = new ArrayList<int[]>();
        ArrayList<Integer> selections = new ArrayList<Integer>();
        for (int j: IntStream.range(0, numParents).toArray()){
            for (int i: IntStream.range(0, tournSize).toArray()) {
                selections.add((int) (Math.random() * popSize));
            }
            int topI = 0;
            int topScore = 0;

            for (int i: selections){
                if (fitnessFunction(population.get(i))>topScore) {
                    topScore = fitnessFunction(population.get(i));
                    topI = i;
                }
            }
            parents.add(population.get(topI));
            selections.clear();
        }
        return parents;
    }

    private static void initializePop(int popSize) {
        population = new ArrayList<int[]>();
        for(int i=0; i<popSize; i++) {
            int[] chrome = new int[length];
            for (int j=0; j<length; j++) {
                chrome[j] = (int)(Math.random()*10);
            }
            population.add(chrome);
        }
    }

    // Example function of how close is each of its values to 5
    private static int fitnessFunction(int[] chromesome) {
        int total = 0;
        for (int i: chromesome) {
            total += 5-Math.abs(5-i);
        }
        return total;
    }
}