package stack;
import java.util.stream.IntStream;

class StackTest {
	private Boolean [] poped;
	void testStack(Stack<Integer> Stack) {
		for(int i = 0;i < 5000; i++) {
			Stack.Push(i);
		}
		poped = new Boolean[5001];
		Thread threads [] = new Thread[5000];
		for(int i = 0; i < 5000; i++) {
			threads[i] = new popThread(Stack);
		}
		for(int i = 0; i < 5000; i++) {
			threads[i].start();
		}
		for(int i = 0; i < 5000; i++) {
			try {
				threads[i].join();
			} catch (InterruptedException e) {
				// TODO Auto-generated catch block
				e.printStackTrace();
			}
		}
		System.out.print(Stack);
		System.out.print("Done");
	}
	
	private class popThread extends Thread{
		private Stack stack;
		public popThread(Stack _stack) {
			this.stack = _stack;
		}
		public void run() {
			super.run();
			Integer item = (Integer) stack.Pop();
			if( poped[item]!= null && poped[item]) {
				System.out.println(String.format("Thread %d Item ", Thread.currentThread().getId()) + "Item " + item.toString());
			}
			poped[item] = true;
		}
	}
}
