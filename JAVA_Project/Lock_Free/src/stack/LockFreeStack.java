package stack;

import java.util.concurrent.atomic.AtomicReference;


class LockFreeStack <T> extends  Stack<T>{
	private AtomicReference<Node<T>> ref;
	public LockFreeStack() {
		super();
		ref = new  AtomicReference<Node<T>>(_head.next);
	}
	@Override
	void Push(T item) {
		Node<T> node = new Node<T>(item);
		Node<T> old = ref.get();
		do {
			node.next = old;
		}while(!ref.compareAndSet(old, node));
		_head.next = ref.get();
	}

	@Override
	T Pop() {
		Node<T> old; 
		do{
			old = ref.get();
			if(old == null)
				return null; 
		}while(!ref.compareAndSet(old, old.next));
		_head.next = ref.get();
		return old.item;
		
	}
	
}