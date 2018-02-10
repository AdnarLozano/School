import java.util.concurrent.ExecutorService;
import java.util.concurrent.Executors;


public class EmployeeQuery {


public static void main( String[] args ) 
{
	ExecutorService application = Executors.newCachedThreadPool(); // create thread pool
	
	SynchronizedBuffer sharedLocation = new SynchronizedBuffer();
	

   
   application.execute( new AddEmployees( sharedLocation) );
   application.execute(new ViewEmployees( sharedLocation) );
   application.shutdown();
}
}
