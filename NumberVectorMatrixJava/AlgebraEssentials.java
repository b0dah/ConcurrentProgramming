import java.util.*;

class AlgebraEssentials {
	
	static ArrayList<Integer> vectorByNumber(ArrayList<Integer> vect, int number) {
		
		ArrayList <Integer> result = new ArrayList<>();

		for (int i=0; i<vect.size(); i++)
			result.add(vect.get(i) * number);
		return result;
	}
	
	static int vectorByVector(ArrayList<Integer> first, ArrayList<Integer> second) {
	// Scalar multiplication
		int result = 0;
		
		for (int i=0; i<first.size(); i++)
			result += first.get(i) * second.get(i);
		
		return result;
	}

	// MARK:- Matrix operations

	static ArrayList<ArrayList<Integer>> matrixByNumber(ArrayList<ArrayList<Integer>> matrix, int number) {
		ArrayList<ArrayList<Integer>> result = new ArrayList<>();
		
		for (int i=0; i<matrix.size(); i++) {
			ArrayList<Integer> currentLine = new ArrayList<>();
			for (int j=0; j<matrix.size(); j++) {
//				result[i][j] = matrix[i][j] * number;
				currentLine.add(matrix.get(i).get(j)*number);
			}
			result.add(currentLine);
		}
		
		return result;
	}

	static ArrayList<Integer> matrixByVector(ArrayList<ArrayList<Integer>> matrix, ArrayList<Integer> vect) {
		ArrayList<Integer> result = new ArrayList<>();
		
		for (int i=0; i<matrix.size(); i++) {
			result.add(0);
			for (int j=0; j<vect.size(); j++) {
//				result[i] += matrix[i][j] * vect[j];
				result.set(i, result.get(i) + matrix.get(i).get(j) * vect.get(j));
			}
		}
				
		return result;
	}

	static ArrayList<ArrayList<Integer>> matrixByMatrix(ArrayList<ArrayList<Integer>> first, ArrayList<ArrayList<Integer>> second) {
		ArrayList<ArrayList<Integer>> result = new ArrayList<>();
		
		// row number for first = col number for second and
		for (int i=0; i<first.size(); i++) {
			ArrayList<Integer> currentLine = new ArrayList<>();
			for (int j=0; j<second.size(); j++) {
				currentLine.add(0);
				for (int k=0; k<second.size(); k++) {
//					result[i][j] += first[i][k] * second[k][j];
					currentLine.set(j, currentLine.get(j) + first.get(i).get(k) * second.get(k).get(j));
				}
			}
			result.add(currentLine);
		}
		
		return result;
	}

	
	
	
	public static void main(String[] args) {
		ArrayList<Integer> vector1 = new ArrayList<>(Arrays.asList(1,2,3));
//		ArrayList<Integer> vector2 = new ArrayList<>(Arrays.asList(1,2,3));
//
//
//		OutputEssentials.prettyVectorOutput(result);
//		
//		int scalarMultiplication = vectorByVector(vector1, vector2);
//		System.out.println(scalarMultiplication);
		
		ArrayList<ArrayList<Integer>> matrix = Generation.generateRandomMatrix(3, 3, 3);
		OutputEssentials.prettyMatrixOutput(matrix);
//		
//		ArrayList<ArrayList<Integer>> result = matrixByNumber(matrix, 10);
//		OutputEssentials.prettyMatrixOutput(result);
		
		OutputEssentials.prettyVectorOutput(vector1);
		
		ArrayList<Integer> result = matrixByVector(matrix, vector1);
		OutputEssentials.prettyVectorOutput(result);
		

	}
	
}