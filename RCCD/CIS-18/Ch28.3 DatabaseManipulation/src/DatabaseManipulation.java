// Adnar Lozano
// CIS-18A
// R. Casolaro
// 05/20/14
// Exercise 28.3: DatabaseManipulation.java

import java.sql.Connection;
import java.sql.ResultSet;
import java.sql.ResultSetMetaData;
import java.sql.Statement;
import java.sql.DriverManager;
import java.sql.SQLException;
import java.util.Scanner;

public class DatabaseManipulation 
{
   // JDBC driver and database URL
   static final String JDBC_DRIVER = "com.mysql.jdbc.Driver";
   static final String DATABASE_URL = "jdbc:mysql://localhost/books";
   static final String USERNAME = "root";
   static final String PASSWORD = null;
   
   private Connection connection; // manages connection
   private Statement statement; // performs queries
   private Scanner scanner; // reads user input

   public DatabaseManipulation() 
   {   
      // Load the driver to allow connection to the database
      try 
      {
         Class.forName( JDBC_DRIVER ); // load database driver class

         // establish connection to database
         connection = DriverManager.getConnection(
            DATABASE_URL, USERNAME, PASSWORD);

         // create Statement for querying database
         statement = connection.createStatement();
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

      // create Scanner for user input
      scanner = new Scanner( System.in );

      int choice = getChoice();

      // process user request
      while ( choice != 5 )
      {
         switch( choice )
         {
            case 1: // add new author
               addAuthor();
               break;
            case 2: // edit existing author
               editAuthor();
               break;
            case 3: // add new title
               addTitle();
               break;
            case 4: // associate title with author
               addTitleAuthor();
               break;
            default:
               System.out.println( "invalid input" );
         } // end switch

         choice = getChoice();
      } // end while
   } // end DisplayQueryResult constructor

   // get user choice
   private int getChoice()
   {        
      System.out.println( "Please choose one action:" );
      System.out.println( "1 -- Add a new author" );
      System.out.println( 
         "2 -- Edit the existing information for an author" );
      System.out.println( "3 -- Add a new title for an author" );
      System.out.println( "4 -- Associate new title with an author" );
      System.out.println( "5 -- Exit" );
      return scanner.nextInt(); // get user choice
   } // end method getChoice

   // add new author to database
   private void addAuthor() 
   {
      // get first name and last name of the author
      System.out.println( "Please enter author's first name" );
      String firstName = scanner.next();
      System.out.println( "Please enter author's last name" );
      String lastName = scanner.next();

      // insert author into authors table
      String insertSQL = "INSERT INTO authors ( firstName, lastName ) " +
         "VALUES ( '" + firstName + "', '" + lastName + "' )";

      executeSQL( insertSQL ); // execute SQL
   } // end method addAuthor

   // edit existing author
   private void editAuthor()
   {
      // get author id, first name and last name
      System.out.println( "Please enter author id" );
      int id = scanner.nextInt();
      System.out.println( "Please enter new first name" );
      String firstName = scanner.next();
      System.out.println( "Please enter new last name" );
      String lastName = scanner.next();

      // update author
      String updateSQL = "UPDATE authors SET firstName = '" + firstName +
         "', lastName = '" + lastName + "' WHERE authorID = " + id;

      executeSQL( updateSQL ); // execute SQL
   } // end method editAuthor

   // add new title to database
   private void addTitle()
   {
      // get ISBN, title, editionNumber, copyright, publisherID, 
      // imageFile and price
      System.out.println( "Please enter ISBN" );
      String isbn = scanner.next();
      System.out.println( "Please enter title" );
      scanner.nextLine(); // read remaining characters from last input
      String title = scanner.nextLine();
      System.out.println( "Please enter edition number" );
      int editionNumber = scanner.nextInt();
      System.out.println( "Please enter copyright year" );
      String copyright = scanner.next();

      // insert title into titles table
      String insertSQL = "INSERT INTO titles ( isbn, title, " + 
         "editionNumber, copyright ) " +  "VALUES ( '" + isbn +
         "', '" + title + "', '" + editionNumber +
         "', " + copyright + " )";

      executeSQL( insertSQL ); // execute SQL
   } // end method addTitle

   // associate title with author
   private void addTitleAuthor()
   {
      // get author ID
      System.out.println( 
         "Please choose an author ID from the list below:" );
      displayAuthors();
      int authorID = scanner.nextInt();

      // get title isbn
      System.out.println(
         "Please choose a book isbn from the list below:" );
      displayISBNs();
      String isbn = scanner.next();

      // update authorISBN table
      String insertSQL = "INSERT INTO authorISBN VALUES ( " +
         authorID + ", '" + isbn + "' )";

      executeSQL( insertSQL ); // execute SQL
   } // end method addTitleAuthor

   // execute SQL
   private void executeSQL( String sqlStatement )
   {
      // execute specified SQL statement
      try
      {
         System.out.printf( "Sending SQL: %s\n", sqlStatement );
         int result = statement.executeUpdate( sqlStatement ); 

         // display result of SQL execution
         if ( result == 1 )
            System.out.println( "Update successful\n" );
         else
            System.out.println( "Update failed\n" );
      } // end try
      catch ( SQLException exception )
      {
         exception.printStackTrace();
      } // end catch
   } // end method executeSQL

   // display authors table
   private void displayAuthors()
   {
      String query = 
         "SELECT authorID, firstName, lastName FROM authors";
      executeQuery( query );
   } // end method displayAuthors

   // display book title and isbn
   private void displayISBNs()
   {
      String query = "SELECT isbn, editionNumber, title FROM titles";
      executeQuery( query );
   } // end method displayISBNs

   // execute query
   private void executeQuery( String query )
   {
      // execute query and display result
      try
      {
         // query database
         ResultSet resultSet = statement.executeQuery( query );
         
         // process query results
         ResultSetMetaData metaData = resultSet.getMetaData();
         int numberOfColumns = metaData.getColumnCount();

         for ( int i = 1; i <= numberOfColumns; i++ )
            System.out.printf( "%-8s\t", metaData.getColumnName( i ) );
         System.out.println();
         
         while ( resultSet.next() ) 
         {
            for ( int i = 1; i <= numberOfColumns; i++ )
               System.out.printf( "%-8s\t", resultSet.getObject( i ) );
            System.out.println();
         } // end while
      } // end try
      catch ( SQLException sqlException ) 
      {
         sqlException.printStackTrace();
      } // end catch
   } // end method executeQuery

   public static void main( String args[] ) 
   {
      new DatabaseManipulation();
   } // end main
} // end class DatabaseManipulation



 