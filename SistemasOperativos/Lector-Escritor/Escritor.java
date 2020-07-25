public class Escritor{
		public static void main(String[] args) {
			Lector1 instance = new Lector1();
			instance.start();

			while(instance.count != 100){
				try{
					Thread.sleep(250);
				}catch (InterruptedException exc){
					exc.printStackTrace();
				}
			}
		}
}
