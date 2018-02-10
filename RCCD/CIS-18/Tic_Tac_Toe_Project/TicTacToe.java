





/*Adnar Lozano
 * Ryan Dimassimo
 * Hugo Gutierrez
 * Alfredo 
 * Illiana
 * 
 * Tic Tac Toe Project
 * Java 18B
 * Rochelle Cassolaro
 * May 13, 2014
 */


import java.awt.*;


import java.awt.event.*;
import javax.swing.*;
import java.io.*;
import java.net.*;
import javax.swing.border.*;


//****************************** class TicTacToe ********************************
//class tictactoe is used to handle the
//creation of server or client objects
public class TicTacToe extends Thread {

	private static boolean ServerReady = false;
	private String Statistics[];
	
	
	
	public TicTacToe(String AppType) throws Exception
	{
		super(AppType);
		
		
	}	
	
	
	//if the command is "java TicTacToe client IP", run this 
	public TicTacToe(String AppType, String TargetIp) throws Exception
	{
		
		int NoOfGames = 0;
		String Name = null;
		
		Statistics = new String[1000]; 
		for (int i=0; i<1000; i++)
			Statistics[i] = null;
		
		
		
		if (AppType.toUpperCase().equals("CLIENT")) 
		{
			
			try
			{		
				while (true)
				{
					TicTacToeClient TTTClient = new TicTacToeClient(TargetIp, Statistics, Name);
					TTTClient.Play();
				
					//if play again, playing history will be cleared, 
					//dispose old interface and start again
					
					if (!TTTClient.lblStatus.getText().equals("Status: Server down! Game stopped."))
					{				
						
						//get the game result first no matter the player continues to play or not
						Statistics[++NoOfGames] = TTTClient.GetGameResult();
						Name = TTTClient.GetName();
						
						if (TTTClient.PlayAgain())
							TTTClient.dispose();
						else
						//not play again, the player can still read the play history
							break;
					}		
					else
						break;
					
				}
			
			}
			catch (Exception e) {
				System.err.println("SYSTEM MSG: Exception when connecting to server: " + e.toString());
			}
	
		}
	
	
	}
	
	
	//if the command is "java server", start two threads
	//one to start the server, one to start the client
	public void run()
	{
		
		
		if (Thread.currentThread().getName().equals("ServerThread"))
		{
			
			if (!ServerReady)
			{
				
				try  {
					
					ServerReady = true;
					TicTacToeServer TTTServer = new TicTacToeServer();

				}
				catch (Exception e) {
					System.err.println("SYSTEM MSG: Exception when starting server: " + e.toString());
				}		
			}
			
			
		
		}
		else if (Thread.currentThread().getName().equals("ClientThread"))
		{
			int NoOfGames = 0;
			String Name = null;

			Statistics = new String[1000]; 
			for (int i=0; i<1000; i++)
				Statistics[i] = null;

				
			try {

				while (!ServerReady)
					sleep(100);

				
				while (true)
				{
					TicTacToeClient TTTClient = new TicTacToeClient("127.0.0.1", Statistics, Name);
					TTTClient.Play();
				
					//get the game result first no matter the player continues to play or not
					Statistics[++NoOfGames] = TTTClient.GetGameResult();
					Name = TTTClient.GetName();
					
					//if play again, playing history will be cleared, 
					//dispose old interface and start again
					
					if (!TTTClient.lblStatus.getText().equals("Status: Server down! Game stopped."))
					{
						if (TTTClient.PlayAgain())
							TTTClient.dispose();
						else
						//not play again, the player can still read the play history
							break;
					}
					else
						break;
					
												
				}			
			}
			catch (Exception e) {
				System.err.println("SYSTEM MSG: Exception when connecting to server: " + e.toString());
			}
			
	
		}
	}
	
	
	//tictactoe server
	private class TicTacToeServer
	{
		
		private Game game = new Game();		
		private ServerSocket serverSocket = null;
		private Socket clientSocket = null;

		
		public TicTacToeServer() throws Exception
		{


			//setup serversocket  
	        try {
	            serverSocket = new ServerSocket(1357);
	            
	        } catch (IOException e) {
	            System.err.println("SYSTEM MSG: Server could not listen on port: 1357.");
	            System.exit(1);
	        }
			
			
			try
			{
				while (true)
				{
					
					//each client will be served by a thread playerhelper
					//first player is assigned x
					game.AddPlayer(new PlayerHelper(game, 'x', listen()));
					game.AddPlayer(new PlayerHelper(game, 'o', listen()));
					
					
					if (game.IsFull())
					{
						
						
						game.SetOpponent();					
						game.GetPlayer1().start();
						game.GetPlayer2().start();
						
								
						//start a new game			
						game = new Game();
					}
				}
			}
			finally 	
			{	
				try
				{
					serverSocket.close();
				}
				catch (IOException e)
				{
					System.out.println("SYSTEM MSG: Error when closing server socket.");
			
				}
			}
		}		
		
		public Socket listen()
		{
			Socket TempSocket = null;
			
			//start serversocket to listen
	        try {
	        	System.out.println("SYSTEM MSG: Server is listening for incoming connection...");
	            
	            TempSocket = serverSocket.accept();
	        } catch (IOException e) {
	            System.err.println("SYSTEM MSG: Server fails to accept incoming call.");
	            System.exit(1);
	        }
			
			return TempSocket;
		
		}


