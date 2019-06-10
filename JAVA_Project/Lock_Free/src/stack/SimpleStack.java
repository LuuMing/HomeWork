package stack;
import java.util.stream.IntStream;

public class SimpleStack<T> extends Stack<T> {
	
	public SimpleStack(){
		super();
	}
	
	public void Push(T item) {
		Node<T> node = new Node<T>(item);
		node.next = _head.next;
		_head.next = node;
	}
	
	public T Pop() {
		Node<T> node = _head.next;
		if(node == null)
			return null;
		_head.next = node.next; 
		return node.item;
	}
}
