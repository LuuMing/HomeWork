package stack;
import java.util.stream.IntStream;

class StackTest {
	void testStack(Stack<Integer> Stack) {
		for(int i = 0;i < 100000; i++) {
			Stack.Push(i);
		}
		IntStream stream = IntStream.range(0,100000);
		Boolean [] poped = new Boolean[100001];
		stream.parallel().forEach(integer -> {
			Integer item = Stack.Pop();
			if( poped[item]!= null && poped[item]) {
				System.out.println(String.format("Thread %d Item ", Thread.currentThread().getId()) + "Item " + item.toString());
			}
			poped[item] = true;
		});
		System.out.print(Stack);
		System.out.print("Done");
	}
}