		//********************* class game *******************	
		private class Game
		{
			private PlayerHelper PHelper1 = null;
			private PlayerHelper PHelper2 = null;
			
			private PlayerHelper CurrentPlayer = null;
			private BoardOwner Board[];	//game board
			
			public static final int VALIDMOVE = 1;
			public static final int INVALIDMOVE = 2;
			public static final int NOTYOURTURN = 3;

			private int NoOfMove = 0;
			
			
			public Game()
			{
				
				Board = new BoardOwner[9];
				for (int i=0; i<9; i++)
					Board[i] = new BoardOwner();
				
			}
		
			public void AddPlayer(PlayerHelper NewPlayer)
			{
				if (PHelper1 == null)
					PHelper1 = NewPlayer;
				else
					PHelper2 = NewPlayer;
			}
					
			public void SetOpponent()
			{
				PHelper1.SetOpponent(PHelper2);
				PHelper2.SetOpponent(PHelper1);
				
			
			}
			
						
			public boolean IsFull()
			{
				return ((PHelper1 != null) && (PHelper2 != null));
			}

			public PlayerHelper GetPlayer1()
			{
				return PHelper1;
			
			}
			
			public PlayerHelper GetPlayer2()
			{
				return PHelper2;
			}
			
			
			//both players own the game object, so we use this as the
			//monitor
			public synchronized int ValidateMove(PlayerHelper Player, int Location) 
			{
				
				int ReturnValue = INVALIDMOVE;
				
				try {
				
			
				
					if (Player == CurrentPlayer)
					{

						//if nobody choose that location			
						if (Board[Location].Player == null)	
						{
							

							//assign board location and move order
							Board[Location].Player = Player;
							Board[Location].MoveOrder = NoOfMove++;
				
																						
							
							//set new current player
							CurrentPlayer = Player.GetOpponent();			
							
							//call current player to record opponent move first (the one 
							//we have just processed above) before he moves
							CurrentPlayer.RecordOpponentMove(Location); 							
							
							//notify the other waiting player he can move now
							ReturnValue = VALIDMOVE;
		
							
							
						}			
						else
							ReturnValue = INVALIDMOVE;
					}
					else
					//not his turn
						ReturnValue = NOTYOURTURN;
							
				}
				catch (Exception e) {
					System.out.println("SYSTEM MSG: Error when validating move.");
				}

				return ReturnValue;

			}
			
			
			//validate name when user press submit
			public synchronized boolean ValidateName(PlayerHelper Player, String InputName)
			{

				
				if (Player.GetOpponent().GetName() == null || !Player.GetOpponent().GetName().equals(InputName)) 
				{
					
					
					Player.SetName(InputName);
					Player.GetOpponent().RecordOpponentName(InputName);
					return true;
				}
				else
					return false;
					
				
			}
			
			//send a move back request to the opponent 
			public synchronized void ValidateMoveBack(PlayerHelper Player)
			{
				Player.GetOpponent().RequestMoveBack();
				
			}
			
			
			//once the opponent response to the move back request(either deny or confirm)
			//game will announce the move back decision
			//ResponsePlayer is the player who authorize the other to move back
			public synchronized void AnnounceMoveBack(String Result, PlayerHelper ResponsePlayer)
			{
				int XLastMove, OLastMove;

				if (Result.equals("YES"))
				{
					//ok to move back
					
					//case 1: X move 1 step, O move 1 step, 
					//X make the request in his turn and O authorize it
					if (CurrentPlayer == ResponsePlayer.GetOpponent())
					{
						
						
						//modify server board
						//remove O's last move
						OLastMove = GetPlayerLastMove(CurrentPlayer.GetOpponent());
						RemoveMove(OLastMove);
					
					
					
						//remove X's last move
						XLastMove = GetPlayerLastMove(CurrentPlayer); 
						RemoveMove(XLastMove);
						
						
						
						//modify client's board
						//do this again in client's program
						//return the name of the requester
						CurrentPlayer.GetOpponent().MoveBack(ResponsePlayer.GetOpponent().GetName(), OLastMove);
						CurrentPlayer.GetOpponent().MoveBack(ResponsePlayer.GetOpponent().GetName(), XLastMove);
						
						CurrentPlayer.MoveBack(ResponsePlayer.GetOpponent().GetName(), OLastMove);
						CurrentPlayer.MoveBack(ResponsePlayer.GetOpponent().GetName(), XLastMove);
					
						
						//current player remains currentplayer
					
					}
					else
					//case 2: X move 1 step, O is making decision, X request to move back
					//and O authorize it 
					{
						
						
						//modify server board
						//remove X's last move
						XLastMove = GetPlayerLastMove(CurrentPlayer.GetOpponent()); 
						RemoveMove(XLastMove);
						
						
						
						//modify client's board
						//return the name of the requester
						CurrentPlayer.GetOpponent().MoveBack(ResponsePlayer.GetOpponent().GetName(), XLastMove);
						CurrentPlayer.MoveBack(ResponsePlayer.GetOpponent().GetName(), XLastMove);
						
						//currentplayer change back to X
						SuperSetCurrentPlayer(CurrentPlayer.GetOpponent());
					}
						
					
						
					
				}
				else
				{
					
					//-1 means request not authorize
					CurrentPlayer.MoveBack(ResponsePlayer.GetOpponent().GetName(), -1);
					CurrentPlayer.GetOpponent().MoveBack(ResponsePlayer.GetOpponent().GetName(), -1);
				}



			}			
			
			
			//delete a move from the game board
			public void RemoveMove(int Location)
			{
				Board[Location].Player = null;
				Board[Location].MoveOrder = -1;
				
				NoOfMove--;
			}
			
			
			//get the last move of player from history
			public int GetPlayerLastMove(PlayerHelper Player)
			{
				int MaxMoveOrder = -1;
				int LastMove = -1;
				
				for (int i=0; i<9; i++)
				{
					if (Board[i].Player == Player)
					{
						
						
						
						if (Board[i].MoveOrder > MaxMoveOrder)
						{	
							MaxMoveOrder = Board[i].MoveOrder;
							LastMove = i;
						}
					
					
					}
				}
			
				return LastMove;
			
			}
			
