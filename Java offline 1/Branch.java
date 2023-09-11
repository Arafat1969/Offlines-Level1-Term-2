public class Branch {

    private int id;
    private String name;
    private Account []  accounts;
    private int accountCount=0;
	// add your code here
	// you are allowed to add variables here
    private static  Branch br[]=new Branch[20];
    private static int count=0;

    // there can be at most 20 branches  

    // you are not allowed to write any other constructor
    public Branch(int id, String name) {
        this.id = id;
        this.name = name;
        this.accounts = new Account[10];
        // add your code here
        br[count++]=this;
    }



    // add your code here
    public static void transferBalance(Account account, Account account1, int i) {
        account.setBalance(account.getBalance()-i);
        account1.setBalance(account1.getBalance()+i);

    }

    public static void printAllBranchesInfo() {
        for(int i=0;i<count;i++){
            System.out.println("Branch Id: "+br[i].id+", Branch Name: "+br[i].name);
            for(int j=0;j<br[i].accountCount;j++){
                System.out.println("Account Number: "+br[i].accounts[j].getNumber()+", Customer Name: "+br[i].accounts[j].getCustomer()+", Balance: "+br[i].accounts[j].getBalance());
            }
        }
    }

    // you are not allowed to modify this method
    public void addAccount(Account a) {
        accounts[accountCount++] = a;
    }

    public double getBranchBalance() {
        double sum=0;
        for(int i=0; i< accountCount;i++){
            sum+= accounts[i].getBalance();
        }
        return sum;

    }

    public Account getMinBalanceAccount() {
        double min;
        int m=0;
        min=accounts[0].getBalance();
        for(int i=0;i< accountCount;i++){
            if(accounts[i].getBalance()<min){
                min=accounts[i].getBalance();
                m=i;
            }
        }
        return accounts[m];
    }

}
