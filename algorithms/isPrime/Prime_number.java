public class Prime_number {
    
    static boolean isPrime(int n){
        if(n <= 3){
             if(n <= 1 ) return false;
             else return true;
        } 
        if(n%2==0) return false;
        if(n%3==0) return false;
        
        int m = (int) Math.sqrt(n)+1;
        
        for(int i = 5 ; i< m ; i+=6){
            if(n%i==0) return false;
            if(n%(i+2)==0) return false;
        }
        return true;
    }
    
    public static void main(String[] args) {
        int count=0;
        for(int n = 1 ; n<=1000 ; n++){
            if(isPrime(n)) count++;
        }
        System.out.println(count);
    }
}