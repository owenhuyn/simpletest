
public class stack {
	int data;
	stack next = null;
	
	public stack(int i){
		this.data = i;
	}
	
	void push(int i){
		stack n = new stack(i);
		stack old = this;
		n.next = old;
	}
	
	int pop(){
		if (this == null){
			return (Integer) null;
		}
		stack n = this;
		int nData = n.data;
		n = n.next;
		return nData;
	}
}
