package Java;

import java.util.ArrayList;
import java.util.List;
public class GenericMap<K,V>{

    private List<KeyValue<K,V>> keys = new ArrayList<>();

    public void put(K key,V value){
        KeyValue k = new KeyValue(key,value);
        keys.add(k);
    }

    public void readAll(){
        for(KeyValue key : keys){
            System.out.println(key);
        }
    }

    public void remove(K key){
        for(int i=0;i<keys.size();i++){
            if(keys.get(i).getKey()==key)
                keys.remove(keys.get(i));
        }
    }

    public void readByKey(K key){
        for(int i=0;i<keys.size();i++){
            if(keys.get(i).getKey()==key)
                System.out.println(keys.get(i));
        }
    }

    public int size(){
        return keys.size();
    }

    public boolean isEmpty(){
        if(keys.size()==0){
            return true;
        }
        return false;
    }
}

class KeyValue<K,V>{
    private K key;
    private V value;

    public KeyValue(K key,V value){
        this.key=key;
        this.value=value;
    }

    public K getKey() {
        return key;
    }

    public void setKey(K key) {
        this.key = key;
    }

    public V getValue() {
        return value;
    }

    public void setValue(V value) {
        this.value = value;
    }

    @java.lang.Override
    public java.lang.String toString() {
        return "key=" + key +
                ", value=" + value;
    }
}