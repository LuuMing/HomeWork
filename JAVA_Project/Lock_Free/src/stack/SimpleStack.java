package stack;
import java.util.stream.IntStream;

public class SimpleStack<T> {
	
	
	private class Node<T>{
		public T item;
		public Node<T> next;
	}
	
	private Node _head;
	
	public SimpleStack(){
		_head = new Node<T>();
	}
	
	public void Push(T item) {
		Node<T> node = new Node<T>();
		node.item = item;
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
	
	public String toString(){
		Node<T> p = _head;
		String ret = "";
		while(p != null){
			if(p.item == null)
				ret += "head";
			else
				ret += p.item.toString();
			ret  += " -> ";
			p = p.next;
		}
		return ret;
	}	
	public static void main(String[] args) {
		
		SimpleStack<Integer> Stack = new SimpleStack<Integer>();
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