			public PlayerHelper GetCurrentPlayer()
			{
				return CurrentPlayer;
			}
				
			public synchronized void SetCurrentPlayer(PlayerHelper Player)
			{
				if (CurrentPlayer == null)
					CurrentPlayer = Player;
			}
				
			public void SuperSetCurrentPlayer(PlayerHelper Player)
			{
				//use in requesting move back 1 step
				
				CurrentPlayer = Player;
			}
				
			public boolean HaveWinner()
			{
				//check the owner of each box to see the winner
				
			    return (((Board[0].Player != null) && (Board[0].Player == Board[1].Player) && (Board[1].Player == Board[2].Player)) ||
				((Board[3].Player != null) && (Board[3].Player == Board[4].Player) && (Board[4].Player == Board[5].Player)) ||
				((Board[6].Player != null) && (Board[6].Player == Board[7].Player) && (Board[7].Player == Board[8].Player)) ||
				((Board[0].Player != null) && (Board[0].Player == Board[3].Player) && (Board[3].Player == Board[6].Player)) ||
				((Board[1].Player != null) && (Board[1].Player == Board[4].Player) && (Board[4].Player == Board[7].Player)) ||
				((Board[2].Player != null) && (Board[2].Player == Board[5].Player) && (Board[5].Player == Board[8].Player)) ||
				((Board[0].Player != null) && (Board[0].Player == Board[4].Player) && (Board[4].Player == Board[8].Player)) ||
				((Board[2].Player != null) && (Board[2].Player == Board[4].Player) && (Board[4].Player == Board[6].Player)));
			}
					
				

			//check whether game is tie			
			public boolean Tie()
			{
				boolean BoardIsFull = true;
				
				for (int i=0; i<9; i++)
				{
					//if one of the board is null, then not full -> not tie
					if (Board[i].Player == null)
						BoardIsFull = false;
				}
						
						
				//if board is full but still no winner, then tie
				if ((BoardIsFull) && (HaveWinner() == false))
					return true;
				else 
					return false;
						
			}	
				
			

						
		}
		
		
		
		private class BoardOwner
		{
			public PlayerHelper Player = null;
			public int MoveOrder = -1;
		}
		
		
		//************************ class PlayerHelper **********************
		//each playerhelper will handle a player's communication inside a game
		private class PlayerHelper extends Thread
		{
			private PlayerHelper Opponent;
			private PrintWriter out = null;
			private BufferedReader in = null;
			private Socket socket;
			
			private Game game; 			
			private char sign;
			private String MyName;
			private boolean GameOver = false;
	
			
			public PlayerHelper(Game gm, char tempsign, Socket clientSocket) throws Exception
			{
				
				game = gm;
				sign = tempsign;
				
				try {
				
					//client connects and we setup clientsocket to communicate
					//with client
					socket = clientSocket;
					out = new PrintWriter(clientSocket.getOutputStream(), true);
					in = new BufferedReader( new InputStreamReader(
									clientSocket.getInputStream()));		
			
	
					//first response to client after first connect
					out.println("WELCOM");
					out.println("YRSIGN " + sign);			
				} catch (IOException e)
				{
					System.out.println("SYSTEM MSG: Unable to start player thread.");
				}

			}
			

			public PlayerHelper GetOpponent()
			{
				return Opponent;
			}
			
