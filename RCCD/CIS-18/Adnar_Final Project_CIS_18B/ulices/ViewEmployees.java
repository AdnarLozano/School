// Team: Adnar, Ulices & Francisco
// CIS-18B: Adv. Objects
// R. Casolaro
// 5/22/14
// Exercise 25.4: AddEmployees.java


import java.nio.Buffer;
import java.sql.Connection;
import java.sql.Statement;
import java.sql.SQLException;
import java.util.Random;
import java.util.regex.PatternSyntaxException;
import java.awt.FlowLayout;
import java.awt.BorderLayout;
import java.awt.event.ActionListener;
import java.awt.event.ActionEvent;
import java.awt.event.WindowAdapter;
import java.awt.event.WindowEvent;
import javax.swing.Box;
import javax.swing.JFrame;
import javax.swing.JMenu;
import javax.swing.JMenuItem;
import javax.swing.JMenuBar;
import javax.swing.JTable;
import javax.swing.JButton;
import javax.swing.JPanel;
import javax.swing.JLabel;
import javax.swing.JScrollPane;
import javax.swing.JOptionPane;
import javax.swing.JTextField;
import javax.swing.RowFilter;
import javax.swing.TransferHandler;
import javax.swing.table.TableModel;
import javax.swing.table.TableRowSorter;

public class ViewEmployees extends JFrame implements Runnable
{
   // JDBC driver and database URL
   static final String JDBC_DRIVER = "com.mysql.jdbc.Driver";
   static final String DATABASE_URL = "jdbc:mysql://localhost/employees";
   static final String USERNAME = "root";
   static final String PASSWORD = null;

   // default query retrieves all data from employees table
   static final String DEFAULT_QUERY = "SELECT * FROM employees";
   
   private Connection connection;
   private Statement statement;
   private ResultSetTableModel tableModel;
   private JTable table;
   private JButton addEmployee;
   private JButton addSalariedEmployee;
   private JButton addCommissionEmployee;
   private JButton addBasePlusCommissionEmployee;
   private JButton addHourlyEmployee;
   private JButton Refresh;
   private final static Random generator = new Random();
   private final SynchronizedBuffer sharedLocation; // reference to shared object
   private JFrame employeeframe;
   
   private JLabel filterLabel;
   final JTextField filterText = new JTextField();
  
