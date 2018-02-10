// File Name : MaximumNumber.java

public class MaximumNumber implements Runnable
{
   private int[] number;
   public MaximumNumber(int[] number)
   {
      this.number = number;
   }
   public void run()
   {
      int largest = number[0];
	  for(int i=1; i< number.length; i++)
        {
           if(number[i] > largest)
            largest = number[i];            
        }
		System.out.println("Largest Number is : " + largest);
   }
}