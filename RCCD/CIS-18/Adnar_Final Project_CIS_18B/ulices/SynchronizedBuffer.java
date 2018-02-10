// Fig. 26.16: SynchronizedBuffer.java
// Synchronizing access to shared data using Object 
// methods wait and notifyAll.
public class SynchronizedBuffer
{
   private int buffer = -1; // shared by producer and consumer threads
   private boolean occupied = false;// whether the buffer is occupied
   
   // place value into buffer
   public synchronized void set( int value ) throws InterruptedException
   {
      // while there are no empty locations, place thread in waiting state
      while ( occupied ) 
      {
         // output thread information and buffer information, then wait
         System.out.println( "Admin tries to write." );
         displayState( "Buffer full. Admin waits." );
         wait();
      } // end while
        
      buffer = value; // set new buffer value
        
      // indicate producer cannot store another value
      // until consumer retrieves current buffer value
      occupied = true;
        
      displayState( "Admin writes " + buffer );
      
      notifyAll(); // tell waiting thread(s) to enter runnable state
   } // end method set; releases lock on SynchronizedBuffer 
    
   // return value from buffer
   public synchronized int get() throws InterruptedException
   {
      // while no data to read, place thread in waiting state
      while ( !occupied )
      {
         // output thread information and buffer information, then wait
         System.out.println( "EmployeeTable tries to read." );
         displayState( "Buffer empty. Employeetable waits." );
         wait();
      } // end while

      // indicate that producer can store another value 
      // because consumer just retrieved buffer value
      occupied = false;

      displayState( "Employeetable reads " + buffer );
      
      notifyAll(); // tell waiting thread(s) to enter runnable state

      return buffer;
   } // end method get; releases lock on SynchronizedBuffer 
    
   // display current operation and buffer state
   public void displayState( String operation )
   {
      System.out.printf( "%-40s%d\t\t%b\n\n", operation, buffer, 
         occupied );
   } // end method displayState
} // end class SynchronizedBuffer
