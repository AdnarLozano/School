
import java.io.*;
import javax.imageio.*;
import javax.swing.ImageIcon;

import javax.imageio.ImageIO;
import javax.swing.ImageIcon;
import javax.swing.JLabel;
import javax.swing.JOptionPane;
import javax.swing.JPasswordField;
import javax.swing.JFrame;
import javax.swing.JButton;
import javax.swing.JTextField;

import java.awt.event.*;
import java.io.File;
import java.io.IOException;
import java.sql.DriverManager;
import java.sql.Connection;
import java.sql.PreparedStatement;
import java.sql.ResultSet;
import java.util.Arrays;

public class LoginForm implements ActionListener{

	String dbName = "record";
	String driver = "com.mysql.jdbc.Driver";
	String url = "jdbc:mysql://localhost:3306/"+dbName;
	String user = "root";
	String password = null;
	
	char[] inputPassword;
	
	Connection con = null;
	PreparedStatement ps = null;
	ResultSet rs = null;
	
	JFrame frame;
	JLabel l_pw, l_text;
	JButton button;
	JPasswordField pw;
	JTextField name_text;
	public void createUI()
	{
		frame = new JFrame("Please login into EDMS");	
		
		//Set the background image
		try{
			frame.setContentPane(new JLabel(new ImageIcon(ImageIO.read(new File("D:/Cool/RCC 2014 SCHOOL/'14 Spring Semester/CIS 18B - JAVA/18B Java Programs/Final Project_CIS_18B/Desert.jpg")))));
		}
		catch(IOException e)
		{
			System.out.println("Image Doesn't exits");
		}
		frame.setResizable(true);
		//frame.pack();
		frame.setVisible(true);
		// end background image
		
		frame.setLayout(null);
		
		l_text = new JLabel("Enter Name");
		name_text = new JTextField(10);
		l_pw = new JLabel("Enter Password");		
		pw = new JPasswordField(10);
		pw.setEchoChar('*');
		button = new JButton("Enter");
		button.addActionListener(this);
		
		l_text.setBounds(10,40,100,20);
        name_text.setBounds(120,40,100,20);
        l_pw.setBounds(10, 90, 100, 20);
        pw.setBounds(120,90,100,20);
        button.setBounds(120,120,80,20);
        
        frame.add(l_text);
        frame.add(name_text);
        frame.add(l_pw);
        frame.add(pw);
        frame.add(button);
		
		frame.setVisible(true);
		frame.setSize(600, 400);
		frame.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
	}
	
	public void actionPerformed(ActionEvent ae)
	{
		if(ae.getSource() == button)
		{
			boolean bol = matchPassword();
			if(bol == true)
			{
				JOptionPane.showMessageDialog(frame, "Login Successfull.");
				frame.dispose();
				AddEmployees table=new AddEmployees();
				table.setVisible(true);
			}
			else
			{
				JOptionPane.showMessageDialog(pw, "Password not matched." +
					" Try again.", "Error Message", JOptionPane.ERROR_MESSAGE);
				//Zero out the possible password, for security.
				Arrays.fill(inputPassword, '0');
				//select all characters in password field
				pw.selectAll();
				//reset focus on password field
				pw.requestFocusInWindow();
			}
		}
	}
	
	public boolean matchPassword()
	{
		char[] dbPassword = null;
		inputPassword = pw.getPassword();
		String name = name_text.getText();
		try
		{
			Class.forName(driver);
			con = DriverManager.getConnection(url, user, password);
			String sql = "Select name, password from user where name = '"+name+"'";
			ps = con.prepareStatement(sql);
			rs = ps.executeQuery();
			while(rs.next())
			{
				String psw = rs.getString("password");
				dbPassword = psw.toCharArray();
			}
		}
		catch(Exception e)
		{
		  JOptionPane.showMessageDialog(null, "Login failed!","Failed!!",
				  JOptionPane.ERROR_MESSAGE);
		 }		
		if(inputPassword.length != dbPassword.length)
		{
			return false;
		}
		else
			return Arrays.equals(inputPassword, dbPassword);
	}
	
	
	public static void main(String args[])
	{
		try
		{
		LoginForm form=new LoginForm();
		form.createUI();
		//frame.setSize(300,100);
		//frame.setVisible(true);
		}
	catch(Exception e)
		{JOptionPane.showMessageDialog(null, e.getMessage());}
	}
}
