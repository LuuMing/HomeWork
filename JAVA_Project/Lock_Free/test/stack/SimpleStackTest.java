package stack;

import static org.junit.jupiter.api.Assertions.*;

import java.util.stream.IntStream;

import org.junit.jupiter.api.Test;

class SimpleStackTest extends StackTest {

	@Test
	void test() {
		Stack<Integer> Stack = new SimpleStack<Integer>();
		testStack(Stack);
		assertEquals(true,Stack.empty());
	}

}
