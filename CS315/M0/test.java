
public class test {
    public static void main(String args[]) {
		mystery(3, 11);

	}
public static int mystery(int a, int b) {
		if (b==0) return 0;
		if (b%2 == 0){
			int testa = a+a;
			int testb = b/2;
			System.out.print("Mystery(a,b) " + String.valueOf(testa)+ " " + String.valueOf(testb));
			return mystery(a+a, b/2);
		}else{
			int testa = a+a;
			int testb = b/2;
			System.out.println("Mystery(a/a,b/2) + a " + String.valueOf(testa)+ " " + String.valueOf(testb) + " " + String.valueOf(a));
		return mystery(a+a, b/2) + a;
		}
	}


}
