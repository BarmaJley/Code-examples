package buses;

import java.util.ArrayList;
import java.util.Arrays;
import java.util.Collections;
import java.util.HashMap;
import java.util.HashSet;
import java.util.List;
import java.util.Map;
import java.util.Set;
import java.util.TreeMap;

public class Buses {
    HashMap<Integer, ArrayList<String>> buses = new HashMap<>();
    int queue = 1;

    Buses(){}

    Buses(int number, String name, String[] stops){
        ArrayList<String> nameStops = new ArrayList<>();
        nameStops.add(name);
        nameStops.addAll(Arrays.asList(stops));
        this.queue = number;
        this.buses.put(queue, nameStops);
        this.queue++;
    }
    
    public int addBus (String name, String[] stops) throws Exception {
        ArrayList<String> nameStops = new ArrayList<>(Arrays.asList(name));
        
        nameStops.addAll(Arrays.asList(stops));
        
        int fl = isAlreadyExist(nameStops);
        if (fl != -1)
            throw new Exception(String.format("Already exists for %d", fl));

        this.buses.put(queue, nameStops);
        this.queue++;
        return queue-1;
    }

    public boolean equalWithoutFirst(ArrayList<String> l1, ArrayList<String> l2){
        for (int i = 1 ; i < l1.size(); i++)
            if (!l1.get(i).equals(l2.get(i)))
                return false;
        return true;
    }

    // Возвращает номер маршрута если такой существует, -1 - не существует
    public int isAlreadyExist(ArrayList<String> l){
        for (Map.Entry<Integer, ArrayList<String>> dict : this.buses.entrySet()) {
            int key = dict.getKey();
            ArrayList<String> stops = dict.getValue();
            
            if (!equalWithoutFirst(l, stops))
                return -1;
            else
                return key;
        }
        return -1;
    }



    public List<String> sbusesForStop (String nameStop) throws Exception{
        List<String> list = new ArrayList<>();
        Map<Integer, String> list_queues = new TreeMap<>();
        
        for (Map.Entry<Integer, ArrayList<String>> dict : this.buses.entrySet()) {
            int key = dict.getKey();
            ArrayList<String> stops = dict.getValue();
            if (stops.contains(nameStop))
                list_queues.put(key, stops.get(0));
        }
        
        if (list_queues.isEmpty())
            throw new Exception(String.format("No stop"));
        
        list.addAll(list_queues.values());
        
        return list;
    }

    public Set<Integer> nbusesForStop (String nameStop) throws Exception {
        Set<Integer> numbers = new HashSet<>();
        
        for (Map.Entry<Integer, ArrayList<String>> dict : this.buses.entrySet()) {
            int key = dict.getKey();
            ArrayList<String> stops = dict.getValue();
            if (stops.contains(nameStop)){
                numbers.add(key);
            }
        }

        if (numbers.isEmpty())
            throw new Exception(String.format("No stop"));

        return numbers;
    }
    
    public ArrayList<String> busStops(String name){
        ArrayList<String> stops = new ArrayList<>();
        for (ArrayList<String> n_stops : this.buses.values()) {
            if (n_stops.get(0).equals(name)){
                for (int j = 1 ; j < n_stops.size(); j++)
                    stops.add(n_stops.get(j));
            }
            
        }
        return stops;
    } 

    public Map<String, Set<Integer>> stopsForBus (String name) throws Exception{
        Map<String, Set<Integer>> dict = new HashMap<>();
        ArrayList<String> stops = busStops(name);
        for(String station : stops){ 
            Set<Integer> buse = nbusesForStop(station);
            buse.remove(getNumber(name));
            dict.put(station, buse);
        }
        
        int n = 0;
        for (String key : dict.keySet())     
            n = Math.max(dict.get(key).size(), n);
        if (n == 0) throw new Exception(String.format("No bus"));
            
        
        return dict;
    }
    public int getNumber(String name){
        for (Map.Entry<Integer, ArrayList<String>> dict : this.buses.entrySet()) {
            int key = dict.getKey();
            ArrayList<String> stops = dict.getValue();
            if (stops.get(0).equals(name))
                return key;
        }
        return -1;    
    }

    public List<String> allBuses () throws Exception {
        List<String> list = new ArrayList<>();
        for (ArrayList<String> name_stops: this.buses.values())
            list.add(name_stops.get(0));
        Collections.sort(list);
        return list;
    }

    public static void main(String[] args) throws Exception {
       String[] stops1 = new String[]{"Railway Station", "Stachki 1902", "Сrossing bridge"};
       String[] stops2 = new String[]{"Central market", "Donskoi corpus", "Stachki 1902", "Сrossing bridge"};
       String[] stops4 = new String[]{"Airport"};
       String[] stops3 = new String[]{"Theatre prospect", "Music theatre", "Universitetcki"};
       Buses b = new Buses(1, "Zapadniy", stops1);
       b.addBus("Centralniy rinok", stops2);
       b.addBus("GPZ_10", stops3);
       b.addBus("Platov", stops4);
       
       System.out.println(b.allBuses());
       System.out.println(b.sbusesForStop("Airport"));
       System.out.println(b.nbusesForStop("Stachki 1902"));
       System.out.println(b.stopsForBus("Centralniy rinok"));
       
       
    }

}
