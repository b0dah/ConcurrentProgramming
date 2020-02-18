import java.util.*;

public class ComputationDemo {
	public static void main(String[] args) {
		
		ArrayList<ArrayList<Integer>> first = Generation.generateRandomMatrix(100, 100, 100);
//		OutputEssentials.prettyMatrixOutput(first);
		ArrayList<ArrayList<Integer>> second = Generation.generateRandomMatrix(100, 100, 100);
//		OutputEssentials.prettyMatrixOutput(second);
		
		Long start = System.currentTimeMillis();
		ArrayList<ArrayList<Integer>> res = AlgebraEssentials.matrixByMatrix(first, second);
		Long end = System.currentTimeMillis();
//		OutputEssentials.prettyMatrixOutput(res);
		
		Long timeTaken = end - start;
		System.out.println("Time take is "+ timeTaken + " ms");
		
	}
}