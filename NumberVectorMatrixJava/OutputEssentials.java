import java.util.*;

class OutputEssentials {
	
	static void prettyVectorOutput(ArrayList<Integer> v) {
		System.out.print("\t[  ");
		
		for (Integer each : v)
			 System.out.print(each + "  ");
		
		System.out.print("]\n");
	}
	
	static void prettyMatrixOutput(ArrayList<ArrayList<Integer>> matrix) {
		System.out.print("[\n");
		for (ArrayList<Integer> eachLine : matrix) {
			prettyVectorOutput(eachLine);
		}
		System.out.print("]\n");
	}
}