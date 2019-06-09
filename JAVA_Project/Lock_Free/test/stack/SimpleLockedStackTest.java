package stack;

import static org.junit.jupiter.api.Assertions.*;

import org.junit.jupiter.api.Test;

class SimpleLockedStackTest extends StackTest {

	@Test
	void test() {
		Stack<Integer> Stack = new SimpleLockedStack<Integer>();
		testStack(Stack);
		assertEquals(true,Stack.empty());
	}

}
