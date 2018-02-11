// Adnar Lozano
// CSE 320
// Lab #8
// 11/12/17
import java.lang.*;
//import java.util.*;
//  Single Responsibility Principle 
class  Check_Even {
	public boolean is_Even(int x) {
		if (x % 2 == 0) return true;
		else return false;
	}
}
class Number {
	public void check_Number(int x) {
		Check_Even num = new Check_Even();
		boolean result = num.is_Even(x);
		if (result) System.out.print("Integer is true\n");
		else System.out.print("Integer is false\n");
	}
}
// Open/Closed Principle
class Shopping_Cart {
	public void buy_Items(Item i) {
		i.buy();
	}
}
abstract class Item {
	abstract void buy();
}
class Shoes extends Item {
	public void buy() {
    	System.out.print("Buying shoes\n");
	}
}
// Liskov Substitution Principle
interface Alarm {
	public void sound_Alarm();
}
class Fire implements Alarm {
	public void sound_Alarm() {
 	System.out.print("Fire Alarm...\n");
  }
}
class Burglar implements Alarm {
  public void sound_Alarm() {
    System.out.print("Burglar Alarm...\n");
  }
}
// Interface Segregation Principle
interface Device extends ICall, IText, IGetEmail { }
interface ICall {
	public void make_Call();
}
interface IText {
	public void send_Text();
}
interface IGetEmail {
	public void get_Email();
}

class CellPhone implements ICall, IText, IGetEmail {
  public void make_Call() {
    System.out.print("Cellphone is calling...\n");
  }
  public void send_Text() {
    System.out.print("Cellphone is texting...\n");
  }
  public void get_Email() {
    System.out.print("Cellphone is getting email...\n");
  }
}
class Telephone implements ICall {
  public void make_Call() {
    System.out.print("Telephone is calling...\n");
  }
}
// Dependency Inversion Principle
interface IPhone {
  public void make_Call();
}
class NewCellPhone implements IPhone {
	public void make_Call() {
 		System.out.print("NewCellphone is calling...\n");
	}
}
class NewTelephone implements IPhone {
	public void make_Call() {
    	System.out.print("NewTelephone is calling...\n");
  	}
}
class NewDevice {
	IPhone my_Iphone;
  	public void call(IPhone my_Iphone) {
    	my_Iphone.make_Call();
  	}
}
// main program
public class Lab8  {
    public static void sound_The_Alarm(Alarm a) {
    		a.sound_Alarm();
    }
	public static void main(String[] args) {
		// Single Responsibility Principle application
    	System.out.print("Single Responsibility Principle:\n");
		int x = 4;
		Number foo = new Number();
    	foo.check_Number(x);

    	// Open/Closed Principle  application
    	System.out.print("\nOpen/Closed Principle:\n");
    	Shopping_Cart my_Cart = new Shopping_Cart();
    	my_Cart.buy_Items(new Shoes());

    	// Liskov Substitution Principle application
    	System.out.print("\nLiskov Substitution Principle:\n");
    	Fire f = new Fire();
    	Burglar b = new Burglar();
    	sound_The_Alarm(f);
    	sound_The_Alarm(b);

    	// Interface Segregation Principle application
    	System.out.print("\nInterface Segregation Principle:\n");
    	CellPhone iPhone = new CellPhone();
    	Telephone landline = new Telephone();
		iPhone.make_Call();
    	iPhone.send_Text();
    	iPhone.get_Email();
    	landline.make_Call();

    	// Dependency Inversion Principle application
    	System.out.print("\nInversion Principle:\n");
    	NewDevice my_Device = new NewDevice();
    	IPhone my_Iphone = new NewCellPhone();
   	 	my_Device.call(my_Iphone);
    }
}