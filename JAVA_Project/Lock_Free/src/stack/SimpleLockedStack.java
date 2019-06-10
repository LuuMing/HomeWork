package stack;

public class SimpleLockedStack<T> extends Stack<T> {
	@Override
	void Push(T item) {
		synchronized(_head) {
			Node<T> node = new Node<T>(item);
			node.next = _head.next;
			_head.next = node;
		}
	}

	@Override
	T Pop() {
		synchronized(_head) {
			Node<T> node = _head.next;
			if(node == null)
				return null;
			_head.next = node.next; 
			return node.item;
		}
	}
}
