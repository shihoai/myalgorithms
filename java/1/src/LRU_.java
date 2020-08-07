import java.util.HashMap;

public class LRU_ {
    class Dnode{
        int key;
        int value;
        Dnode prev;
        Dnode next;
        Dnode(){

        }

        Dnode(int key1,int value1){
            key = key1;
            value = value1;
        }
    }

    private HashMap<Integer,Dnode> map;
    private int size;
    private int capacity;
    private Dnode head;
    private Dnode tail;


    public LRU_(int capacity) {
        map = new HashMap<>();
        size = 0;
        this.capacity = capacity;
        head = new Dnode();
        tail = new Dnode();
        head.next = tail;
        tail.prev = head;
    }

    public void addToHead(Dnode dnode){
        dnode.prev =head;
        dnode.next = head.next;
        head.next.prev = dnode;
        head.next = dnode;
    }

    public void removeNode(Dnode dnode){
        dnode.prev.next = dnode.next;
        dnode.next.prev = dnode.prev;
        dnode.next = null;
        dnode.prev = null;
    }

    public void moveTohead(Dnode dnode){
        removeNode(dnode);
        addToHead(dnode);
    }

    public Dnode removeTail(){
        Dnode res = tail.prev;
        removeNode(res);
        return res;
    }

    public int get(int key) {
        Dnode dnode = map.get(key);
        if(dnode == null){
            return -1;
        }
        moveTohead(dnode);
        return dnode.value;
    }

    public void put(int key, int value) {
        Dnode dnode = map.get(key);
        if(dnode == null){
            Dnode newDnode = new Dnode(key,value);
            map.put(key,newDnode);
            addToHead(newDnode);
            size++;

            if(size > capacity){
                Dnode res = removeTail();
                size--;
                map.remove(res.key);
            }
        }else{
            dnode.value = value;
            moveTohead(dnode);
        }
    }
}

