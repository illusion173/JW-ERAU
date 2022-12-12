public class test {
	public static void example1(int[] anArray) {
		int n = anArray.length;
		for (int i = 1; i < n; i *= 2) {
			System.out.println(anArray[i]);
		}
	}

	public static void main(String Args[]) {
		int[] arrayone = { 1, 3, 5, 7 };
		int[] arraytwo = { 1, 2, 3, 4, 5, 6, 7, 8 };
		example1(arrayone);
		System.out.println("NEXT");
		example1(arraytwo);
	}
}
