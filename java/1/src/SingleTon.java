

public class SingleTon {
    private static volatile  SingleTon singleInstance;

    public SingleTon(){

    }

    public SingleTon getInstance(){
        if(singleInstance == null){
            synchronized (SingleTon.class){
                if(singleInstance == null){
                    singleInstance = new SingleTon();
                }
            }
        }
        return singleInstance;
    }
}
