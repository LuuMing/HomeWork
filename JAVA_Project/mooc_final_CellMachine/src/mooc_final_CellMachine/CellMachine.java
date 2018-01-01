package mooc_final_CellMachine;

import java.awt.List;
import java.util.ArrayList;
import java.util.Scanner;
import java.util.WeakHashMap;

public class CellMachine {

	Integer map[][];
	int height;
	int width;
	public Integer[] getNeighbour(int row,int col) {
		ArrayList<Integer> list = new ArrayList<Integer>();
		for(int i=-1; i<2; i++)
		{
			for(int j=-1; j<2; j++)
			{
				int r = row +i;
				int c = col+j;
				if( r>-1 && r<height && c>-1 && c<width &&!(r==row&&c==col))
				{
					list.add(map[r][c]);
				}
			}
		}
		return list.toArray(new Integer[list.size()]);
	}
	
	public CellMachine(int a, int b) {
	Scanner scanner = new Scanner(System.in);
	height = a;
	width = b;
	map = new Integer[a][b];
	for(Integer[] c:map)
	{
		for(int i = 0 ;i<width;i++)
		{
			c[i] =new Integer(0);
		}
	}
	int c = 0,d = 0;
		while (((c=scanner.nextInt())!=-1)&&((d=scanner.nextInt())!=-1)) 
		{
			map[c][d] = 1;
		}
	
	}
	
	public CellMachine(CellMachine old) 
	{
		this.height = old.height;
		this.width = old.width;
		this.map = old.map;
	} 
	public int getLive()
	{
		int l = 0;
		for(int i=0;i<height;i++)
		{
			for(int j =0 ;j<width;j++)
			{
				if(map[i][j].equals(1))
					l++;
			}
		}
		return l;
	}
	public CellMachine step() {
		CellMachine newCellMachine = new CellMachine(this);
		for(int i = 0;i<height;i++)
		{
			for(int j = 0; j < width; j++ )
			{//±ãÀûÕû¸öÏ¸°û
				int alive = 0;
				Integer neighbor[] = getNeighbour(i, j);
				for (Integer c:neighbor)
				{
					if(c.equals(1))
					{
						alive++;
					}
				}
				if(map[i][j].equals(1))
				{
					if( alive==2 || alive==3)
					{
						newCellMachine.map[i][j]=1;
					}
					else if(alive>3||alive<2)
					{
						newCellMachine.map[i][j]=0;
					}
				}else if ( alive==3 )
				{
					newCellMachine.map[i][j] = 1;
				}
			}
		}
		return newCellMachine;
	}
	
	
	
	
	
	public static void main(String[] args) {
		int a,b,c;
		Scanner scanner = new Scanner(System.in);
		a = scanner.nextInt();
		b = scanner.nextInt();
		CellMachine ca = new CellMachine(a, b);
		c = scanner.nextInt();
		for(int i = 0; i<c;i++)
		{
			ca = ca.step();
		}
		System.out.print(ca.getLive());
	}

}




