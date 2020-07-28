import java.util.Arrays;
import java.util.Comparator;
import java.util.PriorityQueue;

public class mainFunction {
    public static void main(String []args){
        int k = 7;
        int []c = new int[]{8,9,10,-232,4332,-90032,231,5490,2112,54,-50,45,-222};
        int []b = new int[k];
        b = mainFunction.TopK(c,k);

        Arrays.sort(c);
        for(int i : c){
            System.out.print(i + " ");
        }

        System.out.println("");
        for(int i : b){
            System.out.print(i + " ");
        }
    }

    public static int[] TopK(int []a,int k){
        int []answer = new int[k];
        PriorityQueue<Integer> heap = new PriorityQueue<>(new Comparator<Integer>() {
            @Override
            public int compare(Integer o1, Integer o2) {
                return o1 - o2;
            }
        });

        for(int i : a){
            if(heap.isEmpty() || heap.size() < k || i > heap.peek()){
                heap.add(i);
            }

            if(heap.size() > k){
                heap.poll();
            }
        }

        int n = 0;
        for(int i : heap){
            answer[n++] = i;
        }


        return answer;
    }
}
