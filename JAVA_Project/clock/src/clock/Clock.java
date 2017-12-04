package clock;

public class Clock 
{
	private Display hour;
	private Display minute;
	private Display second;
	
	public Clock (int hour,int minute,int second) 
	{
		this.hour = new Display(24);
		this.minute = new Display(60);
		this.second = new Display(60);
		this.hour.set(hour);
		this.minute.set(minute);
		this.second.set(second);
	}
	public void tick() 
	{
	
		second.increase();
		if(second.getValue()==0)
		{
			minute.increase();
			if( minute.getValue()==0 )
			{
				hour.increase();
			}	
		}
		
	}
	public String toString()
	{
		
		return String.format("%02d:%02d:%02d",hour.getValue(),minute.getValue(),second.getValue());
	}
	
}