			public void SetOpponent(PlayerHelper NewPlayer)
			{
				Opponent = NewPlayer;
				out.println("OPPARR");
				
			}		

			
			//thread started to listen to client's command				
			public void run()
			{
				String Command = null; //command = optcode + param
				String OptCode = null;
				String Param = null; 
				
				
				try {
				
					while (!GameOver)
					{
						
						Command = in.readLine();
						if (Command != null)		
						{
							OptCode = Command.substring(0, 6);
							Param = Command.substring(6).trim();
						}	
		
					
						if (OptCode.equals("MOVETO"))
						{
							
					
							
							//the player who move first will be set as
							//currentplayer
							if (game.GetCurrentPlayer() == null)
								game.SetCurrentPlayer(this);
						
						
							//client wants to move, so go to the game to 
							//validate that move
							if (game.ValidateMove(this, Integer.parseInt(Param)) == game.VALIDMOVE)
							{
									out.println("MOVEOK " + Param);
									
									if (game.HaveWinner())
										out.println("YOUWIN");
									else if (game.Tie())
										out.println("GAMTIE");
							
							}
							else if (game.ValidateMove(this, Integer.parseInt(Param)) == game.INVALIDMOVE)
								out.println("MOVENK");						
							else if (game.ValidateMove(this, Integer.parseInt(Param)) == game.NOTYOURTURN)
								out.println("NOTTRN");
							
						}
						else if (OptCode.equals("MYNAME"))
						{
							
							if (game.ValidateName(this, Param) == true)
								out.println("NAMEOK " + Param );
							else
								out.println("NAMENK");
							
						}
						//request move back
						else if (OptCode.equals("MOVEBK"))
						{
							game.ValidateMoveBack(this);
						}
						//response to move back request
						else if (OptCode.equals("REQRES"))
						{
							game.AnnounceMoveBack(Param, this);
						}	
						//when playerhelper catch the exception that a player has disconnected,
						//it will tell the opponent of this player that his opponent has disconnected
						else if (OptCode.equals("GMQUIT"))
						{
							System.out.println("SYSTEM MSG: Player " + (MyName == null ? "No Name" : MyName) + " has disconnected, game stopped.");
							GameOver = true;
						}
						
					} 
						
				}
				catch (IOException e) {
					System.out.println("SYSTEM MSG: Player " + (MyName == null ? "No Name" : MyName) + " has disconnected, game stopped.");
					Opponent.RecordOpponentDead();
					


				}
				finally {
					
					try {
						socket.close();
					} catch (IOException e) {
						System.out.println("SYSTEM MSG: Error when closing playerhelp socket.");		
					}
				
				}
				
				
											
			}
			
			public void RecordOpponentDead()
			{
				out.println("OPDEAD");
			}
			
			
			public void RecordOpponentMove(int Loc)
			{
				//call this player to record opponent move
				out.println("OPPMOV " + Loc);

				if (game.HaveWinner())
					out.println("YOULSE");
				else if (game.Tie())
					out.println("GAMTIE");
			}
			
			public String GetName()
			{
				return MyName;
			}
			
			public void SetName(String InputName)
			{
			
				MyName = InputName;
				 
			}
			
			public void RecordOpponentName(String InputName)
			{
				out.println("OPPNAM " + InputName);
			}
			
			//other side request to move back
			public void RequestMoveBack()
			{
				out.println("OPPREQ");
			}
			
			//announce result of moveback request
			//requester is the player who make the request to move back
			//location is the square that needs to be removed
			public void MoveBack(String Requester, int Location)
			{
				if (Location == -1)
				//not authorize
					out.println("REQRES NK " + "0" + Requester);
				else
					out.println("REQRES OK " + Location + Requester);
				
		
			}			
			
		}
		
	
	
	}



	//*********************** class tictactoeclient *******************
	private class TicTacToeClient extends JFrame
	{

		private JPanel buttonPanel;
		private JButton squares[];
		private JLabel lblStatus;
		
		private JPanel InputPanel;
		private JLabel lblPlayerName;
		private JTextField txtPlayerName;
		private JButton submit;
		private JLabel lblYourSignMsg;
		private JLabel lblYourSign;
		
		
		private JPanel HistPanel;
		private JButton BtnBegin, BtnPrev, BtnNext, BtnEnd;
		
		private JPanel OtherFuncPanel;
		private JButton BtnMoveBack;
		private JButton BtnStat;
		
		
		private JPanel StatusPanel;
		
		private JPanel VsPanel;
		private JLabel MyName;
		private JLabel OppName;
		private ImageIcon TurnIcon;
		private JLabel MyTurn;
		private JLabel YourTurn;


		private JPanel RightPanel;
		private JPanel BottomPanel;


		private Socket TTTSocket = null;
		private PrintWriter out = null;
		private BufferedReader in = null;
		private boolean GameOver = false;
		private boolean GameStart = false;
		private boolean OppArrived = false;
		private String Sign;
		private ImageIcon MyIcon;
		private ImageIcon OppIcon;
		private String PlayerName = null;
		private String OpponentName = null;
		
		private String History[] = new String[9];	
		private int NoOfMove = 0;
		private int ViewPointer = -1;		
		
		//statistics
		private String GameResult = null;
		private String Statistics[];


