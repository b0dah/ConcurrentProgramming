import java.util.*;

class Generation {
	
	static int generateRandomNumber(int lessThan) {
		Random random = new Random();
		return random.nextInt(lessThan);
	}
	
	static ArrayList<Integer> generateRandomVector(int size, int threshold) {
		ArrayList<Integer> result = new ArrayList<>();
		Random random = new Random();
		
		for (int i=0; i<size; i++)
			result.add(random.nextInt(threshold));
		
		return result;
	}
	
	
	static ArrayList<ArrayList<Integer>> generateRandomMatrix(int rows, int cols, int threshold) {
		ArrayList<ArrayList<Integer>> result = new ArrayList<>();
		
		for (int i=0; i<rows; i++) 
				result.add(generateRandomVector(cols, threshold));
	
		return result;
	}
	
	
	
	
	public static void main(String[] args) {
		ArrayList<Integer> v = generateRandomVector(10, 10);
		
		OutputEssentials.prettyVectorOutput(v);
		
		ArrayList<ArrayList<Integer>> m = generateRandomMatrix(5, 5, 10);
		OutputEssentials.prettyMatrixOutput(m);
	}
	
	
}