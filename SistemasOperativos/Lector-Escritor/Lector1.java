public class Lector1 extends Thread{
	int count = 0;

	public void run(){
		System.out.println("Lector starting");
		try{
			while(count < 100){
				Thread.sleep(500);
				System.out.println("Count is: " +count);
				count++;
			}
			}catch(InterruptedException exc){
				System.out.println("Lector interrupted");
			
		}
		System.out.println("Lector terminating");
	}
}