		//constructor
		public TicTacToeClient(String TargetIp, String in_stat[], String Name)
		{
			
			
			super("TicTacToeClient");
		
			//store statistics	
			Statistics = new String[1000];
			Statistics = in_stat;

			
			addWindowListener(
				new WindowAdapter(){
					public void windowClosing(WindowEvent e)
					{
						System.exit(0);
					}
				}
			);
			
			
			

			//setting up the socket
			try 
			{
	            TTTSocket = new Socket(TargetIp, 1357);
	            out = new PrintWriter(TTTSocket.getOutputStream(), true);
	            in = new BufferedReader(new InputStreamReader(TTTSocket.getInputStream()));
	        } catch (UnknownHostException e) {
	            System.err.println("SYSTEM MSG: Unknown host:" + TargetIp);
	            System.exit(1);
	        } catch (IOException e) {
	            System.err.println("SYSTEM MSG: Server " + TargetIp + " has no response. Game stopped");
	            System.exit(1);
	        }


			
			
			//*************layout the interface**************
			Container c = getContentPane();
			c.setLayout(new BorderLayout());
		
		
			//create a button panel to hold 9 squares
			buttonPanel = new JPanel();
			buttonPanel.setLayout(new GridLayout(3, 3, 0, 0));
		
			squares = new JButton[9];
			
			
			
		
			//initialize 9 squares
			for (int i=0; i<squares.length; i++)
			{	
				final int j = i;
			
				squares[i] = new JButton("");

  				squares[i].addMouseListener( new MouseAdapter() {
	                public void mouseReleased(MouseEvent e) {
	                	
	           			//when user press a square, moveto will send to the playerhelper
	                	if (GameStart && !GameOver)
	            		{	
			            	out.println("MOVETO " + j); 
						}
	             	}	
				} );
				
				buttonPanel.add(squares[i]);
			}
		
			
			
			
			//create other components
					
			//right-handed side of button panel
			InputPanel = new JPanel();
			InputPanel.setLayout(new BoxLayout(InputPanel, BoxLayout.Y_AXIS));
			
	
			lblPlayerName = new JLabel("Player Name: ");
			txtPlayerName = new JTextField(10);			
			if (Name != null)
				txtPlayerName.setText(Name);
			lblYourSignMsg = new JLabel("Your sign is:");
			lblYourSign = new JLabel(" ");
			lblYourSign.setBorder(BorderFactory.createEtchedBorder());
		    
				
			submit = new JButton("Submit");
			submit.addMouseListener( new MouseAdapter() {
					public void mouseReleased(MouseEvent e) {

					if (OppArrived)
					{
						if (txtPlayerName.getText().trim().length() > 0)
						{						
							//send your name to the server to check 
							out.println("MYNAME " + txtPlayerName.getText());
						}
						else
							ShowErrMessageDialog("Please enter your name before pressing Submit", "TicTacToe Error Message");
	
					}
					else
						ShowErrMessageDialog("Please wait until game start", "TicTacToe Error Message");
					
					}
				} );
			

			
			
			InputPanel.add(lblPlayerName);
			InputPanel.add(Box.createRigidArea(new Dimension(0,5)));
			InputPanel.add(txtPlayerName);
			InputPanel.add(submit);
			InputPanel.add(Box.createRigidArea(new Dimension(0,30)));
			InputPanel.add(lblYourSignMsg);
			InputPanel.add(Box.createRigidArea(new Dimension(0,5)));
			InputPanel.add(lblYourSign);
	
			
			
			RightPanel = new JPanel();
			RightPanel.add(InputPanel);


			//bottom of button panel
			BottomPanel = new JPanel();
			BottomPanel.setLayout(new BoxLayout(BottomPanel, BoxLayout.Y_AXIS));

			VsPanel = new JPanel();
			VsPanel.setLayout(new BoxLayout(VsPanel, BoxLayout.X_AXIS));
			
			MyName = new JLabel(" ");
			OppName = new JLabel(" ");
			MyTurn = new JLabel(" ");
			YourTurn = new JLabel(" ");
			TurnIcon = new ImageIcon("reddot1.gif");


			
			VsPanel.add(Box.createRigidArea(new Dimension(140, 0)));
			VsPanel.add(MyTurn);
			VsPanel.add(Box.createRigidArea(new Dimension(10, 0)));
			VsPanel.add(MyName);
			VsPanel.add(new JLabel("   VS   "));
			VsPanel.add(OppName);
			VsPanel.add(Box.createRigidArea(new Dimension(10, 0)));
			VsPanel.add(YourTurn);
			VsPanel.add(Box.createHorizontalGlue());



			HistPanel = new JPanel();
			HistPanel.setLayout(new BoxLayout(HistPanel, BoxLayout.X_AXIS));
			BtnBegin = new JButton("BEGIN");
			BtnPrev = new JButton("PREV");
			BtnNext = new JButton("NEXT");
			BtnEnd = new JButton("END");
			DirectionListener directionListener = new DirectionListener();
			BtnBegin.addActionListener(directionListener);
			BtnPrev.addActionListener(directionListener);
			BtnNext.addActionListener(directionListener);
			BtnEnd.addActionListener(directionListener);
			HistPanel.add(Box.createRigidArea(new Dimension(65, 0)));
			HistPanel.add(BtnBegin);
			HistPanel.add(Box.createRigidArea(new Dimension(5, 0)));
			HistPanel.add(BtnPrev);
			HistPanel.add(Box.createRigidArea(new Dimension(5, 0)));
			HistPanel.add(BtnNext);
			HistPanel.add(Box.createRigidArea(new Dimension(5, 0)));
			HistPanel.add(BtnEnd);
			HistPanel.add(Box.createHorizontalGlue());

			
			
			OtherFuncPanel= new JPanel();
			OtherFuncPanel.setLayout(new BoxLayout(OtherFuncPanel, BoxLayout.X_AXIS));
			BtnMoveBack = new JButton("Take back move");
			BtnStat = new JButton("Statistics");
			BtnMoveBack.addActionListener( new ActionListener() {
				public void actionPerformed(ActionEvent e) {
	
					//request if not blank
					if (IHaveMoved() && !GameOver)
					{
						if (ConfirmRequest() == true)
						{
							//request to take back 1 move				
							out.println("MOVEBK");
							lblStatus.setText("Status: You move back request is sent, waiting for response...");
						}
						else
							lblStatus.setText("Status: Move back request is cancelled");
						
					}
					else
					{
						if (!GameOver)
							ShowErrMessageDialog("Status: Move back request invalid. You have not made you move yet", "TicTacToe Error Message");
					}							

				
				}
			} );
		
			BtnStat.addActionListener( new ActionListener() {
				public void actionPerformed(ActionEvent e) {
					float NoOfTie = 0;
					float NoOfWin = 0;
					float NoOfLose = 0;
					float Total = 0;
					float TiePercent = 0;
					float WinPercent = 0;
					float LosPercent = 0;
					String Output = null;
					

	
					for (int i=1; i<Statistics.length && Statistics[i]!= null; i++)
					{
							if (Statistics[i].equals("WIN"))
								NoOfWin++;
							else if (Statistics[i].equals("LOS"))
								NoOfLose++;
							else if (Statistics[i].equals("TIE"))
								NoOfTie++;
					
					}

					Total = NoOfWin + NoOfLose + NoOfTie;
					
					if (Total > 0)
					{					
						WinPercent = (NoOfWin / Total) * 100;
						LosPercent = (NoOfLose / Total) * 100;
						TiePercent = (NoOfTie / Total) * 100;
					}
					
					Output = "Game Statistics: \n" + 
							"Total number of games played: "+ (int)Total  +
							"\nNumber of games WIN: " + (int)NoOfWin +
							"\nNumber of games LOSE: " + (int)NoOfLose +
							"\nNumber of games TIE: " + (int)NoOfTie +
							"\n" +
							"\n Average winning percentage is: " + WinPercent + "%" +
							"\n Average losing percentage is: " + LosPercent+ "%" +
							"\n Average tieing percentage is: " + TiePercent + "%";


					
					ShowStatDialog(Output);


				
				}
			} );
			
			OtherFuncPanel.add(Box.createRigidArea(new Dimension(100, 0)));
			OtherFuncPanel.add(BtnMoveBack);
			OtherFuncPanel.add(BtnStat);
			OtherFuncPanel.add(Box.createHorizontalGlue());
			
			
			StatusPanel = new JPanel();
			StatusPanel.setLayout(new BoxLayout(StatusPanel, BoxLayout.X_AXIS));	
			lblStatus = new JLabel("Status:");
			StatusPanel.add(lblStatus);
			StatusPanel.add(Box.createHorizontalGlue());


			BottomPanel.add(Box.createRigidArea(new Dimension(0,10)));
			BottomPanel.add(VsPanel);
			BottomPanel.add(Box.createRigidArea(new Dimension(0,20)));
			BottomPanel.add(HistPanel);			
			BottomPanel.add(Box.createRigidArea(new Dimension(0,10)));
			BottomPanel.add(OtherFuncPanel);
			BottomPanel.add(StatusPanel);
			
			
			
			
			
			
			//add all components to the content pane
			c.add(buttonPanel);			
			c.add(BottomPanel, BorderLayout.SOUTH);
			c.add(RightPanel, BorderLayout.EAST);		   						
			
			
		
						
						
			
			setSize(550, 500); //original 300, 300
			show();
		}
			
			
	
