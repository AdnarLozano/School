// Team: Adnar, Ulices & Francisco
// CIS-18B: Adv. Objects
// R. Casolaro
// 5/22/14
// Exercise 25.4: AddEmployees.java

import java.io.*;
import javax.imageio.*;
import javax.swing.ImageIcon;

import java.awt.*;
import java.io.File;
import java.io.IOException;
import java.sql.Connection;
import java.sql.Statement;
import java.sql.SQLException;
import java.util.regex.PatternSyntaxException;
import java.awt.FlowLayout;
import java.awt.BorderLayout;
import java.awt.event.ActionListener;
import java.awt.event.ActionEvent;
import java.awt.event.WindowAdapter;
import java.awt.event.WindowEvent;

import javax.imageio.ImageIO;
import javax.swing.Box;
import javax.swing.ImageIcon;
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

public class AddEmployees extends JFrame 
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
   
   private JFrame frame;
   
   private JLabel filterLabel;
   final JTextField filterText;
  
   private JButton filterButton;
   private Box boxSouth;

   public AddEmployees()
   {
      super( "Welcome to Employee Database Management System" );
                 
      JMenu fileMenu = new JMenu( "File" ); // create file menu
      fileMenu.setMnemonic( 'F' ); // set mnemonic to F

      // create About... menu item
      JMenuItem aboutItem = new JMenuItem( "About..." );
      aboutItem.setMnemonic( 'A' ); // set mnemonic to A
      fileMenu.add( aboutItem ); // add about item to file menu
      aboutItem.addActionListener(

         new ActionListener() // anonymous inner class
         {  
            // display message dialog when user selects About...
            public void actionPerformed( ActionEvent event )
            {
            	            	
               JOptionPane.showMessageDialog( AddEmployees.this,
            		"Employee Database Management System (EDMS)\nVersion 1.4.2\n\n"
                  + "Designed and built by Adnar Lozano & Ulices Viramontes.\n"
                  + "Using Eclipse Java EE IDE for web developers.\n\n"
                  + "Version: Kepler Service Release 2\nBuild id: 20140224-0627\n\n"
                  + "(c) Copyright Eclipse contributors and others 2005, 2014.  All rights reserved.\n"
                  + "Visit http://www.eclipse.org/webtools",
                  "About", JOptionPane.INFORMATION_MESSAGE );                             
            } // end method actionPerformed
         } // end anonymous inner class
      ); // end call to addActionListener
 
      JMenuItem exitItem = new JMenuItem( "Exit" ); // create exit item
      exitItem.setMnemonic( 'x' ); // set mnemonic to x
      fileMenu.add( exitItem ); // add exit item to file menu
      exitItem.addActionListener(

         new ActionListener() // anonymous inner class
         {  
            // terminate application when user clicks exitItem
            public void actionPerformed( ActionEvent event )
            {
            	if (JOptionPane.showConfirmDialog( AddEmployees.this, "Are You sure you want to exit?", "Warning",
            			JOptionPane.YES_NO_OPTION) == JOptionPane.YES_OPTION)
            			{
            				JOptionPane.showMessageDialog( AddEmployees.this, "Thank you for using EMDS v.1.4.2", "Exit",
                			JOptionPane.INFORMATION_MESSAGE);
    	  					System.exit(0); // exit application
            			}
            	else { 	
            		
            	}       
            } // end method actionPerformed
         } // end anonymous inner class
      ); // end call to addActionListener
      
      JMenuBar bar = new JMenuBar(); // create menu bar
      setJMenuBar( bar ); // add menu bar to application
      bar.add( fileMenu ); // add file menu to menu bar

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

      // if connected to database, set up GUI
      
      JPanel topPanel = new JPanel();
      addEmployee = new JButton( "Add Generic Employee" );
      addEmployee.addActionListener( new ButtonHandler() );
      Refresh = new JButton ("Refresh");
      Refresh.addActionListener(new ButtonHandler() );
      
      topPanel.add(Refresh);
      topPanel.add( addEmployee );

      // create four buttons that allow user to add specific employee
      addSalariedEmployee = new JButton( "Add Salaried Employee" );
      addSalariedEmployee.addActionListener( new ButtonHandler() );

      addCommissionEmployee = new JButton( "Add Commission Employee" );
      addCommissionEmployee.addActionListener( new ButtonHandler() );

      addBasePlusCommissionEmployee =
         new JButton( "Add Base Plus Commission Employee" );
      addBasePlusCommissionEmployee.addActionListener( 
         new ButtonHandler() );

      addHourlyEmployee = new JButton( "Add Hourly Employee" );
      addHourlyEmployee.addActionListener( new ButtonHandler() );

      // add four buttons to centerPanel
      JPanel centerPanel = new JPanel();
      centerPanel.add( addSalariedEmployee );
      centerPanel.add( addCommissionEmployee );
      centerPanel.add( addBasePlusCommissionEmployee );
      centerPanel.add( addHourlyEmployee );
      
      //add filter
      filterLabel = new JLabel( "Filter:" );
      filterText = new JTextField();
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
      inputPanel.add( centerPanel, BorderLayout.CENTER );
      

      table = new JTable( tableModel );

      setLayout( new BorderLayout() );
      add( inputPanel, BorderLayout.NORTH );
      add( new JScrollPane( table ), BorderLayout.CENTER );
      add( boxSouth, BorderLayout.SOUTH); //filter not added 

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

   // add employee to database
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
				tableModel.setQuery( DEFAULT_QUERY );
				String text = filterText.getText();
				JOptionPane.showMessageDialog(null,text);
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
    	  
    	 
    	  if(event.getSource() != Refresh && event.getSource() != filterButton)
    	  {
    		  String socialSecurityNumber;
    		  
    		  do{
         socialSecurityNumber = JOptionPane.showInputDialog(
            "Employee Social Security Number" );
    		  }while(!socialSecurityNumber.matches("([0-9]{3})-([0-9]{2})-([0-9]{4})"));
         String insertQuery = "", displayQuery = "";

         // add generic employee to table employees
         if ( event.getSource() == addEmployee )
         {
        	 String firstName;
        	 String lastName;
        	 String birthday;
        	 String employeeType;
        	 String department;
        	 do
        	 {
            firstName =
               JOptionPane.showInputDialog( "First Name" );
        	 }while(firstName.isEmpty());
        	 do {
            lastName = JOptionPane.showInputDialog( "Last Name" );
        	 }while(lastName.isEmpty());
        	 do{
            birthday = JOptionPane.showInputDialog( "Birthday" );
        	 }while(!birthday.matches("([0-9]{4})-([0-9]{2})-([0-9]{2})"));
        	 do{
            employeeType = JOptionPane.showInputDialog( "Employee Type" );
        	 }while(employeeType== "salariedEmployee" || employeeType== "commissionEmployee" || 
        			 employeeType=="hourlyEmployee" || employeeType=="basepluscommissionEmployee");
        	 do{
            department = JOptionPane.showInputDialog( "Department Name" );
        	 }while(department=="R&D" || department=="SALES" || department== "HR");
            insertQuery = "INSERT INTO employees VALUES ( '" +
               socialSecurityNumber + "', '" + firstName + "', '" +
               lastName + "', '" + birthday + "', '" + employeeType +
               "', '" + department + "' )";
            displayQuery = "SELECT socialSecurityNumber, firstName, " +
               "lastName, birthday, employeeType, departmentName FROM " +
               "employees";
            
         } // end if

         // add salaried employee to table salariedEmployees
         else if ( event.getSource() == addSalariedEmployee ) 
         {
            double weeklySalary = Double.parseDouble( 
               JOptionPane.showInputDialog( "Weekly Salary:" ) );
            insertQuery = "UPDATE salariedEmployees SET weeklySalary = '" +
            		weeklySalary + "' WHERE socialSecurityNumber = '" + socialSecurityNumber + "'";
            displayQuery = "SELECT employees.socialSecurityNumber, " + 
               "employees.firstName, employees.lastName, " + 
               "employees.employeeType, salariedEmployees.weeklySalary" +
               " FROM employees, salariedEmployees WHERE " + 
               "employees.socialSecurityNumber = " + 
               "salariedEmployees.socialSecurityNumber";
         } // end if

         // add commission employee to table commissionEmployees
         else if ( event.getSource() == addCommissionEmployee ) 
         {
            int grossSales = Integer.parseInt(
               JOptionPane.showInputDialog( "Gross Sales:" ) );
            double commissionRate = Double.parseDouble(
               JOptionPane.showInputDialog( "Commission Rate:" ) );
            insertQuery = "UPDATE commissionEmployees SET grossSales = '" +
               grossSales + "' , commissionRate ='" + commissionRate + "' WHERE SocialSecurityNumber = '" + socialSecurityNumber + "'";
            displayQuery = "SELECT employees.socialSecurityNumber, " + 
               "employees.firstName, employees.lastName, " + 
               "employees.employeeType, commissionEmployees.grossSales," +
               " commissionEmployees.commissionRate FROM employees, " + 
               "commissionEmployees WHERE employees.socialSecurityNumber=" 
               + "commissionEmployees.socialSecurityNumber";
         } // end else if

         // add base plus commission employee to table 
         // basePlusCommissionEmployees
         else if ( event.getSource() == addBasePlusCommissionEmployee ) 
         {
            int grossSales = Integer.parseInt(
               JOptionPane.showInputDialog( "Gross Sales:" ) );
            double commissionRate = Double.parseDouble(
               JOptionPane.showInputDialog( "Commission Rate:" ) );
            double baseSalary = Double.parseDouble(
               JOptionPane.showInputDialog( "Base Salary:" ) );
            insertQuery = "UPDATE basePluscommissionEmployees SET commissionRate, grossSales = '" +
                    commissionRate + "' , '" + grossSales + "' WHERE SocialSecurityNumber = '" + socialSecurityNumber+ "'";
            displayQuery = "SELECT employees.socialSecurityNumber, " + 
               "employees.firstName, employees.lastName, employees." + 
               "employeeType, basePlusCommissionEmployees.baseSalary, " +
               "basePlusCommissionEmployees.grossSales, basePlus" + 
               "CommissionEmployees.commissionRate FROM employees, " +
               "basePlusCommissionEmployees WHERE " + 
               "employees.socialSecurityNumber = " + 
               "basePlusCommissionEmployees.socialSecurityNumber";
         } // end else if

         // add hourly employee to table hourlyEmployees
         else 
         {
            int hours = Integer.parseInt(
               JOptionPane.showInputDialog( "Hours:" ) );
            double wage = Double.parseDouble(
               JOptionPane.showInputDialog( "Wage:" ) );
            insertQuery = "UPDATE hourlyEmployees SET hours = '" + hours + "' , wage ='" +
               wage + "' WHERE socialSecurityNumber = '" + socialSecurityNumber+ "'";
            displayQuery = "SELECT employees.socialSecurityNumber, " + 
               "employees.firstName, employees.lastName, " + 
               "employees.employeeType, hourlyEmployees.hours, " +
               "hourlyEmployees.wage FROM employees, hourlyEmployees " +
               "WHERE employees.socialSecurityNumber = " + 
               "hourlyEmployees.socialSecurityNumber";
         } // end else

         // execute insert query and display employee info
         try 
         {
            statement = connection.createStatement();
            statement.executeUpdate( insertQuery );   

            // display the employee info
            tableModel.setQuery( displayQuery );
         } // end try
         catch ( SQLException exception ) 
         {
            JOptionPane.showMessageDialog( null, exception.toString() );
         } // end catch
      } // end method actionPerformed
      }// end check 
   } // end inner class ButtonHandler
   
/*
   public static void main( String[] args ) 
   {
      new AddEmployees();
   } // end main
   */
   
} // end class AddEmployees

