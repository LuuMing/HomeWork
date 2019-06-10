package stack;

import static org.junit.jupiter.api.Assertions.*;

import org.junit.jupiter.api.Test;

class LockFreeStackTest extends StackTest {

	@Test
	void test() {
		Stack<Integer> Stack = new LockFreeStack<Integer>();
		testStack(Stack);
		assertEquals(true,Stack.empty());
	}
}