		//client listen to playhelper's response			
		public void Play() throws Exception
		{
			String ServerResponse = null;
			String OptCode = null;
			String Param = null;
			
			
			
			try
			{
			
			while (!GameOver)
			{
				ServerResponse = in.readLine();
				OptCode = ServerResponse.substring(0, 6);
				Param = ServerResponse.substring(6).trim();
							
				
				if (OptCode.equals("WELCOM"))
				{
					lblStatus.setText("Status: CONNECTED, waiting for your opponent...");

				}
				//opponent has arrived
				else if (OptCode.equals("OPPARR"))
				{
					lblStatus.setText("Status: Another player has connected, please submit your name to start the game");
					OppArrived = true;
				}				
				//your sign
				else if (OptCode.equals("YRSIGN"))
				{
					
					Sign = Param;
					
					if (Param.equals("x"))
					{
						MyIcon = new ImageIcon("cross.gif");						
						OppIcon = new ImageIcon("circle.gif");
						
					}
					else
					{ 
						MyIcon = new ImageIcon("circle.gif");
						OppIcon = new ImageIcon("cross.gif");
					
					}


					lblYourSign.setIcon(MyIcon);
					lblYourSign.repaint();

						
				}
				else if (OptCode.equals("OPPNAM"))
				{
					OpponentName = Param;
					OppName.setText(Param);
					lblStatus.setText("Status: Your opponent is " + Param);
				
					if (PlayerName != null)
						GameStart = true;
					
				}
				else if (OptCode.equals("NAMEOK"))
				{
					//my name is ok
					
					PlayerName = Param;
					MyName.setText(Param);
					lblStatus.setText("Status: Welcome, " + Param);
					
					if (OpponentName != null)
						GameStart = true;
					
					submit.setEnabled(false);
					txtPlayerName.setEnabled(false);
					
				}
				//name not ok
				else if (OptCode.equals("NAMENK"))
				{
					ShowErrMessageDialog("Status: You name is already chosen by the opponent, please choose another", "TicTacToe Error Message");
					
				}				
				else if (OptCode.equals("MOVEOK"))
				{
					
					
										
					
					lblStatus.setText("Status: Waiting for opponent to move..");
					MyTurn.setIcon(null);
					MyTurn.repaint();
					YourTurn.setIcon(TurnIcon);
					YourTurn.repaint();
					
				
					//store my move
					History[NoOfMove++] = "MY" + Param;
					ViewPointer = NoOfMove - 1;

					CleanAndRepaint();

				}
				
				else if (OptCode.equals("MOVENK"))
				{	
					//u can move again, choose another correct square
					lblStatus.setText("Status: This square is already occupied, please choose another");
				}
				else if (OptCode.equals("OPPMOV"))
				{
		
		
										
					lblStatus.setText("Status: Opponent moved. Your turn..");
					MyTurn.setIcon(TurnIcon);
					MyTurn.repaint();
					YourTurn.setIcon(null);
					YourTurn.repaint();

			
				
					//store opponent's move
					History[NoOfMove++] = "OP" + Param;
					ViewPointer = NoOfMove - 1;				
		
				
					CleanAndRepaint();				
				
				
				}
				//not your turn		
				else if (OptCode.equals("NOTTRN"))
				{
					lblStatus.setText("Status: Not your turn, waiting for opponent to move..");
				}
				//opponent request to move back
				else if (OptCode.equals("OPPREQ"))
				{
					int response = JOptionPane.showConfirmDialog(this, 
	        			"Opponent requests to move back 1 step",
	        			"Tic Tac Toe ", 
	        			JOptionPane.YES_NO_OPTION);
			
					if (JOptionPane.YES_OPTION == response)
						out.println("REQRES YES" );
					else
						out.println("REQRES NO");
				}
				//receive request response
				else if (OptCode.equals("REQRES"))
				{
					int Location;
					String Requester = null;
						
					Location = Integer.parseInt(Param.substring(3, 4));
					Requester = Param.substring(4).trim();	



					//request is ok		
					if (Param.substring(0, 2).equals("OK"))
					{
						
						
						//reset history
						DeleteMoveFromHistory(Location);				


						//repaint all square
						//cos user may be reviewing history while he is making request
						CleanAndRepaint();
						
						
						if (Requester.equals(PlayerName))
						{
							lblStatus.setText("Status: You have moved back one step, it is your turn now...");
						
							MyTurn.setIcon(TurnIcon);
							MyTurn.repaint();
							YourTurn.setIcon(null);
							YourTurn.repaint();
						}
						else
						{
							lblStatus.setText("Status: Move back request granted, waiting for opponent to move...");
							
							MyTurn.setIcon(null);
							MyTurn.repaint();
							YourTurn.setIcon(TurnIcon);
							YourTurn.repaint();
						}
							

											
										
					}						
					else 
					{//request not ok

						if (Requester.equals(PlayerName))
							lblStatus.setText("Status: The other side has denied your move back request");
						else
							lblStatus.setText("Status: You have denied the move back request");
						
		
					}


				}

				else if (OptCode.equals("OPDEAD"))
				{
					lblStatus.setText("Status: Opponent has disconnected. Game stopped.");
					ShowErrMessageDialog("Status: Opponent has disconnected. Game stopped.", "TicTacToe Error Message");
					GameOver = true;
					
				}				
				else if (OptCode.equals("YOUWIN"))
				{
					lblStatus.setText("Status: You Win!!!");
					GameResult = "WIN";
					
					MyTurn.setIcon(null);
					MyTurn.repaint();
					YourTurn.setIcon(null);
					YourTurn.repaint();
				
					GameOver = true;
						
				}
				else if (OptCode.equals("YOULSE"))
				{
					lblStatus.setText("Status: You Lose..");
					GameResult = "LOS";
					
					
					MyTurn.setIcon(null);
					MyTurn.repaint();
					YourTurn.setIcon(null);
					YourTurn.repaint();

					GameOver = true;

				}
				else if (OptCode.equals("GAMTIE"))
				{
					lblStatus.setText("Status: Game Tie.");
					GameResult = "TIE";
					
					MyTurn.setIcon(null);
					MyTurn.repaint();
					YourTurn.setIcon(null);
					YourTurn.repaint();
				
					GameOver = true;
				}
			}
			
			
				//call player thread to stop
				out.println("GMQUIT");
			
			
			}
			catch (IOException e)
			{
				System.err.println("SYSTEM MSG: Server down! Game stopped.");
				lblStatus.setText("Status: Server down! Game stopped.");
				ShowErrMessageDialog("Status: Server down! Game stopped.", "TicTacToe Error Message");
	
				
				GameOver = true;
			}
			finally
			{
				try
				{
					TTTSocket.close();
				}
				catch (IOException e)
				{
					System.out.println("SYSTEM MSG: Error when closing client socket.");
				}
			}
			
					
			
		}
	

