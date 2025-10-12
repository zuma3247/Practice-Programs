package edu.webster.arrays;

public class Hourly extends Employee
{
    private float hourlyRate;
    private float startTime;
    private float endTime;
    private String address;

    public Hourly(String firstName, String lastName, int empID, float hourlyRate, float startTime, float endTime, String address)
    {
        super(firstName, lastName, empID);
        this.hourlyRate = hourlyRate;
        this.startTime = startTime;
        this.endTime = endTime;
        this.address = address;
    }

    public Hourly()
    {
        super();
        this.hourlyRate = 0f;
        this.startTime = 0;
        this.endTime = 0;
        this.address = "Unknown address";
    }

    public float getHourlyRate() {
        return hourlyRate;
    }

    public void setHourlyRate(float hourlyRate) {
        this.hourlyRate = hourlyRate;
    }

    public float getStartTime() {
        return startTime;
    }

    public void setStartTime(float startTime) {
        this.startTime = startTime;
    }

    public float getEndTime() {
        return endTime;
    }

    public void setEndTime(float endTime) {
        this.endTime = endTime;
    }

    public String getAddress() {
        return address;
    }

    public void setAddress(String address) {
        this.address = address;
    }

    public String toString()
    {
        String output;

        output = super.toString() + "\nHourly Rate: " + getHourlyRate() +
                "\nStart Time: " + getStartTime() +
                "\nEnd Time: " + getEndTime() +
                "\nAddress: " + getAddress();

        return output;
    }
}
