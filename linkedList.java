
public class linkedList {
	int data;
	linkedList next = null;
	
	public linkedList(int i){
		this.data = i;
	}
	
	void appendToTail(int i){
		linkedList n = new linkedList(i);
		linkedList old = this;
		while (old.next != null){
			old = old.next;
		}
		old.next = n;
		old = old.next;
	}
	
	void deleteAllIntegerNodes(int i){
		linkedList old = this;
		
		if (old.data == i){
			old = old.next;
		}
		
		while (old.next != null){
			if (old.next.data == i){
				old.next = old.next.next;
			}
			old = old.next;
		}
	}
		
	int getLength(){
		if ((this == null) && (this.next == null)){
			return 0;
		}
		
		int length = 1;
		linkedList n = this;
		while (n.next != null){
			length++;
		}
		return length;	
	}
	
	void deleteIndexedNode(int i){
		int length = this.getLength();
		
		linkedList n = this;
		int temp = 1;
		
		if (length == 0){
			return;
		}
		
		if (i > length){
			System.out.println("The associated index is over the length.");
		}
		
		while (n.next != null){
			if (temp == i){
				n.next = n.next.next;
				return;
			}
		}
		
		
	}
	
}
