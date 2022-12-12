
public class BinarySearch{
	public static void main(String[] args){
		
		int key;	
	
		System.out.println("Beginning Recursive Binary Search");

		key = Integer.parseInt(args[0]);


		System.out.println("Key: " + args[0]);	
		// allocate new array for data_array
		int[] data_array = new int[args.length - 1];
		//Input values into new array from args
		for(int i=1;i<args.length;i++){
			data_array[i-1] = Integer.parseInt(args[i]);		
		}
		// Quick printing of data array
		System.out.print("Data Array: ");
		for(int i = 0; i<data_array.length;i++){
			System.out.print(""+String.valueOf(data_array[i]));
			System.out.print(" ");
		}
		// We now have the key and the data_array parsed. Begin Recursive Binary Search
		//
		System.out.println();	
		int result_from_recursive_binary_search = recursive_binary_search(key, data_array, 0, data_array.length);
		if(result_from_recursive_binary_search == -1){
			System.out.println("Element was not found in data array: " + String.valueOf(result_from_recursive_binary_search));

		}
		else{
			System.out.println("Key found at index: " + String.valueOf(result_from_recursive_binary_search));
		}

	}


	public static int recursive_binary_search(int key, int[] data_array, int low, int high){
		if(low>high){
			return -1; // If the key is not found, return -1
		}
		else{
			int mid = low + (high-low) / 2;
			if(key<data_array[mid]){
				return recursive_binary_search(key, data_array, low, (mid-1)); // Recurse Left
			}
			else if(key>data_array[mid]){
				return recursive_binary_search(key, data_array, (mid+1), high); // Recurse Right
			}
			else
				return mid;
		}
	}



}
