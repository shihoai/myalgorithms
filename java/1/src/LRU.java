import java.util.HashMap;
import java.util.Map;

public class LRU {
    class DlinkNode{
        int key;
        int value;
        DlinkNode prev;
        DlinkNode next;
        public DlinkNode(){}
        public DlinkNode(int _key,int _value){
            key = _key;
            value = _value;
        }
    }

    private Map<Integer,DlinkNode> cache = new HashMap<>();
    private int size;
    private int capacity;
    private DlinkNode head,tail;

    public LRU(int capacity){
        this.size = 0;
        this.capacity = capacity;

        head = new DlinkNode();
        tail = new DlinkNode();
        head.next = tail;
        tail.prev = head;
    }

    public int get(int key){
        DlinkNode node = cache.get(key);
        if(node == null){
            return -1;
        }
        return node.value;
    }

    public void put(int key,int value){
        DlinkNode node = cache.get(key);
        if(node == null){
            DlinkNode newNode = new DlinkNode(key,value);
            cache.put(key,newNode);
            addToHead(newNode);
            ++size;

            if(size > capacity){
                DlinkNode tail = removeTail();
                cache.remove(tail.key);
                --size;
            }
        }else{
            node.value = value;
            moveToHead(node);
        }
    }

    public void addToHead(DlinkNode node){
        node.prev = head;
        node.next = head.next;
        head.next.prev = node;
        head.next = node;
    }

    public void removeNode(DlinkNode node){
        node.prev.next = node.next;
        node.next.prev = node.prev;
        node.next = null;
        node.prev = null;
    }

    public void moveToHead(DlinkNode node){
        removeNode(node);
        addToHead(node);
    }

    private DlinkNode removeTail(){
        DlinkNode res = tail.prev;
        removeNode(res);
        return res;
    }
}
