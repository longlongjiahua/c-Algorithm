import java.util.ArrayList;
import java.util.Arrays;
import java.util.Collections;
import java.util.Scanner;
//solved 
//implement comparator
class Main {
	private static class One implements Comparable<One> {
		public int d;
		public int idx;
		public One(int x, int y) {
			this.d =x;
			this.idx = y;
		}
		public int compareTo( One a){
			return d-a.d;
		}
	}
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		int Case=0;
		while (true) {
			Case++;
			int n = sc.nextInt();
			int l = sc.nextInt();
			int r = sc.nextInt();
			if(n ==l && n==r && n==0) break;
			System.out.println("Case "+Case);
			ArrayList<One> mList = new ArrayList<One>();
			for(int i=1; i<=n; i++) {
				One mOne = new One(sc.nextInt(), i);
				mList.add(mOne);
			}
			Collections.sort(mList);	
			ArrayList<Integer> mL = new ArrayList<Integer>();
			for(int i=0; i<l; i++) mL.add(mList.get(i).idx);
			Collections.sort(mL);
			String out="";
			for(int i=0; i<l-1; i++)	out += mL.get(i) + " ";
			System.out.println(out + mL.get(l-1));
			mL.clear();
			for(int i=n-r; i<n; i++) mL.add(mList.get(i).idx);
			out ="";
			Collections.sort(mL); Collections.reverse(mL);
			for(int i=0; i<r-1; i++) out +=mL.get(i) + " ";
			System.out.println(out + mL.get(r-1));
					
						

		}
	}
}

