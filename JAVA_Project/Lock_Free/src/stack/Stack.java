package stack;

public abstract class Stack <T>{
	protected Node _head;
	protected class Node<T>{
		public T item;
		public Node<T> next;
		public Node() {
		}
		public Node(T _item){ 
			this.item = _item;
		}
	}
	abstract void Push(T item);
	abstract T Pop();
	
	public Stack(){
		_head = new Node<T>();
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
	public Boolean empty() {
		return _head.next == null;
	}
}
