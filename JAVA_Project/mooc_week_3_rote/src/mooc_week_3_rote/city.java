package mooc_week_3_rote;

import java.util.Scanner;
import java.util.ArrayList;
public class city {
	
	public static void main(String[] args) {
		Scanner inScanner = new Scanner(System.in);
		String input = inScanner.next();
		 ArrayList<String> citys = new ArrayList<String>();
		while(!input.equals("###"))
		{
			citys.add(input);
			input = inScanner.next();
		}
		int distance [][] = new int[citys.size()][citys.size()];
		for (int i = 0; i < citys.size(); i++)
		{
			for(int j = 0; j<citys.size(); j++)
			{
				distance[i][j] = inScanner.nextInt();
			}
		}
		String city1 = inScanner.next();
		String city2 = inScanner.next();
		System.out.println(distance[citys.indexOf(city1)][citys.indexOf(city2)]);
	}

}
