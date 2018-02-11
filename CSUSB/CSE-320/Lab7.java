// Adnar Lozano
// CSE 320
// Lab #7
// 11/4/17

import java.lang.*;
import java.util.*;

// Parent class
class Player {
  private String PlayerName;
  public void setName(String name) { this.PlayerName = name; }
  public String getName() { return PlayerName; }
  public String role() { return "Player"; }
}
// Inheritance
class Human extends Player {
  public String role() { return "Human"; }
}
// Subtype Polymorphism
class Robot extends Player {
  public String role() { return "Robot"; }
}
// Composition
class AddressOnEarth {
  public String role() { return "AddressOnEarth"; }
}
// Abstract Data Type
abstract class Giant extends Human {
  private AddressOnEarth place;
  abstract String citizenship();
  abstract int height();
  abstract boolean isGood();
}
// First implementation of ADT
class NorthAmerican extends Giant {
  private AddressOnEarth place;
  public String citizenship() {
    return "Canadian Giant";
  }
  public int height() {
    int height = 10;
    return height;
  }
  public boolean isGood() {
    return true;
  }
}
// Second implementation of ADT
class European extends Giant {
  private AddressOnEarth place;
  public String citizenship() {
    return "Italian Giant";
  }
  public int height() {
    int height = 8;
    return height;
  }
  public boolean isGood() {
    return false;
  }
}
// Role Printer class
class RolePrinter {
  public void printRole(Player x) {
    System.out.println(x.role());
  }
}
// Main program
public class Lab7 {
    public static void main(String argv[]) {
        RolePrinter r = new RolePrinter();
        Player pl = new Player();
        Human hu = new Human();
        Robot ro = new Robot();
        r.printRole(pl);
        r.printRole(hu);
        r.printRole(ro);
        System.out.println();
        NorthAmerican na = new NorthAmerican();
        European euro = new European();
        na.setName("John");
        euro.setName("Luigi");
        makePlayer(na);
        System.out.println();
        makePlayer(euro);
    }

    // Polymorphism
    static void makePlayer(Giant player) {
      System.out.println("Name: " + player.getName());
      System.out.println("Citizenship: " + player.citizenship());
      System.out.println("Height: " + player.height() + " feet");
      System.out.println("Is Good?: " + player.isGood());
    }
    // static void makePlayer(European player) {
    //   System.out.println("Name: " + player.getName());
    //   System.out.println("Citizenship: " + player.citizenship());
    //   System.out.println("Height: " + player.height() + " feet");
    //   System.out.println("Is Good?: " + player.isGood());
    // }
}