		public String GetName()
		{
			return PlayerName;
		}


		public void ShowStatDialog(String output)
		{
				JOptionPane.showMessageDialog(this, output, PlayerName + "Statistics", 
						JOptionPane.INFORMATION_MESSAGE);
		}			
			
		
		public void ShowErrMessageDialog(String output, String title)
		{
				JOptionPane.showMessageDialog( this, output, title, JOptionPane.ERROR_MESSAGE );
		}
							
		public String GetGameResult()
		{
			return GameResult;
		}
	

		public void CleanAndRepaint()
		{
			for (int i=0; i<9; i++)
			{
 				squares[i].setIcon(null);
				squares[i].repaint();
			}
			
			for (int i=0; i<=NoOfMove-1; i++)
			{
				if (History[i].substring(0,2).equals("MY"))
					squares[Integer.parseInt(History[i].substring(2).trim())].setIcon(MyIcon);
				else
					squares[Integer.parseInt(History[i].substring(2).trim())].setIcon(OppIcon);

				squares[Integer.parseInt(History[i].substring(2).trim())].repaint();
			}
		}


		public void RepaintAllSquare()
		{
						
			for (int i=0; i<=NoOfMove-1; i++)
			{
				if (History[i].substring(0,2).equals("MY"))
					squares[Integer.parseInt(History[i].substring(2).trim())].setIcon(MyIcon);
				else
					squares[Integer.parseInt(History[i].substring(2).trim())].setIcon(OppIcon);

				squares[Integer.parseInt(History[i].substring(2).trim())].repaint();
			}
		}
	
	
		public boolean PlayAgain()
		{
			
			String temp = null;
			
			if (lblStatus.getText().equals("Status: You Win!!!") ||
				lblStatus.getText().equals("Status: You Lose..") ||
				lblStatus.getText().equals("Status: Game Tie."))
				temp = lblStatus.getText();
			else
				temp = "";
			
			
			
			int response = JOptionPane.showConfirmDialog(this, 
        			temp + " Do you want to play again?",
        			"Tic Tac Toe", 
        			JOptionPane.YES_NO_OPTION);
		
			if (JOptionPane.YES_OPTION == response)
				return true;
			else
			{
				lblStatus.setText("Status: You have been disconnected from server");
				return false;
			}
		
		}
	
