package mooc_week_1;

public class Fraction {
	public Fraction(int a,int b) 
	{
		
		fenmu = b;
		fenzi = a;
		gcd();
	}
	
	public double toDouble() 
	{
		return fenzi/(double)fenmu;
		
	}
	public Fraction plus(Fraction r)
	{
		int t_fenzi;
		int t_fenmu;
		t_fenmu = fenmu * r.fenmu;
		t_fenzi = fenzi * r.fenmu + r.fenzi * fenmu;
		return new Fraction(t_fenzi,t_fenmu);
	}
	public Fraction multiply(Fraction r)
	{
		int t_fenzi = fenzi * r.fenzi;
		int t_fenmu = fenmu * r.fenmu;
		return new Fraction(t_fenzi, t_fenmu);
		
	}
	public void print()
	{
		if (fenzi!= fenmu &&fenzi%fenmu!=0)
		{
			System.out.println(fenzi+"/"+fenmu);
		}
		if(fenzi%fenmu==0)
		{
			System.out.println(fenzi);
		}
	}
	 void gcd()
	{
		 int m =fenzi;
		 int n = fenmu;
		  if (m<n){
		   int t = n;
		   n = m;
		   m = t;
		  }
		  int r;
		  do{
		  r = m % n;
		  m = n;
		  n = r;
		  }while (r != 0);
		  fenzi = fenzi /m;
		  fenmu = fenmu /m;
	}
	private int fenzi,fenmu;
}