   private JButton filterButton;
   private Box boxSouth;
   private int sum;

   
   public ViewEmployees(SynchronizedBuffer shared)
   {
      super( "Client Table" );

      
      sharedLocation = shared;
      // create ResultSetTableModel with default JDBC driver, 
      // database URL and query
      try 
      {
         // create TableModel for results of query SELECT * FROM employees
         tableModel = new ResultSetTableModel( JDBC_DRIVER, DATABASE_URL, 
            USERNAME, PASSWORD, DEFAULT_QUERY );
         connection = tableModel.getConnection();
        
      } // end try
      catch ( ClassNotFoundException cnfex ) 
      {
         System.err.println( "Failed to load JDBC driver." );
         cnfex.printStackTrace();
         System.exit( 1 );  // terminate program
      } // end catch
      catch ( SQLException sqlex ) 
      {
         System.err.println( "Unable to connect" );
         sqlex.printStackTrace();
         System.exit( 1 );  // terminate program
      } // end catch
     
      

   }// add employee to database
   
   
    private void addEmployee( String query )
   {        
      try 
      {
         statement = connection.createStatement();
         statement.executeUpdate( query ); 
         tableModel.setQuery( DEFAULT_QUERY );
      } // end try
      catch ( SQLException sqlex ) 
      {
         sqlex.printStackTrace();
      } // end catch
   } // end addEmployee

    
  
    
   // inner class ButtonHandler handles button event
   private class ButtonHandler implements ActionListener 
   {
      public void actionPerformed( ActionEvent event )
      {
    	  
    	  if(event.getSource() == Refresh)
    	  {
    		  try {
    			  try 
    		      { int sum;
    		         Thread.sleep( generator.nextInt( 1000 ) );
    		         sum = sharedLocation.get();
    		         if(sum == 1)
    		         {
    		        	 tableModel.setQuery( DEFAULT_QUERY );
    		         }
    		         else 
    		         {
    		        	 
    		         }
    		      } // end try
    		      // if lines 26 or 27 get interrupted, print stack trace
    		      catch ( InterruptedException exception ) 
    		      {
    		         exception.printStackTrace();
    		      } // end catch
				
				
			} catch (IllegalStateException e) {
				// TODO Auto-generated catch block
				e.printStackTrace();
			} catch (SQLException e) {
				// TODO Auto-generated catch block
				e.printStackTrace();
			}
    		  
    		  
    	  }
    	  if(event.getSource() == filterButton)
    	  {
    		  final TableRowSorter<TableModel> sorter;
    		    sorter = new TableRowSorter<TableModel>(tableModel);
    		    table.setRowSorter(sorter);
    		    
                   String text = filterText.getText();

                   if ( text.length() == 0 )
                      sorter.setRowFilter( null );
                   else
                   {
                      try
                      {
                         sorter.setRowFilter( 
                            RowFilter.regexFilter( text ) );
                      } // end try
                      catch ( PatternSyntaxException pse ) 
                      {
                         JOptionPane.showMessageDialog( null,
                            "Bad regex pattern", "Bad regex pattern",
                            JOptionPane.ERROR_MESSAGE );
                      } // end catch
                   } // end else
                 // end method actionPerfomed
    	  }
    	  
    	 
         // add hourly employee to table hourlyEmployees
         else 
         {
            
         } // end else

         // execute insert query and display employee info
         try 
         {

            // display the employee info
            tableModel.setQuery( DEFAULT_QUERY );
         } // end try
         catch ( SQLException exception ) 
         {
            JOptionPane.showMessageDialog( null, exception.toString() );
         } // end catch
      } // end method actionPerformed
      // end check 
   } // end inner class ButtonHandler
  
public void seeEmployees() throws InterruptedException
{
	try 
    {
		employeeframe = new JFrame("Employee Table");
		
       // create TableModel for results of query SELECT * FROM employees
       tableModel = new ResultSetTableModel( JDBC_DRIVER, DATABASE_URL, 
          USERNAME, PASSWORD, DEFAULT_QUERY );
       connection = tableModel.getConnection();
    } // end try
    catch ( ClassNotFoundException cnfex ) 
    {
       System.err.println( "Failed to load JDBC driver." );
       cnfex.printStackTrace();
       System.exit( 1 );  // terminate program
    } // end catch
	catch (SQLException e) {
		// TODO Auto-generated catch block
		e.printStackTrace();
	}
	 table = new JTable( tableModel );
	 setLayout( new BorderLayout() );
	 employeeframe.getContentPane().add( new JScrollPane( table ), BorderLayout.CENTER );
	 employeeframe.getContentPane().add( boxSouth, BorderLayout.SOUTH); //filter not added 

     setSize( 900, 600 );
     setVisible( true );

     // dispose of window when user quits application (this overrides
     // the default of HIDE_ON_CLOSE)
     setDefaultCloseOperation( DISPOSE_ON_CLOSE );
     
     
     // ensure database connection is closed when user quits application
     addWindowListener(
        new WindowAdapter() 
        {
           // disconnect from database and exit when window has closed
           public void windowClosed( WindowEvent event )
           {
              tableModel.disconnectFromDatabase();
              System.exit( 0 );
           } // end method windowClosed
        } // end WindowAdapter inner class
     ); // end call to addWindowListener
  } // end AddEmployees constructor

@Override
public void run() {
	// TODO Auto-generated method stub
	 // if connected to database, set up GUI      
    JPanel topPanel = new JPanel();
  
    Refresh = new JButton ("Refresh");
 
    Refresh.addActionListener(new ButtonHandler() );
    
    topPanel.add(Refresh);
    
    //add filter
    filterLabel = new JLabel( "Filter:" );
    filterText.addActionListener(null);
    
    
    filterButton = new JButton( "Apply Filter" );
    filterButton.addActionListener(new ButtonHandler());
    boxSouth = Box.createHorizontalBox();
    
    boxSouth.add( filterLabel );
    boxSouth.add( filterText );
    boxSouth.add( filterButton );
    
    

    JPanel inputPanel = new JPanel();
    inputPanel.setLayout( new BorderLayout() );
    inputPanel.add( topPanel, BorderLayout.NORTH );

    table = new JTable( tableModel );

    setLayout( new BorderLayout() );
    add( inputPanel, BorderLayout.NORTH ); //button
    add( new JScrollPane( table ), BorderLayout.CENTER ); //table
    add( boxSouth, BorderLayout.SOUTH); //filter

    setSize( 800, 300 );
    setVisible( true );
    
    // dispose of window when user quits application (this overrides
    // the default of HIDE_ON_CLOSE)
    setDefaultCloseOperation( DISPOSE_ON_CLOSE );
   
  
    
    
    // ensure database connection is closed when user quits application
    addWindowListener(
       new WindowAdapter() 
       {
          // disconnect from database and exit when window has closed
          public void windowClosed( WindowEvent event )
          {
             tableModel.disconnectFromDatabase();
             System.exit( 0 );
          } // end method windowClosed
       } // end WindowAdapter inner class
    ); // end call to addWindowListener
    
 } // end AddEmployees constructor



/*
public void checkUpdate(String h) throws InterruptedException
{
	int num;
	
	JOptionPane.showMessageDialog(null,h + " checking for update ");
		
		Refresh.setEnabled(true);
		
	 JOptionPane.showMessageDialog(null,"checked For Update ");
}
 
*/
}
 // end class AddEmployees