		public void DeleteMoveFromHistory(int Location)
		{
			
			int HistLoc;
	
			for (int i=0; i<NoOfMove; i++)
			{
				
				HistLoc = Integer.parseInt(History[i].substring(2).trim());
				
				//delete this move
				if (HistLoc == Location)
				{
					//if it is the first or last node, just delete it, no need to
					//rearrange the value
					if ((i == 0) || (i == NoOfMove-1))
						History[i] = null;
					else
					{	for (int j=i; j<NoOfMove-1; j++)
							History[j] = History[j+1];
					}		
				}
			}
			
			NoOfMove--;
			ViewPointer = NoOfMove - 1;
			
			
		}
		
		public boolean IHaveMoved()
		{
			String HistPlayer = null;
			boolean Result = false;
			
			

			
			for (int i=0; i<NoOfMove; i++)
			{
				HistPlayer = History[i].substring(0, 2).trim();
			

				
				if (HistPlayer.equals("MY"))					
				{
					Result = true;
					break;

				}

			}
			
			return Result;
			
		}	
	
		
		
		public boolean ConfirmRequest()
		{
			
			
			int response = JOptionPane.showConfirmDialog(this, 
				"Are you sure to request move back one step?",
				"Tic Tac Toe ", 
				JOptionPane.YES_NO_OPTION);
	
			if (JOptionPane.YES_OPTION == response)
				return true;
			else
				return false;

		}
			
		//review history by clicking the begin, prev, next and end button
		private class DirectionListener implements ActionListener {
			
			
			public void actionPerformed(ActionEvent e) {
			
			
				//View pointer points to the square that the player is viewing	
				if (e.getSource() == BtnBegin)
				{
					ViewPointer = -1;
					
					for (int i=0; i<9; i++)
					{	squares[i].setIcon(null);
						squares[i].repaint();
					}	
			
					lblStatus.setText("Status: First move in history...");
					
				}
				else if (e.getSource() == BtnPrev)
				{
					if (ViewPointer >= 0)
					{
						
						int PointingSquare = Integer.parseInt(History[ViewPointer].substring(2).trim());
						
						squares[PointingSquare].setIcon(null);
						squares[PointingSquare].repaint();
					
						ViewPointer--;
					}
			
					lblStatus.setText("Status: Reviewing previous move...");
			
				}
				
				else if (e.getSource() == BtnNext)
				{
					
					
					if (!(ViewPointer == (NoOfMove - 1)))
					{
						ViewPointer++;
						
						
						int PointingSquare = Integer.parseInt(History[ViewPointer].substring(2).trim());
						
						if (History[ViewPointer].substring(0,2).equals("MY"))
							squares[PointingSquare].setIcon(MyIcon);
						else
							squares[PointingSquare].setIcon(OppIcon);
			
						squares[PointingSquare].repaint();
			
						lblStatus.setText("Status: Reviewing previous move...");
			
					}
					else
					//last move
					{
						
						
						lblStatus.setText("Status: Last move in history");
					
					}
					
				}
				else if (e.getSource() == BtnEnd)
				{
					
					ViewPointer = NoOfMove - 1;
					
					
					for (int i=0; i<=NoOfMove-1; i++)
					{
						if (History[i].substring(0,2).equals("MY"))
							squares[Integer.parseInt(History[i].substring(2).trim())].setIcon(MyIcon);
						else
							squares[Integer.parseInt(History[i].substring(2).trim())].setIcon(OppIcon);
			
						squares[Integer.parseInt(History[i].substring(2).trim())].repaint();
					}

					lblStatus.setText("Status: Last move in history");

				
				}
			} 
		} 
		
	
	}


			
			
			
	
	
	public static void main(String args[]) throws Exception
	{
		
	
		
		if ((args.length == 1) && (args[0].toUpperCase().equals("SERVER")))
		{
				
			TicTacToe ServerHandlerThread = new TicTacToe("ServerThread");	
			TicTacToe ClientHandlerThread = new TicTacToe("ClientThread");
			
			ServerHandlerThread.start();
			ClientHandlerThread.start();
			
			
						
		}		
		else if (args.length == 2) {
			TicTacToe app = new TicTacToe(args[0], args[1]);	
		}
		else
		{
			System.out.println("Usage: java TicTacToe client|server [ipaddress].");
			
		}


	} 



}
