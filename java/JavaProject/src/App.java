class Player {
    private String name;
    private int baseHP;
    private int baseAtk;
    private Weapon weapon;
    private Armor armor;
    private int level;
    private int incrementHP;
    private int incrementAtk;

    public Player(String name) {
        this.name = name;
        this.baseHP = 100;
        this.baseAtk = 100;
        this.level = 1;
        this.incrementHP = 20;
        this.incrementAtk = 20;
    }

    public void display() {
        System.out.println("Player: " + this.name);
        System.out.println("Level: " + this.level);
        System.out.println("Max Health: " + this.maxHealth());
        System.out.println("Attack: " + this.getAttackPower());
        armor.displayArmor();
        weapon.displayWeapon();
        System.out.println();
    }

    public void levelUp() {
        this.level++;
    }

    public void setArmor(Armor armor) {
        this.armor = armor;
    }

    public void setWeapon(Weapon weapon) {
        this.weapon = weapon;
    }

    public int maxHealth() {
        return this.baseHP + this.level * this.incrementHP + this.armor.getAddHealth();
    }

    public int getAttackPower() {
        return this.baseAtk + this.level * this.incrementAtk + this.weapon.getAttack();
    }

}

class Armor {
    private String name;
    private int def;
    private int health;

    public Armor(String name, int defense, int health) {
        this.name = name;
        this.def = defense;
        this.health = health;
    }

    public void displayArmor() {
        System.out.println("Armor: " + this.name);
    }

    public int getAddHealth() {
        return this.def * 10 + this.health;
    }

    public int getDef() {
        return this.def;
    }

}

class Weapon {
    private String name;
    private int dmg;

    public Weapon(String name, int attack) {
        this.name = name;
        this.dmg = attack;
    }

    public void displayWeapon() {
        System.out.println("Weapon: " + this.name);
    }

    public int getAttack() {
        return this.dmg;
    }
}

public class App {
    public static void main(String[] args) throws Exception {
        Player player1 = new Player("Felix");
        Armor iron_armor = new Armor("Iron", 5, 100);
        Weapon iron_axe = new Weapon("Iron Axe", 10);
        player1.setArmor(iron_armor);
        player1.setWeapon(iron_axe);

        Player player2 = new Player("Vander");
        Armor wooden_armor = new Armor("Wood", 2, 50);
        Weapon wooden_axe = new Weapon("Wooden Axe", 4);
        player2.setArmor(wooden_armor);
        player2.setWeapon(wooden_axe);

        player1.display();
        player2.display();
    }

}
