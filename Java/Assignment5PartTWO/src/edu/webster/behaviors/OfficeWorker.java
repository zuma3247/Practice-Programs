package edu.webster.behaviors;

public interface OfficeWorker
{
	public void scheduleMeeting( String time, String location);
	
	public void calculatePay(int hoursWorked, float hourlyRate );

}