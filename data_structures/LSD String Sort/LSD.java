public class LSD{
	private int count[];
	private String aux[];
	private String array[];
	private int R=256;
	
	public String[] sort(String[] a,int W){
		int N=a.length;
		aux=new String[N];
		for(int d=W-1;d>=0;d--){
			count=new int[R+1];

			for(int i=0;i<N;i++){
				count[a[i].charAt(d)+1]++;
			}

			for (int r=0;r<R;r++) {
				count[r+1]+=count[r];
			}

			for (int i=0;i<N;i++) {
				aux[count[a[i].charAt(d)]++]=a[i];
				
			}

			for(int i=0;i<N;i++){
				a[i]=aux[i];
			}

		}
		return a;
	}

}