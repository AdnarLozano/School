// Adnar Lozano
// CIS-18B: Advanced Java
// 04/08/14
// Homework #4: Exercise 25.16: DrawFrame.java
// This class creates the desktop, manages menu items and creates frames.

import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;

import javax.swing.JDesktopPane;
import javax.swing.JInternalFrame;
import javax.swing.JFrame;
import javax.swing.JMenu;
import javax.swing.JMenuBar;
import javax.swing.JMenuItem;

@SuppressWarnings("serial")
public class DrawFrame extends JFrame 
{
   private static final int MAX_WINDOWS = 20; 	// maximum of windows
   private JInternalFrame[] frames; 			// array of internal frames
   private JMenuItem[] frameItems; 				// array of menu items
   private int count = 0; 						// count of internal frames created
   private JDesktopPane desktop; 				// holds internal frames
   private JMenuItem newItem; 					// menu item to create new internal frame
   private JMenu windowMenu; 					// window menu to select internal frame

   // Constructor has no arguments
   
   public DrawFrame()
   {
      super( "Complete Drawing Program" );
      
      desktop = new JDesktopPane(); 			// holds internal frames
      add( desktop ); 							// add desktop to application

      frames = new JInternalFrame[ MAX_WINDOWS ];	// internal frames
      frameItems = new JMenuItem[ MAX_WINDOWS ]; 	// menu items for frames

      JMenuBar menuBar = new JMenuBar(); 	// menu bar
      JMenu fileMenu = new JMenu( "File" ); // file menu
      fileMenu.setMnemonic( 'f' ); 			// set mnemonic to f for file menu

      newItem = new JMenuItem( "New" );	// new menu item
      newItem.setMnemonic( 'n' ); 		// set mnemonic to n for new
      fileMenu.add( newItem ); 			// add new item to file menu 
      newItem.addActionListener(
         new ActionListener() 		// anonymous inner class
         { 
            public void actionPerformed( ActionEvent event )
            {
               String title = "Picture " + ( count + 1 ); // window title
               
               frames[ count ] = new DrawInternalFrame( title, 
                  DrawFrame.this ); // create internal frame
               desktop.add( frames[ count ] ); // add frame to desktop
               frames[ count ].setVisible( true ); // show frame

               // create the menu item for frame
               frameItems[ count ] = new JMenuItem( title );
               windowMenu.add( frameItems[ count ] ); // add menu item
               frameItems[ count ].addActionListener(
                  new ActionListener() // anonymous inner class
                  { 
                     // move selected frame to front of application
                     public void actionPerformed( ActionEvent event )
                     {
                        String caller = event.getActionCommand();
                        int number = 
                           Integer.parseInt( caller.substring( 7 ) );
                        
                        // set the selected frame to the front
                        frames[ number - 1 ].toFront(); // move to front
                     } // end method actionPerformed
                  } // end anonymous inner class
               ); // end call to addActionListener

               count++; // increment the count

               // if maximum number of windows, disable new menu item
               if ( count == MAX_WINDOWS )
                  newItem.setEnabled( false ); // disable new menu item
            } // end method actionPerformed
         } // end anonymous inner class
      ); // end call to addActionListener

      JMenuItem exitItem = new JMenuItem( "Exit" ); // exit menu item
      exitItem.setMnemonic( 'e' ); // set mnemonic to e
      fileMenu.add( exitItem ); // add exit item to file menu
      menuBar.add( fileMenu ); // add file menu to menu bar
      exitItem.addActionListener(
         new ActionListener() // anonymous inner class
         { 
            public void actionPerformed( ActionEvent event ) 
            {
               System.exit( 0 ); // exit application
            } // end method actionPerformed
         } // end anonymous inner class
      ); // end call to addActionListener
      
      windowMenu = new JMenu( "Window" ); // create window menu
      menuBar.add( windowMenu ); // add window menu to menu bar      
      setJMenuBar( menuBar ); // set menu bar for application
   } // end DrawFrame constructor
   
   // called when a child frame is closed
   public void frameClosed( String window )
   {
      // get number of closed frame
      int number = Integer.parseInt( window.substring( 7 ) );
      windowMenu.remove( frameItems[ number - 1 ] ); // remove menu item
      frameItems[ number - 1 ] = null; // set reference to null
   } // end method frameClosed
} // end class DrawFrame
